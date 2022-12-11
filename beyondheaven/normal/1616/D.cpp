#include <bits/stdc++.h>
#define int int64_t
struct data
{
	int add;
	std::multiset<int> s;
	
	void clear() {s.clear(); add = 0;}
	data() {clear();}
	
	void insert(int x) {s.insert(x - add);}
	void modify(int x) {add += x;}
	int get() {return add + *s.begin();}
	int size() {return s.size();}
};

signed main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int T; std::cin >> T;
	while(T--)
	{
		int n, x, ans = 0; std::cin >> n; std::vector<int> a(n);
		for(int i = 0; i < n; ++i) std::cin >> a[i];
		data S;
		
		std::cin >> x;
		for(int i = 0; i < n; ++i)
		{
			if(S.size() && S.get() + a[i] - x < 0) S.clear();
			else ++ans, S.modify(a[i] - x), S.insert(a[i] - x);
		}
		
		std::cout << ans << "\n";
	}
	return 0;
}