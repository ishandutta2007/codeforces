#pragma GCC optimize(2,3,"Ofast") 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define re register int
#define db double
#define in inline
namespace fast_io
{
	char buf[1<<12],*p1=buf,*p2=buf,sr[1<<23],z[23],nc;int C=-1,Z=0,Bi=0;
	in char gc() {return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<12,stdin),p1==p2)?EOF:*p1++;}
	in ll read()
	{
		ll x=0,y=1;while(nc=gc(),(nc<48||nc>57)&&nc!=-1)if(nc==45)y=-1;Bi=1;
		x=nc-48;while(nc=gc(),47<nc&&nc<58)x=(x<<3)+(x<<1)+(nc^48),Bi++;return x*y;
	}
	in db gf() {re a=read(),b=(nc!='.')?0:read();return (b?a+(db)b/pow(10,Bi):a);}
	in int gs(char *s) {char c,*t=s;while(c=gc(),c<32);*s++=c;while(c=gc(),c>32)*s++=c;return s-t;}
	in void ot() {fwrite(sr,1,C+1,stdout);C=-1;}
	in void flush() {if(C>1<<22) ot();}
	template <typename T>
	in void write(T x,char t)
	{
		re y=0;if(x<0)y=1,x=-x;while(z[++Z]=x%10+48,x/=10);
		if(y)z[++Z]='-';while(sr[++C]=z[Z],--Z);sr[++C]=t;flush();
	}
	in void write(char *s) {re l=strlen(s);for(re i=0;i<l;i++)sr[++C]=*s++;flush();}
}
using namespace fast_io;
const int N=2e5+5;
ll n,k,f[N];
char s[N];
struct seg{
	ll mn[N<<2];
	#define ls(x) (x<<1)
	#define rs(x) (x<<1|1)
	#define mid ((l+r)>>1) 
	in void push_up(re x) {mn[x]=min(mn[ls(x)],mn[rs(x)]);}
	void build(re p,re l,re r)
	{
		if(l==r) return mn[p]=(l==1)?0:1e18,void();
		build(ls(p),l,mid);build(rs(p),mid+1,r);push_up(p);
	} 
	void update(re p,re l,re r,re x,ll y)
	{
		if(l==r) return mn[p]=min(mn[p],y),void();
		(x<=mid)?update(ls(p),l,mid,x,y):update(rs(p),mid+1,r,x,y);push_up(p);
	} 
	ll query(re p,re l,re r,re ql,re qr)
	{
		if(ql<=l&&r<=qr) return mn[p];
		if(ql>mid) return query(rs(p),mid+1,r,ql,qr);
		if(qr<=mid) return query(ls(p),l,mid,ql,qr);
		return min(query(ls(p),l,mid,ql,qr),query(rs(p),mid+1,r,ql,qr));
	}
}t;
int main()
{
	n=read()+1;k=read();gs(s+1);t.build(1,1,n);
	for(re i=2;i<=n;i++) 
	{
		t.update(1,1,n,i,t.query(1,1,n,i-1,i-1)+i-1);
		if(s[i-1]=='1') t.update(1,1,n,min(n,i+k),t.query(1,1,n,max(1ll,i-k-1),min(n,i+k))+i-1);
	}
	write(t.query(1,1,n,n,n),'\n');
	return ot(),0;
}
//Author: disangan233
//In my dream's scene,I can see the everything that in Cyaegha.