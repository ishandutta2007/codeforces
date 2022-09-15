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

ld x[2], y[2];
ld v, t;
ld vx, vy, wx, wy;

ld calc(ld a, ld b, ld c) {
	ld delta = b * b - 4 * a * c;
	if (delta < 0) return INF;
	ld r1 = (-b + sqrt(delta)) / 2 / a;
	ld r2 = (-b - sqrt(delta)) / 2 / a;
	if (r2 >= 0) return r2;
	if (r1 >= 0) return r1;
	return INF;
}

void solve() {
	FOR(i, 0, 2) cin>>x[i]>>y[i];
	cin>>v>>t>>vx>>vy>>wx>>wy;
	ld a = x[1] - x[0], b = y[1] - y[0];
	ld ans = calc(vx * vx + vy * vy - v * v, -2 * (a * vx + b * vy), a * a + b * b);
	if (ans > t) ans = INF;
	a = x[1] - x[0] - t * vx;
	b = y[1] - y[0] - t * vy;
	ans = min(ans, t + calc(wx * wx + wy * wy - v * v, -2 * (a * wx + b * wy + v * v * t), a * a + b * b - v * v * t * t));
	cout<<fixed<<setprecision(6)<<ans;
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