#include <algorithm>
#include <iostream>
#include <utility>
#include <cstdio>
#include <bitset>
#define mp make_pair
using namespace std;
pair<int, int> app[15];  
bitset<5005> in[200005]; 
int arr[15][100005]; 
int main()
{
	// freopen("878D.in", "r", stdin); 
	int n, k, q; 
	scanf("%d%d%d", &n, &k, &q); 
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < 1 << 12; j++)
		{
			if (j & (1 << i))
				in[i].set(j); 
		}
		for (int j = 0; j < n; j++)
			scanf("%d", arr[i] + j);
	}
	int cur = k; 
	while (q--)
	{
		int tp, x, y; 
		scanf("%d%d%d", &tp, &x, &y); 
		x--; 
		y--; 
		if (tp == 1)
			in[cur++] = in[x] & in[y]; 
		else if (tp == 2)
			in[cur++] = in[x] | in[y]; 
		else
		{
			int cnt = 0; 
			for (int i = 0; i < k; i++)
				app[cnt++] = mp(arr[i][y], i); 
			sort(app, app + cnt); 
			int ans = 0; 
			for (int i = 0; i < k; i++)
			{
				ans |= 1 << app[i].second; 
				if (in[x][ans])
				{
					printf("%d\n", app[i].first);
					break; 
				}
			}
		}
	}
	return 0; 
}