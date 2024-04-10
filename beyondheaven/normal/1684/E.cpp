#include <bits/stdc++.h>
const int MaxN = 1e5 + 5;

int n, k, a[MaxN];
int sum[MaxN * 4], cnt[MaxN * 4];

#define Mid ((L + R) / 2)
#define ls (k << 1)
#define rs (k << 1 | 1)

void build(int k, int L, int R)
{
	sum[k] = cnt[k] = 0;
	if(L == R) return;
	build(ls, L, Mid); build(rs, Mid + 1, R);
}

void modify(int p, int v, int k = 1, int L = 1, int R = n)
{
	if(L == R) return sum[k] += p * v, cnt[k] += v, void();
	if(p <= Mid) modify(p, v, ls, L, Mid);
	else modify(p, v, rs, Mid + 1, R);
	sum[k] = sum[ls] + sum[rs];
	cnt[k] = cnt[ls] + cnt[rs];
}

int query(int v, int k = 1, int L = 1, int R = n)
{
	if(L == R) return std::min(v / L, cnt[k]);
	if(v >= sum[ls]) return cnt[ls] + query(v - sum[ls], rs, Mid + 1, R);
	else return query(v, ls, L, Mid);
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int T; std::cin >> T;
	while(T--)
	{
		std::map<int, int> mp;
		std::cin >> n >> k;
		for(int i = 1; i <= n; ++i) std::cin >> a[i], ++mp[a[i]];
		
		build(1, 1, n);
		for(const auto &p : mp) modify(p.second, 1);
		
		int ans = n, vis = 0;
		for(int mex = 0; mex <= n; ++mex)
		{
			int diff = query(n) - query(k) + mex;
			ans = std::min(ans, diff - mex);
			
			if(!mp.count(mex)) ++vis;
			else modify(mp[mex], -1);
			if(vis > k) break;
		}
		std::cout << ans << "\n";
	}
	return 0;
}