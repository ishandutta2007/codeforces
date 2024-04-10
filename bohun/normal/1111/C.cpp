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

int n;
int k;
vector <int> av;
int A, B;

LL solve(int l, int r, vector <int> v) {
	if (!ss(v)) return A;
	int m = (l + r) / 2;
	vector <int> L, R;
	for (auto it : v) {
		if (it <= m) L.pb(it);
		else R.pb(it);
	}
	LL res2 = (LL) B * ss(v) * (r - l + 1);
	if (l == r) return res2;
	LL res3 = solve(l, m, L) + solve(m + 1, r, R);
	return min(res2, res3);
}

int main() {	
	scanf ("%d%d%d%d", &n, &k, &A, &B);
	rep(i, 1, k) {
		int c;
		scanf ("%d", &c);
		av.pb(c);
	}
	
	printf ("%lld\n", solve(1, (1 << n), av));
	
	
	return 0;
}