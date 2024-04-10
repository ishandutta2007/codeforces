#include <bits/stdc++.h>
#define LL long long
#define LD long double
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

const int N = 1010;

int T;
int n;
int a[N];
bool sito[N];
vector <int> p;
int ans[N];

void solve() {
	scanf ("%d", &n);
	rep(i, 1, n) scanf ("%d", a + i);
	vector <int> s;
	rep(i, 1, n)
		rep(j, 0, ss(p) - 1) {
			if (a[i] % p[j] == 0) {
				s.pb(j);
				ans[i] = j;
				break;
			}
		}
	sort(all(s));
	s.erase(unique(all(s)), s.end());
	printf ("%d\n", ss(s));
	rep(i, 1, n) printf ("%d ", (int) ((lower_bound(all(s), ans[i])) - s.begin()) + 1);
	printf ("\n");
}

int main() {
	rep(i, 2, 35)
		if (!sito[i]) {
			p.pb(i);
			for (int j = i; j <= 35; j += i)
				sito[j] = 1;
		}
	scanf ("%d", &T);
	while (T--) {
		solve();
	}
	
    return 0;
}