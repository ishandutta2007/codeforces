#include <iostream>
#include <cstdio>
using namespace std; 
int main()
{
	// freopen("A.in", "r", stdin); 
	int n, m, ans = 1e9; 
	scanf("%d%d", &n, &m); 
	for (int i = 0; i < m; i++)
	{
		int l, r; 
		scanf("%d%d", &l, &r); 
		ans = min(ans, r - l + 1); 
	}
	printf("%d\n", ans);
	for (int i = 0; i < n; i++)
		printf("%d%c", i % ans, " \n"[i + 1 == n]);
	return 0; 
}