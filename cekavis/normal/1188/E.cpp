#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 100005, M = 1000005, P = 998244353;
int n, sum, cnt[N], f[N], a[N], fac[M], ifac[M];
int Pow(ll x, int y=P-2){
	int ans=1;
	for(; y; y>>=1, x=x*x%P) if(y&1) ans=ans*x%P;
	return ans;
}
void work(int x){
	for(int i=1; i<=x; ++i) if(a[i]<x) ++f[a[i]+1];
	int now=0, ans=0;
	for(int i=0; i<x; ++i){
		now+=f[i];
		ans=(ans+(ll)fac[i-now+n-1]*ifac[n-1]%P*ifac[i-now])%P;
	}
	printf("%d\n", ans);
}
int main() {
	fac[0]=1;
	for(int i=1; i<=1000000; ++i) fac[i]=(ll)fac[i-1]*i%P;
	ifac[1000000]=Pow(fac[1000000]);
	for(int i=1000000; i; --i) ifac[i-1]=(ll)ifac[i]*i%P;
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) scanf("%d", a+i);
	sort(a+1, a+n+1);
	for(int i=1; i<=n; ++i) if(a[i]<i-1) return work(i-1), 0;
	for(int i=1; i<=n; ++i) ++cnt[a[i]%n], sum+=a[i]-a[i]%n;
	sum/=n;
	int ans=0;
	for(int i=0; i<n; ++i){
		ans=(ans+(ll)fac[sum+n-1]*ifac[n-1]%P*ifac[sum])%P;
		sum=sum-1+cnt[n-i-1];
	}
	printf("%d\n", ans);
	return 0;
}