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

int n;
char s[300005];

int main() {
	int t;
	scanf ("%d", &t);
	while (t--) {
		scanf ("%s", s + 1);
		n = strlen(s + 1);
		vector <int> q;
		rep(i, 1, n) {
			if (s[i] == 'A') q.pb(0);
			if (s[i] == 'B') {
				if (sz(q)) q.pop_back();
				else q.pb(1);
			}
		}
		printf ("%d\n", sz(q));
	}
	return 0;
}