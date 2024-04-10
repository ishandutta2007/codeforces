#include<bits/stdc++.h>
using namespace std;
const int M=1000000007;
const int N=1000005;
int n,i,ch[N][2],fa[N],rev[N],mx[N],k,m,j,u[N],v[N];
struct str{int u,v;}e[N];
int lazy[N],w[N];
void pushup(int x)
{
    mx[x]=mx[ch[x][0]]|mx[ch[x][1]]|(x>n?w[x]:0);
}
void pushdown(int x)
{
	if(rev[x])
		rev[ch[x][0]]^=1,rev[ch[x][1]]^=1,swap(ch[x][0],ch[x][1]),rev[x]=0;
	if(lazy[x]!=-1)
	{
		if(ch[x][0])
			lazy[ch[x][0]]=mx[ch[x][0]]=w[ch[x][0]]=lazy[x];
		if(ch[x][1])
			lazy[ch[x][1]]=mx[ch[x][1]]=w[ch[x][1]]=lazy[x];
		lazy[x]=-1;
	}
}
void update(int x){pushup(x),pushdown(x);}
bool isr(int x){return !(ch[fa[x]][0]==x||ch[fa[x]][1]==x);}
void rotate(int x)
{
    int y=fa[x];bool d=(ch[y][0]==x);
    ch[y][!d]=ch[x][d];
    if(ch[x][d]!=0)fa[ch[x][d]]=y;
    fa[x]=fa[y];if(!isr(y))ch[fa[y]][ch[fa[y]][1]==y]=x;
    ch[x][d]=y;fa[y]=x;pushup(y),pushup(x);
}
void pd(int x){if(!isr(x))pd(fa[x]);update(x);}
void splay(int x){pd(x);for(int y=fa[x];!isr(x);rotate(x),y=fa[x])if((!isr(y))&&(ch[fa[y]][0]==y)==(ch[y][0]==x))rotate(y);}
void access(int x){for(int y=0;x!=0;y=x,x=fa[x])splay(x),update(x),ch[x][1]=y,update(x);}
void maker(int x){access(x),splay(x),rev[x]^=1,update(x);}
void link(int x,int y){maker(x),splay(x),fa[x]=y;}
void cut(int x,int y){maker(x),access(y),splay(x),update(x),ch[x][1]=0,fa[y]=0,update(x);}
int findroot(int x){access(x),splay(x);update(x);while(ch[x][0]!=0)x=ch[x][0],update(x);splay(x);return x;}
bool iscon(int x,int y){maker(x);if(findroot(y)==x)return true;else return false;}
int Sum(int u,int v)
{
	maker(u);
	access(v);
	splay(v);
	return mx[v];
}
void Tag(int u,int v,int z)
{
	maker(u);
	access(v);
	splay(v);
	mx[v]=w[v]=lazy[v]=z;
}
long long ans=0;
int main()
{
	scanf("%d %d",&n,&m);
	for(i=1;i<=m;i++)
		scanf("%d %d",&e[i].u,&e[i].v);
	k=n;
    int l=1;
    memset(lazy,-1,sizeof(lazy));
    for(i=1;i<=m;i++)
    {
        if(!iscon(e[i].u,e[i].v))
        {
        	link(n+i,e[i].u);
        	link(n+i,e[i].v);
        }
        else
        {
            while(iscon(e[i].u,e[i].v)&&Sum(e[i].u,e[i].v))
            {
            	splay(n+l);
            	int x=w[n+l];
            	//cerr<<x<<endl;
            	if(x!=0)
            	{
            		Tag(e[x].u,e[x].v,0);
            		cut(e[l].u,n+l);
            		link(e[x].u,n+x);
            		link(e[x].v,n+x);
            	}
            	else
            		cut(e[l].u,n+l);
            	++l;
            }
            if(!iscon(e[i].u,e[i].v))
            {
            	link(n+i,e[i].u);
        		link(n+i,e[i].v);
        	}
        	else
        		Tag(e[i].u,e[i].v,i);
        }
        ans+=i-l+1;
    }
    cout<<ans;
}