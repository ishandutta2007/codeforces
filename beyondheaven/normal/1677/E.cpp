#include <bits/stdc++.h>
const int MaxN = 2e5 + 5;
const int MaxQ = 1e6 + 5;
using ll = long long;

int n, a[MaxN], rev[MaxN], p[MaxN], idx[MaxN];
int q, L[MaxQ], R[MaxQ]; ll ans[MaxQ];
std::vector<int> V[MaxN];

int T;
ll c1[MaxN], c2[MaxN], c3[MaxN], c4[MaxN];

void add(ll c[], int x, ll v) { for(; x <= n; x += (x & -x)) c[x] += v; }
ll sum(ll c[], int x, ll v = 0) { for(; x; x -= (x & -x)) v += c[x]; return v; }

void modify(int l, int r, ll v)
{
	add(c1, l, v); add(c2, l, v * l);
	add(c1, r + 1, -v); add(c2, r + 1, -v * (r + 1));
	add(c3, l, v * (1 - T)); add(c4, l, v * l * (1 - T));
	add(c3, r + 1, -v * (1 - T)); add(c4, r + 1, -v * (r + 1) * (1 - T));
}

ll query(int l, int r, ll v = 0)
{
	v += T * ((r + 1) * sum(c1, r) - sum(c2, r));
	v -= T * (l * sum(c1, l - 1) - sum(c2, l - 1));
	v += (r + 1) * sum(c3, r) - sum(c4, r);
	v -= l * sum(c3, l - 1) - sum(c4, l - 1);
	return v;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	std::cin >> n >> q;
	for(int i = 1; i <= n; ++i) std::cin >> a[i], rev[a[i]] = i;
	
	for(int i = 1; i <= q; ++i)
	{
		std::cin >> L[i] >> R[i];
		V[L[i] - 1].push_back(i);
		V[R[i]].push_back(i);
	}
	
	a[0] = n + 1;
	std::vector<int> stk = {0};
	
	for(int i = 1; i <= n; ++i)
	{
		++T;
		while(!stk.empty() && a[stk.back()] < a[i])
		{
			int x = stk.back();
			int pre = stk[idx[x] - 1];
			if(pre + 1 <= p[x]) modify(pre + 1, std::min(p[x], x), -1);
			idx[x] = 0; stk.pop_back();
		}
		idx[i] = stk.size(); stk.push_back(i);
		
		for(int v = 1; v * a[i] <= n; ++v) if(rev[v] < i)
		{
			int x = rev[v * a[i]];
			if(!idx[x]) continue;
			int pre = stk[idx[x] - 1];
			if(pre + 1 <= p[x]) modify(pre + 1, std::min(p[x], x), -1);
			p[x] = std::max(p[x], rev[v]);
			if(pre + 1 <= p[x]) modify(pre + 1, std::min(p[x], x), 1);
		}
		
		for(int v = 1; v * v < a[i]; ++v) if(a[i] % v == 0)
		{
			int w = a[i] / v;
			if(rev[v] < i && rev[w] < i)
			{
				int pre = stk[idx[i] - 1];
				if(pre + 1 <= p[i]) modify(pre + 1, std::min(p[i], i), -1);
				p[i] = std::max(p[i], std::min(rev[v], rev[w]));
				if(pre + 1 <= p[i]) modify(pre + 1, std::min(p[i], i), 1);
			}
		}
		
		for(int t : V[i])
		if(i == L[t] - 1) ans[t] -= query(L[t], R[t]);
		else ans[t] += query(L[t], R[t]);
	}
	
	for(int i = 1; i <= q; ++i) std::cout << ans[i] << "\n";
	return 0;
}