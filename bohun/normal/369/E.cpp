#include <bits/stdc++.h>
#define LL long long
#define LD double
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

const int N = 1e6 + 1000;

int n, m, l, r, q;
vector <int> v[N];
int ans[N];
vector <pair<int, int>> qw[N];

int f[N];
void add(int x, int c) {
	for (; x < N; x += (x & -x))
		f[x] += c;
}
int query(int x) {
	int res = 0;
	for (; x; x -= (x & -x))
		res += f[x];
	return res;
}
int qq(int l, int r) {
	if (l > r) return 0;
	return query(r) - query(l - 1);
}

int main() {	
	scanf ("%d%d", &n, &q);
	rep(i, 1, n) {
		scanf ("%d%d", &l, &r);
		v[r].pb(l);
	}
	rep(i, 1, q) {
		scanf ("%d", &l);
		int last = 0;
		while (l--) {
			scanf ("%d", &r);
			qw[r - 1].pb({last + 1, i});
			last = r;
		}
		qw[N - 1].pb({last + 1, i});
	}
	rep(i, 1, N - 1) {
		for (auto it : v[i])
			add(it, 1);
		for (auto it : qw[i])
			ans[it.se] += qq(it.fi, i);
	}
	rep(i, 1, q) printf ("%d\n", n - ans[i]);
	
		
	return 0;
}