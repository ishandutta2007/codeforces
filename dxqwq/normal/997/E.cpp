// Problem: E. Good Subsegments
// Contest: Codeforces - Codeforces Round #493 (Div. 1)
// URL: https://codeforces.com/problemset/problem/997/E
// Memory Limit: 512 MB
// Time Limit: 7000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
#define ll long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int a[250003],l2[250003],MX[250003][23],MN[250003][23],n;
inline void init(int l)
{
	MX[l][0]=MN[l][0]=a[l];
	for(int i=1; i<=20; i++) 
    MX[l][i]=max(MX[l][i-1],MX[min(l+(1<<(i-1)),n)][i-1]),
    MN[l][i]=min(MN[l][i-1],MN[min(l+(1<<(i-1)),n)][i-1]);
}
inline int check(int l,int r)
{
	int L=l2[r-l+1];
	return (r-l)==(max(MX[l][L],MX[min(r-(1<<L)+1,n)][L])-min(MN[l][L],MN[min(r-(1<<L)+1,n)][L]));
}
struct node{int L,R,type;}tree[250003];
vector<int> e[250003];
int cnt,leaf[250003];
int s[250003],top;
int smin[250003],topmin;
int smax[250003],topmax;
int tag[1000003],ans[1000003];
int qwq[250003];
int d[250003],f[250003][23];
void push_down(int x)
{
	tag[x<<1]+=tag[x],tag[(x<<1)+1]+=tag[x],
	ans[x<<1]+=tag[x],ans[(x<<1)+1]+=tag[x],
	tag[x]=0;
	return ;
}
void update(int l,int r,int L,int R,int id,int val)
{
	if(L==l && r==R) 
	{
		tag[id]+=val;
		ans[id]+=val;
		return ;
	}
	int mid=(l+r)>>1;
	push_down(id);
	if(R<=mid) update(l,mid,L,R,id<<1,val);
	else if(L>=mid+1) update(mid+1,r,L,R,(id<<1)+1,val);
	else update(l,mid,L,mid,id<<1,val),update(mid+1,r,mid+1,R,(id<<1)+1,val);
    ans[id]=min(ans[(id<<1)],ans[(id<<1)+1]);
	return ;
}
int query(int l,int r,int id)
{
	if(l==r) return l;
	int mid=(l+r)>>1;
	push_down(id);
	if(ans[id<<1]==0) return query(l,mid,id<<1);
	return query(mid+1,r,(id<<1)+1);
}
inline bool check1(int x)
{
    if(tree[s[top]].type!=1) return 0;
    return check(qwq[s[top]],x);
}
inline bool check2(int x)
{
    return check(tree[s[top]].L,tree[x].R);
}
inline void init(int u,int father)
{
    d[u]=d[father]+1;
    for(int i=1; i<=20; i++) f[u][i]=f[f[u][i-1]][i-1];
    for(int v:e[u])
        f[v][0]=u,init(v,u);
    return ;
}
inline int LCA(int x,int y)
{
    if(d[x]<d[y])swap(x,y);
    for(int i=20; i>=0; --i)
    {
        if(d[f[x][i]]>=d[y])x=f[x][i];
        if(x==y)return x;
    }
    for(int i=20; i>=0; --i) if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	return f[x][0];
}
inline int ACL(int x,int y)
{
    for(int i=20; i>=0; --i) if(d[f[x][i]]>d[y]) x=f[x][i];
	return x;
}
struct Query{int l,r,id;};
vector<Query> v[300003];
ll Ans[300003],sum[300003];
int son[300003];
ll tree1[300003];
ll tree2[300003];
void add1(int x,int k)
{
	while(x<=300000) tree1[x]+=k,x+=x&(-x);
	return ;
}
ll find1(int x)
{
	ll res=0;
	while(x) res+=tree1[x],x-=x&(-x);
	return res;
}
void add2(int x,int k)
{
	while(x<=300000) tree2[x]+=k,x+=x&(-x);
	return ;
}
ll find2(int x)
{
	ll res=0;
	while(x) res+=tree2[x],x-=x&(-x);
	return res;
}
void solve(int x)
{
	int sz=(int)e[x].size();
	for(int i=0; i<sz; ++i)
		son[e[x][i]]=i,solve(e[x][i]),sum[x]+=sum[e[x][i]];
	if(tree[x].type==1) 
	{
		for(int i=1; i<sz; ++i) add2(tree[e[x][i]].R,i),sum[x]+=i;
		for(int i=sz-2; i>=0; --i) add1(tree[e[x][i]].L,sz-i-1);
		for(Query i:v[x]) 
		{
			int l=ACL(leaf[i.l],x),r=ACL(leaf[i.r],x);
			Ans[i.id]=sum[x]-find1(i.l-1)+find1(tree[x].L-1)
			-find2(tree[x].R)+find2(i.r)
			+(son[l]+1ll-(i.l==tree[l].L))*(sz-son[r]-(i.r==tree[r].R));
		}
	} 
	else 
	{
		add1(tree[x].L,1),add2(tree[x].R,1),++sum[x];
		for(Query i:v[x])
			Ans[i.id]=sum[x]-find1(i.l-1)+find1(tree[x].L-1)
			-find2(tree[x].R)+find2(i.r)+(i.l!=tree[x].L&&i.r!=tree[x].R);
	}
	return ;
}
signed main()
{
    n=read();
    for(int i=1; i<=n; i++) a[i]=read();
    for(int i=2; i<=n; ++i) l2[i]=l2[i>>1]+1;
    for(int i=n; i>=1; i--) init(i);
    for(int i=1; i<=n; i++) 
    {
        while(topmin&&a[i]<a[smin[topmin]]) update(1,n,smin[topmin-1]+1,smin[topmin],1,a[smin[topmin]]),--topmin;
        while(topmax&&a[i]>a[smax[topmax]]) update(1,n,smax[topmax-1]+1,smax[topmax],1,-a[smax[topmax]]),--topmax;
        update(1,n,smin[topmin]+1,i,1,-a[i]);
        update(1,n,smax[topmax]+1,i,1,a[i]);
        if(i!=1) update(1,n,1,i-1,1,-1);
        smin[++topmin]=i,smax[++topmax]=i;
        int now=++cnt,tmp,le=query(1,n,1);
        leaf[i]=now,tree[now].L=tree[now].R=i,tree[now].type=-1;
        while(top&&tree[now].L>=le)
        {
            if(check1(i))
        		tmp=s[top--],e[tmp].push_back(now),
            	tree[tmp].L=min(tree[tmp].L,tree[now].L),
            	tree[tmp].R=max(tree[tmp].R,tree[now].R),
            	now=tmp;
            else if(check2(now))
                tmp=++cnt,e[tmp].push_back(now),e[tmp].push_back(s[top]),
                tree[tmp].L=tree[s[top--]].L,
                tree[tmp].R=tree[now].R,
                tree[tmp].type=1,
                qwq[tmp]=tree[now].L,
                now=tmp;
            else if(top&&le<=tree[s[top]].L)
            {
                tmp=++cnt,e[tmp].push_back(now),
                tree[tmp].R=tree[now].R,
                tree[tmp].type=0;
                do 
                {
                	tree[tmp].L=tree[s[top]].L,e[tmp].push_back(s[top--]); 
                }while(top&&check(tree[s[top]].R+1,tree[now].R)==0);
                now=tmp;
            } 
            else break;
        }
        s[++top]=now;
    }
    int rt=-1;
    for(int i=1; i<=cnt; ++i) 
    	sort(e[i].begin(),e[i].end(),
    	[&](int x,int y){return tree[x].L<tree[y].L;});
    for(int i=1; i<=cnt; i++) 
        if(tree[i].L==1 && tree[i].R==n) rt=i;
    f[rt][0]=rt;
    init(rt,rt);
 	int m=read();
    for(int i=1; i<=m; ++i)
    {
    	int x=read(),y=read(),id=LCA(leaf[x],leaf[y]);
    	v[id].push_back((Query){x,y,i});
    }
    solve(rt);
    for(int i=1; i<=m; ++i) printf("%lld\n",Ans[i]);
    return 0;
}