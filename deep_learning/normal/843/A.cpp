#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <cstdio>
#include <cctype>
#include <vector>
#include <queue>
#include <map>
#include <set>
#define mp make_pair
#define pb push_back
using namespace std; 
typedef long long ll; 
bool vis[100005]; 
int arr[100005], app[100005], res[100005]; 
int main()
{
#ifndef ONLINE_JUDGE
	freopen("843A.in", "r", stdin); 
#endif
	int n; 
	scanf("%d", &n); 
	for (int i = 0; i < n; i++)
	{
		scanf("%d", arr + i); 
		app[i] = arr[i]; 
	}
	sort(app, app + n); 
	for (int i = 0; i < n; i++)
		arr[i] = lower_bound(app, app + n, arr[i]) - app; 
	int ans = 0; 
	for (int i = 0; i < n; i++)
	{
		if (vis[i])
			continue; 
		int cur = i; 
		while (!vis[cur])
		{
			vis[cur] = true; 
			cur = arr[cur]; 
		}
		ans++; 
	}
	printf("%d\n", ans);
	memset(vis, false, sizeof(vis)); 
	for (int i = 0; i < n; i++)
	{
		if (vis[i])
			continue; 
		int cur = i, len = 0; 
		while (!vis[cur])
		{
			vis[cur] = true; 
			res[len++] = cur; 
			cur = arr[cur]; 
		}
		printf("%d ", len);
		for (int j = 0; j < len; j++)
			printf("%d%c", res[j] + 1, " \n"[j + 1 == len]);
	}
	return 0; 
}