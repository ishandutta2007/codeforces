#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef complex<double> cd;

#define rep(i, n) for(int i = 0; i < n; ++i)
#define repe(i, a, b) for(int i = a; i <= b; ++i)
#define ri(a) scanf("%d", &a)
#define rii(a, b) scanf("%d%d", &a, &b)
#define riii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define ria(a, n) rep(_, n) ri(a[_])
#define pia(a, n) rep(_, n) printf("%d ", a[_])
#define pi(x) printf("%d\n", x)
#define PB push_back
#define SZ size()
#define fst first
#define snd second
#define Ttimes int T; scanf("%d", &T); while(T--)
#define CASE  int T; scanf("%d", &T); for(int ks = 1; ks <= T; ++ks)

int main() {
	int m, t, r, x;
	vector<int> a;
	set<int> vis;
	riii(m, t, r);
	bool fg = false;
	rep(i, m) {
		ri(x);
		int tmp = 0;
		for(int i = 0; i < a.size(); ++i)
			if(a[i] + 1 <= x && a[i] + t >= x) tmp++;
		int need = r - tmp;
		int cur = x - 1;
		while(need > 0) {
			if(vis.count(cur)) {
				cur--;
				continue;
			}
			if(cur + t < x) break;
			need--;
			a.push_back(cur);
			vis.insert(cur);
			cur--;
		}
		if(need > 0) fg = true;
	}

	if(fg) puts("-1");
	else cout << vis.size() << endl;

	return 0;
}