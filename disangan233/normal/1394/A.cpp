#pragma GCC optimize(2,3,"Ofast")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define in inline
namespace fast_io
{
	char buf[1<<12],*p1=buf,*p2=buf,sr[1<<23],z[23],nc;int C=-1,Z=0,Bi=0,Ny;
	in char gc() {return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<12,stdin),p1==p2)?EOF:*p1++;}
	in ll read()
	{
		ll x=0;Ny=1;while(nc=gc(),(nc<48||nc>57)&&nc!=EOF)if(nc==45)Ny=-1;Bi=1;if(nc<0)return nc;
		x=nc-48;while(nc=gc(),47<nc&&nc<58&&nc!=EOF)x=(x<<3)+(x<<1)+(nc^48),Bi++;return x*Ny;
	}
	in db gf() {int a=read(),y=Ny,b=(nc!='.')?0:read();return (b?a+(db)b/pow(10,Bi)*y:a);}
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
#define lb lower_bound
#define ub upper_bound
#define pii pair<int,int>
#define fi first
#define se second
const int N=1e6+5;
int n,m,d,a[N],b[N],c[N];ll ans,sb[N],sc[N];
int main()
{
	n=read();d=read();m=read();
	for(int i=1;i<=n;i++) a[i]=read();sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) if(a[i]<=m) b[++b[0]]=a[i]; else c[++c[0]]=a[i];
	for(int i=b[0];i;i--) sb[i]=sb[i+1]+b[i]; for(int i=c[0];i;i--) sc[i]=sc[i+1]+c[i];
	for(int i=0;i<=c[0];i++)
	{
		ll res=max(0ll,1ll*(d+1)*(i-1)+1);if(res>n) break;
		int o=n-res;
		ans=max(ans,sb[max(1,b[0]-o+1)]+sc[c[0]-i+1]);
	}
	write(ans,'\n');
	return ot(),0;
}
//Author: disangan233