#include <bits/stdc++.h>

#define pb push_back
#define ld long double
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define ull unsigned long long

#define Rep(i,n) for(int i = 0; i < (n); ++i)
#define Repd(i,n) for(int i = (n)-1; i >= 0; --i)
#define For(i,a,b) for(int i = (a); i <= (b); ++i)
#define Ford(i,a,b) for(int i = (a); i >= (b); --i)
#define Fit(i,v) for(__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++i)
#define Fitd(i,v) for(__typeof((v).rbegin()) i = (v).rbegin(); i != (v).rend(); ++i)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(), (a).end()
#define ms(a,x) memset(a, x, sizeof(a))

using namespace std;

const int nm = 200010;

int n;
ll l[nm], t[nm], r;
vector<ll> tg;
bool toomany;

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d%I64d", &n, &r);
	for (int i = 1; i <= n; ++i)
		scanf("%I64d", &l[i]);
	for (int i = 1; i <= n; ++i)
		scanf("%I64d", &t[i]);
	for (int i = 1; i <= n; ++i)
		if (l[i] > t[i]) {
			cout << "-1\n";
			return 0;
		}
	ll res = 0, du = 0, cur = 0;
	for (int i = 1; i <= n; ++i) {
		if (du >= l[i]) {
			du -= l[i];
			cur = cur + l[i];
			continue;
		}
		if (du + 2ll * (l[i] - du) <= t[i]) {
			cur = cur + du + 2ll * (l[i] - du);
			du = 0;
			continue;
		}
		ll x = 2ll * l[i] - du - t[i];
		ll tmp = (x + r - 1) / r;
		ll y = l[i] - du - x;
		res += tmp;
		assert(du + y + (tmp - 1ll) * r <= l[i]);
		if (!toomany && (ll) tg.size() + tmp <= 100000ll) {
			for (ll z = cur + du + y * 2ll, j = 1; j <= tmp; z += r, j++)
				tg.pb(z);
		} else
			toomany = 1;
		cur = cur + t[i];
		du = (r - x % r) % r;
	}
	printf("%I64d\n", res);
	if (!toomany && tg.size() <= 100000) {
		for (int i = 0; i < tg.size(); ++i)
			printf("%I64d ", tg[i]);
	}
#ifdef LOCAL
	printf("\n%.3f s\n", (double) clock() / CLOCKS_PER_SEC);
#endif
}