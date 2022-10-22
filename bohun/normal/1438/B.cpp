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
// c0 3f
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;



int main() {
	int T, n, a;
	scanf ("%d", &T);
	while (T--) {
		map<int, int> M;
		bool ok = 0;
		scanf ("%d", &n);
		while (n--) {
			scanf ("%d", &a);
			M[a]++;
			ok |= M[a] > 1;
		}
		printf (ok ? "YES\n" : "NO\n");
	}
		
	return 0;
}