#include<cstdio>
#include<cstring>
#include<algorithm>
#define lc (o << 1)
#define rc (o << 1 | 1)
#define Mid ((l+r) >> 1)
using namespace std;

const int maxn = 200009;
struct segment{
	int l, r, pos;
	bool operator < (const segment &a) const{
		return l < a.l || l == a.l && r > a.r;
	}
} s[maxn];
int T[maxn<<2], P[maxn<<2];
int N, n = 0, m, a, b, c, p, q, u, v;
long long ans = 0;

inline int read(){
	char ch = getchar(); int x = 0;
	while (ch < '0' || '9' < ch) ch = getchar();
	while ('0' <= ch && ch <= '9') { x = x*10 + ch-'0'; ch = getchar(); }
	return x;
}

void build(int o, int l, int r){
	if (l == r) { T[o] = s[l].r - s[l].l; P[o] = l; return; }
	build(lc, l, Mid); build(rc, Mid+1, r);
	if (T[lc] > T[rc]) P[o] = P[lc]; else P[o] = P[rc];
	T[o] = max(T[lc], T[rc]);
}

int query(int o, int l, int r, int x, int y, int &p){
	if (x > y) { p = -1; return 0; }
	if (l == x && y == r) { p = P[o]; return T[o]; }
	int a = 0, b = 0, p1 = 0, p2 = 0;
	if (x <= Mid) a = query(lc, l, Mid, x, min(y, Mid), p1);
	if (Mid+1 <= y) b = query(rc, Mid+1, r, max(x, Mid+1), y, p2);
	if (Mid+1 > y || x <= Mid && a > b) p = p1; else p = p2; 
	return max(a, b);
}

int searchL(int k){
	int l = 1, r = n, mid;
	while (l < r){
		mid = (l+r+1) >> 1;
		if (s[mid].l < k) l = mid;
		else r = mid-1;
	}
	return l;
}

int searchR(int k){
	int l = 1, r = n, mid;
	while (l < r){
		mid = (l+r) >> 1;
		if (k < s[mid].r) r = mid;
		else l = mid+1;
	}
	return r;
}

long long x, y, z; int t;
int main(){
	N = read(); m = read();
	for (int i=1; i<=N; i++){
		s[i].l = read(); s[i].r = read(); s[i].pos = i;
	}
	sort(s+1, s+N+1);
	for (int i=1; i<=N; i++)
		if (i == 1 || s[i].r > s[n].r) s[++n] = s[i];
	build(1, 1, n);
	for (int i=1; i<=m; i++){
		scanf("%d%d%d", &a, &b, &c);
		p = searchL(a); q = searchR(b);
		x = 1LL*c*(min(s[p].r, b)-max(s[p].l, a));
		y = 1LL*c*(min(s[q].r, b)-max(s[q].l, a));
		z = 1LL*c*query(1, 1, n, p+1, q-1, t);
		if (x >= y && x >= z && x > ans) { ans = x; u = s[p].pos; v = i; }
		if (y >= x && y >= z && y > ans) { ans = y; u = s[q].pos; v = i; }
		if (z >= x && z >= y && z > ans) { ans = z; u = s[t].pos; v = i; }
	}
	printf("%I64d\n", ans);
	if (ans) printf("%d %d\n", u, v);
	return 0;
}