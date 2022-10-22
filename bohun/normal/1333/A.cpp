#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define sz(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define all(x) x.begin(), x.end()

using namespace std;

void solve() {
	int n, m;
	scanf ("%d%d", &n, &m);
	rep(i, 1, n) {
		rep(j, 1, m) {
			if (i == 1 && j < m) printf ("W");
			else printf ("B");
		}
		printf ("\n");
	}
}

int main() {
	int T;
	scanf ("%d", &T);
	while (T--) solve();
		
	
    return 0;
}