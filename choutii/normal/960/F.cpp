#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define SZ(x) ((int) (x).size())
#define ALL(x) x.begin(), x.end()

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef unsigned long long u64;
typedef vector<int> VI;

template <typename T> inline bool cmin(T & a, const T & b) { return a > b ? a = b, 1 : 0;}
template <typename T> inline bool cmax(T & a, const T & b) { return a < b ? a = b, 1 : 0;}

int read() {
	int x = 0, f = 1;char ch;
	for (ch = getchar(); !isdigit(ch); ch = getchar())
		if (ch == '-') f = -1;
	for (; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	return x * f;
}

const int MaxN = 101234, MaxNode = 15000000;

int lc[MaxNode], rc[MaxNode], mx[MaxNode], rot[MaxN], segn;

int qmax(int p, int l, int r, int L, int R) {
	if(l > R || r < L || !p) return 0;
	if(L <= l && r <= R)
		return mx[p];
	return max(qmax(lc[p], l, l + r >> 1, L, R), qmax(rc[p], (l + r >> 1) + 1, r, L, R));
}

void add(int &p, int q, int l, int r, int x, int y) {
	p = ++segn; mx[p] = mx[q]; lc[p] = lc[q]; rc[p] = rc[q];
	cmax(mx[p], y);
	if(l == r) return;
	if(x <= (l + r >> 1))
		add(lc[p], lc[q], l, l + r >> 1, x, y);
	else
		add(rc[p], rc[q], (l + r >> 1) + 1, r, x, y);
}

int main() {
	int n = read(), m = read(), tn = 1e5, ans = 0;
	while(m--) {
		int u = read(), v = read(), w = read();
		int g = qmax(rot[u], 0, tn, 0, w - 1);
		add(rot[v], rot[v], 0, tn, w, g + 1);
		cmax(ans, g + 1);
	}
	cout << ans << endl;
	return 0;
}