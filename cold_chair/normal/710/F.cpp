#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, _b = y; i <= _b; i ++)
#define ff(i, x, y) for(int i = x, _b = y; i <  _b; i ++)
#define fd(i, x, y) for(int i = x, _b = y; i >= _b; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

#define fl fflush(stdout)

const int N = 6e5 + 5;

int T, op;
char s[N]; int len;
int cnt[N];

int son[N][26], tot;

int add(int x, int c) {
	if(!son[x][c]) son[x][c] = ++ tot;
	return son[x][c];
}

int d[N], d0, fa[N];

ll v[N];

void build(int rt) {
	fo(j, 0, 25) son[0][j] = rt;
	d[d0 = 1] = rt; fa[rt] = v[rt] = 0;
	for(int i = 1; i <= d0; i ++) {
		int x = d[i];
		fo(j, 0, 25) if(son[x][j]) {
			int y = son[x][j], k = fa[x];
			while(!son[k][j]) k = fa[k];
			k = son[k][j];
			fa[y] = k;
			v[y] = cnt[y] + v[fa[y]];
			d[++ d0] = y;
		}
	}
}

int mer(int i, int j) {
	if(!i || !j) return i + j;
	cnt[i] += cnt[j];
	fo(k, 0, 25) son[i][k] = mer(son[i][k], son[j][k]);
	return i;
}

const int M = 35;

int rt[M], siz[M], r0;

void work() {
	while(r0 > 1 && siz[r0] == siz[r0 - 1]) {
		rt[r0 - 1] = mer(rt[r0 - 1], rt[r0]);
		siz[r0 - 1] += siz[r0];
		r0 --;
		build(rt[r0]);
	}
}

int go(int x, int c) {
	while(!son[x][c]) x = fa[x];
	return son[x][c];
}

int main() {
	scanf("%d", &T);
	fo(ii, 1, T) {
		scanf("%d", &op);
		scanf("%s", s + 1); len = strlen(s + 1);
		switch(op) {
			case 1:
			case 2: {
				rt[++ r0] = ++ tot; siz[r0] = 1;
				int x = rt[r0];
				fo(i, 1, len) x = add(x, s[i] - 'a');
				cnt[x] += op == 1 ? 1 : -1;
				build(rt[r0]);
				work();
				break;
			}
			case 3 : {
				ll ans = 0;
				fo(i, 1, r0) {
					fo(j, 0, 25) son[0][j] = rt[i];
					int x = rt[i];
					fo(j, 1, len) {
						x = go(x, s[j] - 'a');
						ans += v[x];
					}
				}
				pp("%lld\n", ans); fl;
				break;
			}
		}
	}
}