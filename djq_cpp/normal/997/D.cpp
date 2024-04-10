#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <complex>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cwchar>
#include <cwctype>
#include <exception>
#include <locale>
#include <numeric>
#include <new>
#include <stdexcept>
#include <limits>
#include <valarray>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <list>
#include <utility>
#include <bitset>
#include <algorithm>
#include <functional>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int k;
struct dp_sta
{
	int dat[80];
	dp_sta()
	{
		memset(dat, 0, sizeof(int) * (k + 1));
	}
	dp_sta(const dp_sta& oth)
	{
		memcpy(dat, oth.dat, sizeof(int) * (k + 1));
	}
	
	dp_sta operator+(const dp_sta& oth) const
	{
		dp_sta ans;
		for(int i = 0; i <= k; i ++)
		ans.dat[i] = (dat[i] + oth.dat[i]) % MOD;
		return ans;
	}
	dp_sta operator-(const dp_sta& oth) const
	{
		dp_sta ans;
		for(int i = 0; i <= k; i ++)
		ans.dat[i] = (dat[i] - oth.dat[i] + MOD) % MOD;
		return ans;
	}
	dp_sta gen_rep() const
	{
		dp_sta ans;
		ans.dat[0] = 1;
		rep1(i, k) for(int j = 2; j <= i; j ++)
		ans.dat[i] = (ans.dat[i] + 1LL * ans.dat[i - j] * dat[j - 2]) % MOD;
		return ans;
	}
};

struct d_tree
{
	int n;
	vector<int> G[4005];
	dp_sta dp[4005], ret[4005];
	vector<dp_sta> pre_dp[4005];
	vector<dp_sta> pre[4005];
	dp_sta ans;
	
	void dfs0(int v, int par)
	{
		dp_sta tot;
		pre[v].resize(G[v].size());
		
		rep(i, G[v].size()) {
			int u = G[v][i];
			if(u == par) {
				pre[v][i] = tot;
				continue;
			}
			
			dfs0(u, v);
			pre[v][i] = tot;
			tot = tot + dp[u];
		}
		
		pre[v].push_back(tot);
		dp[v] = tot.gen_rep();
	}
	
	void dfs1(int v, int par, int pe)
	{
		pre_dp[v].resize(G[v].size());
		
		rep(i, G[v].size()) {
			int u = G[v][i];
			if(u == par) {
				pre_dp[v][i] = dp[v];
				continue;
			}
			
			dp_sta cur = pre[v].back() - pre[v][i + 1] + pre[v][i];
			if(par != -1) cur = cur + pre_dp[par][pe];
			pre_dp[v][i] = cur.gen_rep();
			dfs1(u, v, i);
		}
		
		ret[v] = pre[v].back();
		if(par != -1) ret[v] = ret[v] + pre_dp[par][pe];
		ret[v] = ret[v].gen_rep();
		
		ans = ans + ret[v];
	}
	
	void input_t()
	{
		rep(i, n - 1) {
			int u, v;
			scanf("%d%d", &u, &v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
	}
}tr0, tr1;

LL power(LL b, LL t)
{
	t %= MOD - 1;
	if(t < 0) t += MOD - 1;
	LL ret = 1;
	while(t > 0) {
		if(t & 1) ret = ret * b % MOD;
		b = b * b % MOD;
		t >>= 1;
	}
	return ret;
}

LL comb(int n, int m)
{
	LL ret = 1;
	rep(i, m) {
		ret = ret * (n - i) % MOD;
		ret = ret * power(i + 1, -1) % MOD;
	}
	return ret;
}

int main()
{
	scanf("%d%d%d", &tr0.n, &tr1.n, &k);
	tr0.input_t();
	tr0.dfs0(1, -1);
	tr0.dfs1(1, -1, -1);
	tr1.input_t();
	tr1.dfs0(1, -1);
	tr1.dfs1(1, -1, -1);
	
	int ans = 0;
	
	for(int i = 0; i <= k; i ++)
	ans = (ans + comb(k, i) * (1LL * tr0.ans.dat[i] * tr1.ans.dat[k - i] % MOD)) % MOD;
	printf("%d\n", ans);
	return 0;
}