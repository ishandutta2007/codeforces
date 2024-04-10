#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef complex<double> cd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

#define rep(i, n) for(int i = 0; i < n; ++i)
#define repe(i, a, b) for(int i = a; i <= b; ++i)
#define ri(a) scanf("%d", &a)
#define rii(a, b) scanf("%d%d", &a, &b)
#define riii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define rs(s) scanf("%s", s)
#define pi(n) printf("%d\n", n)
#define pia(a, n) rep(_, n) printf("%d%c", a[_], _ == n - 1 ? '\n' : ' ')
#define ria(a, n) rep(_, n) scanf("%d", &a[_])
#define Ttimes int T; ri(T); for(int ks = 1; ks <= T; ++ks)
#define IO(name) freopen(name".in", "r", stdin);freopen(name".out", "w", stdout)
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define F first
#define S second

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
const int maxn = 100010;
const double eps = 1e-8;
vector<int> a, b, c;
int main() {
	int n, m;
	char s[12]; int t;
	rii(n, m);
	rep(i, n) {
		rs(s); ri(t);
		if(s[0] == 'A') a.EB(t);
		else b.EB(t);
	}
	rep(i, m) {
		ri(t);
		c.EB(t);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	sort(c.begin(), c.end());

	int ans = 0;
	for(int i = 0; i < a.size(); ++i) {
		int tmp = 0;
		for(int j = 0; j < c.size() && i - j >= 0; ++j) {
			tmp += max(0, c[c.size() - j - 1] - a[i - j]);
		}
		ans = max(ans, tmp);
	}
	// pi(ans);

	bool fg = true, v[110] = {};
	for(int i = 0, j = 0; i < b.size(); ++i) {
		while(j < c.size() && c[j] <= b[i]) ++j;
		if(j == c.size()) {
			fg = false;
			break;
		}
		else {
			v[j++] = true;
		}
	}

	if(fg) {
		int ans2 = 0;
		vector<int> d;
		for(int i = 0; i < c.size(); ++i) if(!v[i]) d.EB(c[i]);
		//pia(a, a.size());
		// pia(d, d.size());
		fill(v, v + 110, false);
		for(int i = 0, j = 0; i < a.size(); ++i) {
			while(j < d.size() && d[j] < a[i]) ++j;
			if(j == d.size()) {
				fg = false;
				break;
			}
			else {
				ans2 += d[j] - a[i];
				v[j++] = true;
			}
		}
		if(fg) {
			for(int i = 0; i < d.size(); ++i) if(!v[i]) ans2 += d[i];
			ans = max(ans, ans2);
		}
	}
	pi(ans);

	return 0;
}