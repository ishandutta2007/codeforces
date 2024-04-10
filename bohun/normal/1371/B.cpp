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
		ll a, b;
		scanf ("%lld%lld", &a, &b);
		ll res = 0;
		ll c = min(b, a - 1);
		res += c * (c + 1) / 2;
		printf ("%lld\n", res + (b >= a));
	}
	
	return 0;
}