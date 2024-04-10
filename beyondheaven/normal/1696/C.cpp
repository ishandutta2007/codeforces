#include <bits/stdc++.h>
int main()
{
	int T; std::cin >> T;
	while(T--)
	{
		int n, m; std::cin >> n >> m;
		std::vector<int> a(n);
		for(int &x : a) std::cin >> x;
		int k; std::cin >> k;
		std::vector<int> b(k);
		for(int &x : b) std::cin >> x;
		
		std::set<int> S;
		for(long long i = 1; i <= int(1e9); i *= m) S.insert(i);
		
		auto test = [&](int x, int y)
		{
			if(x < y) std::swap(x, y);
			return (x % y == 0 && S.count(x / y));
		};
		
		bool flag = true;
		while(a.size() && b.size())
		{
			int x = a.back(), y = b.back();
			if(!test(x, y)) { flag = false; break; }
			long long suma = 0, sumb = 0;
			while(a.size() && test(a.back(), x)) suma += a.back(), a.pop_back();
			while(b.size() && test(b.back(), y)) sumb += b.back(), b.pop_back();
			if(suma != sumb) { flag = false; break; }
		}
		
		if(flag && !a.size() && !b.size()) std::cout << "Yes" << "\n";
		else std::cout << "No" << "\n"; 
	}
	return 0;
}