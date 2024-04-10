#include <bits/stdc++.h>
const int MaxN = 2e5 + 5;
using ll = long long;

int n, a[MaxN], b[MaxN], nxt[MaxN], vis[MaxN];
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int T; std::cin >> T;
	while(T--)
	{
		std::cin >> n;
		for(int i = 1; i <= n; ++i) std::cin >> a[i];
		for(int i = 1; i <= n; ++i) std::cin >> b[i];
		for(int i = 1; i <= n; ++i) nxt[a[i]] = b[i];
		
		std::fill(vis + 1, vis + n + 1, 0);
		
		int tmp = 0;
		for(int i = 1; i <= n; ++i) if(!vis[i])
		{
			int x = i, len = 0;
			while(!vis[x]) { vis[x] = 1; ++len; x = nxt[x]; }
			tmp += len / 2;
		}
		
		ll ans = 0;
		for(int i = 1; i <= tmp; ++i) ans += (n - i + 1) - i;
		std::cout << ans * 2 << "\n";
	}
	return 0;
}