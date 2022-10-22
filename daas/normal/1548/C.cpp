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
const int MAXN=3e6+10;
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
int n,q,sum[MAXN],inv[MAXN],f[MAXN];
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
	n=read(),q=read();
	sum[0]=inv[0]=1;
	for(int i=1;i<=3*n+5;++i) sum[i]=(ll)sum[i-1]*i%mod;
	inv[3*n+5]=ksm(sum[3*n+5],mod-2);
	for(int i=3*n+5-1;i>=1;--i) inv[i]=(ll)inv[i+1]*(i+1)%mod;
	int inv3=ksm(3,mod-2);
	for(int i=0;i<=3*n;++i)
	{
		int sum=MOD(C(3*n+3,i+1)-C(0,i+1));
		if(i>=1) sum=MOD(sum-3ll*f[i-1]%mod);
		if(i>=2) sum=MOD(sum-f[i-2]);
		f[i]=(ll)sum*inv3%mod;
	}
	while(q--) printf("%d\n",f[read()]);
	return 0;
}
//ore no turn,draw!