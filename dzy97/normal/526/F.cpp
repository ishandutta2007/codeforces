#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 300010

int n, s[N * 4], t[N * 4], c[N * 4], a[N], p[N], q[N], cp, cq;
#define ls (x * 2)
#define rs (x * 2 + 1)

void upd(int x){
	t[x] = min(t[ls], t[rs]);
	c[x] = ((t[ls] == t[x]) ? c[ls] : 0) + ((t[rs] == t[x]) ? c[rs] : 0);
}

void down(int x){
	if(s[x]){
		s[ls] += s[x];
		s[rs] += s[x];
		t[ls] += s[x];
		t[rs] += s[x];
		s[x] = 0;
	}
}

void modify(int ql, int qr, int v, int l, int r, int x){
	if(ql <= l && r <= qr){
		s[x] += v;
		t[x] += v;
		return;
	}
	down(x);
	int mid = (l + r) >> 1;
	if(ql <= mid) modify(ql, qr, v, l, mid, ls);
	if(mid < qr)  modify(ql, qr, v, mid + 1, r, rs);
	upd(x);
}

void build(int l, int r, int x){
	if(l == r){
		t[x] = l;
		c[x] = 1;
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, ls);
	build(mid + 1, r, rs);
	upd(x);
}

int main(){
	scanf("%d", &n);
	int x, y;
	for(int i = 1;i <= n;i ++)
		scanf("%d%d", &x, &y), a[x] = y;
	build(1, n, 1);
	long long ans = 0;
	for(int i = 1;i <= n;i ++){
		while(cp >= 1 && a[i] < a[p[cp]]){
			modify(p[cp - 1] + 1, p[cp], a[p[cp]], 1, n, 1);
			cp --;
		}
		while(cq >= 1 && a[i] > a[q[cq]]){
			modify(q[cq - 1] + 1, q[cq], -a[q[cq]], 1, n, 1);
			cq --;
		}
		p[++ cp] = i;
		q[++ cq] = i;
		modify(p[cp - 1] + 1, p[cp], -a[p[cp]], 1, n, 1);
		modify(q[cq - 1] + 1, q[cq], a[q[cq]], 1, n, 1);
		ans += c[1];
	}
	printf("%I64d\n", ans);
	return 0;
}