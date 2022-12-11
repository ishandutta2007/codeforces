#include <bits/stdc++.h>
int main()
{
	std::vector<int> SG(500);
	for(int i = 1; i < 500; ++i)
	{
		std::set<int> mex;
		for(int j = 0; j <= i - 2; ++j) mex.insert(SG[j] ^ SG[i - 2 - j]);
		for(int j = 0; j <= i; ++j) if(!mex.count(j)) { SG[i] = j; break; }
	}
	
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int T; std::cin >> T;
	while(T--)
	{
		int n; std::cin >> n;
		std::string s; std::cin >> s;
		
		int cnt = 0;
		for(int i = 0; i < n; ++i)
		{
			if(s[i] == 'R') ++cnt;
			if(s[i] == 'B') --cnt;
		}
		
		if(cnt != 0) { std::cout << ((cnt > 0) ? "Alice" : "Bob") << "\n"; continue; }
		
		int ans = 0;
		for(int i = 0; i < n; )
		{
			int j = i;
			while(j + 1 < n && s[j] != s[j + 1]) ++j;
			int len = j - i + 1;
			while(len >= 500) len -= 34;
			ans ^= SG[len];
			i = j + 1;
		}
		
		std::cout << (ans ? "Alice" : "Bob") << "\n";
	}
	return 0;
}