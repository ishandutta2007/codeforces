#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

inline ll read() {
	char c = getchar(); ll x = 0, f = 1;
	while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * f;
}

const int N = 100005;

ll n; char str[N]; int l; bool usd[N << 4];
int ch[N << 4][4], buc[4][4][15], tot;

struct matrix {
	ll a[4][4];
	void init(ll v) {
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++) a[i][j] = v;
	}
} bse;
matrix operator * (matrix a, matrix b) {
	matrix c; c.init(n + 1);
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			for (int k = 0; k < 4; k++) c.a[i][j] = min(c.a[i][j], a.a[i][k] + b.a[k][j]);
	return c; 
}

int fpow(int x, int y) {
	int ret = 1; if (y < 1) return 1;
	for (; y; y >>= 1, x = x * x) if (y & 1) ret = ret * x;
	return ret;
}
bool check(ll mid) {
	if (!mid) return false; mid--;
	matrix res = bse, cp = bse;
	for (; mid; mid >>= 1, cp = cp * cp) if (mid & 1) res = res * cp;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++) if (res.a[i][j] < n) return true;
	return false;
}

int main() {
	n = read(); scanf("%s", str + 1); l = strlen(str + 1); 
	int lim = min(l, 10) + 1;
	for (int i = 1; i <= l; i++) {
		int now = 0, fir = str[i] - 'A';
		for (int j = i; j <= min(i + lim - 1, l); j++) {
			int c = str[j] - 'A';
			if (!ch[now][c]) ch[now][c] = ++tot;
			now = ch[now][c];
			if (!usd[now]) usd[now] = true, buc[fir][c][j - i + 1]++; 
		}
	}
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			for (int k = lim; k >= 2; k--) if (buc[i][j][k] != fpow(4, k - 2)) bse.a[i][j] = k - 1;
	ll l = 0, r = n + 1;
	while (l + 1 < r) {
		ll mid = (l + r) >> 1;
		if (check(mid)) l = mid; else r = mid;
	}
	printf("%lld\n", r); 
	return 0;
}