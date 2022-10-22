#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define per(i, a, b) for (int i = b; i >= a; --i)
#define all(x) x.begin(), x.end()
 
using ll = long long;
using namespace std;

const int N = 1 << 20;

int n, q, l[N], r[N];
char s[N], t[N];

void solve() {
	scanf("%d%d%s%s", &n, &q, s + 1, t + 1);
	rep(i, 1, q) scanf("%d%d", l + i, r + i);
	map<int, int> T;
	rep(i, 1, n) T[i] = t[i] - '0';
	bool ans = 1;
	per(i, 1, q) {
		for (auto x : {l[i], r[i] + 1}) 
			T[x] = prev(T.upper_bound(x))->se;
		int cnt[2] {};
		for (auto it = T.find(l[i]); it->fi <= r[i]; it = T.erase(it))
			cnt[it->se] += next(it)->fi - it->fi;
		ans &= cnt[0] != cnt[1];
		T[l[i]] = cnt[0] < cnt[1];
	}
	rep(i, 1, n)
		ans &= s[i] - '0' == prev(T.upper_bound(i))->se;
	printf(ans ? "YES\n" : "NO\n");
}	

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}