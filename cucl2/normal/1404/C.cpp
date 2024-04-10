/* by Natsu Kinmoe */
#include <bits/stdc++.h>
using namespace std;
#define SZ(x)               ((int)(x).size())
#define all(x)              (x).begin(), (x).end()
#define loop(i, n)          for(int i = 0; i < (n); i++)
#define cont(i, n)          for(int i = 1; i <= (n); i++)
#define circ(i, a, b)       for(int i = (a); i <= (b); i++)
#define range(i, a, b, c)   for(int i = (a); ((c) > 0 ? i <= (b) : i >= (b)); i += (c))
#define foreach(it, v)      for(__typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
#define y0          y0O0OO00OO0OO0OO0OOO00OO0OO0O0O000OO0
#define y1          y1II11II11III11I1III11II111IIII1II1I1
#define pub         push_back
#define pob         pop_back
#define mak         make_pair
typedef long long   ll;
typedef long double lf;
const int   Inf = 0x3f3f3f3f;
const ll    INF = 0x3f3f3f3f3f3f3f3fll;
/* Source code starts here */

const int maxn = 1 << 19;

struct Segtree {
	int dt[maxn << 1];
	void inline add(int x) {
		x += maxn; dt[x]++;
		for(x >>= 1; x; x >>= 1) dt[x] = dt[x << 1] + dt[x << 1 | 1];
	}
	int inline find(int x, int now = 1, int nl = 0, int nr = maxn - 1) {
		if(dt[now] < x || x <= 0) return -1;
		if(nl == nr) return nl;
		int m = (nl + nr) >> 1;
		if(dt[now << 1] >= x) return find(x, now << 1, nl, m);
		else return find(x - dt[now << 1], now << 1 | 1, m + 1, nr);
	}
} seg;

struct Preseg {
	int dt[1 << 23], l[1 << 23], r[1 << 23], nds;
	void inline add(int to, int &now, int nl = 0, int nr = maxn - 1) {
		nds++; dt[nds] = dt[now]; l[nds] = l[now]; r[nds] = r[now]; now = nds;
		if(nl == nr) return void(dt[now]++);
		int m = (nl + nr) >> 1;
		if(m >= to) add(to, l[now], nl, m);
		else add(to, r[now], m + 1, nr);
		dt[now] = dt[l[now]] + dt[r[now]];
	}
	int inline sum(int L, int R, int now, int nl = 0, int nr = maxn - 1) {
		if(!now) return 0;
		if(nl >= L && nr <= R) return dt[now];
		if(nl > R || nr < L) return 0;
		int m = (nl + nr) >> 1;
		return sum(L, R, l[now], nl, m) + sum(L, R, r[now], m + 1, nr);
	}
} ps;

int n, q;
int a[1 << 19];
int id[1 << 19], rt[1 << 19];

int main() {
	scanf("%d%d", &n, &q);
	int cnt = 0;
	cont(i, n) {
		scanf("%d", a + i);
		int xj = i - a[i];
		id[i] = -1;
		if(xj < 0) continue;
		cnt++;
		if(xj == 0) {
			seg.add(id[i] = i - 1);
			continue;
		}
		id[i] = seg.find(cnt - xj);
		if(~id[i]) seg.add(id[i]);
		else cnt--;
	}
	cont(i, n) {
		// cerr<<i<<' '<<id[i]<<endl;
		rt[i] = rt[i - 1];
		if(~id[i]) ps.add(id[i], rt[i]);
	}
	while(q--) {
		int l, r; scanf("%d%d", &l, &r); r = n - r;
		printf("%d\n", ps.sum(l, r, rt[r]));
	}
	return 0;
}