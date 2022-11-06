#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define check(x) ((x) > 0 && (x) < 512)
using namespace std;
typedef long long ll;  
bitset<512> arr[512], cur[512][8], tmp[512][8]; 
int l[] = {4, 7, 5, 6, 3, 0, 1, 2}, r[] = {5, 6, 7, 4, 0, 2, 3, 1}; 
int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1}, dy[] = {0, 0, 1, -1, -1, 1, -1, 1}; 
inline bitset<512> shift(const bitset<512> &a, const int &cnt)
{
	return cnt > 0 ? a >> cnt : a << -cnt; 
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("750D.in", "r", stdin); 
#endif
	int n; 
	scanf("%d", &n); 
	cur[256][0].set(256); 
	arr[256].set(256); 
	for (int i = 0; i < n; i++)
	{
		// int ans = 0; 
		// for (int i = 0; i < 512; i++)
		// 	ans += arr[i].count(); 
		// printf("%d\n", ans);
		int t; 
		scanf("%d", &t); 
		for (int j = 0; j < 512; j++)
		{
			for (int k = 0; k < 8; k++)
				tmp[j][k].reset(); 
		}
		t--; 
		for (int j = 0; j < 8; j++)
		{
			for (int k = 0; k < 512; k++)
			{
				if (check(k + dx[j] * t + dx[l[j]]))
					tmp[k + dx[j] * t + dx[l[j]]][l[j]] |= shift(cur[k][j], dy[j] * t + dy[l[j]]); 
				if (check(k + dx[j] * t + dx[r[j]]))
					tmp[k + dx[j] * t + dx[r[j]]][r[j]] |= shift(cur[k][j], dy[j] * t + dy[r[j]]);
				for (int x = 0; x <= t; x++)
				{
					if (check(k + dx[j] * x))
						arr[k + dx[j] * x] |= dy[j] > 0 ? (cur[k][j] >> (dy[j] * x)) : (cur[k][j] << (-dy[j] * x)); 
				}
			}
		}
		for (int j = 0; j < 512; j++)
		{
			for (int k = 0; k < 8; k++)
			{
				// if (tmp[j][k].count())
				// 	cout << k << " " << tmp[j][k] << endl;
				cur[j][k] = tmp[j][k]; 
			}
		}
	}
	int ans = 0; 
	for (int i = 0; i < 512; i++)
		ans += arr[i].count(); 
	printf("%d\n", ans);
	return 0; 
}