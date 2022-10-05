#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=int(b); i++)
#define per(i,a,b) for (int i=(a); i>=int(b); i--)
using namespace std;

const int maxn = 2005;
int l[maxn][maxn], r[maxn][maxn], n, m, Q, T, x, y, X, Y, flag, best, now;

int getpa(int pa[maxn], int x) {
	if (pa[x] == x) return x;
	return pa[x] = getpa(pa, pa[x]);
}

void update(int xx, int yy) {
	if (yy == 0 || yy == m + 1) return;
	if (!flag) {
		now = abs(xx-x)+abs(yy-y);
		if (!X && !Y || now < best || now == best && xx < X || now == best && xx == X && yy < Y)
			X = xx, Y = yy, best = now;
	}
	else {
		now = abs(xx-x)+abs(yy-y);
		if (!X && !Y || now < best || now == best && yy < Y	|| now == best && yy == Y && xx < X) 
			X = xx, Y = yy, best = now;
	}
}

int main() {
	scanf("%d%d%d", &n, &m, &Q); 
	if (n > m) flag = 1, swap(n, m);
	rep (i, 1, n) rep (j, 0, m+1) l[i][j] = r[i][j] = j;
	rep (K, 1, Q) {
		T = sqrt(K * 2) + 1;
		scanf("%d%d", &x, &y); X = Y = 0;
		if (flag) swap(x, y); best = 1e9;
		for (int i=0; i<=T&&i<=best&&(x-i>=1||x+i<=n); i++) {
			if (x-i>=1) update(x-i, getpa(l[x-i], y)), update(x-i, getpa(r[x-i], y));
			if (x+i<=n) update(x+i, getpa(l[x+i], y)), update(x+i, getpa(r[x+i], y));
		}
		l[X][Y] = getpa(l[X], Y-1);
		r[X][Y] = getpa(r[X], Y+1);
		if (flag) swap(X, Y);
		printf("%d %d\n", X, Y);
	}
	return 0;
}