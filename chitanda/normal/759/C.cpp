#include <bits/stdc++.h>
using namespace std;
#define ls (t << 1)
#define rs ((t << 1) | 1)

const int maxn = 100100;
struct info{
	int s, v;
	info() {}
	info(int s, int v) : s(s), v(v) {}
	info operator + (const info &a) {
		return info(s + a.s, max(v + a.s, a.v));
	}
}tr[maxn << 2];
int n, x[maxn];

void build(int t, int l, int r){
	tr[t] = info(0, 0);
	if (l == r) return;
	int mid = (l + r) >> 1;
	build(ls, l, mid);
	build(rs, mid + 1, r);
}

void modify(int t, int l, int r, int w, int v){
	if(l == r){
		tr[t] = info(v, v);
		return;
	}
	int mid = (l + r) >> 1;
	if(w <= mid) modify(ls, l, mid, w, v);
	else modify(rs, mid + 1, r, w, v);
	tr[t] = tr[ls] + tr[rs];
}

int query(int t, int l, int r, info tmp){
	if((tr[t] + tmp).v <= 0) return 0;
	if(l == r) return l;
	int mid = (l + r) >> 1;
	int k = query(rs, mid + 1, r, tmp);
	return k ? k : query(ls, l, mid, tr[rs] + tmp);
}

int main(){
	//freopen("x.in", "r", stdin);
	//freopen("x.out", "w", stdout);
	scanf("%d", &n);
	build(1, 1, n);
	int p, ty;
	x[0] = -1;
	for(int i = 1; i <= n; ++i){
		scanf("%d%d", &p, &ty);
		if(ty) scanf("%d", x + p);
		modify(1, 1, n, p, ty ? 1 : -1);
		printf("%d\n", x[query(1, 1, n, info(0, 0))]);
	}
	return 0;
}