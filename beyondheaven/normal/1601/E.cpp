#include <bits/stdc++.h>
const int MaxN = 300123;

int n, q, k, a[MaxN], b[MaxN], L[MaxN], R[MaxN];
int64_t c1[MaxN], c2[MaxN], ans[MaxN];

void Modify(int l, int r, int64_t v)
{
	auto add = [&](auto c, int x, auto v) {for(; x <= n; x += (x & -x)) c[x] += v;};
	add(c1, l, v); add(c1, r + 1, -v);
	add(c2, l, v * l); add(c2, r + 1, -v * (r + 1));
}

auto Query(int l, int r)
{
	int64_t res = 0;
	auto sum = [&](auto c, int x, auto v) {for(; x; x -= (x & -x)) res += c[x] * v;};
	sum(c1, r, r + 1); sum(c2, r, -1);
	sum(c1, l - 1, -l); sum(c2, l - 1, 1);
	return res;
}

std::vector<int> S[MaxN];
int main()
{
	scanf("%d%d%d", &n, &q, &k);
	for(int i = 1; i <= n; ++i) scanf("%d", a + i);
	
	std::deque<int> V;
	for(int i = 1; i <= n; ++i)
	{
		while(!V.empty() && a[V.back()] >= a[i]) V.pop_back();
		V.push_back(i);
		if(V.front() < i - k) V.pop_front();
		b[i] = a[V.front()];
	}

	for(int i = 1; i <= q; ++i) scanf("%d%d", L + i, R + i), S[L[i]].push_back(i);
	
	for(int z = 0; z < k; ++z)
	{
		std::vector<int> V = {0};
		for(int i = (z == 0 ? k : z); i <= n; i += k) V.push_back(i);
		
		int m = V.size() - 1;
		std::fill(c1, c1 + m + 1, 0);
		std::fill(c2, c2 + m + 1, 0);
		
		std::vector<int> stk;
		for(int i = m; i; --i)
		{
			for(int x : S[V[i]])
			{
				int t = (R[x] - L[x]) / k;
				ans[x] = a[L[x]] + (t ? Query(i + 1, i + t) : 0);
			}
			
			while(!stk.empty() && b[V[stk.back()]] >= b[V[i]])
			{
				int t = stk.back(); stk.pop_back();
				Modify(t, (stk.empty() ? m : stk.back() - 1), b[V[i]] - b[V[t]]);
			}
			stk.push_back(i);
			Modify(i, i, b[V[i]]);
		}
	}
	
	for(int i = 1; i <= q; ++i) printf("%lld\n", ans[i]);
	return 0;
}