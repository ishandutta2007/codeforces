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

const int nax = 5e5 + 100;

int T, n, p[nax], gdzie[nax];

void solve() {
	scanf ("%d", &n);
	rep(i, 1, n) {
		scanf ("%d", p + i);
		gdzie[p[i]] = i;
	}
	int last = n + 1;
	int mini = n + 1;
	rep(i, 1, n) {
		int x = gdzie[i];
		if (x < mini && x == n - i + 1) {
			mini = min(mini, x);
			last = x;
		}
		else if (x != last + 1 && last < x) {	
			printf ("No\n");
			return;
		}
		mini = min(mini, x);
		last = x;
	}
	printf ("Yes\n");
	
}

int main() {
	scanf ("%d", &T);
	while (T--) solve();
	
	return 0;
}