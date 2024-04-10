#include <bits/stdc++.h>
const int MaxN = 2.5e5 + 5;
using ll = long long;

int vis[MaxN], deg[MaxN], rt[MaxN];
ll f[MaxN], g[MaxN], S[MaxN];
std::vector<std::array<int, 2>> G[MaxN];
std::vector<int> D[MaxN];
std::priority_queue<ll, std::vector<ll>, std::greater<>> Q[MaxN];
std::priority_queue<ll> cand[MaxN];

std::vector<ll> minimum_closure_costs(int n, std::vector<int> U, std::vector<int> V, std::vector<int> W)
{
	std::vector<ll> ans(n);
	for(int i = 0; i < n - 1; ++i)
	{
		++deg[U[i]]; ++deg[V[i]];
		G[U[i]].push_back({V[i], W[i]});
		G[V[i]].push_back({U[i], W[i]});
	}
	
	for(int i = 0; i < n - 1; ++i) ans[std::max(deg[U[i]], deg[V[i]])] += W[i];
	for(int k = 1; k < n; ++k) ans[k] += ans[k - 1];
	
	for(int i = 0; i < n; ++i)
	for(int k = 1; k < deg[i]; ++k) D[k].push_back(i);
	
	for(int i = 0; i < n; ++i)
	std::sort(G[i].begin(), G[i].end(), [&](auto a, auto b) { return deg[a[0]] > deg[b[0]]; });
	
	for(int k = 1; k < n; ++k)
	{
		for(int u : D[k])
		{
			while(int(Q[u].size()) < k && cand[u].size())
			{
				ll x = cand[u].top(); cand[u].pop();
				Q[u].push(x); S[u] += x;
			}
			
			while(G[u].size() && deg[G[u].back()[0]] <= k)
			{
				ll w = G[u].back()[1]; G[u].pop_back();
				if(int(Q[u].size()) < k) Q[u].push(w), S[u] += w;
				else
				{
					cand[u].push(w);
					ll x = Q[u].top(); Q[u].pop(); S[u] -= x;
					ll y = cand[u].top(); cand[u].pop();
					Q[u].push(std::max(x, y)); S[u] += std::max(x, y);
					cand[u].push(std::min(x, y)); 
				}
			}
			
			if(Q[u].size() && cand[u].size()) assert(Q[u].top() >= cand[u].top());
		}
		
		auto dfs = [&](auto &&self, int u, int p) -> void
		{
			vis[u] = k;
			
			ll add = 0;
			std::vector<ll> V;
			for(auto e : G[u]) if(e[0] != p)
			{
				self(self, e[0], u);
				add += f[e[0]];
				ll t = e[1] + g[e[0]] - f[e[0]];
				if(t > 0) V.push_back(t);
			}
			
			assert(int(Q[u].size()) <= k);
			
			std::sort(V.begin(), V.end(), std::greater<>());
			
			f[u] = add + S[u];
			g[u] = add + S[u] - (int(Q[u].size()) == k ? Q[u].top() : 0);
			
			ll pre = 0;
			std::vector<ll> del;
			for(int i = 1; i <= std::min(int(V.size()), k); ++i)
			{
				pre += V[i - 1];
				if(int(Q[u].size()) > k - i)
				{
					ll x = Q[u].top(); Q[u].pop(); S[u] -= x;
					del.push_back(x);
				}
				
				assert(int(Q[u].size()) + i <= k);
				
				f[u] = std::max(f[u], add + pre + S[u]);
				if(i < k) g[u] = std::max(g[u], add + pre + S[u] - (int(Q[u].size()) == k - i ? Q[u].top() : 0));
			}
			
			for(ll x : del) Q[u].push(x), S[u] += x;
		};
		
		for(int u : D[k]) if(vis[u] != k) dfs(dfs, u, -1), ans[k] += f[u];
	}
	
	ll tot = 0;
	for(int i = 0; i < n - 1; ++i) tot += W[i];
	for(int i = 0; i < n; ++i) ans[i] = tot - ans[i];
	return ans;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n; std::cin >> n;
	std::vector<int> U(n - 1), V(n - 1), W(n - 1);
	for(int i = 0; i < n - 1; ++i)
	{
		std::cin >> U[i] >> V[i] >> W[i];
		--U[i]; --V[i];
	}
	for(ll x : minimum_closure_costs(n, U, V, W)) std::cout << x << " ";
	return 0;
}