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
	int t;
	scanf ("%d", &t);
	while (t--) {
		int n;
		scanf ("%d", &n);
		for (int i = 2; i <= 60; ++i) {
			ll p = (1LL << i) - 1;
			if (n % p == 0) {
				printf ("%lld\n", n / p);
				break;
			}
		}
	}
	
	return 0;
}