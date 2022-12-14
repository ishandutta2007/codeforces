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
const int N=1e7+5;
int n,m,p[N],v[N],a[N],f[N],g[N];ll s1,s2,s3,phi[N];
int main()
{
	n=read();
	for(int i=2;i<=n;i++) 
	{
		if(!v[i]) p[++m]=i,phi[i]=i-1,a[i]=i;
		for(int j=1;j<=m&&i*p[j]<=n;j++)
		{
			v[i*p[j]]=1,a[i*p[j]]=p[j],phi[i*p[j]]=phi[i]*(p[j]-1);
			if(i%p[j]==0) {phi[i*p[j]]+=phi[i];break;} 
		}f[a[i]]++;
	}
	for(int i=2;i<=n;i++) g[i]=g[i-1]+f[i],s1+=i-phi[i]-1,s2-=(1ll*a[i]*a[i]<=n),s3+=(a[i]*2<=n);
	for(int i=2;i<=n;i++) s2+=1ll*f[i]*g[n/i];
	s2=s2/2-s1,s3=s3*(s3-1)/2-s1-s2;write(s1+2*s2+3*s3,'\n');
	return ot(),0;
}
//Author: disangan233