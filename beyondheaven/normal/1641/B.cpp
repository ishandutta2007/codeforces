#include <bits/stdc++.h>
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int T; std::cin >> T;
	while(T--)
	{
		int n; std::cin >> n;
		std::deque<int> a(n);
		for(int &x : a) std::cin >> x;
		
		std::map<int, int> mp;
		for(int x : a) ++mp[x];
		
		bool flag = true;
		for(auto p : mp) if(p.second % 2 == 1) flag = false;
		if(!flag) { std::cout << -1 << "\n"; continue; }
		
		std::vector<std::pair<int, int>> opt;
		std::vector<int> len;
		
		int pre = 0;
		while(a.size())
		{
			int t = std::find(a.begin() + 1, a.end(), a[0]) - a.begin();
			std::deque<int> b(a.begin() + t + 1, a.end());
			
			for(int i = 1, x = t; i < t; ++i)
			{
				opt.push_back({pre + ++x, a[i]});
				b.push_front(a[i]);
			}
			
			len.push_back(t * 2);
			pre += t * 2;
			a = b;
		}
		
		std::cout << opt.size() << "\n";
		for(auto p : opt) std::cout << p.first << " " << p.second << "\n";
		std::cout << len.size() << "\n";
		for(int x : len) std::cout << x << " ";
		std::cout << "\n";
	}
	return 0;
}