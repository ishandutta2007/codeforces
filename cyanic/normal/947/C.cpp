#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=(b); i++)
#define per(i,a,b) for (int i=(a); i>=(b); i--)
using namespace std;

const int maxn = 300005;
int t[maxn*35][2], size[maxn*35], a[maxn];
int n, b, tot = 1;

void insert(int x) {
	int o = 1;
	per (i, 29, 0) {
		if (!t[o][x>>i&1]) t[o][x>>i&1] = ++tot;
		o = t[o][x>>i&1]; size[o]++;
	}
}

int query(int x) {
	int o = 1, need, res = 0;
	per (i, 29, 0) {
		need = (x>>i&1);
		// printf("%d %d %d\n", i, need, t[o][need]);
		if (t[o][need] && size[t[o][need]]) o = t[o][need]; 
		else { o = t[o][need^1]; res |= 1 << i; }
		size[o]--;
	}
	return res;
}

int main() {
	scanf("%d", &n);
	rep (i, 1, n) scanf("%d", &a[i]);
	rep (i, 1, n) { scanf("%d", &b); insert(b); }
	rep (i, 1, n)
		printf("%d ", query(a[i]));
	return 0;
}