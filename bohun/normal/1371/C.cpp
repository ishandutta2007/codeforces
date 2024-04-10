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

int main() {
	int T;
	scanf ("%d", &T);
	while (T--) {
		ll a, b, n, m;
		scanf ("%lld%lld%lld%lld", &a, &b, &n, &m);
		if (a + b < n + m || m > min(a, b))
			printf ("No\n");
		else
			printf ("Yes\n");
	}
	
	return 0;
}