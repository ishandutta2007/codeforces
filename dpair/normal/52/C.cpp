#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n;
#define MAXN 200005
LL a[MAXN], t[MAXN << 2], lazy[MAXN << 2];
#define LSON rt << 1, l, mid
#define RSON rt << 1 | 1, mid + 1, r

inline LL mn(LL x, LL y){return x < y? x : y;}
inline void pushup(int rt){t[rt] = mn(t[rt << 1], t[rt << 1 | 1]);}
inline void update(int rt, LL val){
	t[rt] += val;
	lazy[rt] += val;
}
inline void pushdown(int rt){
	if(lazy[rt]){
		update(rt << 1, lazy[rt]);
		update(rt << 1 | 1, lazy[rt]);
		lazy[rt] = 0;
	}
}
void build(int rt, int l, int r){
	if(l == r) {
		t[rt] = a[l];
		return ;
	}
	int mid = (l + r) >> 1;
	build(LSON);build(RSON);
	pushup(rt);
}
void modify(int rt, int l, int r, int x, int y, LL z){
	if(x <= l && r <= y) return update(rt, z);
	pushdown(rt);
	int mid = (l + r) >> 1;
	if(x <= mid) modify(LSON, x, y, z);
	if(y > mid) modify(RSON, x, y, z);
	pushup(rt);
}
LL query(int rt, int l, int r, int x, int y){
	if(x <= l && r <= y) return t[rt];
	pushdown(rt);
	int mid = (l + r) >> 1;
	if(x <= mid && y > mid) return mn(query(LSON, x, y), query(RSON, x, y));
	if(x <= mid) return query(LSON, x, y);
	else return query(RSON, x, y);
}
template <typename T>
inline bool read(T &x){
	x = 0;int fu = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-') fu = -1;
		ch = getchar();
	}
	while(ch <= '9' && ch >= '0'){
		x = (x << 3) + (x << 1) + ch - 48;
		ch = getchar();
	}
	x = x * fu;
	return ch == 32;
}
int main(){
	scanf("%d", &n);
	for (register int i = 0;i < n;i ++) scanf("%lld", &a[i]);
	build(1, 0, n - 1);
	int q;
	scanf("%d", &q);
	while(q --){
		int l, r, x;
		read(l);int opt = read(r);
		if(opt) {
			read(x);
			if(l > r){
				modify(1, 0, n - 1, l, n - 1, x);
				modify(1, 0, n - 1, 0, r, x);
			}
			else modify(1, 0, n - 1, l, r, x);
		}
		else{
			if(l > r){
				printf("%lld\n", mn(query(1, 0, n - 1, l, n - 1), query(1, 0, n - 1, 0, r)));
			}
			else printf("%lld\n", query(1, 0, n - 1, l, r));
		}
	}
}