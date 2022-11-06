#include <iostream>
#include <cstdio>
#include <map>
using namespace std; 
map<int, int> app; 
int arr[102400], fa[102400], num[102400], res[102400]; 
int getfa(int x)
{
	if (x == fa[x])
		return x; 
	return fa[x] = getfa(fa[x]); 
}
void unite(int x, int y)
{
	fa[getfa(x)] = getfa(y); 
}
int main()
{
	// freopen("468B.in", "r", stdin); 
	int n, a, b; 
	scanf("%d%d%d", &n, &a, &b); 
	for (int i = 0; i < n; i++)
	{
		scanf("%d", arr + i); 
		app[arr[i]] = i; 
	}
	for (int i = 0; i < n; i++)
		fa[i] = i; 
	for (int i = 0; i < n; i++)
	{
		if (app.count(a - arr[i]))
		{
			unite(i, app[a - arr[i]]); 
			num[i] |= 1; 
		}
		if (app.count(b - arr[i]))
		{
			unite(i, app[b - arr[i]]); 
			num[i] |= 2; 
		}
		res[i] = 3; 
	}
	for (int i = 0; i < n; i++)
		res[getfa(i)] &= num[i]; 
	for (int i = 0; i < n; i++)
	{
		if (!res[i])
		{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	for (int i = 0; i < n; i++)
		printf("%c%c", '0' + (res[getfa(i)] & 1 ^ 1), " \n"[i + 1 == n]);
	return 0; 
}