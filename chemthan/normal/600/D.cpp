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
#define mp make_pair
#define fi first
#define se second
#define prec(n) fixed<<setprecision(n)
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
const ld PI = 2 * acos((ld) 0);

ll x[2], y[2], r[2];

void solve() {
	FOR(i, 0, 2) cin>>x[i]>>y[i]>>r[i];
	ll d = (x[0] - x[1]) * (x[0] - x[1]) + (y[0] - y[1]) * (y[0] - y[1]);
	if (d >= (r[0] + r[1]) * (r[0] + r[1])) {
		cout<<prec(9)<<0.0;
	}
	else if (d <= (r[0] - r[1]) * (r[0] - r[1])) {
		cout<<prec(9)<<PI * min(r[0], r[1]) * min(r[0], r[1]);
	}
	else {
		ld alpha = acos((ld) 1.0 * (r[1] * r[1] + d - r[0] * r[0]) / 2 / r[1] / sqrt((ld) d));
		ld beta = acos((ld) 1.0 * (r[0] * r[0] + d - r[1] * r[1]) / 2 / r[0] / sqrt((ld) d));
		ld ans = (ld) 1.0 * r[1] * r[1] * (alpha - sin(2 * alpha) / 2);
		ans += (ld) 1.0 * r[0] * r[0] * (beta - sin(2 * beta) / 2);
		cout<<prec(9)<<ans;
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