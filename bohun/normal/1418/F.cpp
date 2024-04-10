#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) (int) x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define all(x) x.begin(), x.end()
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)

using ll = long long;
using ld = long double;
using namespace std;		

const int N = 2e5 + 5;

ll n, m, l, r;
int cnt[N];
vector <int> ans[N], d[N];
set <int> setik;

int main() {
	scanf ("%lld%lld%lld%lld", &n, &m, &l, &r);
	int e = max(n, m);
	rep(i, 1, e)
		rep(j, 1, e / i)
			d[i * j].pb(i);
	ll L = m + 1, R = m + 1;
	rep(i, 1, n) {
		ll lq = (l + i - 1) / i, rq = min(m, r / i);
		lq = min(lq, rq + 1);
		while (lq < L) {
			--L;
			for (auto x : d[L]) {
				if (!cnt[x]) setik.insert(x);
				cnt[x]++;
			}
		}
		while (rq + 1 < R) {
			--R;
			for (auto x : d[R]) {
				cnt[x]--;
				if (!cnt[x])
					setik.erase(x);
			}
		}
		for (auto g : d[i]) {
			auto it = setik.upper_bound(i / g);
			if (it == setik.end() || *it > n / g) continue;
			int q = (lq + *it - 1) / *it;
			ans[i] = {i, q * *it, g * *it, i / g * q};
			break;
		} 
	}
	rep(i, 1, n) {
		if (ans[i].empty()) printf ("-1\n");
		else printf ("%d %d %d %d\n", ans[i][0], ans[i][1], ans[i][2], ans[i][3]);
	}
	return 0;
}