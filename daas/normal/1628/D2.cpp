#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
#define ll long long
using namespace std;
const int MAXN=1e6+10;
const int mod=1e9+7;
const int inv2=(mod+1)/2;
inline int MOD(int x) {return x+((x>>31)&mod);}
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int T,n,m,K,sum[MAXN],inv[MAXN];
int ksm(int x,int y)
{
	int z=1;
	while(y)
	{
		if(y&1) z=(ll)z*x%mod;
		x=(ll)x*x%mod;
		y>>=1;
	}
	return z;
}
inline int C(int n,int m) {return (n<0 || m<0 || n<m)?0:(ll)sum[n]*inv[m]%mod*inv[n-m]%mod;}
int main()
{
	sum[0]=inv[0]=1;
	for(int i=1;i<=1000000;++i) sum[i]=(ll)sum[i-1]*i%mod;
	inv[1000000]=ksm(sum[1000000],mod-2);
	for(int i=999999;i>=1;--i) inv[i]=(ll)inv[i+1]*(i+1)%mod;
	T=read();
	while(T--)
	{
		n=read(),m=n-read(),K=read();
		if(!m) {printf("%lld\n",(ll)n*K%mod);continue;}
		int ans=0;
		//cout<<n<<" "<<m<<endl;
		for(int i=1;i<=n;++i)
		{
			int val=(ll)(n-i)*K%mod;
			ans=MOD(ans+(ll)val*ksm(ksm(2,i),mod-2)%mod*C(i-1,m-1)%mod-mod);
		}
		printf("%d\n",ans);
	}
	return 0;
}
//ore no turn,draw!