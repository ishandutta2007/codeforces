#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, B = y; i <= B; i ++)
#define ff(i, x, y) for(int i = x, B = y; i <  B; i ++)
#define fd(i, x, y) for(int i = x, B = y; i >= B; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

const int N = 3e5 + 5;

int T, n, a[N], l[N], r[N];

int main() {
//	freopen("a.in", "r", stdin);
	for(scanf("%d", &T); T; T --) {
		scanf("%d", &n);
		fo(i, 1, n) l[i] = n + 1, r[i] = 0;
		fo(i, 1, n) {
			scanf("%d", &a[i]);
			l[a[i]] = min(l[a[i]], i);
			r[a[i]] = max(r[a[i]], i);
		}
		int ans = 0, mx = 0, la = 0, len = 0;
		fo(i, 1, n) if(r[i]) {
			ans ++;
			if(l[i] > la) {
				len ++;
			} else {
				len = 1;
			}
			la = r[i];
			mx = max(mx, len);
		}
		pp("%d\n", ans - mx);
	}
}