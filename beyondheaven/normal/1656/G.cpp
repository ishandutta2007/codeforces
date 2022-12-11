#include <bits/stdc++.h>
const int MaxN = 2e5 + 5;

int n, a[MaxN], p[MaxN], f[MaxN];
std::vector<int> V[MaxN];

int find(int x) { return (f[x] == x ? x : (f[x] = find(f[x]))); }

int main()
{
	int T; std::cin >> T;
	while(T--)
	{
		std::cin >> n;
		for(int i = 1; i <= n; ++i) V[i].clear();
		for(int i = 1; i <= n; ++i) std::cin >> a[i], V[a[i]].push_back(i);
		
		int pos = 0, num = 0;
		for(int i = 1; i <= n; ++i) if(V[i].size() % 2) pos = i, ++num;
		
		int mid = (n + 1) / 2;
		if(num != n % 2 || V[pos] == std::vector<int>{mid})
		{
			std::cout << "NO" << "\n";
			continue;
		}
		
		std::cout << "YES" << "\n";
		
		std::deque<int> d;
		if(pos) d.push_back(V[pos].back()), V[pos].pop_back();
		
		for(int i = 1; i <= n; ++i)
		{
			while(!V[i].empty())
			{
				d.push_front(V[i].back()), V[i].pop_back();
				d.push_back(V[i].back()), V[i].pop_back();
			}
		}
		
		std::copy(d.begin(), d.end(), p + 1);
		if(n % 2 && p[mid] == mid)
		{
			for(int i = 1; i <= n; ++i) if(i != mid && a[p[i]] == a[p[mid]])
			{
				std::swap(p[i], p[mid]);
				break;
			}
		}
		
		std::iota(f + 1, f + n + 1, 1);
		for(int i = 1; i <= n; ++i) if(find(i) != find(p[i])) f[find(i)] = find(p[i]);
		
		for(int i = 1; i <= n; ++i) if(find(i) != find(n - i + 1))
		{
			std::swap(p[i], p[n - i + 1]);
			f[find(i)] = find(n - i + 1);
		}
		
		for(int i = 1; i < n; ++i) if(find(i) != find(i + 1))
		{
			std::swap(p[i], p[n - i + 1]);
			std::swap(p[i], p[i + 1]);
			std::swap(p[n - i + 1], p[n - i]);
			f[find(i)] = find(i + 1);
		}
		
		for(int i = 1; i <= n; ++i) std::cout << p[i] << " \n"[i == n];
	}
	return 0;
}