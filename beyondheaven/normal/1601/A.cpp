#include <bits/stdc++.h>
void solve()
{
	int n; std::cin >> n;
	std::vector<int> a(n);
	for(int i = 0; i < n; ++i) std::cin >> a[i];
	
	if(*std::max_element(a.begin(), a.end()) == 0)
	{
		for(int i = 1; i <= n; ++i) printf("%d ", i);
		puts("");
		return;
	}
	
	std::vector<int> cnt(32);
	for(int x : a) for(int i = 0; i < 32; ++i) if((x >> i) & 1) ++cnt[i];
	
	std::sort(cnt.begin(), cnt.end());
	std::reverse(cnt.begin(), cnt.end());
	
	while(cnt.back() == 0) cnt.pop_back();
	int g = cnt.front();
	for(int x : cnt) g = std::__gcd(g, x);
	for(int i = 1; i <= n; ++i) if(g % i == 0) printf("%d ", i);
	puts("");
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int T; std::cin >> T;
	while(T--) solve();
	return 0;
}