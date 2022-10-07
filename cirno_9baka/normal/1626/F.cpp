#include<bits/stdc++.h>
using namespace std;
const int N=10000005,M=998244353;
typedef unsigned long long ull;
typedef __uint128_t L;
struct FastMod {
	ull b, m;
	FastMod(ull b) : b(b), m(ull((L(1) << 64) / b)) {}
	ull reduce(ull a) {
		ull q = (ull)((L(m) * a) >> 64);
		ull r = a - q * b; // can be proven that 0 <= r < 2*b
		return r >= b ? r - b : r;
	}
};
int n,x,y,k,m,i,j,a[N],t,mn;
int s[1000005],dp[1000005];
long long ans,mi[25];
long long qpow(long long a,long long b){
	long long s=a,ans=1;
	while(b){
		if(b&1)
			ans=ans*s%M;
		b>>=1;
		s=s*s%M;
	}
	return ans;
}
int main(){
	cin>>n>>a[0]>>x>>y>>k>>m;
	FastMod F(m);
	t=1;
	for(int i=1;i<k;++i)
		t=t/__gcd(i,t)*i;
	for(int i=1;i<n;++i)
		a[i]=F.reduce(1ll*a[i-1]*x+y);
	long long ii=qpow(n,k-1);
	FastMod G(t);
	for(int i=0;i<n;++i){
		int md=(t==1?0:G.reduce(a[i]));
		ans=(ans+1ll*(a[i]-md)*k%M*ii)%M;
		++s[md];
	}
	for(int i=1;i<=k;++i){
		long long ss=0;
		for(int j=0;j<t;++j){
			long long tmp=s[j];
			ss=(ss+1ll*j*s[j])%M;
			s[j]=1ll*s[j]*(n-1)%M;
			s[j/i*i]=(s[j/i*i]+tmp)%M;
		}
		ans=(ans+ss*qpow(n,k-i))%M;
	}
	cout<<(ans%M+M)%M;
}