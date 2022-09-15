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

const int maxn = 200010;
int n, k, a;
int x[maxn];
set<int> st;

void solve() {
	scanf("%d%d%d", &n, &k, &a);
	st.insert(0); st.insert(n + 1);
	int m; scanf("%d", &m);
	int cnt = (n + 1) / (a + 1);
	FOR(i, 0, m) {
		scanf("%d", x + i);
		set<int>::iterator it = st.lower_bound(x[i]);
		int up = *it; it--;
		int down = *it;
		int u = (up - down) / (a + 1);
		int v = (up - x[i]) / (a + 1);
		int w = (x[i] - down) / (a + 1);
		cnt -= u - v - w;
		if (cnt < k) {printf("%d", i + 1); return;}
		st.insert(x[i]);
	}
	printf("-1");
}

int main() {
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}