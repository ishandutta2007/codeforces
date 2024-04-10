#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, B = y; i <= B; i ++)
#define ff(i, x, y) for(int i = x, B = y; i <  B; i ++)
#define fd(i, x, y) for(int i = x, B = y; i >= B; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

const int N = 2005;

int n, a[2005];

map<int, int> bz; int bz0;

int cnt[2005][2005];

ll s[N];

int pd(int x, int y) {
	fo(i, 1, bz0) {
		if(cnt[i][n] - (cnt[i][y] - cnt[i][x - 1]) > 1) return 0;
	}
	return 1;
}

int main() {
	//freopen("a.in", "r", stdin);
	scanf("%d", &n);
	fo(i, 1, n) {
		scanf("%d", &a[i]);
		s[i] = s[i - 1] + a[i];
		if(!bz[a[i]]) bz[a[i]] = ++ bz0;
		a[i] = bz[a[i]];
		cnt[a[i]][i] ++;
	}
	fo(i, 1, bz0) fo(j, 1, n) cnt[i][j] += cnt[i][j - 1];
	int ans = n - 1;
	fo(r, 1, n) {
		int as = -1;
		for(int L = 1, R = r + 1; L <= R; ) {
			int m = L + R >> 1;
			if(pd(m, r)) as = m, L = m + 1; else R = m - 1;
		}
		if(as != -1) {
			ans = min(ans, r - (as - 1));
		}
	}
	pp("%d\n", ans);
}