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
const int N=1e5+5;
int n,m,t,a[N],c[N],mu[N],q[N];vector<int>d[N];ll ans;
int main()
{
	n=read();for(int i=1,x;i<=n;i++) a[x=read()]=1,m=max(m,x);
	mu[1]=1,ans=m;for(int i=1;i<=m;i++) for(int j=2*i;j<=m;j+=i) mu[j]-=mu[i];
	for(int i=1;i<=m;i++) for(int j=i;j<=m;j+=i) a[i]=a[i]|a[j],mu[i]?d[j].pb(i):void();
	for(int i=m;i;i--) if(a[i])
	{
		int s=0;for(int j:d[i]) s+=mu[j]*c[j];
		while(s)
		{
			int s1=s;
			for(int j:d[q[t]]) c[j]--,s-=mu[j]*(i%j==0);
			if(s^s1) ans=max(ans,1ll*i*q[t]);t--;
		}
		q[++t]=i;for(int j:d[i]) c[j]++;
	}write(ans,'\n');
	return ot(),0;
}
//Author: disangan233