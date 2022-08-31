#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 1e9 + 7;

namespace nt
{
	int inv[200005];
	void gen_inv(int maxn)
	{
		inv[1] = 1;
		for(int i = 2; i <= maxn; i ++)
		inv[i] = 1LL * (MOD - MOD / i) * inv[MOD % i] % MOD;
	}
	
	bool isp[200005];
	int mu[200005], phi[200005];
	int coef[200005];
	
	void gen_str(int maxn)
	{
		for(int i = 2; i <= maxn; i ++) isp[i] = true;
		rep1(i, maxn) phi[i] = i;
		for(int i = 2; i <= maxn; i ++) if(isp[i]) {
			phi[i] = i - 1;
			for(int j = i * 2; j <= maxn; j += i) {
				isp[j] = false;
				phi[j] -= phi[j] / i;
			}
		}
		
		mu[1] = 1;
		rep1(i, maxn) for(int j = i * 2; j <= maxn; j += i) mu[j] -= mu[i];
		
		gen_inv(maxn);
		rep1(i, maxn) {
			int cur = 1LL * i * inv[phi[i]] % MOD;
			for(int j = i; j <= maxn; j += i) coef[j] = (coef[j] + cur * mu[j / i]) % MOD;
			coef[i] = (coef[i] + MOD) % MOD;
		}
	}
};

struct segt
{
	int dat[524288];
	int tid[1048576];
	
	void modify(int id, int val)
	{
		dat[id] = val;
		tid[id + 524288] = id;
		id += 524288;
		while(id > 1) {
			id >>= 1;
			if(dat[tid[id << 1]] > dat[tid[id << 1 | 1]]) tid[id] = tid[id << 1 | 1];
			else tid[id] = tid[id << 1];
		}
	}
	
	int query(int l, int r)
	{
		int ret = l;
		l += 524288;
		r += 524288;
		while(l < r) {
			if((l & 1) && dat[ret] > dat[tid[l]]) ret = tid[l];
			if(!(r & 1) && dat[ret] > dat[tid[r]]) ret = tid[r];
			l = l + 1 >> 1;
			r = r - 1 >> 1;
		}
		if(l == r && dat[ret] > dat[tid[l]]) ret = tid[l];
		return ret;
	}
}tre;

int n;
vector<int> G[200005];
int perm[200005];

int pos[200005];
int dep[200005];
int ldfn[200005], rdfn[200005], dfo[400005], tot;

void dfs0(int v, int pre, int cd)
{
	dep[v] = cd;
	dfo[++ tot] = v;
	ldfn[v] = tot;
	rep(i, G[v].size()) {
		int u = G[v][i];
		if(u == pre) continue;
		dfs0(u, v, cd + 1);
		dfo[++ tot] = v;
	}
	rdfn[v] = tot;
}

void build_t()
{
	rep1(i, tot) tre.modify(i, dep[dfo[i]]);
}

int par[200005], sum[200005];
int imag_t(int ct, vector<int> vec)
{
	rep(i, vec.size()) vec[i] = ldfn[vec[i]];
	sort(vec.begin(), vec.end());
	
	for(int i = vec.size() - 1; i >= 1; i --)
	vec.push_back(ldfn[dfo[tre.query(vec[i - 1], rdfn[dfo[vec[i]]])]]);
	
	sort(vec.begin(), vec.end());
	vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
	rep(i, vec.size()) vec[i] = dfo[vec[i]];
	
	stack<int> cur;
	rep(i, vec.size()) {
		while(!cur.empty() && rdfn[vec[cur.top()]] < ldfn[vec[i]]) cur.pop();
		if(!cur.empty()) par[i] = cur.top();
		else par[i] = -1;
		cur.push(i);
	}
	
	rep(i, vec.size()) sum[i] = 0;
	for(int i = vec.size() - 1; i >= 0; i --) {
		if(perm[vec[i]] % ct == 0) sum[i] = (sum[i] + nt::phi[perm[vec[i]]]) % MOD;
		if(par[i] != -1) sum[par[i]] = (sum[par[i]] + sum[i]) % MOD;
	}
	
	int ans = 0;
	for(int i = vec.size() - 1; i >= 1; i --)
	ans = (ans + 1LL * sum[i] * (sum[0] - sum[i] + MOD) % MOD * (dep[vec[i]] - dep[vec[par[i]]])) % MOD;
	return ans;
}

int main()
{
	scanf("%d", &n);
	rep1(i, n) scanf("%d", &perm[i]);
	rep(i, n - 1) {
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	rep1(i, n) pos[perm[i]] = i;
	dfs0(1, 0, 0);
	build_t();
	
	nt::gen_str(n);
	
	int ans = 0;
	rep1(i, n) {
		vector<int> hv;
		for(int j = i; j <= n; j += i)  hv.push_back(pos[j]);
		ans = (ans + 1LL * nt::coef[i] * imag_t(i, hv)) % MOD;
	}
	
	printf("%d\n", ans * (1LL * nt::inv[n] * nt::inv[n - 1] * 2 % MOD) % MOD);
	return 0;
}