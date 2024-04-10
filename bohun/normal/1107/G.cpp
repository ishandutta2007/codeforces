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
#define all(x) x.begin(), x.end()

using namespace std;

const int N = 3e5 + 111;
const int K = 18;

int n, a;
int d[N], c[N];
int lo[N];
LL ans = 0;
LL pref[N];

LL maxi[N][K + 1];
LL mini[N][K + 1];

LL Min(int l, int r) {
	int j = lo[r - l + 1];
	return min(mini[l][j], mini[r - (1 << j) + 1][j]);
}

LL Max(int l, int r) {
	int j = lo[r - l + 1];
	return max(maxi[l][j], maxi[r - (1 << j) + 1][j]);
}

int L[N], R[N];

int main() {
	rep(i, 2, N - 1) lo[i] = lo[i / 2] + 1;
	
	scanf ("%d%d", &n, &a);
	rep(i, 1, n) {
		scanf ("%d%d", d + i, c + i);
		ans = max(ans, (LL) a - c[i]);
		pref[i] = pref[i - 1] + a - c[i];
		maxi[i][0] = pref[i];
		mini[i][0] = pref[i];
	}	
	
	rep(j, 1, K)
		rep(i, 0, n - (1 << j) + 1) {
			maxi[i][j] = max(maxi[i][j - 1], maxi[i + (1 << (j - 1))][j - 1]);
			mini[i][j] = min(mini[i][j - 1], mini[i + (1 << (j - 1))][j - 1]);
		}
	
	vector <pair<LL, int>> val;
	rep(i, 1, n - 1) {
		LL x = (LL) (d[i + 1] - d[i]) * (d[i + 1] - d[i]);
		while (ss(val) && val.back().fi < x) {
			R[val.back().se] = i;
			val.pop_back();
		}
		val.pb({x, i});
	}
	while (ss(val)) {
		R[val.back().se] = n;
		val.pop_back();
	}
	per(i, 1, n - 1) {
		LL x = (LL) (d[i + 1] - d[i]) * (d[i + 1] - d[i]);
		while (ss(val) && val.back().fi <= x) {
			L[val.back().se] = i + 1;
			val.pop_back();
		}
		val.pb({x, i});
	}
	while (ss(val)) {
		L[val.back().se] = 1;
		val.pop_back();
	}
	rep(i, 1, n - 1) {
		ans = max(ans, Max(i + 1, R[i]) - Min(L[i] - 1, i - 1) - (LL) (d[i + 1] - d[i]) * (d[i + 1] - d[i]));
		// printf ("%d %d %d\n", i, L[i], R[i]);
	}
	printf ("%lld", ans);
	return 0;
}