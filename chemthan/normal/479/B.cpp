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

const int maxn = 110;
int n, k;
set<pi> st;
vii ans;

void solve() {
	scanf("%d%d", &n, &k);
	FOR(i, 0, n) {
		int a; scanf("%d", &a);
		st.insert(make_pair(a, i));
	}
	int dmin;
	FOR(i, 0, k) {
		int u = st.begin()->first;
		int v = st.rbegin()->first;
		int x = st.begin()->second;
		int y = st.rbegin()->second;
		dmin = v - u;
		if (u >= v - 1) break;
		st.erase(*st.begin());
		st.erase(*st.rbegin());
		ans.push_back(make_pair(y, x));
		st.insert(make_pair(u + 1, x));
		st.insert(make_pair(v - 1, y));
		dmin = st.rbegin()->first - st.begin()->first;
	}
	printf("%d %d\n", dmin, sz(ans));
	FOR(i, 0, sz(ans)) printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
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