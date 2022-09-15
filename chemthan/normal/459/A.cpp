#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
#define EPS 1e-9
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos(0);

void solve() {
	int x[2], y[2];
	FOR(i, 0, 2) scanf("%d%d", x + i, y + i);
	if (x[0] == x[1]) {
		printf("%d %d %d %d", x[0] + abs(y[0] - y[1]), y[0], x[1] + abs(y[0] - y[1]), y[1]);
	}
	else if (y[0] == y[1]) {
		printf("%d %d %d %d", x[0], y[0] + abs(x[0] - x[1]), x[1], y[1] + abs(x[0] - x[1]));
	}
	else {
		if (abs(x[0] - x[1]) != abs(y[0] - y[1])) printf("-1");
		else printf("%d %d %d %d", x[0], y[1], x[1], y[0]);
	}
}

int main() {
	//ios_base::sync_with_stdio(0); cin.tie(NULL);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	//printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}