#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define per(i, a, b) for (int i = b; i >= a; --i)
#define all(x) x.begin(), x.end()
#define mp make_pair
 
using ll = long long;
using namespace std;	

const int N = 1e5 + 5;
const int B = 300;

int n, q, a[N], tg[N], jmp[N];

int fa(int i) {
	return max(0, a[i] - tg[i / B]);
}

void build(int k) {
	rep(i, k * B, min(n - 1, (k + 1) * B - 1))
		jmp[i] = i / B == fa(i) / B ? jmp[fa(i)] : i;
}

void chg(int l, int r) {
	int x;
	scanf("%d", &x);
	rep(i, l / B, r / B) {
		if (l <= i * B && (i + 1) * B - 1 <= r)
			tg[i] = min(tg[i] + x, n);
		else 
			rep(j, max(l, i * B), min(r, (i + 1) * B - 1))
				a[j] = max(0, a[j] - x);
		if (tg[i] < B) build(i);
	}
}

int qry(int x, int y) {
	while (x != y) {
		if (x < y) swap(x, y);
		int px = tg[x / B] < B ? jmp[x] : x;
		int py = tg[y / B] < B ? jmp[y] : y;
		if (px == py) x = fa(x);
		else x = fa(px);
	}
	return x;
}

int main() {
	scanf("%d%d", &n, &q);
	rep(i, 1, n - 1) scanf("%d", a + i), a[i]--;
	rep(i, 0, (n - 1) / B) build(i);
	while (q--) {
		int t, l, r;
		scanf("%d%d%d", &t, &l, &r);
		l--; r--;
		if (t == 1) chg(l, r);
		else printf("%d\n", qry(l, r) + 1);
	}
	return 0;
}