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

const int N = 1e5 + 500;

int n, k, b[N];
ll res, a[N];
set <pair<ll, int>> S;

ll cost(int x, int l) {
	ll h = x / l;
	int a = x % l;
	int b = l - a;
	return h * h * b + (h + 1) * (h + 1) * a;
}

int main() {
	scanf ("%d%d", &n, &k);
	rep(i, 1, n) {
		scanf ("%lld", a + i);
		res += cost(a[i], 1);
		b[i] = 1;
		if (b[i] != a[i])
			S.insert({cost(a[i], 2) - cost(a[i], 1), i});
	}
	//~ for (auto it : S)
		//~ cat(it.fi);
	while (k > n) {
		k--;
		int id = S.begin()->se;
		S.erase(S.begin());
		res -= cost(a[id], b[id]);
		b[id]++;
		res += cost(a[id], b[id]);
		if (a[id] != b[id])
			S.insert({cost(a[id], b[id] + 1) - cost(a[id], b[id]), id});
	}
	printf ("%lld\n", res);
	return 0;
}