#include <iostream>
#include <cstdio>
using namespace std;
int arr[512]; 
bool adj[512][512], vis[512]; 
int main()
{
	// freopen("500B.in", "r", stdin); 
	int n; 
	scanf("%d", &n); 
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i); 
	for (int i = 0; i < n; i++)
	{
		scanf("%*c"); 
		for (int j = 0; j < n; j++)
		{
			char c; 
			scanf("%c", &c); 
			adj[i][j] = c == '1'; 
		}
	}
	for (int i = 0; i < n; i++)
		adj[i][i] = true; 
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				adj[i][j] |= adj[i][k] & adj[k][j]; 
		}
	}
	// for (int i = 0; i < n; i++)
	// {
	// 	for (int j = 0; j < n; j++)
	// 		printf("%d%c", adj[i][j], " \n"[j + 1 == n]);
	// }
	for (int i = 0; i < n; i++)
	{
		int mn = arr[i], pos = i; 
		for (int j = 0; j < n; j++)
		{
			if (adj[i][j] && !vis[arr[j]] && arr[j] < mn)
			{
				mn = arr[j];
				pos = j; 
			}
		}
		vis[mn] = true;
		swap(arr[i], arr[pos]);  
	}
	for (int i = 0; i < n; i++)
		printf("%d%c", arr[i], " \n"[i + 1 == n]);
	return 0; 
}