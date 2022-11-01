#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 100005, P = 1000000007;
int n, m, ans, fac[N], ifac[N];
int Pow(ll x, int y=P-2){
	int ans=1;
	for(; y; y>>=1, x=x*x%P) if(y&1) ans=ans*x%P;
	return ans;
}
int main() {
	fac[0]=1;
	for(int i=1; i<=100000; ++i) fac[i]=(ll)fac[i-1]*i%P;
	ifac[100000]=Pow(fac[100000]);
	for(int i=100000; i; --i) ifac[i-1]=(ll)ifac[i]*i%P;
	scanf("%d%d", &n, &m);
	for(int i=0; i*2<=n; ++i)
		ans=(ans+(ll)fac[n-i]*ifac[n-i-i]%P*ifac[i]%P)%P;
	for(int i=1; i*2<=m; ++i)
		ans=(ans+(ll)fac[m-i]*ifac[m-i-i]%P*ifac[i]%P)%P;
	printf("%d\n", ans*2%P);
	return 0;
}