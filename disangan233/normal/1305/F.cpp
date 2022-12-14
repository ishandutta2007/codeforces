#include<bits/stdc++.h>
using namespace std;
#define ll long long
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
#define pb push_back
const int N=1e6+5;
int n,mx,mn=1e12,vis[N];unordered_map<ll,int>vst;
ll a[N],ans=1e18;
ll gcd(ll a,ll b) {return !b?a:gcd(b,a%b);}
in void upd(ll x)
{
	ll res=0;if(x<=1||vst[x]) return;
	for(int i=1;i<=n;i++) res+=(a[i]<x?x-a[i]:min(a[i]%x,x-a[i]%x));
	ans=min(ans,res);vst[x]=1;
}
in void check(ll x)
{
    if(x<=1) return;
	for(ll i=2;i*i<=x;i++) if(x%i==0) {while(x%i==0)x/=i;upd(i);}
	if(x>1) upd(x);
}
int main()
{
	srand(time(0));
	n=read();for(int i=1;i<=n;i++) a[i]=read();
	for(int dlz=1,j=1;dlz<=min(n,40);dlz++)
	{
		int i=rand()*rand()%n+1;while(vis[i]) i=rand()*rand()%n+1;vis[i]=1;
		check(a[i]);check(a[i]-1);check(a[i]+1);
	}
	write(ans,'\n');
	return ot(),0;
}
//Author: disangan233
//In my dream's scene,I can see the everything that in Cyaegha.