#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#define mp make_pair
#define pb push_back
using namespace std; 
typedef long long ll; 
int arr[1005], n, m, c; 
inline void inp(int &x)
{
	scanf("%d", &x); 
}
inline void put(int idx, int x)
{
	printf("%d\n", idx);
	fflush(stdout); 
	arr[idx] = x; 
}
inline void chk()
{
	for (int i = 1; i <= n; i++)
	{
		if (arr[i] == -1 || arr[i] < arr[i - 1])
			return; 
	}
	exit(0); 
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("896B.in", "r", stdin); 
#endif
	memset(arr, -1, sizeof(arr)); 
	scanf("%d%d%d", &n, &m, &c); 
	while (m--)
	{
		int x; 
		inp(x); 
		if (x <= c >> 1)
		{
			for (int i = 1; i <= n; i++)
			{
				if (arr[i] == -1 || arr[i] > x)
				{
					put(i, x); 
					break; 
				}
			}
		}
		else
		{
			for (int i = n; i; i--)
			{
				if (arr[i] == -1 || arr[i] < x)
				{
					put(i, x); 
					break; 
				}
			}
		}
		chk(); 
	}
	return 0; 
}