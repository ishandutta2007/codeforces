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
const int mod=1e9+7;
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
int n,a[310],sum[310],inv[310],dp[310];
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
	for(int i=1;i<=300;++i) sum[i]=(ll)sum[i-1]*i%mod;
	inv[300]=ksm(sum[300],mod-2);
	for(int i=299;i>=1;--i) inv[i]=(ll)inv[i+1]*(i+1)%mod;
	n=read();
	for(int i=1;i<=n;++i)
	{
		a[i]=read();
		int tmp=a[i];
		for(int j=2;j<=sqrt(tmp);++j)
		{
			int tot=0;
			while(tmp%j==0) tmp/=j,++tot;
			for(int k=2;k<=tot;k+=2) a[i]/=j,a[i]/=j;
		}
	}
	sort(a+1,a+n+1);
	dp[0]=1;
	for(int l=1,r;l<=n;l=r+1)
	{
		r=l;
		while(r+1<=n && a[r+1]==a[l]) ++r;
		for(int i=n;i>=0;--i)
		{
			dp[i]=0;
			for(int j=1;j<=r-l+1 && j<=i;++j)
				dp[i]=MOD(dp[i]+(ll)dp[i-j]*sum[r-l+1]%mod*C(r-l,j-1)%mod*inv[j]%mod-mod);
		}
		/*cout<<"cao "<<r-l+1<<endl;
		for(int i=0;i<=n;++i) cout<<dp[i]<<" ";
		cout<<endl;*/
	}
	int ans=0;
	for(int i=1;i<=n;++i)
	{
		//cout<<dp[i]<<endl;
		if((n-i)&1) ans=MOD(ans-(ll)dp[i]*sum[i]%mod);
		else ans=MOD(ans+(ll)dp[i]*sum[i]%mod-mod);
	}
	printf("%d\n",ans);
	return 0;
}
//ore no turn,draw!