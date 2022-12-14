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
};
using namespace fast_io;
#define pb push_back
#define mid ((l+r)>>1)
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
const int N=1e5+5;
int n,m,k,t,a[N],b[N<<2],c[N<<2],d[N],r[N],s[N],mx[N<<4],ans[N];
struct did
{
	int x,y,c,i;
	in bool operator<(did a) const {return c>a.c;}
}q[N];
in bool cmp(int i,int j) {return r[i]<r[j]||(r[i]==r[j]&&a[i]<a[j]);}
in void add(int x,int y) {for(;x<=m;x+=x&-x)c[x]+=y;}
in int ask(int x) {int y=0;for(;x;x-=x&-x)y+=c[x];return y;}
in int ha(int x) {return lower_bound(b+1,b+m+1,x)-b;}
void add(int p,int l,int r,int x,int y)
{
	if(l==r) return mx[p]=max(mx[p],y),void();
	x<=mid?add(ls(p),l,mid,x,y):add(rs(p),mid+1,r,x,y);mx[p]=max(mx[ls(p)],mx[rs(p)]); 
}
int ask(int p,int l,int r,int L,int R)
{
	if(R<l||r<L) return 0;if(L<=l&&r<=R) return mx[p];
	return max(ask(ls(p),l,mid,L,R),ask(rs(p),mid+1,r,L,R));
}
int main()
{
	n=read(),k=read();for(int i=1;i<=n;i++) r[i]=read();
	for(int i=1;i<=n;i++) a[d[i]=i]=read(),b[++m]=a[i],b[++m]=a[i]+k,b[++m]=a[i]-k,b[++m]=a[i]-k-1;
	sort(b+1,b+m+1),m=unique(b+1,b+m+1)-b-1;sort(d+1,d+n+1,cmp);
	for(int i=1;i<=n;i++) 
	{
		int j=i;while(r[d[j+1]]==r[d[i]]) j++;
		for(int k=i;k<=j;k++) add(ha(a[d[k]]),1);
		for(int l=i;l<=j;l++) s[d[l]]=ask(ha(a[d[l]]+k))-ask(ha(a[d[l]]-k-1));
		i=j;
	}t=read();
	for(int i=1,x,y;i<=t;i++) x=read(),y=read(),q[i]={x,y,max(r[x],r[y]),i};
	sort(q+1,q+t+1);int j=n;
	for(int i=1;i<=t;i++)
	{
		while(j&&r[d[j]]>=q[i].c) add(1,1,m,ha(a[d[j]]),s[d[j]]),j--;
		int x=q[i].x,y=q[i].y,res;if(a[x]>a[y]) swap(x,y);
		int l=max(ha(a[x]-k),ha(a[y]-k)),r=min(ha(a[x]+k),ha(a[y]+k));
		if(l>r) ans[q[i].i]=-1;
		else res=ask(1,1,m,l,r),ans[q[i].i]=res?res:-1;
	}
	for(int i=1;i<=t;i++) write(ans[i],'\n');
	return ot(),0;
}
//Author: disangan233