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

const int maxn = 100010;
const int maxm = 10;
int n, m, k;
int a[maxn][maxm];
deque<pi> dq[maxm];

void solve() {
	scanf("%d%d%d", &n, &m, &k);
	FOR(i, 0, n) FOR(j, 0, m) scanf("%d", &a[i][j]);
	int ans[maxm], dmax = 0, cur = 0; ms(ans, 0);
	FOR(i, 0, n) {
		int cnt = 0;
		FOR(j, 0, m) {
			while (sz(dq[j]) && dq[j].back().first <= a[i][j]) dq[j].pop_back();
			dq[j].push_back(make_pair(a[i][j], i));
			while (sz(dq[j]) && dq[j].front().second < cur) dq[j].pop_front();
			cnt += dq[j].front().first;
		}
		if (cnt <= k) {
			if (dmax < i - cur + 1) {
				dmax = i - cur + 1;
				FOR(j, 0, m) ans[j] = dq[j].front().first;
			}
		}
		else {
			while (cnt > k && cur <= i) {
				cnt = 0;
				FOR(j, 0, m) {
					while (sz(dq[j]) && dq[j].front().second <= cur) dq[j].pop_front();
					if (sz(dq[j])) cnt += dq[j].front().first;
				}
				cur++;
			}
		}
	}
	FOR(i, 0, m) printf("%d ", ans[i]);
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