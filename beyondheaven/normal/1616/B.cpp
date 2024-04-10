#include <bits/stdc++.h>
int main()
{
	int T; std::cin >> T;
	while(T--)
	{
		std::string s; std::cin >> *new int >> s;
		std::string t;
		
		if(s.size() == 1) {std::cout << s << s << std::endl; continue;}
		if(s[0] <= s[1]) {std::cout << s[0] << s[0] << std::endl; continue;}
		
		char last = 'z';
		for(char c : s) if(c <= last) t += c, last = c;
		else break;
		std::cout << t;
		std::reverse(t.begin(), t.end());
		std::cout << t << std::endl;
	} 
	return 0;
}