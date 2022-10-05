#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=(b); i++)
#define per(i,a,b) for (int i=(a); i>=(b); i--)
using namespace std;
typedef long long LL;

const int maxn = 1000005;
int p[maxn], c[maxn], f[1<<20], ALL, n, m, d, x, y, s, ans;

int main() {
	cin >> n >> m >> d;
	rep (i, 1, m) {
		cin >> x;
		rep (j, 1, x) 
			cin >> y, p[y] = i;
	}
	ALL = (1 << m) - 1;
	rep (i, 1, n) {
		c[p[i]]++; if (i > d) c[p[i-d]]--;
		if (i >= d) {
			s = 0;
			rep (j, 1, m) if (!c[j])
				s |= 1 << (j - 1);
			f[s] = 1;
		}
	}
	ans = n;
	per (i, ALL, 0)
		if (f[i]) {
			rep (j, 0, m - 1)
				if (i >> j & 1) f[i-(1<<j)] = 1;
		}
		else ans = min(ans, __builtin_popcount(i));
	cout << ans << endl;
	return 0;
}