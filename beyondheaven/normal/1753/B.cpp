#include <bits/stdc++.h>
const int MaxN = 5e5 + 5;

int n, x, cnt[MaxN];
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	std::cin >> n >> x;
	for(int i = 1, z; i <= n; ++i) std::cin >> z, cnt[z] += 1;
	
	for(int i = 1; i < x; ++i)
	{
		if(cnt[i] % (i + 1) != 0) { std::cout << "No" << "\n"; exit(0); }
		cnt[i + 1] += cnt[i] / (i + 1);
	}
	
	std::cout << "Yes" << "\n";
	return 0;	
}