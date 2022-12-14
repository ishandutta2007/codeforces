#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define in inline
namespace fast_io
{
	char buf[1<<12],*p1=buf,*p2=buf,sr[1<<23],z[23],nc;int C=-1,Z=0,Bi=0;
	in char gc() {return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<12,stdin),p1==p2)?EOF:*p1++;}
	in int read()
	{
		int x=0,y=1;while(nc=gc(),(nc<48||nc>57)&&nc!=-1)if(nc==45)y=-1;Bi=1;
		x=nc-48;while(nc=gc(),47<nc&&nc<58)x=(x<<3)+(x<<1)+(nc^48),Bi++;return x*y;
	}
	in db gf() {int a=read(),b=(nc!='.')?0:read();return (b?a+(db)b/pow(10,Bi):a);}
	in int gs(char *s) {char c,*t=s;while(c=gc(),c<=32);*s++=c;while(c=gc(),c>32)*s++=c;return s-t;}
	in void ot() {fwrite(sr,1,C+1,stdout);C=-1;}
	in void flush() {if(C>1<<22) ot();}
	template <typename T>
	in void write(T x,char t)
	{
		int y=0;if(x<0)y=1,x=-x;while(z[++Z]=x%10+48,x/=10);
		if(y)z[++Z]='-';while(sr[++C]=z[Z],--Z);sr[++C]=t;flush();
	}
	in void write(char *s) {int l=strlen(s);for(int i=0;i<l;i++)sr[++C]=*s++;sr[++C]='\n';flush();}
}
using namespace fast_io;
const int N=6e5+5;
#define int ll
int n,m,k,a[N],b[N],ca[N],cb[N],arr[N],ans=-1e18,tmp[N],tl;
struct did{int a,b,c;}p[N];
struct node{int a,ca;}wp[N];
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
#define mid ((l+r)>>1)
int mx[N<<2],t[N<<2];
in void push_up(int x) {mx[x]=max(mx[ls(x)],mx[rs(x)]);}
in void push_down(int x) {if(!t[x])return;mx[ls(x)]+=t[x],mx[rs(x)]+=t[x],t[ls(x)]+=t[x],t[rs(x)]+=t[x];t[x]=0;}
in void build(int p,int l,int r)
{
	if(l==r) return mx[p]=arr[l],void();
	build(ls(p),l,mid);build(rs(p),mid+1,r);push_up(p);
}
void add(int p,int l,int r,int L,int R,int v)
{
	if(L<=l&&r<=R) return mx[p]+=v,t[p]+=v,void();push_down(p);
	if(L<=mid) add(ls(p),l,mid,L,R,v); if(R>mid) add(rs(p),mid+1,r,L,R,v);
	push_up(p);
}
int ask(int p,int l,int r,int L,int R)
{
	if(L<=l&&r<=R) return mx[p];push_down(p);
	if(R<=mid) return ask(ls(p),l,mid,L,R);
	if(L>mid) return ask(rs(p),mid+1,r,L,R);
	return max(ask(ls(p),l,mid,L,R),ask(rs(p),mid+1,r,L,R));
}
signed main()
{
	n=read();m=read();k=read();
	for(int i=1;i<=n;i++) wp[i]={read(),read()};
	for(int i=1;i<=m;i++) tmp[++tl]=b[i]=read(),cb[i]=read();
	for(int i=1;i<=k;i++) p[i]={read(),read(),read()},tmp[++tl]=p[i].b;
	sort(p+1,p+k+1,[](did a,did b){return a.a<b.a;});
	sort(wp+1,wp+n+1,[](node a,node b){return a.a<b.a;});
	sort(tmp+1,tmp+tl+1);tl=unique(tmp+1,tmp+tl+1)-tmp-1;
	for(int i=1;i<=n;i++) a[i]=wp[i].a,ca[i]=wp[i].ca;
	for(int i=1;i<=m;i++) b[i]=lower_bound(tmp+1,tmp+tl+1,b[i])-tmp;
	for(int i=1;i<=k;i++) p[i].b=lower_bound(tmp+1,tmp+tl+1,p[i].b)-tmp;
	for(int i=1;i<=tl;i++) arr[i]=-1e18;
	for(int i=1;i<=m;i++) arr[b[i]]=max(arr[b[i]],-cb[i]);
	build(1,1,tl);
	for(int i=1,j=1;i<=n;i++)
	{
		while(j<=m&&p[j].a<a[i])
		{
			if(p[j].b^tl) add(1,1,tl,p[j].b+1,tl,p[j].c);
			j++;
		}
		ans=max(ans,mx[1]-ca[i]);
	}
	write(ans,'\n');
	return ot(),0;
}
//Author: disangan233
//In my dream's scene,I can see the everything that in Cyaegha.
/*
5 5 7
2 3
4 4
8 8
2 8
7 6
3 8
6 1
4 7
3 8
2 5
1 2 4
5 2 1
3 2 1
1 4 4
5 2 1
2 3 3
3 2 2
*/