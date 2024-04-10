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
#include <cmath>
#include <set>
#include <map>
#define my_abs(x) ((x) < 0 ? -(x) : (x))
#define mp std::make_pair
#define pb push_back
#define X first
#define Y second
typedef long long ll; 
int nxt[5005]; 
bool vis[5005]; 
int main()
{
#ifndef ONLINE_JUDGE
	freopen("939A.in", "r", stdin); 
#endif
	int n; 
	scanf("%d", &n); 
	for (int i = 0; i < n; i++)
	{
		scanf("%d", nxt + i); 
		nxt[i]--; 
	}
	for (int i = 0; i < n; i++)
	{
		memset(vis, false, sizeof(vis)); 
		int cnt = 0, x = i; 
		while (!vis[x])
		{
			vis[x] = true; 
			cnt++; 
			x = nxt[x]; 
		}
		if (x == i && cnt == 3)
		{
			puts("YES"); 
			return 0; 
		}
	}
	puts("NO"); 
	return 0; 
}