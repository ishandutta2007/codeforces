#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;
const int PR = 3;

int gr[105][8192], vgr[105][8192];
int dp[105][8192], vdp[105][8192];

int perm[105][2][105];


int power(int x, int t)
{
	t %= MOD - 1;
	t += t < 0 ? MOD - 1 : 0;
	int ret = 1;
	while(t > 0) {
		if(t & 1) ret = 1LL * ret * x % MOD;
		x = 1LL * x * x % MOD;
		t >>= 1;
	}
	return ret;
}

void fft(int from[], int to[], int dir)
{
	int cur = 0;
	rep(i, 8192) {
		to[i] = from[cur];
		for(int j = 12; j >= 0; j --) {
			cur ^= 1 << j;
			if(cur >> j & 1) break;
		}
	}
	
	for(int d = 2; d <= 8192; d <<= 1) {
		int dr = power(PR, (MOD - 1) / d * dir);
		for(int i = 0; i < 8192; i += d) {
			int cr = 1;
			for(int j = i; j < i + (d >> 1); j ++) {
				int ev = to[j], od = 1LL * to[j + (d >> 1)] * cr % MOD;
				to[j] = (ev + od) % MOD;
				to[j + (d >> 1)] = (ev - od + MOD) % MOD;
				cr = 1LL * cr * dr % MOD;
			}
		}
	}
	
	if(dir == -1) {
		int invn = power(8192, -1);
		rep(i, 8192) to[i] = 1LL * to[i] * invn % MOD;
	}
}

int ret[105];
int main()
{
	for(int i = 2; i <= 100; i ++) {
		gr[i - 1][i * (i + 1) / 2 - 1] = 1;
		if(i >= 4) gr[i - 1][i] = 1;
	}
	rep1(i, 99) fft(gr[i], vgr[i], 1);
	
	for(int i = 2; i <= 100; i ++) {
		rep1(j, i) perm[i][1][j] = j;
		if(i >= 4) {
			rep1(j, i) perm[i][0][j] = j % 2 == 1 ? i / 2 + 1 + j / 2 : j / 2;
			if(i & 1) swap(perm[i][0][i - 2], perm[i][0][i]);
		}
	}
	
	dp[0][0] = 1;
	fft(dp[0], vdp[0], 1);
	
	rep1(i, 99) {
		rep1(j, i) rep(k, 8192) vdp[i][k] = (vdp[i][k] + 1LL * vgr[j][k] * vdp[i - j][k]) % MOD;
		fft(vdp[i], dp[i], -1);
		rep(k, 8192) dp[i][k] = dp[i][k] != 0;
		fft(dp[i], vdp[i], 1);
	}
	
	int T;
	scanf("%d", &T);
	while(T --) {
		int n, m;
		scanf("%d%d", &n, &m);
		if(dp[n - 1][m - 1]) {
			printf("YES\n");
			int cn = n - 1, cm = m - 1;
			int clen = 1;
			ret[1] = 1;
			while(cn > 0) {
				int curn = 0;
				for(curn = 1; (!gr[curn][curn + 1] || !dp[cn - curn][cm - curn - 1]) && !dp[cn - curn][cm - (curn + 1) * (curn + 2) / 2 + 1]; curn ++);
				bool fl = dp[cn - curn][cm - (curn + 1) * (curn + 2) / 2 + 1];
				rep1(i, clen) ret[i] += perm[curn + 1][fl][1] - 1;
				if(fl) reverse(ret + 1, ret + clen + 1);
				for(int i = clen + 1; i <= clen + curn; i ++) 
				ret[i] = perm[curn + 1][fl][i - clen + 1] + (perm[curn + 1][fl][i - clen + 1] > perm[curn + 1][fl][1] ? clen - 1 : 0);
				clen += curn;
				cn -= curn;
				cm -= fl ? (curn + 1) * (curn + 2) / 2 - 1 : curn + 1;
			}
			rep1(i, n) printf("%d ", ret[i]); printf("\n");
		} else printf("NO\n");
	}
	return 0;
}