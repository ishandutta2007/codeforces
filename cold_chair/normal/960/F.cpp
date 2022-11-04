#include<cstdio>
#define fo(i, x, y) for(int i = x; i <= y; i ++)
#define max(a, b) ((a) > (b) ? (a) : (b))
using namespace std;

const int M = 1e7 + 5;

int n, m, x, y, z, ans;
struct node {
	int l, r, s;
} t[M];
int g[100005], pl, pr, px, tot;

void add(int &i, int x, int y) {
	if(y < pl || x > pr) return;
	if(!i) i = ++ tot;
	if(x == y) {
		t[i].s = max(t[i].s, px);
		return;
	}
	int m = x + y >> 1;
	add(t[i].l, x, m); add(t[i].r, m + 1, y);
	t[i].s = max(t[t[i].l].s, t[t[i].r].s);
}

void fi(int &i, int x, int y) {
	if(y < pl || x > pr) return;
	if(x >= pl && y <= pr) {
		px = max(px, t[i].s);
		return;
	}
	int m = x + y >> 1;
	fi(t[i].l, x, m); fi(t[i].r, m + 1, y);
}

int main() {
//	freopen("f.in", "r", stdin);
	scanf("%d %d", &n, &m);
	fo(i, 1, m) {
		scanf("%d %d %d", &x, &y, &z);
		px = 0; pl = 0; pr = z - 1;
		fi(g[x], 0, 1e5);
		px ++;
		ans = max(ans, px);
		pl = pr = z;
		add(g[y], 0, 1e5);
	}
	printf("%d\n", ans);
}