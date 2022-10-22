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

const int nax = 1e5 + 100;

int n;
int a[nax], b[nax];

void solve() {
	scanf ("%d", &n);
	rep(i, 1, n) scanf ("%d", a + i);
	rep(i, 1, n) scanf ("%d", b + i);
	
	if (a[1] != b[1]) {
		printf ("NO\n");
		return;
	}
	int x = 0;
	int y = 0;
	if (a[1] == -1) x++;
	if (a[1] == 1) y++;
	rep(i, 1, n) {
		int dif = b[i] - a[i];
		if ((dif > 0 && y == 0) || (dif < 0 && x == 0)) {
			printf ("NO\n");
			return;
		}
		if (a[i] == -1) x++;
		if (a[i] == 1) y++;
	}
	printf ("YES\n"); 
	
}

int main() {
	int T;
	scanf ("%d", &T);
	while (T--) solve();
		
	
    return 0;
}