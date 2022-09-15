#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define FORd(i, a, b) for(int i = a - 1; i >= b; i--)
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

const int maxn = 1010;
int n;
int w[maxn];
int h[maxn];

void solve() {
	scanf("%d", &n);
	int wsum = 0, low = 0;
	FOR(i, 0, n) {
		scanf("%d%d", w + i, h + i);
		wsum += w[i];
		low = max(low, min(w[i], h[i]));
	}
	int ans = INT_MAX;
	FOR(k, low, 1001) {
		vi v1, v2;
		int tmp = wsum;
		FOR(i, 0, n) if (h[i] > k) v1.push_back(w[i] - h[i]); else if (w[i] <= k && w[i] > h[i]) v2.push_back(w[i] - h[i]);
		sort(v2.rbegin(), v2.rend());
		if (sz(v1) > n / 2) continue;
		FOR(i, 0, sz(v1)) tmp -= v1[i];
		FOR(i, 0, min(sz(v2), n / 2 - sz(v1))) tmp -= v2[i];
		ans = min(ans, k * tmp);
	}
	printf("%d", ans);
}

int main() {
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}