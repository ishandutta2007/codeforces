#include <bits/stdc++.h>
int main()
{
	int T; std::cin >> T;
	while(T--)
	{
		std::string s; std::cin >> s;
		int sum = 0, fail = (s.back() != 'B');
		for(char c : s) if((sum += (c == 'A' ? 1 : -1)) < 0) fail = 1;
		std::cout << (fail ? "NO" : "YES") << "\n";
	}
	return 0;
}