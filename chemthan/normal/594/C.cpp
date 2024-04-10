#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORd(i, a, b) for(int i = (a) - 1; i >= (b); i--)
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define mp make_pair
#define pb push_back
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
const int mod = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos(0);

const int maxn = 100010;
int n, k;
int x[maxn];
int y[maxn];
multiset<pi> hor, ver;
ll ans = 8 * LINF;

void erase(pi t) {
	hor.erase(hor.find(t));
	swap(t.fi, t.se);
	ver.erase(ver.find(t));
}
void insert(pi t) {
	hor.insert(t);
	swap(t.fi, t.se);
	ver.insert(t);
}

void go(int k) {
	if (!k) {
		ll w = max(2, hor.rbegin()->fi - hor.begin()->fi);
		ll h = max(2, ver.rbegin()->fi - ver.begin()->fi);
		ans = min(ans, w * h);
		return;
	}
	
	pi t = *hor.begin();
	erase(t);
	go(k - 1);
	insert(t);
	
	t = *hor.rbegin();
	erase(t);
	go(k - 1);
	insert(t);
	
	t = *ver.begin();
	swap(t.fi, t.se);
	erase(t);
	go(k - 1);
	insert(t);
	
	t = *ver.rbegin();
	swap(t.fi, t.se);
	erase(t);
	go(k - 1);
	insert(t);
}

void solve() {
	scanf("%d%d", &n, &k);
	FOR(i, 0, n) {
		int u[2], v[2];
		FOR(j, 0, 2) scanf("%d%d", u + j, v + j);
		x[i] = u[0] + u[1];
		y[i] = v[0] + v[1];
		hor.insert(mp(x[i], y[i]));
		ver.insert(mp(y[i], x[i]));
	}
	go(k);
	printf("%I64d", ans / 4);
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