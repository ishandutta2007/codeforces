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

namespace io {
	const int SIZE = (1 << 25) + 1;
	char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c, qu[55]; int qr;
	#define gc() (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS++)) : *iS++)
	inline void flush() {
		fwrite(obuf, 1, oS - obuf, stdout);
		oS = obuf;
	}
	inline void putc(char x) {
		*oS++ = x;
		if(oS == oT) flush();
	}
	template <class T> inline void read(T & x) {
		for (c = gc(); c < '0' || c > '9'; c = gc());
		for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15);
	}
	template <class T> inline void print(T & x) {
		if(!x) putc('0');
		while(x) qu[++qr] = x % 10 + '0',  x /= 10;
		while(qr) putc(qu[qr--]);
	}
}
using io :: read;
using io :: putc;
using io :: print;


const int MaxN = 1001234;

int n, q, ans[MaxN], a[MaxN], l[MaxN], r[MaxN]; VI v[MaxN];
 
int cur, mn[MaxN << 2]; VI seg[MaxN << 2];

#define lc p << 1
#define rc p << 1 | 1
#define mid (l + r >> 1)
#define lson lc, l, mid
#define rson rc, mid + 1, r
 
void build(int p, int l, int r) {
	if(l == r) {
		seg[p].pb(a[r]); mn[p] = INT_MAX;
		return;
	}
	build(lson); build(rson);
	
	vector <int> :: iterator i = seg[lc].begin();
	vector <int> :: iterator j = seg[rc].begin();
	for (; i != seg[lc].end() || j != seg[rc].end(); ) {
		if(i == seg[lc].end() || j == seg[rc].end()) {
			if(i != seg[lc].end()) seg[p].pb(*i++);
			if(j != seg[rc].end()) seg[p].pb(*j++);
		} else {
			if((*i) < (*j))
				seg[p].pb(*i++);
			else
				seg[p].pb(*j++);
		}
	}
	
	mn[p] = INT_MAX; 
	for (int i = 1; i < SZ(seg[p]); i++)
		cmin(mn[p], seg[p][i] - seg[p][i - 1]);
}

int query(int p, int l, int r, int qL, int qR) {
	if(qL > r || qR < l) return INT_MAX;
	if(qL <= l && r <= qR)
		return mn[p];
	int pL = query(lson, qL, qR);
	int pR = query(rson, qL, qR);
	return min(pL, pR);
}

void modify(int p, int l, int r, int x, int v) {
	if(l == r) {
		cmin(mn[p], abs(v - seg[p][0]));
		cmin(cur, mn[p]);
		return;
	}
	vector<int>::iterator it = lower_bound(ALL(seg[p]), v);
	bool cR = it == seg[p].end() || *it - v >= cur;
	bool cL = it == seg[p].begin() || v - *--it >= cur;
	if(cL && cR) {
		cmin(cur, query(p, l, r, l, x));
		return;
	}
	if(x > mid) 
		modify(rson, x, v),
		modify(lson, mid, v);
	else
		modify(lson, x, v);
	cmin(mn[p], min(mn[lc], mn[rc]));
}

int main() {
	read(n);
	for (int i = 1; i <= n; i++)
		read(a[i]);
	read(q);
	for (int i = 1; i <= q; i++) {
		read(l[i]); read(r[i]);
		v[r[i]].pb(i);	
	}
	
	build(1, 1, n);
	for (int i = 1; i <= n; i++) {
		cur = INT_MAX;
		for (int j = 0; j < SZ(v[i]); j++) {
			int x = v[i][j];
			ans[x] = query(1, 1, n, l[x], r[x]);
		} 
		modify(1, 1, n, i, a[i + 1]);
	}
	
	for (int i = 1; i <= q; i++)
		print(ans[i]), putc('\n');
	io::flush();
	return 0;
}