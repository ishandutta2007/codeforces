#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep2(i, j, n) for (LL i = j; i <= n; ++i)
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define boost cin.tie(0);ios_base::sync_with_stdio(0);
#define vi vector <int>

using namespace std;

const int N = 1e5 + 10231;

int n, A, cf, cm;
LL m;
pair <int, int> t[N];
LL pref[N];

LL ok(int z, int w) {
	int x = upper_bound(t + 1, t + n + 1, make_pair(z, -1)) - t - 1;
	x = min(x, n - w);
	return (LL) z * x - pref[x];
}

int ans[N];

int main() {	
	scanf ("%d%d%d%d%lld", &n, &A, &cf, &cm, &m);
	rep(i, 1, n) {
		scanf ("%d", &t[i].fi);
		t[i].se = i;
	}
	sort(t + 1, t + n + 1);
	rep(i, 1, n) {
		pref[i] = pref[i - 1] + t[i].fi;
	}
	LL best = -1;
	pair <int, int> k = {0, 0};
	rep(i, 0, n) {
		LL cost = (LL) A * i - (pref[n] - pref[n - i]);
		cost = m - cost;
		if (cost < 0) continue;
		int Left = 0;
		int Right = A;
		while (Left < Right) {
			int Mid = (Left + Right + 1) / 2;
			if (ok(Mid, i) <= cost) Left = Mid;
			else Right = Mid - 1;
		}
		LL val = (LL) i * cf + (LL) Left * cm;
		if (val > best) {
			best = val;
			k = {i, Left};
		}
	}
	printf ("%lld\n", best);
	rep(i, 1, n) {
		ans[t[i].se] = max(k.se, t[i].fi);
		if (n - i + 1 <= k.fi) ans[t[i].se] = A;
	}
	rep(i, 1, n) printf ("%d ", ans[i]);
	
		
	return 0;
}