#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 200005, P = 998244353;
int n, k, a[N], b[N];
int main() {
	scanf("%d%d", &n, &k);
	for(int i=1; i<=n; ++i) scanf("%d", a+i), b[n-a[i]+1]=i;
	sort(b+1, b+k+1);
	int ans=1;
	for(int i=2; i<=k; ++i) ans=(ll)ans*(b[i]-b[i-1])%P;
	printf("%lld %d\n", (ll)(n+n-k+1)*k/2, ans);
	return 0;
}