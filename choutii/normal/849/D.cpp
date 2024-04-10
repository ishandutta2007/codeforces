#include <bits/stdc++.h>

#define fir first
#define sec second
using namespace std;
typedef long long LL;
typedef unsigned long long u64;

template <typename T> inline bool cmin(T & a, const T & b) { return a > b ? a = b, 1 : 0;}
template <typename T> inline bool cmax(T & a, const T & b) { return a < b ? a = b, 1 : 0;}
int inp() {
	int x = 0, f = 1;char ch;
	for(ch = getchar(); !isdigit(ch); ch = getchar())
		if(ch == '-') f = -1;
	for(; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	return x * f;
}

const int MaxN = 101234;
int n, w, h;
struct info {
	int p, t, d, i;
	bool operator < (info b) const {
		return d < b.d;
	}
}a[MaxN], b[MaxN];

bool cmpp(info a, info b) {
	return a.p < b.p;
}

bool cmpd(info a, info b) {
	return a.d < b.d;
}

int x[MaxN], y[MaxN];
int n1, n2;

const int N = 101234;
queue<int> v[MaxN << 1], u[MaxN << 1];

int main() {
	int i;
	n = inp(); w = inp(); h = inp();
	for(i = 1; i <= n; i++) {
		int g = inp();
		if(g == 1) {
			a[++n1].p = inp();
			a[n1].t = inp();
			a[n1].i = i;
			a[n1].d = a[n1].p - a[n1].t;
		}else {
			b[++n2].p = inp();
			b[n2].t = inp();
			b[n2].i = i;
			b[n2].d = b[n2].p - b[n2].t;
		}
	}
	
	sort(a + 1, a + n1 + 1, cmpp);
	sort(b + 1, b + n2 + 1, cmpp);

	for(i = n2; i; i--) {
		int d = b[i].d + N;
		u[d].push(b[i].i);
		v[d].push(b[i].p);
	}
	
	for(i = 1; i <= n1; i++) {
		int d = a[i].d + N;
		u[d].push(a[i].i);
		x[u[d].front()] = a[i].p;
		y[u[d].front()] = h;
		u[d].pop();
	}
	
	for(i = 1; i < (MaxN << 1); i++) {
		while(!u[i].empty()) {
			x[u[i].front()] = w;
			y[u[i].front()] = v[i].front();
			u[i].pop();
			v[i].pop();
		}
	}
	for(i = 1; i <= n; i++) printf("%d %d\n", x[i], y[i]);
	return 0;
}