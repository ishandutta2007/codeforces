#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, B = y; i <= B; i ++)
#define ff(i, x, y) for(int i = x, B = y; i <  B; i ++)
#define fd(i, x, y) for(int i = x, B = y; i >= B; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

const int N = 4e5 + 5;

int n, m, x, y;
int fi[N], nt[N], to[N], v[N], tot = 1, siz[N];
void link(int x, int y, int z) {
	nt[++ tot] = fi[x], to[tot] = y, v[tot] = z, fi[x] = tot;
}

const int mo = 1e9 + 7;

int bz[N];

ll ans[2];

int us[N];
int d[N], d0, p[N], p0, q[N], q0;

void bfs(int x) {
	d[d0 = 1] = x; bz[x] = 1;
	p0 = 0;
	for(int i = 1; i <= d0; i ++) {
		int x = d[i];
		for(int j = fi[x]; j; j = nt[j]) {
			if(us[j]) continue;
			int y = to[j];
			p[++ p0] = j;
			us[j] = us[j ^ 1] = 1;
			if(!bz[y]) bz[y] = 1, d[++ d0] = y;
			break;
		}
	}
}


ll dp[2][2][2]; int o;
#define mem(a) memset(a, 0, sizeof a)
int cnt[N][2];

void add(ll &x, ll y) {
	(x += y) %= mo;
}
void gg(ll (*dp)[2], int x) {
	fo(j, 0, 1) if(cnt[x][j])  {
		fo(k, 0, 1) {
			if(j ^ k) swap(dp[0][k], dp[1][k]);
		}
	}
}
void dp_lian() {
	mem(dp[o]);
	dp[o][0][0] = dp[o][0][1] = 1;
	fo(i, 1, p0) {
		gg(dp[o], to[p[i] ^ 1]);
		mem(dp[!o]);
		fo(j, 0, 1) fo(k, 0, 1) fo(u, 0, 1) {
			add(dp[!o][j ^ ((k ^ v[p[i] ^ 1]) | (u ^ v[p[i]]))][u], dp[o][j][k]);
		}
		o = !o;
	}
	gg(dp[o], to[p[p0]]);
	ll s[2]; fo(j, 0, 1) s[j] = ans[j], ans[j] = 0;
	fo(j, 0, 1) fo(k, 0, 1) add(ans[j ^ k], s[j] * (dp[o][k][0] + dp[o][k][1]));
}

void dp_huan() {
	ll sum[2]; sum[0] = sum[1] = 0;
	fo(st, 0, 1) {
		mem(dp[o]);
		dp[o][0][st] = 1;
		fo(i, 1, p0) {
			mem(dp[!o]);
			fo(j, 0, 1) fo(k, 0, 1) fo(u, 0, 1) {
				add(dp[!o][j ^ ((k ^ v[p[i] ^ 1]) | (u ^ v[p[i]]))][u], dp[o][j][k]);
			}
			o = !o;
		}
		fo(j, 0, 1) sum[j] += dp[o][j][st];
	}
	ll s[2]; fo(j, 0, 1) s[j] = ans[j], ans[j] = 0;
	fo(j, 0, 1) fo(k, 0, 1) add(ans[j ^ k], s[j] * sum[k]);
}

int main() {
	//freopen("a.in", "r", stdin);
	scanf("%d %d", &m, &n);
	fo(i, 1, m) {
		int c;
		scanf("%d", &c);
		if(c == 1) {
			scanf("%d", &x);
			int t1 = 0;
			if(x < 0) t1 = 1, x = -x;
			cnt[x][t1] ^= 1;
		} else {
			scanf("%d %d", &x, &y);
			int t1 = 0, t2 = 0;
			if(x < 0) t1 = 1, x = -x;
			if(y < 0) t2 = 1, y = -y;
			link(x, y, t2); link(y, x, t1);
			siz[x] ++; siz[y] ++;
		}
	}
	ans[0] = 1;
	fo(i, 1, n) if(!bz[i]) {
		if(siz[i] == 0) {
			if(!cnt[i][0] && !cnt[i][1]) {
				ans[0] = ans[0] * 2 % mo;
				ans[1] = ans[1] * 2 % mo;
			} else {
				if(cnt[i][0] && cnt[i][1]) {
					ans[0] = ans[0] * 2 % mo;
					ans[1] = ans[1] * 2 % mo;
					swap(ans[0], ans[1]);
				} else {
					ans[0] = (ans[0] + ans[1]) % mo;
					ans[1] = ans[0];
				}
			}
		} else
		if(siz[i] == 1) {
			bfs(i);
			dp_lian();
		} else {
			bfs(i);
			if(us[nt[fi[i]]]) {
				dp_huan();
			} else {
				q0 = p0;
				fo(j, 1, q0) q[j] = p[j];
				bfs(i);
				reverse(p + 1, p + p0 + 1);
				fo(j, 1, p0) p[j] ^= 1;
				fo(j, 1, q0) p[++ p0] = q[j];
				dp_lian();
			}
		}
	}
	pp("%lld\n", ans[1]);
}