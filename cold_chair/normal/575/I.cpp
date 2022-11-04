#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, _b = y; i <= _b; i ++)
#define ff(i, x, y) for(int i = x, _b = y; i <  _b; i ++)
#define fd(i, x, y) for(int i = x, _b = y; i >= _b; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

const int N = 300005;

int num, n, q;

struct P {
	int op, ty, x, y, z;		
} a[N];

int ans[N];

int f[10005][5005];

#define low(x) ((x) & -(x))

struct Q {
	int x, y;
} d[N * 4]; int d0;

void add(int u, int v, int z) {
	u = max(1, u), v = max(1, v);
	d[++ d0] = (Q) {u, v};
	for(int x = u; x <= 2 * n; x += low(x))
		for(int y = v; y <= n; y += low(y))
			f[x][y] += z;
}
int sum(int u, int v) {
	if(u < 0 || v < 0) return 0;
	int s = 0;
	for(int x = u; x; x -= low(x))
		for(int y = v; y; y -= low(y))
			s += f[x][y];
	return s;
}
void cl() {
	while(d0) {
		for(int x = d[d0].x; x <= 2 * n; x += low(x))
			for(int y = d[d0].y; y <= n; y += low(y))
				f[x][y] = 0;
		d0 --;
	}
}

void add(int x, int y, int u, int v, int z) {
	if(x > y || u > v) return;
	add(x, u, z);
	add(x, v + 1, -z);
	add(y + 1, u, -z);
	add(y + 1, v + 1, z);
}

void work() {
	fo(i, 1, q)	{
		int x = a[i].x, y = a[i].y, z = a[i].z, s = x + y;
		if(a[i].op == 1) {
			if(a[i].ty == 1) {
				add(s, s + z, x, n, 1);
			}
			if(a[i].ty == 4) {
				add(s - z, s, 1, x, 1);
			}
		} else ans[i] += sum(s, x);
	}
	cl();
	fo(i, 1, q)	{
		int x = a[i].x, y = a[i].y, z = a[i].z, s = x + y;
		if(a[i].op == 1) {
			if(a[i].ty == 1) {
				add(s, s + z, 1, y - 1, -1);
			}
			if(a[i].ty == 4) {
				add(s - z, s, y + 1, n, -1);
			}
		} else ans[i] += sum(s, y);
	}
	cl();
	fo(i, 1, q)	{
		int x = a[i].x, y = a[i].y, z = a[i].z, s = x - y + n;
		if(a[i].op == 1) {
			if(a[i].ty == 2) {
				add(s, s + z, x, n, 1);
			}
			if(a[i].ty == 3) {
				add(s - z, s, 1, x, 1);
			}
		} else ans[i] += sum(s, x);
	}
	cl();
	fo(i, 1, q)	{
		int x = a[i].x, y = a[i].y, z = a[i].z, s = x - y + n;
		if(a[i].op == 1) {
			if(a[i].ty == 2) {
				add(s, s + z, y + 1, n, -1);
			}
			if(a[i].ty == 3) {
				add(s - z, s, 1, y - 1, -1);
			}
		} else ans[i] += sum(s, y);
	}
}

int main() {
	scanf("%d %d", &n, &q);
	fo(i, 1, q) {
		scanf("%d", &a[i].op);
		if(a[i].op == 1) {
			scanf("%d %d %d %d", &a[i].ty, &a[i].x, &a[i].y, &a[i].z);
		} else {
			scanf("%d %d", &a[i].x, &a[i].y);
		}
	}
	work();
	fo(i, 1, q) if(a[i].op != 1)
		pp("%d\n", ans[i]);
}