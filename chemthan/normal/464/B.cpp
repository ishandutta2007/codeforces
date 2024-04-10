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
#define EPS 1e-9
const int mod = 1000000007;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos(0);

struct vertex {
	int x[3];
} v[8];

ll dist(vertex a, vertex b) {
	ll res = 0;
	FOR(i, 0, 3) res += 1LL * (a.x[i] - b.x[i]) * (a.x[i] - b.x[i]);
	return res;
}

bool check(vertex v[]) {
	vector<ll> vd;
	FOR(i, 0, 8) FOR(j, i + 1, 8) vd.push_back(dist(v[i], v[j]));
	sort(vd.begin(), vd.end());
	if (vd[0] == 0) return 0;
	if (vd[0] != vd[11]) return 0;
	if (vd[12] != vd[23]) return 0;
	if (vd[24] != vd[26]) return 0;
	if (vd[0] * 2 != vd[12]) return 0;
	if (vd[0] * 3 != vd[24]) return 0;
	return 1;
}

void go(vector<vi> per, int pos) {
	if (pos == 0) {
		vertex cur[8];
		FOR(i, 0, 7) {
			FOR(j, 0, 3) cur[i].x[j] = v[i].x[per[i][j]];
		}
		cur[7] = v[7];
		if (check(cur)) {
			printf("YES\n");
			FOR(i, 0, 8) {
				FOR(j, 0, 3) printf("%d ", cur[i].x[j]);
				printf("\n");
			}
			exit(0);
		}
		return;
	}
	int a[] = {0, 1, 2};
	do {
		vi p; FOR(i, 0, 3) p.push_back(a[i]);
		per.push_back(p);
		go(per, pos - 1);
		per.pop_back();
	}
	while (next_permutation(a, a + 3));
}

void solve() {
	FOR(i, 0, 8) FOR(j, 0, 3) scanf("%d", &v[i].x[j]);
	vector<vi> per; go(per, 7);
	printf("NO");
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