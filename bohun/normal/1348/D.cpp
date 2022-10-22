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

int T;
int n;

vector <int> v;
	
int main() {		
	scanf ("%d", &T);
	while (T--) {
		scanf ("%d", &n);
		v.clear();
		int x = 1;
		while (x <= n) {
			v.pb(x);
			n -= x;
			x *= 2;
		}
		if (n > 0) v.pb(n);
		sort(all(v));
		printf ("%d\n", ss(v) - 1);
		rep(i, 1, ss(v) - 1)
			printf ("%d ", v[i] - v[i - 1]);
		printf ("\n");
	}
	return 0;
}