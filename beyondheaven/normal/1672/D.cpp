#include <bits/stdc++.h>
const int MaxN = 2e5 + 5;

int n, a[MaxN], b[MaxN], c[MaxN];
int main()
{
	int T; std::cin >> T;
	while(T--)
	{
		std::cin >> n;
		std::fill(c + 1, c + n + 1, 0);
		for(int i = 1; i <= n; ++i) std::cin >> a[i];
		for(int i = 1; i <= n; ++i) std::cin >> b[i];
		
		bool ans = true;
		for(int i = 1, j = 1; i <= n; ++i)
		{
			if(b[i] == b[i - 1] && c[b[i]]) { --c[b[i]]; continue; }
			while(j <= n && a[j] != b[i]) ++c[a[j++]];
			if(j == n + 1) ans = false; else ++j;
		}
		std::cout << (ans ? "YES" : "NO") << "\n";
	}
	return 0;
}