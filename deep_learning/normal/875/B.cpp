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
bool vis[300005]; 
int main()
{
#ifndef ONLINE_JUDGE
	freopen("875B.in", "r", stdin); 
#endif
	int n; 
	scanf("%d", &n); 
	printf("1 ");
	int idx = n; 
	for (int i = 0; i < n; i++)
	{
		int x; 
		scanf("%d", &x); 
		vis[--x] = true; 
		while (idx > 0 && vis[idx - 1])
			idx--; 
		printf("%d%c", i + 2 - n + idx, " \n"[i + 1 == n]);
	}
	return 0; 
}