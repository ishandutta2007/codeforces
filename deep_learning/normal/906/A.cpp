#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#define mp make_pair
#define pb push_back
using namespace std; 
typedef long long ll; 
string tp[100005], str[100005]; 
int main()
{
#ifndef ONLINE_JUDGE
	freopen("906A.in", "r", stdin); 
#endif
	ios::sync_with_stdio(false); 
	cin.tie(0); 
	cout.tie(0); 
	int n; 
	cin >> n; 
	for (int i = 0; i < n; i++)
		cin >> tp[i] >> str[i]; 
	int l = 0, r = n - 1, ans = n - 1; 
	while (l <= r)
	{
		int m = l + r >> 1, cnt = 0; 
		for (int i = 0; i < 26; i++)
		{
			bool g = true; 
			for (int j = 0; j <= m && g; j++)
			{
				if (tp[j][0] == '!')
				{
					bool f = false; 
					for (int x = 0; x < str[j].size(); x++)
						f |= str[j][x] == i + 'a'; 
					if (!f)
						g = false; 
				}
				else if (tp[j][0] == '.')
				{
					bool f = true; 
					for (int x = 0; x < str[j].size(); x++)
						f &= str[j][x] != i + 'a'; 
					if (!f)
						g = false; 
				}
				else
				{
					if (j == n - 1 && i + 'a' != str[j][0])
						g = false; 
					else if (j != n - 1 && i + 'a' == str[j][0])
						g = false;
				}
			}
			cnt += g; 
		}
		if (cnt == 1)
		{
			ans = m; 
			r = m - 1; 
		}
		else
			l = m + 1; 
	}
	int cnt = 0; 
	for (int i = ans + 1; i < n - 1; i++)
		cnt += tp[i][0] != '.'; 
	printf("%d\n", cnt);
	return 0; 
}