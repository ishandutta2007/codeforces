#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;
const int RT = 3;

const int MAXT = 19;
const int MAXL = 550000;

int fac[MAXL + 5], ifac[MAXL + 5], inv[MAXL + 5];
int rg[MAXT + 5];

int ub2(int n)
{
	int ret = 0;
	while((1 << ret) < n) ret ++;
	return ret;
}

int power(int x, int t)
{
	int ret = 1;
	while(t > 0) {
		if(t & 1) ret = 1ULL * ret * x % MOD;
		x = 1ULL * x * x % MOD;
		t >>= 1;
	}
	return ret;
}

int cr[MAXL + 5];
void dft(int arr[], int siz, int dir)
{
	if(dir == -1) reverse(arr + 1, arr + (1 << siz));
	int cur = 0;
	for(int i = 0; i < (1 << siz); i ++) {
		if(cur < i) swap(arr[cur], arr[i]);
		for(int j = siz - 1; j >= 0; j --) {
			cur ^= 1 << j;
			if(cur >> j & 1) break;
		}
	}
	rep1(d, siz) {
		int pr = rg[d];
		cr[0] = 1;
		for(int i = 1; i < (1 << (d - 1)); i ++) cr[i] = 1ULL * cr[i - 1] * pr % MOD;
		for(int i = 0; i < (1 << siz); i += 1 << d) rep(j, 1 << (d - 1)) {
			int ev = arr[i + j], od = 1ULL * arr[i + j + (1 << (d - 1))] * cr[j] % MOD;
			arr[i + j] = ev + od - (ev + od >= MOD ? MOD : 0);
			arr[i + j + (1 << (d - 1))] = ev - od + (ev - od < 0 ? MOD : 0);
		}
	}
	if(dir == -1) {
		int invn = inv[1 << siz];
		rep(i, 1 << siz) arr[i] = 1ULL * arr[i] * invn % MOD;
	}
}

int tmp0[MAXL + 5], tmp1[MAXL + 5];
void poly_mul(int A[], int B[], int ret[], int siz)
{
	rep(i, 1 << (siz + 1)) tmp0[i] = i >> siz ? 0 : A[i];
	rep(i, 1 << (siz + 1)) tmp1[i] = i >> siz ? 0 : B[i];
	dft(tmp0, siz + 1, 1);
	dft(tmp1, siz + 1, 1);
	rep(i, 1 << (siz + 1)) ret[i] = 1ULL * tmp0[i] * tmp1[i] % MOD;
	dft(ret, siz + 1, -1);
}


void init()
{
	rg[0] = 1;
	rep1(i, MAXT) rg[i] = power(RT, (MOD - 1) >> i);
	fac[0] = 1;
	rep1(i, MAXL) fac[i] = 1LL * fac[i - 1] * i % MOD;
	ifac[MAXL] = power(fac[MAXL], MOD - 2);
	for(int i = MAXL; i >= 1; i --) ifac[i - 1] = 1LL * ifac[i] * i % MOD;
	rep1(i, MAXL) inv[i] = 1LL * ifac[i] * fac[i - 1] % MOD;
}

int n, m, a[100005], ps[100005], psx[100005];
bool hv[100005];
int cf[100005], icf[100005], ans;

int f[200005], g[200005];
void solve(int l, int r)
{
	if(l == r) return;
	int mid = (l + r) >> 1;
	solve(l, mid);
	solve(mid + 1, r);
	
	int s0 = 0, s1 = 0;
	for(int i = l; i <= mid; i ++) s0 = (s0 + (1ULL * ps[i] * i + MOD - psx[i]) % MOD * cf[i]) % MOD;
	for(int i = mid + 1; i <= r; i ++) s1 = (s1 + icf[i]) % MOD;
	ans = (ans + 1ULL * s0 * s1) % MOD;
	s0 = s1 = 0;
	for(int i = l; i <= mid; i ++) s0 = (s0 + cf[i]) % MOD;
	for(int i = mid + 1; i <= r; i ++) s1 = (s1 + (1ULL * ps[i] * i + MOD - psx[i]) % MOD * icf[i]) % MOD;
	ans = (ans + 1ULL * s0 * s1) % MOD;
	
	int len = __lg(r - l);
	rep(i, 1 << (len + 1)) f[i] = g[i] = 0;
	for(int i = l; i <= mid; i ++) f[i - l] = cf[i];
	for(int i = mid + 1; i <= r; i ++) g[i - mid - 1] = icf[i];
	poly_mul(f, g, f, len);
	for(int i = l + mid + 1; i <= mid + r; i ++) {
		int ss = i >> 1;
		ans = (ans + (2ULL * psx[ss] + 1ULL * (MOD - ps[ss]) * i) % MOD * f[i - l - mid - 1]) % MOD;
	}
}

int main()
{
	init();
	
	scanf("%d%d", &n, &m);
	rep1(i, n) scanf("%d", &a[i]);
	rep1(i, n) {
		ps[i] = (ps[i - 1] + a[i]) % MOD;
		psx[i] = (psx[i - 1] + 1ULL * a[i] * i) % MOD;
	}
	rep(i, m) {
		int x; scanf("%d", &x);
		hv[x] = true;
	}
	
	int f = 1;
	rep1(i, n) if(hv[i]) {
		ans = (ans + (1ULL * (MOD + ps[i] - ps[n]) * i + MOD + psx[n] - psx[i]) % MOD * f) % MOD;
		cf[i] = f; f = f * 2 % MOD;
	}
	f = 1;
	for(int i = n; i >= 1; i --) if(hv[i]) {
		ans = (ans + (1ULL * ps[i] * i + MOD - psx[i]) % MOD * f) % MOD;
		icf[i] = f; f = f * 2 % MOD;
	}
	
	solve(1, n);
	
	ans = 1ULL * ans * power(f - 1, MOD - 2) % MOD;
	printf("%d\n", ans);
	return 0;
}