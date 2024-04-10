#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ss(x) (int) x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)

using ll = long long;
using namespace std;

int t[1000005];

int main() {
	int T, n;
	scanf ("%d", &T);
	while (T--) {
		scanf ("%d", &n);
		vector <int> v[2];
		rep(i, 1, n) {
			scanf ("%d", t + i);
			v[t[i]].pb(i);
		}
		if (ss(v[0]) < ss(v[1])) swap(v[0], v[1]);
		if (ss(v[0]) > n / 2 && ss(v[0]) & 1) v[0].pop_back();
		printf ("%d\n", ss(v[0]));
		for (auto x : v[0]) printf ("%d ", t[x]);
		printf ("\n");
	}
		
	return 0;
}