#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define per(i, a, b) for (int i = b; i >= a; --i)
#define all(x) x.begin(), x.end()
 
using ll = long long;
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		ll n, k;
		scanf("%lld%lld", &n, &k);
		printf("%lld\n", ((n + k - 1) / k * k + n - 1) / n);
	}
	return 0;
}