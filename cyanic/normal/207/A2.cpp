#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=int(b); i++)
#define mp make_pair
using namespace std;
typedef pair<pair<int,int>,int> P;

const int maxn = 200000;
int K, c, x, y, m, n, cnt, t, mx;
P a[maxn+5];

int main() {
	scanf("%d", &n);
	rep (i, 1, n) {
		scanf("%d%d%d%d%d", &K, &c, &x, &y, &m);
		t = 0;
		rep (j, 1, K) {
			if (cnt <= maxn) a[++cnt] = mp(mp(t, c), i);
			if (j < K && c > (1LL * c * x + y) % m) t++;
			c = (1LL * c * x + y) % m;
		}
		mx = max(mx, t);
	}
	sort(a+1, a+cnt+1); printf("%d\n", mx);
	if (cnt <= maxn) rep (i, 1, cnt)
		printf("%d %d\n", a[i].first.second, a[i].second);
	return 0;
}