#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORd(i, a, b) for(int i = (a) - 1; i >= (b); i--)
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

const int maxp = 100010;
const int maxs = 100;
int n, s;
int p[2][maxp];

void solve() {
	ms(p, 0);
	scanf("%d%d", &n, &s);
	FOR(i, 0, n) {
		char d[10]; int x, y; scanf("%s%d%d", d, &x, &y);
		if (d[0] == 'S') p[0][x] += y; else p[1][x] += y;
	}
	vii ans;
	int cnt = s; FOR(i, 0, maxp) if (cnt && p[0][i]) {ans.push_back(make_pair(i, p[0][i])); cnt--;}
	sort(ans.begin(), ans.end());
	FORd(i, sz(ans), 0) printf("S %d %d\n", ans[i].first, ans[i].second);
	cnt = s; FORd(i, maxp, 0) if (cnt && p[1][i]) {printf("B %d %d\n", i, p[1][i]); cnt--;}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}