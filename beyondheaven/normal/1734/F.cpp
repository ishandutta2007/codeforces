#include <bits/stdc++.h>
using ll = long long;

ll f[64][2][2][2];
int main()
{
	int T; std::cin >> T;
	while(T--)
	{
		ll n, m; std::cin >> n >> m;
		memset(f, 0, sizeof(f));
		
		f[0][0][0][0] = 1;
		for(int i = 0; i < 63; ++i)
		for(int a : { 0, 1 }) for(int b : { 0, 1 }) for(int c : { 0, 1 })
		{
			for(int d : { 0, 1 })
			{
				int e = (d + b + ((n >> i) & 1));
				int g = (e & 1), h = (e >= 2);
				
				int j = ((m >> i) & 1), k = a;
				if(d < j) k = 1; if(d > j) k = 0;
				f[i + 1][k][h][c ^ d ^ g] += f[i][a][b][c];
			}
		}
		
		std::cout << f[63][1][0][1] << "\n";
	}
	return 0;
}