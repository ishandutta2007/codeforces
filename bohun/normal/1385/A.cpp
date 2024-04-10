#include <bits/stdc++.h>
#define ll long long
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

int main() {
	int T;
	scanf ("%d", &T);
	while (T--) {
		int t[3];
		rep(i, 0, 2) scanf ("%d", t + i);
		sort(t, t + 3);
		if (t[1] == t[2]) {
			printf ("YES\n");
			printf ("%d %d %d\n", 1, t[0], t[1]);
		}
		else {
			printf ("NO\n");
		}
	}
	return 0;
}