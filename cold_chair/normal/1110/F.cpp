#include<cstdio>
#include<vector>
#include<cstring>
#define pp printf
#define ll long long
#define fo(i, x, y) for(int i = x, B = y; i <= B; i ++)
using namespace std;

const int N = 5e5 + 5;

int n, Q, x;
int fa[N], fv[N];

vector<int> c[N];


struct nod {
	int i, l, r;
} b;

vector<nod> a[N];


int pl, pr; ll px;
ll t[N * 4], lz[N * 4];

#define i0 i + i
#define i1 i + i + 1
#define max(a, b) ((a) > (b) ? (a) : (b))
void down(int i) {
	if(lz[i]) {
		t[i0] += lz[i]; lz[i0] += lz[i]; 
		t[i1] += lz[i]; lz[i1] += lz[i];
		lz[i] = 0;
	}
}
void add(int i, int x, int y) {
	if(y < pl || x > pr) return;
	if(x >= pl && y <= pr) { t[i] += px; lz[i] += px; return;}
	int m = x + y >> 1; down(i);
	add(i0, x, m); add(i1, m + 1, y);
	t[i] = min(t[i0], t[i1]);
}
void ft(int i, int x, int y) {
	if(y < pl || x > pr) return ;
	if(x >= pl && y <= pr) { px = min(px, t[i]); return ;}
	int m = x + y >> 1; down(i);
	ft(i0, x, m); ft(i1, m + 1, y);
}

int p[N], q[N], tp;
ll s[N];

const ll M = 1e18;

void dg(int x) {
	p[x] = ++ tp;
	fo(j, 0, c[x].size() - 1) {
		int y = c[x][j];
		s[y] = s[x] + fv[y], dg(y);
	}
	q[x] = tp;
	if(p[x] == q[x]) {
		pl = pr = p[x]; px = s[x] - M;
		add(1, 1, n);
	}
}

ll ans[N];

void dfs(int x) {
	fo(j, 0, a[x].size() - 1) {
		pl = a[x][j].l, pr = a[x][j].r; px = 1e18;
		ft(1, 1, n);
		ans[a[x][j].i] = px;
	}
	fo(j, 0, c[x].size() - 1) {
		int y = c[x][j];
		px = -fv[y];
		pl = p[y]; pr = q[y];
		add(1, 1, n);
		px = fv[y];
		pl = 1; pr = p[y] - 1;
		add(1, 1, n);
		pl = q[y] + 1; pr = n;
		add(1, 1, n);
		
		dfs(y);
		
		px = -fv[y];
		pl = q[y] + 1; pr = n;
		add(1, 1, n);
		pl = 1; pr = p[y] - 1;
		add(1, 1, n);
		px = fv[y];
		pl = p[y]; pr = q[y];
		add(1, 1, n);
	}
}
int main() {
//	freopen("a.in", "r", stdin);
	scanf("%d %d", &n, &Q);
	fo(i, 1, n * 4) t[i] = 1e18;
	fo(i, 2, n) {
		scanf("%d %d", &fa[i], &fv[i]);
		c[fa[i]].push_back(i);
	}
	fo(i, 1, Q) {
		scanf("%d", &x);
		scanf("%d %d", &b.l, &b.r); b.i = i;
		a[x].push_back(b);
	}
	dg(1); dfs(1);
	fo(i, 1, Q) pp("%I64d\n", ans[i]);
}