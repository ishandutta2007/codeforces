#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define uni(a) (a).erase(unique(all(a)), (a).end())
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define prec(n) fixed<<setprecision(n)
#define bit(n, i) ((n) & (1LL << (i)))
#define bitcount(n) __builtin_popcount(n)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
ll fpow(ll n, ll k, int p = (int) 1e9 + 7) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
#define EPS 1e-9
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos((ld) 0);

const int maxn = 2010;
int n;

void solve() {
	scanf("%d", &n);
	vii v;
	FOR(i, 0, n) {
		int a; scanf("%d", &a);
		v.pb(mp(a, i));
	}
	sort(all(v));
	vi ans[3]; int cnt = 1;
	int cur = 0;
	while (cur < n) {
		if (cnt == 3) {
			FOR(i, 0, 3) ans[i].pb(v[cur].se + 1);
			cur++;
			continue;
		}
		int flag = 0;
		FORd(i, n, cur + 1) if (v[i].fi == v[cur].fi) {
			int d = min(3, i - cur + 1);
			if (d == 2) {
				if (cnt == 1) {
					ans[0].pb(v[cur].se + 1);
					ans[0].pb(v[cur + 1].se + 1);
					ans[1].pb(v[cur].se + 1);
					ans[1].pb(v[cur + 1].se + 1);
					ans[2].pb(v[cur + 1].se + 1);
					ans[2].pb(v[cur].se + 1);
					cnt++;
				}
				else if (cnt == 2) {
					ans[0].pb(v[cur].se + 1);
					ans[0].pb(v[cur + 1].se + 1);
					ans[1].pb(v[cur + 1].se + 1);
					ans[1].pb(v[cur].se + 1);
					ans[2].pb(v[cur].se + 1);
					ans[2].pb(v[cur + 1].se + 1);
					cnt++;
				}
				cur += 2;
				flag = 1;
			}
			else if (d >= 3) {
				int p[] = {0, 1, 2};
				int t = 0;
				do {
					ans[t].pb(v[cur + p[0]].se + 1);
					ans[t].pb(v[cur + p[1]].se + 1);
					ans[t].pb(v[cur + p[2]].se + 1);
					if (++t >= 3) break;
				}
				while (next_permutation(p, p + 3));
				cur += 3;
				cnt = 3;
				flag = 1;
			}
			break;
		}
		if (!flag) {
			FOR(i, 0, 3) ans[i].pb(v[cur].se + 1);
			cur++;
		}
	}
	if (cnt < 3) printf("NO");
	else {
		printf("YES\n");
		FOR(i, 0, 3) {
			FOR(j, 0, sz(ans[i])) printf("%d ", ans[i][j]);
			printf("\n");
		}
	}
}

int main() {
//	ios_base::sync_with_stdio(0); cin.tie(NULL);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	//printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}