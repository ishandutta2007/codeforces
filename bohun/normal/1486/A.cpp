#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define per(i, a, b) for (int i = b; i >= a; --i)
#define all(x) x.begin(), x.end()
 
using ll = long long;
using namespace std;
 
int n;
ll a[105]; 
 
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		rep(i, 1, n) scanf("%lld", a + i);
		a[0] = -1;
		bool ans = 1;
		rep(i, 1, n) {
			ll x = a[i] - a[i - 1] - 1;
			if (x < 0) ans = 0;
			if (x > 0) {
				a[i] -= x;
				a[i + 1] += x;
			}
		}
		printf(ans ? "YES\n" : "NO\n");	
	}
	return 0;
}