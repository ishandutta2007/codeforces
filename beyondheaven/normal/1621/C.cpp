#include <bits/stdc++.h>
int cnt;

int query(int i)
{
	std::cout << "? " << i << "\n";
	std::cout.flush();
	int ans; std::cin >> ans;
	return ans;
}

int main()
{
	int T; std::cin >> T;
	while(T--)
	{
		cnt = 0;
		int n; std::cin >> n;
		
		std::vector<int> p(n + 1), vis(n + 1);
		
		for(int i = 1; i <= n; ++i) if(!p[i])
		{
			int cur = cnt;
			std::vector<int> s;
			
			while(true)
			{
				int u = query(i);
				s.push_back(u);
				if(!vis[u]) vis[u] = 1;
				else break;
			}
			
			for(int i = 0; i + 1 < int(s.size()); ++i) p[s[i]] = s[i + 1];
		}
		
		std::cout << "! ";
		for(int i = 1; i <= n; ++i) std::cout << p[i] << " ";
		std::cout << std::endl;
		std::cout.flush(); 
	}
}