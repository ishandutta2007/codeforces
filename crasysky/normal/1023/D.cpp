#include <iostream>
#include <cstdio>
#define maxn 1000006
using namespace std;
struct node{ int l, r, x; }tree[maxn];
void build(int rt, int l, int r){
	tree[rt].l = l, tree[rt].r = r;
	if (l == r)
		return;
	build(rt << 1, l, l + r >> 1);
	build(rt << 1 | 1, (l + r >> 1) + 1, r);
}
void pushdown(int rt){
	if (tree[rt].x){
		tree[rt << 1].x = tree[rt << 1 | 1].x = tree[rt].x;
		tree[rt].x = 0;
	}
}
void st(int rt, int l, int r, int x){
	if (tree[rt].r < l || r < tree[rt].l)
		return;
	if (l <= tree[rt].l && tree[rt].r <= r){
		tree[rt].x = x;
		return;
	}
	pushdown(rt);
	st(rt << 1, l, r, x);
	st(rt << 1 | 1, l, r, x);
}
int b[maxn];
void get(int rt){
	if (tree[rt].l == tree[rt].r){
		b[tree[rt].l] = tree[rt].x;
		return;
	}
	pushdown(rt);
	get(rt << 1);
	get(rt << 1 | 1);
}
int a[maxn], l[maxn], r[maxn];
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
	int n = read(), m = read();
	bool flag = false;
	for (int i = 1; i <= n; ++ i){
		a[i] = read();
		if (l[a[i]] == 0)
			l[a[i]] = i;
		r[a[i]] = i;
		if (a[i] == m || a[i] == 0)
			flag = true;
	}
	if (! flag){
		cout << "NO" << endl;
		return 0;
	}
	build(1, 1, n);
	for (int i = 1; i <= m; ++ i)
		if (l[i])
			st(1, l[i], r[i], i);
	get(1);
	for (int i = 1; i <= n; ++ i)
		if (a[i] != b[i] && a[i]){
			cout << "NO" << endl;
			return 0;
		}
	cout << "YES" << endl;
	for (int i = 1; i <= n; ++ i)
		if (b[i] == 0)
			b[i] = b[i - 1];
	for (int i = n; i; -- i)
		if (b[i] == 0)
			b[i] = b[i + 1];
	for (int i = 1; i <= n; ++ i)
		if (b[i] == 0)
			b[i] = m;
	bool flag2 = false;
	for (int i = 1; i <= n; ++ i)
		if (b[i] == m){
			flag2 = true;
			break;
		}
	if (! flag2)
		for (int i = 1; i <= n; ++ i)
			if (a[i] == 0){
				b[i] = m;
				break;
			}
	for (int i = 1; i <= n; ++ i)
		printf("%d ", b[i]);
}
/*
#include <iostream>
using namespace std;
char s[1000006];
int k;
void divide(int l, int r){
	int cnt = 0, last = l - 1;
	for (int i = l; i <= r; ++ i)
		if (s[i] == '(')
			++ cnt;
		else if (-- cnt == 0){
			if (k >= i - last){
				for (int j = last + 1; j <= i; ++ j)
					cout << s[j];
				k -= i - last;
				if (k == 0)
					return;
			}
			else if (i - last > 2)
				divide(last + 2, i - 1);
			last = i;
		}
}
int main(){
	long long n;
	cin >> n >> k;
	scanf("%s", s);
	divide(0, n - 1);
}
*/