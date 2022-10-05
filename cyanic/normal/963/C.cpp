#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=int(b); i++)
using namespace std;
typedef long long LL;

const int maxn = 200005;
LL x[maxn], y[maxn], c[maxn], xx[maxn], yy[maxn], GX, GY, t;
int X[maxn], Y[maxn], cur = 1, n, cntX, cntY, ans;

inline LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }
inline bool cmpX(int a, int b) { return x[a] < x[b]; }
inline bool cmpY(int a, int b) { return y[a] < y[b]; }
bool equal(LL a, LL b, LL c, LL d) {
	//printf("%I64d %I64d %I64d %I64d\n", a, b, c, d);
	LL g = gcd(a, c);	a /= g; c /= g;
	g = gcd(a, d);		a /= g; d /= g;
	if (a != 1) return 0;
	g = gcd(b, c);		b /= g; c /= g;
	g = gcd(b, d);		b /= g; d /= g;
	return b == 1 && c == 1 && d == 1;
}

int get(LL xx[maxn], int l, int r, LL x) {
	int mid;
	//printf("%I64d\n", xx[1]);
	while (l < r) {
		mid = (l + r + 1) >> 1;
		if (xx[mid] <= x) l = mid;
		else r = mid - 1;
	}
	//printf("%I64d\n", xx[l]);
	return l;
}

int main() {
	scanf("%d", &n);
	rep (i, 1, n) {
		scanf("%I64d%I64d%I64d", &x[i], &y[i], &c[i]);
		if (x[i] < x[cur] || x[i] == x[cur] && y[i] < y[cur]) cur = i;
	}
	rep (i, 1, n)
		if (x[i] < x[cur] || y[i] < y[cur]) return puts("0"), 0;
	rep (i, 1, n) {
		if (x[i] == x[cur]) Y[++cntY] = i, yy[cntY] = y[i];
		if (y[i] == y[cur]) X[++cntX] = i, xx[cntX] = x[i];
	}
	if (1LL * cntX * cntY != n) return puts("0"), 0;
	sort(X+1, X+cntX+1, cmpX); sort(xx+1, xx+cntX+1);
	sort(Y+1, Y+cntY+1, cmpY); sort(yy+1, yy+cntY+1);
//	rep (i, 1, cntX) printf("%I64d ", x[i]); puts("");
//	rep (i, 1, cntY) printf("%d ", yy[i]); puts("");
	rep (i, 1, n) {
		t = x[i]; //printf("%d\n", i);
		//printf("%I64d\n", x[i]);
		x[i] = get(xx, 1, cntX, x[i]);
		//printf("%I64d %I64d %I64d\n", x[i], t, xx[x[i]]);
		if (t != xx[x[i]]) return puts("0"), 0;
		t = y[i];
		y[i] = get(yy, 1, cntY, y[i]);
		if (t != yy[y[i]]) return puts("0"), 0;
		//puts("-1");
		//printf("%d\n", X[x[i]]);
		if (!equal(c[cur], c[i], c[X[x[i]]], c[Y[y[i]]]))
			return puts("0"), 0;
	}
	GX = c[X[1]]; GY = c[Y[1]];
	rep (i, 2, cntX) GX = gcd(GX, c[X[i]]);
	rep (i, 2, cntY) GY = gcd(GY, c[Y[i]]);
	for (LL i=1; i*i<=GX; i++) if (GX % i == 0) {
		if (GY % (c[cur] / i) == 0) ans++;
		if (i*i!=GX && GY % (c[cur] / (GX / i)) == 0) ans++;
	}
	printf("%d\n", ans);
	return 0;
}
/*
4
1 1 1
1 2 2
2 1 5
2 2 10
*/