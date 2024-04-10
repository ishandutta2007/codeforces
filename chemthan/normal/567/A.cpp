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

const int maxn = 100010;
int n;
int x[maxn];
vii v;
int ans[2][maxn];

void solve() {
	scanf("%d", &n);
	FOR(i, 0, n) {scanf("%d", x + i); v.push_back(make_pair(x[i], i));}
	sort(v.begin(), v.end());
	FOR(i, 0, n) {
		int k = v[i].second;
		if (!i) {
			ans[0][k] = v[i + 1].first - v[i].first;
			ans[1][k] = v[n - 1].first - v[i].first;
		}
		else if (i == n - 1) {
			ans[0][k] = v[i].first - v[i - 1].first;
			ans[1][k] = v[i].first - v[0].first;
		}
		else {
			ans[0][k] = min(v[i + 1].first - v[i].first, v[i].first - v[i - 1].first);
			ans[1][k] = max(v[n - 1].first - v[i].first, v[i].first - v[0].first);
		}
	}
	FOR(i, 0, n) {
		printf("%d %d\n", ans[0][i], ans[1][i]);
	}
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