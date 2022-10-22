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
ll l, r, m;

int main() {
	scanf ("%d", &T);
	while (T--) {
		scanf ("%lld%lld%lld", &l, &r, &m);
		ll d = (r - l);
		rep(a, l, r) {
			ll n = m / a;
			if (n && m - n * a <= d) {
				printf ("%d %lld %lld\n", a, l + (m - n * a), l);
				break;
			}
			n++;
			if (n && n * a - m <= d) {
				printf ("%d %lld %lld\n", a, l, l + (n * a - m));
				break;
			}
		}
	}
			
	return 0;
}