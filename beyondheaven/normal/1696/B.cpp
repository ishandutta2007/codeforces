#include <bits/stdc++.h>
int main()
{
	int T; std::cin >> T;
	while(T--)
	{
		int n; std::cin >> n;
		std::deque<int> a(n);
		for(int i = 0; i < n; ++i) std::cin >> a[i];
		a.push_front(0); a.push_back(0);
		
		std::vector<int> b;
		for(int x : a)
		{
			if(!b.size() || (!!b.back()) != (!!x)) b.push_back(x);
		}
		
		std::cout << std::min(int(std::count(b.begin(), b.end(), 0) - 1), 2) << "\n";
	} 
	return 0;
}