#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, B = y; i <= B; i ++)
#define ff(i, x, y) for(int i = x, B = y; i <  B; i ++)
#define fd(i, x, y) for(int i = x, B = y; i >= B; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
#define cmin(a, b) ((a) > (b) ? (a) = (b) : 0)
using namespace std;

const int N = 1e5 + 5;

int st, en;
int n, m;
int l[N], r[N];
int x, y;
int fi[N], nt[N * 2], to[N * 2], tot = 1;

void link(int x, int y) {
	nt[++ tot] = fi[x], to[tot] = y, fi[x] = tot;
}

int cr[N];

struct P {
	int x, y, l, r;
	P(){

	}
	P (int _x, int _y, int _l, int _r) {
		x = _x, y = _y, l = _l, r = _r;
	}
} w[N * 3]; int w0;

int l1, r1, l2, r2;
P z[N];
vector<int> g[N];

int mab;

void dg(int x) {
	g[mab].push_back(x);
	if(cr[x] == 2) {
		l1 = max(l1, l[x]);
		r1 = min(r1, r[x]);
	} else {
		l2 = max(l2, l[x]);
		r2 = min(r2, r[x]);
	}
	for(int i = fi[x]; i; i = nt[i]) {
		int y = to[i];
		if(cr[y] && cr[y] == cr[x]) {
			printf("IMPOSSIBLE\n");
			exit(0);
		}
		if(!cr[y]) {
			cr[y] = 3 - cr[x];
			dg(y);
		}
	}
}

int cnt;

void build() {
	fo(i, 1, n) if(!cr[i]) {
		cnt ++;
		mab = i;
		l1 = l2 = 0; r1 = r2 = 1e9 + 1;
		cr[i] = 1; dg(i);
		if(l1 > r1 || l2 > r2) {
			printf("IMPOSSIBLE\n");
			exit(0);
		}
		if(l1 > l2) {
			swap(l1, l2), swap(r1, r2);
			ff(j, 0, g[i].size()) cr[g[i][j]] = 3 - cr[g[i][j]];
		}
		z[i] = P(l1, r1, l2, r2);
		if(l2 <= r1) {
			if(r2 <= r1) {
				w[++ w0] = P(l1, l2 - 1, l2, r2);
				w[++ w0] = P(l2, r2, l1, r1);
				w[++ w0] = P(r2 + 1, r1, l2, r2);
			} else {
				w[++ w0] = P(l1, l2 - 1, l2, r2);
				w[++ w0] = P(l2, r1, l1, r2);
				w[++ w0] = P(r1 + 1, r2, l1, r1);
			}
		} else {
			w[++ w0] = P(l1, r1, l2, r2);
			w[++ w0] = P(l2, r2, l1, r1);
		}
	}
}

multiset<int> s, t;
int e[N * 6], e0;
map<int, int> num;

vector<int> q[N * 6];
#define pb push_back
#define si size()

int n1, n2;

void End() {
	 fo(i, 1, w0) e[++ e0] = w[i].x, e[++ e0] = w[i].y + 1;
	 sort(e + 1, e + e0 + 1);
	 e0 = unique(e + 1, e + e0 + 1) - (e + 1);
	 fo(i, 1, e0) num[e[i]] = i;
	 fo(i, 1, w0) if(w[i].x <= w[i].y) {
		 q[num[w[i].x]].pb(i);
		 q[num[w[i].y + 1]].pb(i);
	 }
	 fo(i, 1, e0 - 1) {
		 int x = e[i], y = e[i + 1] - 1; 
		 ff(j, 0, q[i].si) {
			 int p = q[i][j];
			 if(w[p].x == x) {
				 s.insert(w[p].l);
				 t.insert(w[p].r);
			 } else {
				 s.erase(s.find(w[p].l));
				 t.erase(t.find(w[p].r));
			 }
		 }
		 if(s.size() == cnt) {
			 int l = *s.rbegin(), r = *t.begin();
			 x += l, y += r;
			 if(l <= r && (x <= st && y >= st || x <= en && y >= en || (x >= st && y <= en))) {
				 printf("POSSIBLE\n");
				 int n3;
				 if(x <= st && y >= st) n3 = st;
				 if(x <= en && y >= en) n3 = en;
				 if(x >= st && y <= en) n3 = x;
				 x = e[i], y = e[i + 1] - 1;
				 swap(l, r);
				 l = n3 - l, r = n3 - r;
				 x = max(x, l); y = min(y, r);
				 n1 = x, n2 = n3 - x;
				 pp("%d %d\n", n1, n2);
				 return;
			 }
		 }
	 }
	printf("IMPOSSIBLE\n");
	exit(0);
}
int cho[N];
void true_end() {
	fo(i, 1, n) if(g[i].si) {
		int l1 = z[i].x, r1 = z[i].y, l2 = z[i].l, r2 = z[i].r;
		int tp;
		if(n1 >= l1 && n1 <= r1 && n2 >= l2 && n2 <= r2) {
			ff(j, 0, g[i].si) cho[g[i][j]] = cr[g[i][j]] == 2 ? 1 : 2;
		} else {
			ff(j, 0, g[i].si) cho[g[i][j]] = cr[g[i][j]] == 1 ? 1 : 2;
		}
	}
	fo(i, 1, n) pp("%d", cho[i]); hh;
}

int main() {
	//freopen("a.in", "r", stdin);
	scanf("%d %d", &st, &en);
	scanf("%d %d", &n, &m);
	fo(i, 1, n) scanf("%d %d", &l[i], &r[i]);
	fo(i, 1, m) {
		scanf("%d %d", &x, &y);
		link(x, y); link(y, x);
	}
	build();
	End();
	true_end();
}