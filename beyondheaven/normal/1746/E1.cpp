#include <bits/stdc++.h>
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	auto query = [&](const std::vector<int> &V)
	{
		std::cout << "? " << V.size();
		for(int x : V) std::cout << " " << x;
		std::cout << "\n";
		std::cout.flush();
		std::string s; std::cin >> s;
		return (s == "YES" ? true : false);
	};
	
	int n; std::cin >> n;
	auto solve = [&](auto self, std::vector<int> cand) -> void
	{
		int m = cand.size();
		if(m < 3)
		{
			for(int x : cand)
			{
				std::cout << "! " << x << "\n";
				std::cout.flush();
				std::string s; std::cin >> s;
				if(s == ":)") exit(0);
			}
		}
		
		if(query(std::vector<int>(cand.begin(), cand.begin() + m / 3)) == false)
		{
			if(query(std::vector<int>(cand.begin(), cand.begin() + m / 3)) == false)
			return self(self, std::vector<int>(cand.begin() + m / 3, cand.end()));
		}
		
		auto res = query(std::vector<int>(cand.begin() + m / 3, cand.begin() + 2 * (m / 3)));
		if(res) return self(self, std::vector<int>(cand.begin(), cand.begin() + 2 * (m / 3)));
		else
		{
			cand.erase(cand.begin() + m / 3, cand.begin() + 2 * (m / 3));
			return self(self, cand);
		}
	};
	
	std::vector<int> cand;
	for(int i = 1; i <= n; ++i) cand.push_back(i);
	solve(solve, cand);
}