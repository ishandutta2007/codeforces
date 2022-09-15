#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORd(i, a, b) for(int i = (a) - 1; i >= (b); i--)
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pi;
typedef vector<ll> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

const int maxn = 1000010;
int n;
vector<pair<pi, int> > v;

void solve() {
	scanf("%d", &n);
	FOR(i, 0, n) {
		int x, y;
		scanf("%d%d", &x, &y);
		v.push_back(make_pair(make_pair(x, y), i));
	}
	sort(v.begin(), v.end());
	FOR(i, 0, n) {
		int x = v[i].first.first;
		int y = v[i].first.second;
		int idx = v[i].second;
		v[i] = make_pair(make_pair(y, x), idx);
	}
	vi pos;
	int cur = v[0].first.second;
	pos.push_back(0);
	FOR(i, 1, n) if (v[i].first.second > cur + 3000) {cur = v[i].first.second; pos.push_back(i);}
	pos.push_back(n);
	FOR(i, 0, sz(pos) - 1) sort(v.begin() + pos[i], v.begin() + pos[i + 1]);
	FOR(i, 0, n) printf("%d ", v[i].second + 1);
}

int main() {
	//ios_base::sync_with_stdio(0); cin.tie(NULL);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}