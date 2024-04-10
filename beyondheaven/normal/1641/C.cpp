#include <bits/stdc++.h>
const int MaxN = 2e5 + 5;

int n, q, c[MaxN];
void modify(int x, int v) { for(; x <= n; x += (x & -x)) c[x] = std::max(c[x], v); }
int query(int x, int v = 0) { for(; x; x -= (x & -x)) v = std::max(v, c[x]); return v; }

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	std::cin >> n >> q;
	std::set<int> S = {0, n + 1};
	for(int i = 1; i <= n; ++i) S.insert(i);
	
	while(q--)
	{
		int t; std::cin >> t;
		if(t == 0)
		{
			int l, r, x; std::cin >> l >> r >> x;
			if(x == 0) while(*S.lower_bound(l) <= r) S.erase(S.lower_bound(l));
			else modify(r, l);
		}
		else
		{
			int j; std::cin >> j;
			if(!S.count(j)) std::cout << "NO" << "\n";
			else
			{
				auto it = S.find(j);
				int pre = *std::prev(it), suf = *std::next(it);
				std::cout << (query(suf - 1) >= pre + 1 ? "YES" : "N/A") << "\n";
			} 
		}
	}
	return 0;
}