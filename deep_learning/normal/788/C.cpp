#include <iostream>
#include <cstdio>
#include <queue>
#include <map>
using namespace std; 
bool app[1005]; 
map<int, int> vis; 
int main()
{
	// freopen("C.in", "r", stdin); 
	int n, k; 
	scanf("%d%d", &n, &k); 
	for (int i = 0; i < k; i++)
	{
		int x; 
		scanf("%d", &x); 
		app[x] = true; 
	}
	queue<int> que; 
	que.push(0); 
	while (!que.empty())
	{
		int u = que.front(); 
		que.pop(); 
		if (!u && vis[u])
		{
			printf("%d\n", vis[u]);
			return 0; 
		}
		for (int i = 0; i <= 1000; i++)
		{
			if (app[i] && !vis[u + i - n] && u + i - n >= -1000 && u + i - n <= 1000)
			{
				vis[u + i - n] = vis[u] + 1; 
				que.push(u + i - n); 
			}
		}
	}
	printf("-1\n");
	return 0; 
}