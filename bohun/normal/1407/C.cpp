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

int n, ans[100005];

int ask(int p, int q) {
	printf ("? %d %d\n", p, q);
	fflush(stdout);
	int x;
	scanf ("%d", &x);
	return x;
}

int main() {
	scanf ("%d", &n);
	vector <int> a(n);
	iota(a.begin(), a.end(), 1);
	
	while (ss(a) > 1) {
		vector <int> b;
		if (ss(a) & 1) b.pb(a.back());
		for (int i = 0; i + 1 < ss(a); i += 2) {
			int x = ask(a[i], a[i + 1]);
			int y = ask(a[i + 1], a[i]);
			
			if (x > y) {
				ans[a[i]] = x;
				b.pb(a[i + 1]);
			}
			else {
				ans[a[i + 1]] = y;
				b.pb(a[i]);
			}
		}
		a = b;
	}
	ans[a[0]] = n;
	printf ("! ");
	rep(i, 1, n) printf ("%d ", ans[i]);
	
		
	return 0;
}