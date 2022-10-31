#include <iostream>
#include <bitset>
#include <cstdio>
#define mp make_pair
#define fi first
#define se second
#define maxn 400005
#define mod 1000000007
using namespace std;
int fpw(int x, int y){
	int ans = 1;
	for (int i = 1; i <= y; i <<= 1, x = 1LL * x * x % mod)
		if (y & i)
			ans = 1LL * ans * x % mod;
	return ans;
}

bool flag[maxn];
int prime[maxn], id[maxn], a[maxn], prime_cnt;
struct node1{ int l, r, s, tag; }tree1[maxn * 4];
int pushup1(int rt){
	tree1[rt].s = 1LL * tree1[rt << 1].s * tree1[rt << 1 | 1].s % mod;
}
int pushdown1(int rt){
	if (tree1[rt].tag != 1 && tree1[rt].l != tree1[rt].r){
		int len1 = tree1[rt << 1].r - tree1[rt << 1].l + 1;
		tree1[rt << 1].s = 1LL * tree1[rt << 1].s * fpw(tree1[rt].tag, len1) % mod;
		tree1[rt << 1].tag = 1LL * tree1[rt << 1].tag * tree1[rt].tag % mod;
		int len2 = tree1[rt << 1 | 1].r - tree1[rt << 1 | 1].l + 1;
		tree1[rt << 1 | 1].s = 1LL * tree1[rt << 1 | 1].s * fpw(tree1[rt].tag, len2) % mod;
		tree1[rt << 1 | 1].tag = 1LL * tree1[rt << 1 | 1].tag * tree1[rt].tag % mod;
		tree1[rt].tag = 1;
	}
}
void build1(int rt, int l, int r){
	tree1[rt].l = l, tree1[rt].r = r;
	tree1[rt].tag = 1;
	if (l == r){
		tree1[rt].s = a[l];
		return;
	}
	build1(rt << 1, l, l + r >> 1);
	build1(rt << 1 | 1, (l + r >> 1) + 1, r);
	pushup1(rt);
}
void add1(int rt, int l, int r, int x){
	if (tree1[rt].r < l || r < tree1[rt].l)
		return;
	if (l <= tree1[rt].l && tree1[rt].r <= r){
		tree1[rt].s = 1LL * tree1[rt].s * fpw(x, tree1[rt].r - tree1[rt].l + 1) % mod;
		tree1[rt].tag = 1LL * tree1[rt].tag * x % mod;
		return;
	}
	pushdown1(rt);
	add1(rt << 1, l, r, x);
	add1(rt << 1 | 1, l, r, x);
	pushup1(rt);
}
int query1(int rt, int l, int r){
	if (tree1[rt].r < l || r < tree1[rt].l)
		return 1;
	if (l <= tree1[rt].l && tree1[rt].r <= r)
		return tree1[rt].s;
	pushdown1(rt);
	return 1LL * query1(rt << 1, l, r) * query1(rt << 1 | 1, l, r) % mod;
}
struct node2{
	int l, r;
	bitset <300> b;
	bitset <300> tag;
}tree2[maxn * 4];
bitset <300> update(int x){
	bitset <300> ans;
	ans.reset();
	for (int i = 1; i <= prime_cnt; ++ i)
		if (x % prime[i] == 0)
			ans[i] = 1;
	return ans;
}
void pushup2(int rt){
	tree2[rt].b = tree2[rt << 1].b | tree2[rt << 1 | 1].b;
}
void pushdown2(int rt){
	if (tree2[rt].tag.any() && tree2[rt].l != tree2[rt].r){
		tree2[rt << 1].b |= tree2[rt].tag;
		tree2[rt << 1].tag |= tree2[rt].tag;
		tree2[rt << 1 | 1].b |= tree2[rt].tag;
		tree2[rt << 1 | 1].tag |= tree2[rt].tag;
		tree2[rt].tag.reset();
	}
}
void build2(int rt, int l, int r){
	tree2[rt].l = l, tree2[rt].r = r;
	tree2[rt].tag = 1;
	if (l == r){
		tree2[rt].b = update(a[l]);
		return;
	}
	build2(rt << 1, l, l + r >> 1);
	build2(rt << 1 | 1, (l + r >> 1) + 1, r);
	pushup2(rt);
}
bitset <300> X;
void add2(int rt, int l, int r){
	if (tree2[rt].r < l || r < tree2[rt].l)
		return;
	if (l <= tree2[rt].l && tree2[rt].r <= r){
		tree2[rt].b |= X;
		tree2[rt].tag |= X;
		return;
	}
	pushdown2(rt);
	add2(rt << 1, l, r);
	add2(rt << 1 | 1, l, r);
	pushup2(rt);
}
bitset <300> query2(int rt, int l, int r){
	if (l <= tree2[rt].l && tree2[rt].r <= r)
		return tree2[rt].b;
	pushdown2(rt);
	int m = tree2[rt].l + tree2[rt].r >> 1;
	if (r <= m)
		return query2(rt << 1, l, r);
	if (l > m)
		return query2(rt << 1 | 1, l, r);
	return query2(rt << 1, l, r) | query2(rt << 1 | 1, l, r);
}

int init[maxn];
int read(){
	int cnt = 0;
	char ch = getchar();
	while (ch < '0' || '9' < ch)
		ch = getchar();
	while ('0' <= ch && ch <= '9'){
		cnt = cnt * 10 + ch - '0';
		ch = getchar();
	}
	return cnt;
}
int main(){
	flag[1] = true;
	for (int i = 2; i <= 300; ++ i)
		for (int j = 2; i * j <= 300; ++ j)
			flag[i * j] = true;
	for (int i = 1; i <= 300; ++ i)
		if (! flag[i]){
			prime[++ prime_cnt] = i;
			id[i] = prime_cnt;
		}
	for (int i = 1; i <= prime_cnt; ++ i)
		init[i] = (mod + 1 - fpw(prime[i], mod - 2)) % mod;
    int n = read(), q = read();
    for (int i = 1; i <= n; ++ i)
		a[i] = read();
	build1(1, 1, n);
	build2(1, 1, n);
	while (q --){
		char s[10];
		scanf("%s", s);
		if (s[0] == 'T'){
			int x = read(), y = read();
			int ans = query1(1, x, y);
			bitset <300> own = query2(1, x, y);
			for (int i = 1; i <= prime_cnt; ++ i)
				if (own[i])
					ans = 1LL * ans * init[i] % mod;
			printf("%d\n", ans);
		}
		else{
			int x = read(), y = read(), z = read();
			add1(1, x, y, z);
			X = update(z);
			add2(1, x, y);
		}
	}
}
/*
27 10
186 119 266 187 33 275 98 81 107 64 196 180 215 228 198 21 207 253 196 203 246 75 71 21 214 282 11
MULTIPLY 13 22 163
MULTIPLY 11 26 246
MULTIPLY 14 25 217
TOTIENT 18 19

27 10
186 119 266 187 33 275 98 81 107 64 196 180 215 228 198 21 207 253 196 203 246 75 71 21 214 282 11
MULTIPLY 18 19 163
MULTIPLY 18 19 246
MULTIPLY 18 19 217
TOTIENT 18 19
*/