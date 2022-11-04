#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, B = y; i <= B; i ++)
#define ff(i, x, y) for(int i = x, B = y; i <  B; i ++)
#define fd(i, x, y) for(int i = x, B = y; i >= B; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

int gg;

char str[53]; int lc;
int num[53];

const int N = 405;
const int M = N * (N - 1) * 2;

int n, m;
int p1[M], p2[M], t1[M], t2[M];
char s[N];

int pd() {
	fo(i, 1, m) {
		if(num[s[p1[i]] - 'a'] == t1[i]) {
			if(num[s[p2[i]] - 'a'] != t2[i]) {
				return 0;
			}
		}
	}
	return 1;
}

int fi[N], to[M], nt[M], tot = 1;
void link(int x, int y) {
	nt[++ tot] = fi[x], to[tot] = y, fi[x] = tot;
}
int bl[N], b0, dfn[N], low[N], dfn0, bz[N], z[N], z0;
void dg(int x) {
	dfn[x] = low[x] = ++ dfn0; 
	z[++ z0] = x; bz[x] = z0;
	for(int i = fi[x]; i; i = nt[i]) {
		int y = to[i];
		if(!dfn[y]) dg(y), low[x] = min(low[x], low[y]); else
			if(bz[y]) low[x] = min(low[x], dfn[y]);
	}
	if(low[x] >= dfn[x]) {
		++ b0;
		do  bl[z[z0]] = b0, bz[z[z0]] = 0; while(z[z0 --] != x);
	}
}
void build_graph() {
	fo(i, 1, m) link(p1[i] * 2 - t1[i], p2[i] * 2 - t2[i]) , link(p2[i] * 2 - !t2[i], p1[i] * 2 - !t1[i]);
	fo(i, 1, 2 * n) if(!dfn[i]) dg(i);
}

int us[N];

void dfs(int x) {
	if(bz[x]) return;
	bz[x] = 1;
	for(int i = fi[x]; i; i = nt[i])
		dfs(to[i]);
}
int qc;
int hl() {
	fo(i, 1, 2 * n) bz[i] = 0;
	fo(i, 1, n) if(us[i] != 2) {
		dfs(2 * i - us[i]);
	}
	if(qc != -1) fo(i, 1, n) dfs(2 * i - qc);
	fo(i, 1, n) if(bz[2 * i] && bz[2 * i - 1]) return 0;
	return 1;
}


int main() {
	//freopen("a.in", "r", stdin);
	scanf("%s", str); lc = strlen(str);
	ff(i, 0, lc) num[i] = str[i] == 'V';
	qc = 1;
	ff(i, 0, lc) if(num[i] != num[0]) qc = 0;
	if(qc) qc = num[0]; else qc = -1;
	scanf("%d %d", &n, &m);
	fo(i, 1, m) {
		scanf("%d", &p1[i]);
		scanf("%s", str);
		t1[i] = str[0] == 'V';
		scanf("%d", &p2[i]);
		scanf("%s", str);
		t2[i] = str[0] == 'V';
	}
	scanf("%s", s + 1);
	if(pd()) {
		fo(i, 1, n) pp("%c", s[i]); hh;
		return 0;
	}
	build_graph();
	fo(i, 1, n) if(bl[2 * i] == bl[2 * i - 1]) {
		pp("-1\n");
		return 0;
	}
	fd(i, n - 1, 0) {
		fo(j, 1, i) us[j] = num[s[j] - 'a'];
		fo(j, i + 1, n) us[j] = 2;
		us[i + 1] = 0;
		int pd[2];
		pd[0] = hl();
		us[i + 1] = 1;
		pd[1] = hl();
		ff(k, s[i + 1] - 'a' + 1, lc) {
			if(pd[num[k]]) {
				s[i + 1] = 'a' + k;
				us[i + 1] = num[k];
				fo(j, i + 2, n) {
					us[j] = 0;
					pd[0] = hl();
					us[j] = 1;
					pd[1] = hl();
					ff(c, 0, lc) {
						if(pd[num[c]]) {
							s[j] = 'a' + c;
							us[j] = num[c];
							break;
						}
					}
				}
				fo(j, 1, n) pp("%c", s[j]); hh;
				return 0;
			}
		}
	}
	pp("-1\n");
}