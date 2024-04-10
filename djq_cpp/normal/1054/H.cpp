#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int MOD0 = 998244353, PR0 = 3;
const int MOD1 = 924844033, PR1 = 5;

int power(int x, int t, int m)
{
	int ret = 1;
	while(t > 0) {
		if(t & 1) ret = 1LL * ret * x % m;
		x = 1LL * x * x % m; 
		t >>= 1;
	}
	return ret;
}

int dat0[2][1025][1025], dat1[2][1025][1025], dat2[2][1025][1025], dat3[2][1025][1025];
int n, m, a[100005], b[100005], c;
int ln1[505], ln9[505];

void init_ln()
{
	int t = 1;
	ln1[0] = 1024;
	rep(i, 490) {
		ln1[t] = i;
		t = t * 2 % 491;
	}
	ln9[0] = 1024;
	rep(i, 498) {
		ln9[t] = i;
		t = t * 7 % 499;
	}
}

int tmp[1025];
void dft(int M, int R, int dir)
{
	int cur = 0;
	rep(i, 1024) {
		if(cur < i) swap(tmp[cur], tmp[i]);
		for(int j = 9; j >= 0; j --) {
			cur ^= 1 << j;
			if(cur >> j & 1) break;
		}
	}
	for(int d = 2; d <= 1024; d <<= 1) {
		int pr = dir == -1 ? power(R, M - 1 - (M - 1) / d, M) : power(R, (M - 1) / d, M);
		for(int i = 0; i < 1024; i += d) {
			int cr = 1;
			for(int j = i; j < i + (d >> 1); j ++) {
				int ev = tmp[j], od = 1LL * tmp[j + (d >> 1)] * cr % M;
				tmp[j] = (ev + od) % M;
				tmp[j + (d >> 1)] = (ev - od + M) % M;
				cr = 1LL * cr * pr % M;
			}
		}
	}
	if(dir == -1) {
		int cinv = power(2, M - 11, M);
		rep(i, 1024) tmp[i] = 1LL * tmp[i] * cinv % M;
	}
}

void poly_dft(int arr[][1025][1025], int M, int R, int dir)
{
	rep(i, 1025) rep(j, 1025) if(dir == 1) arr[1][i][j] = (arr[1][i][j] + arr[0][i][j]) % M;
	else if(dir == -1) arr[1][i][j] = (arr[1][i][j] - arr[0][i][j] + M) % M;
	rep(i, 2) rep(k, 1025) {
		rep(j, 1025) tmp[j] = arr[i][j][k];
		if(dir == 1) rep(j, 1024) tmp[1024] = (tmp[1024] + tmp[j]) % M;
		dft(M, R, dir);
		if(dir == -1) rep(j, 1024) tmp[1024] = (tmp[1024] - tmp[j] + M) % M;
		rep(j, 1025) arr[i][j][k] = tmp[j];
	}
	rep(i, 2) rep(j, 1025) {
		rep(k, 1025) tmp[k] = arr[i][j][k];
		if(dir == 1) rep(k, 1024) tmp[1024] = (tmp[1024] + tmp[k]) % M;
		dft(M, R, dir);
		if(dir == -1) rep(k, 1024) tmp[1024] = (tmp[1024] - tmp[k] + M) % M;
		rep(k, 1025) arr[i][j][k] = tmp[k];
	}
}

void poly_mul()
{
	rep(i, 2) rep(j, 1025) rep(k, 1025) dat2[i][j][k] = dat0[i][j][k];
	rep(i, 2) rep(j, 1025) rep(k, 1025) dat3[i][j][k] = dat1[i][j][k];
	poly_dft(dat2, MOD0, PR0, 1);
	poly_dft(dat3, MOD0, PR0, 1);
	rep(i, 2) rep(j, 1025) rep(k, 1025) dat2[i][j][k] = 1LL * dat2[i][j][k] * dat3[i][j][k] % MOD0;
	poly_dft(dat2, MOD0, PR0, -1);
	
	poly_dft(dat0, MOD1, PR1, 1);
	poly_dft(dat1, MOD1, PR1, 1);
	rep(i, 2) rep(j, 1025) rep(k, 1025) dat3[i][j][k] = 1LL * dat0[i][j][k] * dat1[i][j][k] % MOD1;
	poly_dft(dat3, MOD1, PR1, -1);
	
	LL T0 = power(MOD1 % MOD0, MOD0 - 2, MOD0), T1 = power(MOD0 % MOD1, MOD1 - 2, MOD1);
	rep(i, 2) rep(j, 1025) rep(k, 1025) dat0[i][j][k] = 0;
	rep(i, 2) rep(j, 1025) rep(k, 1025) {
		LL cur = (MOD1 * (dat2[i][j][k] * T0 % MOD0) + MOD0 * (dat3[i][j][k] * T1 % MOD1)) % (1LL * MOD0 * MOD1);
		assert(cur % MOD0 == dat2[i][j][k]);
		assert(cur % MOD1 == dat3[i][j][k]);
		dat0[i][j == 1024 ? 1024 : j % 490][k == 1024 ? 1024 : k % 498] += cur % 490019;
	}
	rep(i, 2) rep(j, 1025) rep(k, 1025) dat0[i][j][k] %= 490019;
}

int main()
{
	scanf("%d%d%d", &n, &m, &c);
	init_ln();
	rep(i, n) {
		scanf("%d", &a[i]);
		dat0[1 - i % 2][ln1[1LL * i * i % 491]][ln9[1LL * i * i % 499]] += a[i];
	}
	rep(i, m) {
		scanf("%d", &b[i]);
		dat1[1 - i % 2][ln1[1LL * i * i * i % 491]][ln9[1LL * i * i * i % 499]] += b[i];
	}
	rep(i, 2) rep(j, 491) rep(k, 499) {
		dat0[i][j][k] %= 490019;
		dat1[i][j][k] %= 490019;
	}
	poly_mul();
	
	int ans = 0, t = 1;
	rep(i, 490018) {
		ans = (ans + 1LL * dat0[1 - i % 2][ln1[i % 491]][ln9[i % 499]] * t) % 490019;
		t = 1LL * t * c % 490019;
	}
	printf("%d\n", ans);
	return 0;
}