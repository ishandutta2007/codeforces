#pragma GCC optimize(2,3,"Ofast","unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define in inline
namespace fast_io
{
	char buf[1<<12],*p1=buf,*p2=buf,sr[1<<23],z[23],nc;int C=-1,Z=0,Bi=0,ny;
	in char gc() {return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<12,stdin),p1==p2)?EOF:*p1++;}
	in ll read()
	{
		ll x=0;ny=1;while(nc=gc(),(nc<48||nc>57)&&nc!=EOF)if(nc==45)ny=-1;Bi=1;if(nc<0)return nc;
		x=nc-48;while(nc=gc(),47<nc&&nc<58&&nc!=EOF)x=(x<<3)+(x<<1)+(nc^48),Bi++;return x*ny;
	}
	in db gf() {int a=read(),y=ny,b=(nc!='.')?0:read();return (b?a+(db)b/pow(10,Bi)*y:a);}
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
#define pb push_back
const int N=1e5+5;
int n,s[N],t,ans;ll a[N],b[N],c[N],d[N],g[N],w[N],k,mx[N<<2],md[N<<2],ad[N<<2];
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
#define mid ((l+r)>>1)
in void up(int x) {mx[x]=max(mx[ls(x)],mx[rs(x)]);md[x]=max(md[ls(x)],md[rs(x)]);}
in void down(int x) {if(ad[x]) mx[ls(x)]+=ad[x],mx[rs(x)]+=ad[x],ad[ls(x)]+=ad[x],ad[rs(x)]+=ad[x],ad[x]=0;}
void upd(int p,int l,int r,int x,ll k)
{
	if(l==r) return mx[p]=md[p]=k,void();down(p);
	x<=mid?upd(ls(p),l,mid,x,k):upd(rs(p),mid+1,r,x,k);up(p);
}
void add(int p,int l,int r,int L,int R,ll k)
{
	if(R<l||r<L)return;if(L<=l&&r<=R) return mx[p]+=k,ad[p]+=k,void();down(p);
	add(ls(p),l,mid,L,R,k);add(rs(p),mid+1,r,L,R,k);up(p);
}
int ask(int p,int l,int r,int L,int R,ll x)
{
	if(l==r) return l;down(p);
	if(L>mid) return ask(rs(p),mid+1,r,L,R,x);
	if(R<=mid) return ask(ls(p),l,mid,L,R,x);
	return md[rs(p)]+k>=max(mx[ls(p)],x)?ask(rs(p),mid+1,r,L,R,max(mx[ls(p)],x)):ask(ls(p),l,mid,L,R,x);
}
int main()
{
	n=read(),k=read();memset(mx,-63,sizeof(mx));
	for(int i=1;i<n;i++) a[i]=a[i-1]+(w[i]=read());
	for(int i=1;i<=n;i++) b[i]=b[i-1]+(g[i]=read());
	for(int i=1;i<=n;i++) c[i]=a[i-1]-b[i-1];
	for(int i=1;i<=n;i++) d[i]=b[i]-a[i-1];
	for(int i=n;i;i--)
	{
		while(t&&c[i]>=c[s[t]]) {if(t>1)add(1,1,n,s[t-1]-1,n,c[s[t]]-c[s[t-1]]);t--;}
		s[++t]=i,upd(1,1,n,i,d[i]);if(t>1) add(1,1,n,s[t-1]-1,n,c[s[t-1]]-c[i]);
		int l=1,r=t;
		while(l<r) c[s[mid]]-c[i]<=k?r=mid:l=mid+1;
		r=(r==1)?n:s[r-1]-1;
		ans=max(ans,ask(1,1,n,i,r,-1e18)-i+1);
	}
	write(ans,'\n');
	return ot(),0;
}
//Author: disangan233