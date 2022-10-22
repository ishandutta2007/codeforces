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

const int N = 1e6 + 101;

int n;
ll k;

int p[N];
ll x[N];
ll ver[N];

int fq(int l, int r, int bit) {
	rep(i, l, r)
		if ((ver[i] >> bit) & 1)
			return i;
	return r + 1;
}
	
int main() {	
	scanf ("%d%lld", &n, &k);
	rep(i, 2, n) {
		scanf ("%d%lld", p + i, x + i);
		ver[i] = ver[p[i]] ^ x[i];
	}
	sort(ver + 1, ver + n + 1);
	ll answer = 0;
	vector <pair<pair<int, int>, pair<int, int>>> v = {{{1, n}, {1, n}}}, w;
	per(bit, 0, 61) {
		ll q = 0;
		for (auto it : v) {
			int l1 = it.fi.fi, r1 = it.fi.se, l2 = it.se.fi, r2 = it.se.se;
			int m1 = fq(l1, r1, bit), m2 = fq(l2, r2, bit);
			q += (1LL * (m1 - l1) * (m2 - l2) + 1LL * (r1 - m1 + 1) * (r2 - m2 + 1)) * ((l1 == l2 && r1 == r2) ? 1 : 2);
		}
		if (q < k) {
			k -= q;
			answer += 1LL << bit;
		}
		w.clear();
		for (auto it : v) {
			int l1 = it.fi.fi, r1 = it.fi.se, l2 = it.se.fi, r2 = it.se.se;
			int m1 = fq(l1, r1, bit), m2 = fq(l2, r2, bit);
			if ((answer & (1LL << bit))) {
				w.pb({{l1, m1 - 1}, {m2, r2}});
				if (!(l1 == l2 && r1 == r2))
				w.pb({{m1, r1}, {l2, m2 - 1}});
			}
			else {
				w.pb({{l1, m1 - 1}, {l2, m2 - 1}});
				w.pb({{m1, r1}, {m2, r2}});
			}
		}
		v.clear();
		for (auto it : w)
			if (it.fi.fi <= it.fi.se && it.se.fi <= it.se.se)	
				v.pb(it);
	}
	printf ("%lld\n", answer);
	
	return 0;
}