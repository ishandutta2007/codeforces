#include <iostream>
#include <cstdio>
#include <vector>
using namespace std; 
vector<int> arr[100005], nxt[100005]; 
int mx[100005]; 
int main()
{
	// freopen("777C.in", "r", stdin); 
	int n, m; 
	scanf("%d%d", &n, &m); 
	for (int i = 0; i < n; i++)
	{
		arr[i].resize(m); 
		for (int j = 0; j < m; j++)
			scanf("%d", &arr[i][j]); 
	}
	for (int i = 0; i < n; i++)
	{
		nxt[i].resize(m); 
		for (int j = 0; j < m; j++)
		{
			nxt[i][j] = max(i ? nxt[i - 1][j] : 0, i); 
			while (nxt[i][j] + 1 < n && arr[nxt[i][j]][j] <= arr[nxt[i][j] + 1][j])
				nxt[i][j]++; 
			mx[i] = max(mx[i], nxt[i][j]); 
		}
	}
	int q; 
	scanf("%d", &q); 
	while (q--)
	{
		int l, r; 
		scanf("%d%d", &l, &r); 
		printf("%s\n", mx[--l] >= --r ? "Yes" : "No");
	}
	return 0; 
}