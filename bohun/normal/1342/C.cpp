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

int a, b, q, len;
ll l, r;

int cnt[200][200];

ll good(int A, int B) {
	return (A % b == B % a);
}

int elo;
int pref[400005];

ll qw(ll k) {
	ll res = 0;
	ll full = k / len;
	res += full * elo;
	res += pref[k % len];
	return res;
}		
	 

int main() {
	int T;
	scanf ("%d", &T);
	while (T--) {
		scanf ("%d%d%d", &a, &b, &q);
		rep(i, 0, a - 1)
			rep(j, 0, b - 1)
				cnt[i][j] = 0;
		len = -1;
		elo = 0;
		rep(i, 1, a * b) pref[i] = 0;
		rep(i, 1, 1000000000) {
			int x = i % a;
			int y = i % b;
			if (cnt[x][y] == 1) {
				len = i - 1;
				break;
			}
			cnt[x][y]++;
			if (good(x, y)) elo++;
			pref[i] = pref[i - 1] + good(x, y);
		}
		
		while (q--) {
			scanf ("%lld %lld", &l, &r);
			printf ("%lld ", (r - l + 1) - (qw(r) - qw(l - 1)));
		}	
		printf ("\n");
	}
	
	return 0;
}