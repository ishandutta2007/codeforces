#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, B = y; i <= B; i ++)
#define ff(i, x, y) for(int i = x, B = y; i <  B; i ++)
#define fd(i, x, y) for(int i = x, B = y; i >= B; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

void end() {
	pp("-1\n");
	exit(0);
}

const int N = 2e5 + 50;

int a10[N];
int n, a[N][2], b[N][2];
int bz[7][7], cnt[7][7];

char str[N];

const int M = 1005;

int S, T, fi[M], to[M], r[M], nt[M], cur[M], tot = 1;

void link(int x, int y, int z) {
	nt[++ tot] = fi[x], to[tot] = y, r[tot] = z, fi[x] = tot;
	nt[++ tot] = fi[y], to[tot] = x, r[tot] = 0, fi[y] = tot;
}

int d[M], d0, dis[M];
int bfs() {
	fo(i, 1, T) dis[i] = 0, cur[i] = fi[i];
	d[d0 = 1] = S; dis[S] = 1;
	for(int i = 1; i <= d0; i ++) {
		int x = d[i];
		for(int j = fi[x]; j; j = nt[j]) if(r[j] && !dis[to[j]]) {
			dis[to[j]] = dis[x] + 1;
			d[++ d0] = to[j];
		}
	}
	return dis[T] > 0;
}

int dg(int x, int flow) {
	if(x == T) return flow;
	int use = 0;
	for(int i = cur[x]; i; i = nt[i], cur[x] = i)
		if(r[i] > 0 && dis[x] + 1 == dis[to[i]]) {
			int t = dg(to[i], min(flow - use, r[i]));
			r[i] -= t, r[i ^ 1] += t, use += t;
			if(use == flow) return use;
		}
	return use;
}

void build() {
	scanf("%d", &n);
	S = 43, T = S + 1;
	fo(i, 1, n - 1) {
		scanf("%s", str + 1);
		int x = strlen(str + 1);
		if(a10[x - 1] > n) end();
		a[i][0] = x;
		scanf("%s", str + 1);
		int y = strlen(str + 1);
		if(a10[y - 1] > n) end();
		a[i][1] = y;
		cnt[x][y] ++;
	}
	fo(i, 1, 6) fo(j, 1, 6) {
		link(bz[i][j], 36 + i, 1 << 30);
		link(bz[i][j], 36 + j, 1 << 30);
	}
	link(36 + 1, T, min(n, 9) - 1);
	fo(i, 2, 6) if(n >= a10[i - 1])
		link(36 + i, T, min(a10[i], n + 1) - a10[i - 1]);
	fo(i, 1, 6) fo(j, 1, 6) if(cnt[i][j])
		link(S, bz[i][j], cnt[i][j]);
}

int num[7];

vector<int> q[37];
vector<int> e[7]; int bd[7];

int main() {
	a10[0] = 1; fo(i, 1, 6) a10[i] = a10[i - 1] * 10;
	fo(i, 1, 6) fo(j, 1, 6) bz[i][j] = (i - 1) * 6 + j;
	build();
	int ans = 0;
	while(bfs()) ans += dg(S, 1 << 30);
	if(ans != n - 1) end();
	fo(i, 1, 36) {
		for(int j = fi[i]; j; j = nt[j])
			if(to[j] != S && r[j ^ 1]) {
				fo(k, 1, r[j ^ 1]) q[i].push_back(to[j] - 36);
			}
	}
	fo(i, 2, 6) num[i] = a10[i - 1]; num[1] = 2;
	fo(i, 1, n - 1) {
		int cho = *(--q[bz[a[i][0]][a[i][1]]].end());
		q[bz[a[i][0]][a[i][1]]].pop_back();
		if(cho == a[i][0]) {
			b[i][0] = num[cho] ++;
			e[a[i][1]].push_back(i);
		} else {
			b[i][1] = num[cho] ++;
			e[a[i][0]].push_back(i);
		}
	}
	fo(i, 1, 6) bd[i] = 0;
	d[d0 = 1] = 1; bd[1] = 1;
	for(int i = 1; i <= d0; i ++) {
		int x = d[i];
		ff(j, 0, e[x].size()) {
			int t = e[x][j];
			if(!b[t][0]) {
				b[t][0] = bd[x];
				if(!bd[a[t][1]]) {
					d[++ d0] = a[t][1];
					bd[a[t][1]] = b[t][1];
				}
			} else {
				b[t][1] = bd[x];
				if(!bd[a[t][0]]) {
					d[++ d0] = a[t][0];
					bd[a[t][0]] = b[t][0];
				}
			}
		}
	}
	fo(i, 1, n - 1) if(!b[i][0] || !b[i][1])
		end();
	fo(i, 1, n - 1) {
		pp("%d %d\n", b[i][0], b[i][1]);
	}
}