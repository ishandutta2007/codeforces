#include<bits/stdc++.h>
using namespace std;
#define in inline
#define ll long long
#define pb push_back
namespace fast_io
{
	char buf[1<<12],*p1=buf,*p2=buf,nc;
	in char gc() {return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<12,stdin),p1==p2)?EOF:*p1++;}
	in int read()
	{
		int x=0,y=1;while(nc=gc(),(nc<48||nc>57)&&~nc)if(nc==45)y=-1;if(nc<0)return nc;
		x=nc^48;while(nc=gc(),47<nc&&nc<58) x=x*10+(nc^48);return x*y; 
	}
	in int gs(char *s) {char *t=s;while(nc=gc(),nc<=32);*s++=nc;while(nc=gc(),nc>32)*s++=nc;return s-t;}
}
using namespace fast_io;
const int N=4e3+5,p=998244353;
int n,m,k,mx,ans,sa,sb,a[N],b[N],f[N][N],g[N][N],inv[N],fac[N];
in void M(int &x) {x-=p;x+=x>>31&p;}
in void pre(int n)
{
	fac[0]=inv[0]=inv[1]=1;for(int i=2;i<=n;i++) inv[i]=1ll*(p-p/i)*inv[p%i]%p;
	for(int i=1;i<=n;i++) fac[i]=1ll*fac[i-1]*i%p,inv[i]=1ll*inv[i]*inv[i-1]%p; 
}
in int c(int n,int m) {return n<m?0:1ll*fac[n]*inv[m]%p*inv[n-m]%p;}
int main()
{
	n=read(),m=read(),k=read();pre(mx=max(n,m));
	for(int i=1;i<=k;i++) a[read()]=1,b[read()]=1,a[read()]=1,b[read()]=1;
	for(int i=1;i<=n;i++) sa+=a[i]; for(int i=1;i<=m;i++) sb+=b[i];
	for(int i=0;i<=n;i++) f[i][0]=1;for(int i=0;i<=m;i++) g[i][0]=1;
	for(int i=2;i<=n;i++) for(int j=1;j<=mx;j++) f[i][j]=f[i-1][j],M(f[i][j]+=(!a[i]&&!a[i-1])*f[i-2][j-1]);
	for(int i=2;i<=m;i++) for(int j=1;j<=mx;j++) g[i][j]=g[i-1][j],M(g[i][j]+=(!b[i]&&!b[i-1])*g[i-2][j-1]);
	for(int i=0;i<=mx;i++) for(int j=0;j<=mx;j++) if(i*2+j<=n-sa&&i+j*2<=m-sb)
	M(ans+=1ll*f[n][i]*g[m][j]%p*c(n-sa-2*i,j)%p*c(m-sb-2*j,i)%p*fac[i]%p*fac[j]%p);
	printf("%d\n",ans);
	return 0;
}
//Author: disangan233
//NOIP2020 rp++