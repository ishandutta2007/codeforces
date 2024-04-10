#include <bits/stdc++.h>
int main()
{
	const int L = 200000;
	using u64 = unsigned long long;
	using u128 = __uint128_t;
	
	std::string s; std::cin >> s;
	auto it = std::find(s.begin(), s.end(), '1');
	if(it == s.end()) { std::cout << -1 << "\n"; exit(0); }
	
	int add = it - s.begin() + 1;
	std::cout << add << " ";
	if(std::count(s.begin(), s.end(), '1') == 1) { std::cout << add + 1 << "\n"; exit(0); }
	
	u128 P = 0; int h = 0;
	for(int i = 0; i < int(s.size()); ++i) if(s[i] == '1') P |= (u128(1) << i), h = i;
	
	auto mmod = [&](u128 a)
	{
		for(int i = 2 * h - 1; i >= h; --i) if((a >> i) & 1) a ^= (P << (i - h));
		return a;
	};
	
	auto mmul = [&](u128 a, u128 b)
	{
		u128 res = 0;
		for(int i = 0; i < h; ++i) if((a >> i) & 1) res ^= (b << i);
		return mmod(res);
	};
	
	std::unordered_map<u64, int> mp;
	
	u128 x = 1;
	for(int i = 0; i < L; ++i)
	{
		mp[u64(x)] = i;
		x = mmod(x << 1);
	}
	
	u128 y = 1;
	for(int i = 1; i <= L; ++i)
	{
		y = mmul(y, x);
		if(mp.count(u64(y))) { std::cout << 1LL * i * L - mp[u64(y)] + add << "\n"; break; }
	}
	return 0;
}