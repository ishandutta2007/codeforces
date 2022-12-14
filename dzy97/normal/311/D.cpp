#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int mo=95542721,N=1e5+10;
int pow(int a,int b,int c){int ret=1;for(;b;b>>=1,a=1LL*a*a%c)if(b&1)ret=1LL*ret*a%c;return ret;}
struct node{
	int d[50], tag;
}t[N * 4];
int a[N], n, Q, tmp[N];
#define ls (x * 2)
#define rs (x * 2 + 1)
void upd(int x){
	for(int i = 0;i <= 48;i ++) t[x].d[i] = (t[ls].d[i] + t[rs].d[i]) % mo;
}
void down(int x){
	if(t[x].tag){
		int k = t[x].tag;
		t[ls].tag = (t[ls].tag + k) % 48;
		t[rs].tag = (t[rs].tag + k) % 48;
		for(int i = 0;i < 48;i ++) tmp[i] = t[ls].d[(i + k) % 48];
		for(int i = 0;i < 48;i ++) t[ls].d[i] = tmp[i];
		for(int i = 0;i < 48;i ++) tmp[i] = t[rs].d[(i + k) % 48];
		for(int i = 0;i < 48;i ++) t[rs].d[i] = tmp[i];
		t[x].tag = 0;
	}
}
void build(int l, int r, int x){
	if(l == r){
		t[x].d[0] = a[l];
		for(int i = 1;i <= 47;i ++) t[x].d[i] = 1LL * t[x].d[i - 1] * t[x].d[i - 1] % mo * t[x].d[i - 1] % mo;
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, ls);
	build(mid + 1, r, rs);
	upd(x);
}
void modify(int ql, int qr, int l, int r, int x){
	if(ql <= l && r <= qr){
		t[x].tag = (t[x].tag + 1) % 48;
		int k = t[x].d[0];
		for(int i = 0;i < 47;i ++) t[x].d[i] = t[x].d[i + 1];
		t[x].d[47] = k;
		return;
	}
	down(x);
	int mid = (l + r) >> 1;
	if(ql <= mid) modify(ql, qr, l, mid, ls);
	if(mid < qr)  modify(ql, qr, mid + 1, r, rs);
	upd(x);
}
int query(int ql, int qr, int l, int r, int x){
	if(ql <= l && r <= qr) return t[x].d[0];
	down(x);
	int ret = 0, mid = (l + r) >> 1;
	if(ql <= mid) ret = (ret + query(ql, qr, l, mid, ls)) % mo;
	if(mid < qr)  ret = (ret + query(ql, qr, mid + 1, r, rs)) % mo;
	return ret;
}
int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i ++) scanf("%d", &a[i]), a[i] %= mo;
	build(1, n, 1);
	scanf("%d", &Q);
	int op, x, y;
	while(Q --){
		scanf("%d%d%d", &op, &x, &y);
		if(op == 1) printf("%d\n", (query(x, y, 1, n, 1) + mo) % mo); else modify(x, y, 1, n, 1);	
	}
	return 0;
}