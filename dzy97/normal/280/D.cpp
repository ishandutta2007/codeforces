#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define N 100010

struct node{
        int l, r, sum;
	node operator + (const node &b){ return (node){l, b.r, sum + b.sum};}
	void operator *= (const int &b){ sum *= b;}
}bk[20];

node max(const node &a, const node &b){
	return (a.sum < b.sum) ? b : a;
}

node min(const node &a, const node &b){
	return (a.sum < b.sum) ? a : b;
}

struct segnode{
	node lmax, lmin, rmax, rmin, smax, smin, sum;
	int rev;
	void set(int a, int b){
		lmax = lmin = rmax = rmin = smax = smin = sum = (node){a, a, b};
	}
	void rever(){
		swap(lmax, lmin); swap(rmax, rmin); swap(smax, smin);
		lmax *= -1; lmin *= -1; rmax *= -1; rmin *= -1; smax *= -1; smin *= -1; sum *= -1;
		rev ^= 1;
	}
}t[N << 2];
#define ls (x << 1)
#define rs (x << 1 | 1)
int n, a[N];

void upd(int x){
	t[x].lmax = max(t[ls].lmax, t[ls].sum + t[rs].lmax);
	t[x].lmin = min(t[ls].lmin, t[ls].sum + t[rs].lmin);
	t[x].rmax = max(t[rs].rmax, t[ls].rmax + t[rs].sum);
	t[x].rmin = min(t[rs].rmin, t[ls].rmin + t[rs].sum);
	t[x].smax = max(max(t[ls].smax, t[rs].smax), t[ls].rmax + t[rs].lmax);
	t[x].smin = min(min(t[ls].smin, t[rs].smin), t[ls].rmin + t[rs].lmin);
	t[x].sum = t[ls].sum + t[rs].sum;
}

void build(int l, int r, int x){
	if(l == r){
		t[x].set(l, a[l]);
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, ls);
	build(mid + 1, r, rs);
	upd(x);
}

void down(int x){
	if(t[x].rev){
		t[ls].rever();
		t[rs].rever();
		t[x].rev = 0;
	}
}

void modify(int p, int v, int l, int r, int x){
	if(l == r){
		t[x].set(l, v);
		return;
	}
	int mid = (l + r) >> 1;
	down(x);
	if(p <= mid) modify(p, v, l, mid, ls);
	else modify(p, v, mid + 1, r, rs);
	upd(x);
}

void rever(int ql, int qr, int l, int r, int x){
	if(ql <= l && r <= qr){
		t[x].rever();
		return;
	}
	down(x);
	int mid = (l + r) >> 1;
	if(ql <= mid) rever(ql, qr, l, mid, ls);
	if(mid < qr)  rever(ql, qr, mid + 1, r, rs);
	upd(x);
}

segnode query(int ql, int qr, int l, int r, int x){
	if(ql <= l && r <= qr) return t[x];
	down(x);
	int mid = (l + r) >> 1;
	segnode ans, L, R;
	if(ql <= mid){
		L = query(ql, qr, l, mid, ls);
		if(mid >= qr) return L;
	}
	if(mid < qr){
		R = query(ql, qr, mid + 1, r, rs);
		if(ql > mid) return R;
	}
	ans.lmax = max(L.lmax, L.sum + R.lmax);
	ans.rmax = max(R.rmax, L.rmax + R.sum);
	ans.sum = L.sum + R.sum;
	ans.smax = max(max(L.smax, R.smax), L.rmax + R.lmax);
	return ans;
}

int main(){
        scanf("%d", &n);
        for(int i = 1;i <= n;i ++) scanf("%d", &a[i]);
        build(1, n, 1);
	int Q, op, x, y, K;
	node tmp;
	scanf("%d", &Q);
	while(Q --){
		scanf("%d", &op);
		if(op == 0){
			scanf("%d%d", &x, &y);
			modify(x, y, 1, n, 1);
		}else{
			scanf("%d%d%d", &x, &y, &K);
			int ret = 0, tot = 0;
			for(int i = 1;i <= K;i ++){
				tmp = query(x, y, 1, n, 1).smax;
				if(tmp.sum < 0) break;
				bk[++ tot] = tmp;
				ret += tmp.sum;
				rever(tmp.l, tmp.r, 1, n, 1);
			}
			for(int i = 1;i <= tot;i ++) rever(bk[i].l, bk[i].r, 1, n, 1);
			printf("%d\n", ret);
		}
	}
        return 0;
}