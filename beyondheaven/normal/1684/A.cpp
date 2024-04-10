#include <bits/stdc++.h>
int main()
{
	int T; std::cin >> T;
	while(T--)
	{
		std::string s; std::cin >> s;
		std::vector<int> a;
		for(char c : s) a.push_back(c - '0');
		
		int n = a.size();
		if(n == 2) std::cout << a[1] << "\n";
		else std::cout << *std::min_element(a.begin(), a.end()) << "\n";
	}
	return 0;
}