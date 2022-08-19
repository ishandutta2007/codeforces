#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

struct fwt
{
	int dat[200005];
	void add(int id, int val)
	{
		for(; id <= 200000; id += id & -id) dat[id] += val;
	}
	int query(int id)
	{
		int ret = 0;
		for(; id > 0; id -= id & -id) ret += dat[id];
		return ret;
	}
}tre;

int n, m, s[200005], t[200005], fac[200005], inv[200005], ifac[200005], cnt[200005], cur;

int main()
{
	fac[0] = 1;
	rep1(i, 200000) fac[i] = 1ULL * fac[i - 1] * i % MOD;
	rep1(i, 200000) inv[i] = i == 1 ? 1 : MOD - 1ULL * inv[MOD % i] * (MOD / i) % MOD;
	ifac[0] = 1;
	rep1(i, 200000) ifac[i] = 1ULL * ifac[i - 1] * inv[i] % MOD;
	scanf("%d%d", &n, &m);
	rep1(i, n) scanf("%d", &s[i]);
	rep1(i, m) scanf("%d", &t[i]);
	
	cur = fac[n];
	rep1(i, n) cnt[s[i]] ++;
	rep1(i, 200000) cur = 1ULL * cur * ifac[cnt[i]] % MOD;
	
	rep1(i, n) tre.add(s[i], 1);
	int ans = 0;
	rep1(i, m) {
		if(i == n + 1) ans = (ans + cur) % MOD;
		cur = 1ULL * cur * inv[n - i + 1] % MOD;
		ans = (ans + 1ULL * cur * tre.query(t[i] - 1)) % MOD;
		cur = 1ULL * cur * cnt[t[i]] % MOD;
		cnt[t[i]] --; tre.add(t[i], -1);
	}
	printf("%d\n", ans);
	return 0;
}