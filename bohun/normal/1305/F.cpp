#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep2(i, j, n) for (LL i = j; i <= n; ++i)
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define boost cin.tie(0);ios_base::sync_with_stdio(0);
#define vi vector <int>

using namespace std;

const int nax = 2e5 + 111;

int n;
LL a[nax];

int ans = 1e6;

unordered_map <LL, int> byl;

void proba(LL x) {
	if (byl.find(x) != byl.end()) return;
	byl[x] = 1;
	LL res = 0;
	rep(i, 1, n) {
		LL c = (a[i] / x) * x;
		LL d = (a[i] / x + 1) * x;
		if (c > 0)
			res += min(abs(c - a[i]), abs(d - a[i]));
		else
			res += abs(d - a[i]);
		if (res >= ans) return;
	}
	ans = min(ans, (int) res);
}

void fac(LL x) {
	if (x <= 1) return;
	vector <LL> p;
	for (int i = 2; (LL) i * i <= x; ++i) {
		if (x % i == 0) {
			p.pb(i);
			while (x % i == 0) x /= i;
		}
	}
	if (x > 1) p.pb(x);
	for (auto it : p)
		proba(it);
}

int main() {	
	srand(2137);	
	scanf ("%d", &n);
	rep(i, 1, n) scanf ("%lld", a + i);
	
	proba(2);
	
	while (true) {
		int r = rand() % n + 1;
		for (LL i = a[r] - 2; i <= a[r] + 2; ++i) {
			fac(i);
			if (1.0 * clock() / CLOCKS_PER_SEC > 2.1) {
				printf ("%d\n", ans);
				return 0;
			}
		}
	}
	printf ("%d\n", ans);	
	
	return 0;
}