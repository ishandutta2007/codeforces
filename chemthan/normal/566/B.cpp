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

const int maxn = 30010;
int n;
vector<pair<pair<int, int>, pair<int, int> > > v, tmp;
int cnt[maxn];
vi ans;

void solve() {
	scanf("%d", &n);
	FOR(i, 0, 4 * n) {
		int a, b, c; scanf("%d%d%d", &a, &b, &c); a--; b--; c--;
		v.push_back(make_pair(make_pair(a, b), make_pair(c, i)));
	}
	FOR(i, 0, n) cnt[i] = 4;
	FOR(i, 0, 4 * n) {
		while (sz(v)) {
			int a = v.back().first.first;
			int b = v.back().first.second;
			int c = v.back().second.first;
			int k = v.back().second.second;
			cnt[a]--;
			cnt[b]++;
			cnt[c]++;
			if (cnt[b] > 9 || cnt[c] > 9) {cnt[a]++; cnt[b]--; cnt[c]--; tmp.push_back(v.back());} else ans.push_back(k + 1);
			v.pop_back();
		}
		while (sz(tmp)) {
			v.push_back(tmp.back());
			tmp.pop_back();
		}
	}
	if (sz(ans) != 4 * n) printf("NO");
	else {
		printf("YES\n");
		FOR(i, 0, sz(ans)) printf("%d ", ans[i]);
	}
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