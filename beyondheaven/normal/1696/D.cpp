#include <bits/stdc++.h>
const int MaxN = 2.5e5 + 5;
const int inf = 1e9;

struct node
{
	int val;
	node *ls, *rs;
	
	node(int l, int r): val(inf)
	{
		if(l == r) ls = rs = nullptr;
		else
		{
			int mid = (l + r) / 2;
			ls = new node(l, mid);
			rs = new node(mid + 1, r);
		}
	}
	
	void pushup() { val = std::min(ls -> val, rs -> val); }
	
	void update(int p, int v, int l, int r)
	{
		if(l == r) return val = v, void();
		int mid = (l + r) / 2;
		if(p <= mid) ls -> update(p, v, l, mid);
		else rs -> update(p, v, mid + 1, r);
		pushup();
	}
	
	int query(int ql, int qr, int l, int r)
	{
		if(ql <= l && r <= qr) return val;
		int mid = (l + r) / 2;
		if(ql <= mid && mid < qr) return std::min(ls -> query(ql, qr, l, mid),
			rs -> query(ql, qr, mid + 1, r));
		return (ql <= mid ? ls -> query(ql, qr, l, mid) : rs -> query(ql, qr, mid + 1, r));
	}
};

int n, a[MaxN], dp[MaxN], f[MaxN], g[MaxN];
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int T; std::cin >> T;
	while(T--)
	{
		std::cin >> n;
		for(int i = 1; i <= n; ++i) std::cin >> a[i];
		
		std::vector<int> stk;
		for(int i = 1; i <= n; ++i)
		{
			while(stk.size() && a[stk.back()] < a[i]) stk.pop_back();
			f[i] = (stk.size() ? stk.back() : 0);
			stk.push_back(i);
		}
		
		stk.clear();
		for(int i = 1; i <= n; ++i)
		{
			while(stk.size() && a[stk.back()] > a[i]) stk.pop_back();
			g[i] = (stk.size() ? stk.back() : 0);
			stk.push_back(i);
		}
		
		node *Tf = new node(1, n), *Tg = new node (1, n);
		
		std::vector<int> stkf, stkg;
		for(int i = 1; i <= n; ++i)
		{
			dp[i] = (i == 1 ? 0 : inf);
			
			int t = std::upper_bound(stkf.begin(), stkf.end(), f[i]) - stkf.begin();
			dp[i] = std::min(dp[i], 1 + Tf -> query(t + 1, n, 1, n));
			
			t = std::upper_bound(stkg.begin(), stkg.end(), g[i]) - stkg.begin();
			dp[i] = std::min(dp[i], 1 + Tg -> query(t + 1, n, 1, n));
			
			while(stkf.size() && a[stkf.back()] > a[i])
			{
				Tf -> update(stkf.size(), inf, 1, n);
				stkf.pop_back();
			}
			
			stkf.push_back(i);
			Tf -> update(stkf.size(), dp[i], 1, n);
			
			while(stkg.size() && a[stkg.back()] < a[i])
			{
				Tg -> update(stkg.size(), inf, 1, n);
				stkg.pop_back();
			}
			
			stkg.push_back(i);
			Tg -> update(stkg.size(), dp[i], 1, n);
		}
		
		std::cout << dp[n] << "\n";
	}
	return 0;
}