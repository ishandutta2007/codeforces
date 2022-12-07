#include <bits/stdc++.h>

#define fir first
#define sec second
using namespace std;
typedef long long LL;
typedef unsigned long long u64;

template <typename T> inline bool cmin(T & a, const T & b) { return a > b ? a = b, 1 : 0;}
template <typename T> inline bool cmax(T & a, const T & b) { return a < b ? a = b, 1 : 0;}
int read() {
	int x = 0, f = 1;char ch;
	for(ch = getchar(); !isdigit(ch); ch = getchar())
		if(ch == '-') f = -1;
	for(; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	return x * f;
}

const int MaxN = 101234;

int n, q;
double seg[MaxN << 2], tag[MaxN << 2], add[MaxN << 2], mul[MaxN << 2];

void push_down(int p, int l, int r) {
	int mid = l + r >> 1;
	if(l == r) return;
	mul[p << 1] *= mul[p]; mul[p << 1 | 1] *= mul[p]; 
	add[p << 1] = add[p << 1] * mul[p] + add[p]; 
	add[p << 1 | 1] = add[p << 1 | 1] * mul[p] + add[p]; 
	seg[p << 1] = seg[p << 1] * mul[p] + add[p] * (mid - l + 1);
	seg[p << 1 | 1] = seg[p << 1 | 1] * mul[p] + add[p] * (r - mid);
	mul[p] = 1; add[p] = 0;
}

void modify(int p, int l, int r, int a, int b, double x, double y) {
	if(l > b || r < a) return;
	if(a <= l && r <= b) {
		mul[p] *= x; add[p] = add[p] * x + y;
		seg[p] = seg[p] * x + (r - l + 1) * y; 
		return;
	}
	push_down(p, l, r);
	modify(p << 1, l, l + r >> 1, a, b, x, y);
	modify(p << 1 | 1, (l + r >> 1) + 1, r, a, b, x, y);
	seg[p] = seg[p << 1] + seg[p << 1 | 1];
}


double query(int p, int l, int r, int a, int b) {
	if(l > b || r < a) return 0;
	if(a <= l && r <= b) return seg[p];
	push_down(p, l, r);
	return query(p << 1, l, l + r >> 1, a, b) + query(p << 1 | 1, (l + r >> 1) + 1, r, a, b);
}

void build(int p, int l, int r) {
	mul[p] = 1; 
	if(l == r) 
		seg[p] = read();
	else {
		build(p << 1, l, l + r >>1);
		build(p << 1 | 1, (l + r >> 1) + 1, r);
		seg[p] = seg[p << 1] + seg[p << 1 | 1];
	}
}
int main() {
	int i;
	n = read(); q = read();
	build(1, 1, n);
	while(q--) {
		int op = read();
		if(op == 1) {
			int l1 = read(), r1 = read(), l2 = read(), r2 = read();
			double x = query(1, 1, n, l1, r1) / (r1 - l1 + 1);
			double y = query(1, 1, n, l2, r2) / (r2 - l2 + 1);
            modify(1, 1, n, l1, r1, (double) (r1 - l1) / (r1 - l1 + 1), y / (r1 - l1 + 1));
            modify(1, 1, n, l2, r2, (double) (r2 - l2) / (r2 - l2 + 1), x / (r2 - l2 + 1));
		}else{
			int l = read(), r = read();
			printf("%.6lf\n", query(1, 1, n, l, r));
		}
	}
	return 0;
}