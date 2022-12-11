#include <bits/stdc++.h>
int main()
{
	int T; std::cin >> T;
	while(T--)
	{
		int n; std::cin >> n;
		std::deque<int> a(n);
		for(int i = 0; i < n; ++i) std::cin >> a[i];
		
		int cnt = 0;
		for(int i = 0; i + 1 < n; ++i) cnt += (a[i] == a[i + 1]);
		if(cnt <= 1) { std::cout << 0 << "\n"; continue; }
		
		while(a[0] != a[1] || a.end()[-1] != a.end()[-2])
		if(a[0] != a[1]) a.pop_front();
		else if(a.end()[-1] != a.end()[-2]) a.pop_back();
		
		std::cout << std::max(int(a.size()) - 3, 1) << "\n";
	}
	return 0;
}