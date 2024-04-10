#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define all(x) x.begin(), x.end()

using namespace std;

const int N = 1 << 18;
const int MOD = 998244353;

int n, q, type, l, r, x;
set <pair<int, int>> S[N];

int sum[N + N], a[N + N], b[N + N];

void push(int v, int len) {
	if (a[v] == 1 && b[v] == 0) return;
	len /= 2;
	for (auto g : {2 * v, 2 * v + 1}) {
		a[g] = 1LL * a[v] * a[g] % MOD;
		b[g] = (1LL * a[v] * b[g] + b[v]) % MOD;
		sum[g] = (1LL * sum[g] * a[v] + 1LL * len * b[v]) % MOD;
	}
	a[v] = 1;
	b[v] = 0;
}

void upd(int x, int y, int typ, int v = 1, int l = 0, int r = N - 1) {
	if (x <= l && r <= y) {
		//printf ("upd %d %d %d\n", l, r, typ);
		if (typ == 1) {
			b[v] = (b[v] + 1) % MOD;
			sum[v] = (sum[v] + (r - l + 1)) % MOD;
		}
		if (typ == 2) {
			a[v] = 2 * a[v] % MOD;
			b[v] = 2 * b[v] % MOD;
			sum[v] = 2 * sum[v] % MOD;
		}
		//printf ("%d\n", sum[v]);
		return;
	}
	push(v, r - l + 1);
	int m = (l + r) / 2;
	if (x <= m) upd(x, y, typ, 2 * v, l, m);
	if (m < y)  upd(x, y, typ, 2 * v + 1, m + 1, r);
	sum[v] = (sum[2 * v] + sum[2 * v + 1]) % MOD;
}
	
	
int query(int x, int y, int v = 1, int l = 0, int r = N - 1) {
	if (x <= l && r <= y) {
		//printf ("Q %d %d %d\n", l, r, sum[v]);
		return sum[v];
	}
	push(v, r - l + 1);
	int m = (l + r) / 2;
	int res = 0;
	if (x <= m) res = (res + query(x, y, 2 * v, l, m)) % MOD;
	if (m < y)  res = (res + query(x, y, 2 * v + 1, m + 1, r)) % MOD;
	return res;
}
					

int main() {
	rep(i, 1, 2 * N - 1)
		a[i] = 1;
	scanf ("%d%d", &n, &q);
	//n = 200000;
	//q = 200000;
	rep(i, 1, q) {
		scanf ("%d%d%d", &type, &l, &r);
		//type = 1, l = 1, r = n;
		if (type == 1) {
			scanf ("%d", &x);
			//x = 2;
			int Left = l, Right = r, prev = l - 1;
			auto it = S[x].lower_bound(mp(l, -1));
			if (it != S[x].begin())
				it--;
			while (it != S[x].end() && it->fi <= r) {
				if (it->se < l) {
					it++;
					continue;
				}
				int Lnow = max(l, it->fi), Rnow = min(r, it->se);
				upd(Lnow, Rnow, 2);
				if (prev + 1 <= Lnow - 1)
					upd(prev + 1, Lnow - 1, 1);
				Left = min(Left, it->fi);
				Right = max(Right, it->se);
				prev = it->se;
				auto nx = it;
				nx++;
				S[x].erase(it);
				it = nx;
			}
			if (prev < r)
				upd(prev + 1, r, 1);
			S[x].insert({Left, Right});
		}
		else {
			printf ("%d\n", query(l, r));
		}
	}			
	return 0;
}