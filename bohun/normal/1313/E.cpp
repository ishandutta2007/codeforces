#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ss(x) (int) x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, l, r) for (int i = l; i <= r; ++i)
#define per(i, l, r) for (int i = r; l <= i; --i)
 
using ll = long long;
using namespace std;

const int N = 2e6 + 10;

struct ff {
	int F[N];
	void add(int x, int val) {
		for (; x < N; x += x & -x)
			F[x] += val;
	}
	int query(int x) {
		int res = 0;
		for (; 0 < x; x -= x & -x)
			res += F[x];
		return res;
	}
	int qq(int l, int r) {
		return query(r) - query(l - 1);
	}
} A, B;

int pref[N];

void pp(char *a, char *b) {
	char s[N];
	int n = strlen(a + 1), m = strlen(b + 1), l = 0, r = 0, q = 0;
	rep(i, 1, n) s[++q] = a[i];
	s[++q] = '#';
	rep(i, 1, m) s[++q] = b[i];
	pref[1] = 0;
	rep(i, 2, q) {
		pref[i] = 0;
		if (i <= r)
			pref[i] = min(pref[i - l + 1], r - i + 1);
		while (i + pref[i] <= q && s[i + pref[i]] == s[1 + pref[i]])
			pref[i]++;
		if (i + pref[i] - 1 >= r)
			l = i, r = i + pref[i] - 1;
	}
}

int n, m, x[N], y[N];
char a[N], b[N], c[N];

vector <int> p[N], q[N];
 
int main() {
	scanf ("%d%d%s%s%s", &n, &m, a + 1, b + 1, c + 1);
	pp(c, a);
	rep(i, 1, n) x[i] = pref[m + 1 + i];
	reverse(b + 1, b + n + 1);
	reverse(c + 1, c + m + 1);
	pp(c, b);
	rep(i, 1, n) y[i] = pref[m + 1 + i];
	reverse(y + 1, y + n + 1);
	rep(i, 1, n) q[y[i] + 1].pb(i), p[x[i]].pb(i), B.add(i, 1);
	ll cnt = 0, res = 0;
	per(i, 1, m) {
		for (int x : q[m - i]) {
			cnt -= A.qq(x - m + 2, x);
			B.add(x, -1);
		}
		for (auto x : p[i]) {
			cnt += B.qq(x, x + m - 2);
			A.add(x, 1);
		}
		if (i < m) res += cnt;
	}
	printf ("%lld\n", res);	
	return 0;
}