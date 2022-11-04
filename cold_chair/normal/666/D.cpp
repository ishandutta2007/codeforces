#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, _b = y; i <= _b; i ++)
#define ff(i, x, y) for(int i = x, _b = y; i <  _b; i ++)
#define fd(i, x, y) for(int i = x, _b = y; i >= _b; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

struct P {
	int x[2];
};

int ans;
P s[5], ans2[5];

int T;
P a[5], b[5];
int p[5];
int cho[5];

int l[5], r[5];

int gg(int m, int i, int x, int y, int z) {
	l[i] = -1e9; r[i] = 1e9;
	if(cho[x] == z) {
		l[i] = r[i] = a[x].x[z];
		if(cho[y] == z) {
			if(a[x].x[z] != a[y].x[z]) return 0;
		}
	} else
	if(cho[y] == z) {
		l[i] = r[i] = a[y].x[z];
	}
	l[i] = max(l[i], max(a[x].x[z] - m, a[y].x[z] - m));
	r[i] = min(r[i], min(a[x].x[z] + m, a[y].x[z] + m));
	return l[i] <= r[i];
}

void gt(int x, int y, int z) {
	l[y] = max(l[y], l[x] + z);
	l[x] = max(l[x], l[y] - z);
	r[y] = min(r[y], r[x] + z);
	r[x] = min(r[x], r[y] - z);
}

int pd(int m) {
	if(!gg(m, 1, 1, 2, 0)) return 0;
	if(!gg(m, 2, 3, 4, 0)) return 0;
	if(!gg(m, 3, 2, 3, 1)) return 0;
	if(!gg(m, 4, 4, 1, 1)) return 0;
	int x = l[2] - r[1], y = r[2] - l[1];
	x = max(x, l[4] - r[3]); y = min(y, r[4] - l[3]);
	if(x <= y && !(x == y && x == 0)) {
		if(x == 0) x ++;
		fo(i, 1, 4) s[i] = a[i];
		gt(1, 2, x);
		gt(3, 4, x);
		int x1 = l[1], x2 = l[1] + x;
		int y1 = r[3], y2 = r[3] + x;
		s[1].x[0] = s[2].x[0] = x1;
		s[3].x[0] = s[4].x[0] = x2;
		s[2].x[1] = s[3].x[1] = y1;
		s[1].x[1] = s[4].x[1] = y2;
		fo(i, 1, 4) ans2[p[i]] = s[i];
	}
	return x <= y;
}

void dfs(int x) {
	if(x > 4) {
		for(int l = 0, r = ans - 1; l <= r; ) {
			int m = l + r >> 1;
			if(pd(m)) ans = min(ans, m), r = m - 1; else l = m + 1;
		}
		return;
	}
	cho[x] = 0; dfs(x + 1);
	cho[x] = 1; dfs(x + 1);
}

void dg(int x) {
	if(x > 4) {
		fo(i, 1, 4) b[i] = a[i];
		fo(i, 1, 4) a[i] = b[p[i]];
		dfs(1);
		fo(i, 1, 4) a[i] = b[i];
		return;
	}
	fo(i, 1, 4) if(!p[i]) {
		p[i] = x; dg(x + 1); p[i] = 0;
	}
}

int main() {
	scanf("%d", &T);
	fo(ii, 1, T) {
		fo(i, 1, 4) scanf("%d %d", &a[i].x[0], &a[i].x[1]);
		ans = 1e9;
		dg(1);
		if(ans == 1e9) pp("-1\n"); else {
			pp("%d\n", ans);
			fo(i, 1, 4) pp("%d %d\n", ans2[i].x[0], ans2[i].x[1]);
		}
	}
}