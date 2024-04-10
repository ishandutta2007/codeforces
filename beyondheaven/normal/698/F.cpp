#include <bits/stdc++.h>
const int64_t Mod = 1e9 + 7;
const int MaxN = 1000123;

std::vector<int> w[MaxN];
int bel[MaxN], size[MaxN], cnt[MaxN], val[MaxN], rev[MaxN];
int64_t Fac[MaxN];

int main()
{
	int n; scanf("%d", &n);
	std::fill(bel + 1, bel + n + 1, 1);
	for(int i = 2; i <= n; ++i) if(w[i].empty())
	for(int j = i; j <= n; j += i) w[j].push_back(i), bel[j] *= i;
	
	for(int i = 1; i <= n; ++i) if(w[i].size() == 1 && bel[i] == i) ++cnt[n / i];
	
	for(int i = 1; i <= n; ++i) if(i * 2 > n && w[i].size() == 1 && bel[i] == i) bel[i] = 1;
	for(int i = 1; i <= n; ++i) ++size[bel[i]];
	
	for(int i = 1, v; i <= n; ++i)
	{
		scanf("%d", &v);
		if(v == 0) continue;
		
		if(bel[i] == 1 && bel[v] == 1)
		{
			if(val[i] && val[i] != v) return puts("0"), 0;
			if(rev[v] && rev[v] != i) return puts("0"), 0;
			if(!val[i]) --size[1];
			val[i] = v, rev[v] = i;
			continue;
		}
		else if(bel[i] == 1 || bel[v] == 1) return puts("0"), 0;
		
		if(w[i].size() != w[v].size()) return puts("0"), 0;
		for(int j = 0; j < static_cast<int>(w[i].size()); ++j)
		{
			if(n / w[i][j] != n / w[v][j]) return puts("0"), 0;
			if(val[w[i][j]] && val[w[i][j]] != w[v][j]) return puts("0"), 0;
			if(rev[w[v][j]] && rev[w[v][j]] != w[i][j]) return puts("0"), 0;
			if(!val[w[i][j]]) --cnt[n / w[i][j]];
			val[w[i][j]] = w[v][j], rev[w[v][j]] = w[i][j];
		}
		--size[bel[i]];
	}
	
	for(int i = Fac[0] = 1; i <= n; ++i) Fac[i] = Fac[i - 1] * i % Mod;
	int64_t ans = Fac[size[1]];
	for(int i = 2; i < n; ++i) ans = ans * Fac[cnt[i]] % Mod;
	for(int i = 2; i <= n; ++i) ans = ans * Fac[size[i]] % Mod;
	printf("%lld\n", ans);
	return 0;
}