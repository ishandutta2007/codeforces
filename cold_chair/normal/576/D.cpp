#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, B = y; i <= B; i ++)
#define ff(i, x, y) for(int i = x, B = y; i <  B; i ++)
#define fd(i, x, y) for(int i = x, B = y; i >= B; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

const int N = 155;

int n, m;

struct M {
	bitset<N> a[N];
};

M operator * (M a, M b) {
	M c;
	fo(i, 1, n) c.a[i].reset();
	fo(i, 1, n) fo(k, 1, n) if(a.a[i][k])
		c.a[i] |= b.a[k];
	return c;
}

M operator + (M a, M b) {
	fo(i, 1, n) a.a[i] |= b.a[i];
	return a;
}

struct P {
	int x, y, z;
} a[N];

int cmpa(P a, P b) {
	return a.z < b.z;
}

struct L {
	M a, b;
};

L operator * (L a, L b) {
	L c;
	c.a = a.a * b.a;
	c.b = a.b + a.a * b.b;
	return c;
}

M f;

L b, g[31];

int main() {
	//freopen("a.in", "r", stdin);
	scanf("%d %d", &n, &m);
	fo(i, 1, m) scanf("%d %d %d", &a[i].x, &a[i].y, &a[i].z);
	sort(a + 1, a + m + 1, cmpa);
	a[++ m].z = 1e9 + 1000; a[m].x = a[m].y = 1;
	if(m == 1 || a[1].z != 0) {
		pp("Impossible\n");
		return 0;
	}
	b.a.a[1][1] = b.b.a[1][1] = 1;
	int la = 1;
	fo(i, 2, m) if(a[i].z != a[i - 1].z) {
		fo(j, la, i - 1) f.a[a[j].x][a[j].y] = 1;
		la = i;
		g[0].a = g[0].b = f;
		fo(j, 1, 30) g[j] = g[j - 1] * g[j - 1];
		int dis = a[i].z - a[i - 1].z;
		fd(j, 30, 0) if((1 << j) <= dis) {
			L h = b * g[j];
			if(!h.b.a[1][n]) dis -= 1 << j, b = h;
		}
		if(dis != 0) {
			pp("%d\n", a[i].z - dis + 1);
			return 0;
		}
	}
	pp("Impossible\n");
}