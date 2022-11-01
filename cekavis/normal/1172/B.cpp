#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 200005, P = 998244353;
int n, ans, num, d[N], fac[N];
int main() {
	scanf("%d", &n);
	fac[0]=ans=1;
	for(int i=1; i<=n; ++i) fac[i]=(ll)fac[i-1]*i%P;
	for(int i=1, x, y; i<n; ++i) scanf("%d%d", &x, &y), ++d[x], ++d[y];
	for(int i=1; i<=n; ++i) ans=(ll)ans*fac[d[i]]%P;
	return printf("%lld", (ll)ans*n%P), 0;
}