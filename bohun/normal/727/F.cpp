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
#define ull unsigned long long

using namespace std;

const int N = 800;
const int M = 2e5 + 100;

int n, m;
LL b;
int a[N];
vector <pair<LL, int>> q;
int ans[M];

priority_queue <int> qq;

int qw(LL b) {
	while (ss(qq)) qq.pop();
	LL bil = 0;
	int res = 0;
	rep(i, 1, n) {
		if (a[i] < 0) qq.push(-a[i]);
		bil += a[i];
		if (bil < -b) {
			res++;
			bil += qq.top();
			qq.pop();
		}
		assert(-b <= bil);
	}
	return res;
}	
	

void solve(int l, int r, int optl, int optr) {
	if (l > r) return;
	if (optl == optr) {
		rep(i, l, r) ans[q[i].se] = optl;
		return;
	}
	int m = (l + r) / 2;
	ans[q[m].se] = qw(q[m].fi);
	solve(l, m - 1, ans[q[m].se], optr);
	solve(m + 1, r, optl, ans[q[m].se]);
}

int main() {
	scanf ("%d%d", &n, &m);
	rep(i, 1, n) {
		scanf ("%d", a + i);
	}
	rep(i, 1, m) {
		scanf ("%lld", &b);
		q.pb({b, i});
	}
	sort(q.begin(), q.end());
	solve(0, m - 1, 0, n);
	rep(i, 1, m) printf ("%d\n", ans[i]);
	
	return 0;
}