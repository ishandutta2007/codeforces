#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<ctime>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<bitset>
#define sqr(x) ((x)*(x))
#define fz1(i,n) for ((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for ((i)=(n);(i)>=1;(i)--)
#define fz0g(i,n) for ((i)=0;(i)<=(n);(i)++)
#define fd0g(i,n) for ((i)=(n);(i)>=0;(i)--)
#define fz0k(i,n) for ((i)=0;(i)<(n);(i)++)
#define fd0k(i,n) for ((i)=(long long)((n)-1);(i)>=0;(i)--)
#define fz(i,x,y) for ((i)=(x);(i)<=(y);(i)++)
#define fd(i,y,x) for ((i)=(y);(i)>=(x);(i)--)
#define fzin fz1(i,n)
#define fzim fz1(i,m)
#define fzjn fz1(j,n)
#define fzjm fz1(j,m)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();++itr)
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
#define incm(x,y) {x=((x)+(y))%mod;}
#define spln(i,n) (i==n?'\n':' ')
#define fac_init(n){fac[0]=fac[1]=inv[1]=fi[0]=fi[1]=1;fz(i,2,n){fac[i]=1ll*fac[i-1]*i%mod;inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;fi[i]=1ll*fi[i-1]*inv[i]%mod;}}
#define fi first
#define se second
#define mk make_pair
using namespace std;
inline void read(int &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
const int mod=1e9+7;
int qp(int x,int y)
{
	int z=1;
	while(y){
		if(y&1)z=1ll*z*x%mod;
		x=1ll*x*x%mod;y>>=1;
	}
	return z;
}
int n,m,i,j,dp[1000005],pw[1000005],pwn[1000005],ipw[1000005],sum,ans;
int main()
{
	read(n);read(m);
	if(m==1){
		cout<<n+1<<endl;
		return 0;
	}
	pw[0]=1;pw[1]=m-1;ipw[0]=1;ipw[1]=qp(m-1,mod-2);pwn[0]=1;pwn[1]=m;
	fz(i,2,n+1) pwn[i]=1ll*pwn[i-1]*m%mod;
	fz(i,2,n+1) pw[i]=1ll*pw[i-1]*(m-1)%mod;
	fz(i,2,n+1) ipw[i]=1ll*ipw[i-1]*ipw[1]%mod;
	dp[0]=1;sum=ipw[1];ans=pwn[n];
	fz1(i,n){
		dp[i]=1ll*sum*pw[i]%mod*m%mod;
		sum=(sum+1ll*dp[i]*ipw[i+1])%mod;
		ans=(ans+1ll*dp[i]*pwn[n-i])%mod;
	}
	cout<<ans<<endl;
	return 0;
}