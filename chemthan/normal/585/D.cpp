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
const int mod = 1000000007;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;

const int maxn = 100;
int n;
int l[maxn];
int m[maxn];
int w[maxn];
map<pi, int> mp;
map<pi, int> res1, res2;
int pw[maxn];

void solve() {
	pw[0] = 1; FOR(i, 1, maxn) pw[i] = pw[i - 1] * 3;
	scanf("%d", &n);
	FOR(i, 0, n) scanf("%d%d%d", l + i, m + i, w + i);
	if (n == 1) {
		if (l[0] == 0 && m[0] == 0) printf("LM");
		else if (m[0] == 0 && w[0] == 0) printf("MW");
		else if (w[0] == 0 && l[0] == 0) printf("LW");
		else printf("Impossible");
		return;
	}
	int k = n >> 1;
	FOR(i, 0, pw[k]) {
		int tmp = i;
		int a = 0, b = 0, c = 0;
		FOR(j, 0, k) {
			int r = tmp % 3;
			if (r == 0) {a += l[j]; b += m[j];}
			else if (r == 1) {b += m[j]; c += w[j];}
			else {c += w[j]; a += l[j];}
			tmp /= 3;
		}
		if (!mp.count(make_pair(b - a, c - a)) || mp[make_pair(b - a, c - a)] < a) {
			mp[make_pair(b - a, c - a)] = a;
			res1[make_pair(b - a, c - a)] = i;
		}
	}
	pi ans; int dmax = -INF;
	FOR(i, 0, pw[n - k]) {
		int tmp = i;
		int a = 0, b = 0, c = 0;
		FOR(j, 0, n - k) {
			int r = tmp % 3;
			if (r == 0) {a += l[j + k]; b += m[j + k];}
			else if (r == 1) {b += m[j + k]; c += w[j + k];}
			else {c += w[j + k]; a += l[j + k];}
			tmp /= 3;
		}
		if (mp.count(make_pair(a - b, a - c))) {
			tmp = mp[make_pair(a - b, a - c)];
			if (dmax <  tmp + a) {
				dmax = tmp + a;
				ans = make_pair(a - b, a - c);
				res2[make_pair(a - b, a - c)] = i;
			}
		}
	}
	if (dmax == -INF) {printf("Impossible"); return;}
	int tmp = res1[ans];
	int a = 0, b = 0, c = 0;
	FOR(i, 0, k) {
		int r = tmp % 3;
		if (r == 0) printf("LM\n");
		else if (r == 1) printf("MW\n");
		else printf("LW\n");
		tmp /= 3;
	}
	tmp = res2[ans];
	FOR(i, 0, n - k) {
		int r = tmp % 3;
		if (r == 0) printf("LM\n");
		else if (r == 1) printf("MW\n");
		else printf("LW\n");
		tmp /= 3;
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