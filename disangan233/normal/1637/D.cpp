#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define in inline
namespace fast_io
{
	char buf[1<<12],*p1=buf,*p2=buf,sr[1<<23],z[23],nc;int C=-1,Z=0;
	in char gc() {return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<12,stdin),p1==p2)?EOF:*p1++;}
	in ll read()
	{
		ll x=0,y=1;while(nc=gc(),(nc<48||nc>57)&&nc!=-1) if(nc==45) y=-1;
		x=nc-48;while(nc=gc(),47<nc&&nc<58) x=(x<<3)+(x<<1)+(nc^48);return x*y;
	}
	in db gf() {int a=read(),b=(nc!='.')?0:read(),c=ceil(log10(b));return (b?a+(db)b/pow(10,c):a);}
	in int gs(char *s) {char c,*t=s;while(c=gc(),c<32);*s++=c;while(c=gc(),c>32)*s++=c;return s-t;}
	template <typename T>
	in void write(T x,char t)
	{
		int y=0;if(x<0) y=1,x=-x;while(z[++Z]=x%10+48,x/=10);
		if(y) z[++Z]='-';while(sr[++C]=z[Z],--Z);sr[++C]=t;
	}
	in void write(char *s) {int l=strlen(s);for(int i=0;i<l;i++,*s++)sr[++C]=*s;sr[++C]='\n';}
	in void ot() {fwrite(sr,1,C+1,stdout);C=-1;}
};
using namespace fast_io;
const int N=1e2+5;
int T,n,mn[N],mx[N],a[N],b[N];ll s[N],f[N][N*N],ans,cur;
int main()
{
	T=read();
	while(T--)
	{
		n=read();memset(f,63,sizeof(f));f[0][0]=cur=0,ans=1e18;
		for(int i=1;i<=n;i++) a[i]=read(),cur+=a[i]*a[i];
		for(int i=1;i<=n;i++) b[i]=read(),cur+=b[i]*b[i];
		for(int i=1;i<=n;i++) if(a[i]>b[i]) swap(a[i],b[i]);
		for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i]+b[i],mx[i]=mx[i-1]+b[i],mn[i]=mn[i-1]+a[i];
		for(int i=1;i<=n;i++) for(int j=mn[i];j<=mx[i];j++)
		{
			f[i][j]=min(f[i][j],f[i-1][j-a[i]]+(j-a[i])*a[i]+(s[i-1]-j+a[i])*b[i]);
			if(j>=b[i]) f[i][j]=min(f[i][j],f[i-1][j-b[i]]+(j-b[i])*b[i]+(s[i-1]-j+b[i])*a[i]);
		}
		for(int i=mn[n];i<=mx[n];i++) ans=min(ans,f[n][i]);
		write(ans*2+cur*(n-1),'\n');
	}
	return ot(),0;
}