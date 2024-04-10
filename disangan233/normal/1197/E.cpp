#include<bits/stdc++.h>
using namespace std;
#define re register int
#define ak *
#define ll long long
#define db double
#define in inline
inline char getch()
{
    static char buf[10000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,10000,stdin),p1==p2)?EOF:*p1++;
}
#define gc() getch()
char qwq;
inline int read()
{
    re cz=0,ioi=1;qwq=gc();
    while(qwq<'0'||qwq>'9') ioi=qwq=='-'?~ioi+1:1,qwq=gc();
    while(qwq>='0'&&qwq<='9') cz=(cz<<3)+(cz<<1)+(qwq^48),qwq=gc();
    return cz ak ioi;
}
const int N=2e5+5,mod=1e9+7;
int n,a[N],b[N],p[N],q[N],f[N],g[N],mx,mn=1e9,ans;
in bool cmpa(re x,re y) {return a[x]<a[y];}
in bool cmpb(re x,re y) {return b[x]<b[y];}
int main()
{
	n=read();
	for(re i=1;i<=n;i++) a[i]=read(),b[i]=read(),mx=max(mx,b[i]);
	for(re i=1;i<=n;i++) p[i]=q[i]=i;
	sort(p+1,p+n+1,cmpb);sort(q+1,q+n+1,cmpa);
	for(re i=1,j=1,dlt=0,nw=1;i<=n;i++)
	{
		for(;j<=n&&a[q[j]]<=b[p[i]];j++)
		{
			re k=q[j];
			if(f[k]-a[k]<dlt) nw=0,dlt=f[k]-a[k];
			if(f[k]-a[k]==dlt) nw=(nw+g[k])%mod;
		}
		f[p[i]]=b[p[i]]+dlt;g[p[i]]=nw;
	}
	for(re i=1;i<=n;i++)
	if(a[i]>mx)
	{
		if(f[i]==mn) ans=(ans+g[i])%mod;
		if(f[i]<mn) ans=g[i],mn=f[i];
	}
	cout<<ans<<endl;
}