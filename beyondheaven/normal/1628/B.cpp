#include <bits/stdc++.h>
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int T; std::cin >> T;
	while(T--)
	{
		int n; std::cin >> n;
		std::set<std::string> S;
		std::vector<std::string> V(n);
		for(auto &str : V) std::cin >> str;
		
		bool ans = false;
		for(const auto &str : V)
		{
			if(str.size() == 1) ans = true;
			if(str.size() == 2)
			{
				if(str[0] == str[1]) ans = true;
				if(S.count({ str[1], str[0] })) ans = true;
			}
			if(str.size() == 3)
			{
				if(str[0] == str[2]) ans = true;
				if(S.count({ str[2], str[1], str[0] })) ans = true;
				if(S.count({ str[2], str[1] })) ans = true;
			}
			S.insert(str);
		}
		
		std::reverse(V.begin(), V.end());
		S.clear();
		
		for(const auto &str : V)
		{
			if(str.size() == 3 && S.count({ str[1], str[0] })) ans = true;
			S.insert(str); 
		}
		
		std::cout << (ans ? "YES" : "NO") << "\n";
	}
	return 0;
}