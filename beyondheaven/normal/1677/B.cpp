#include <bits/stdc++.h>
const int MaxN = 1e6 + 5;

int n, m, c[MaxN * 2];
void add(int x, int v) { for(++x; x <= 2 * m; x += (x & -x)) c[x] += v; }
int sum(int x, int v = 0) { for(++x; x; x -= (x & -x)) v += c[x]; return v; }

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int T; std::cin >> T;
	while(T--)
	{
		std::cin >> n >> m;
		std::fill(c + 1, c + 2 * m + 1, 0);
		
		std::vector<int> vis(m);
		
		int tmp = 0;
		for(int i = 1, last = 0; i <= n * m; ++i)
		{
			char c; std::cin >> c;
			int x = (c - '0');
			
			if(x == 1)
			{
				if(last)
				{
					if(i - last >= m) ++tmp;
					else if(last % m < i % m) add(last % m, 1), add(i % m, -1);
					else add(last % m, 1), add(i % m + m, -1); 
				}
				
				last = i;
				
				if(!vis[i % m]) vis[i % m] = 1, ++tmp;
			}
			
			std::cout << tmp + (!!last) + sum(i % m) + sum(i % m + m) << " ";
		}
		std::cout << "\n";
	}
	return 0;
}