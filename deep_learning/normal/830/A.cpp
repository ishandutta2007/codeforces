#include <algorithm>
#include <iostream>
#include <cstdio>
#define my_abs(x) ((x) < 0 ? -(x) : (x))
using namespace std; 
int a[1005], b[2005]; 
int main()
{
	// freopen("A.in", "r", stdin); 
	int n, m, p; 
	scanf("%d%d%d", &n, &m, &p); 
	for (int i = 0; i < n; i++)
		scanf("%d", a + i); 
	for (int i = 0; i < m; i++)
		scanf("%d", b + i); 
	sort(a, a + n); 
	sort(b, b + m); 
	int ans = 2e9; 
	for (int i = 0; i <= m - n; i++)
	{
		int tot = 0; 
		for (int j = 0; j < n; j++)
			tot = max(tot, my_abs(a[j] - b[i + j]) + my_abs(b[i + j] - p)); 
		ans = min(ans, tot);
	}
	printf("%d\n", ans);
	return 0; 
}