#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std; 
char t[200005], p[200005]; 
int arr[200005]; 
bool forbid[200005]; 
int main()
{
	// freopen("A.in", "r", stdin); 
	scanf("%s%s", t, p); 
	int n = strlen(t), m = strlen(p); 
	for (int i = 0; i < n; i++)
	{
		scanf("%d", arr + i); 
		arr[i]--; 
	}
	int l = 0, r = n - 1, ans = -1; 
	while (l <= r)
	{
		memset(forbid, false, sizeof(forbid)); 
		int mid = l + r >> 1, cur = 0; 
		for (int i = 0; i <= mid; i++)
			forbid[arr[i]] = true; 
		for (int i = 0; i < n; i++)
		{
			if (cur < m && !forbid[i] && t[i] == p[cur])
				cur++; 
		}
		if (cur >= m)
		{
			ans = mid; 
			l = mid + 1; 
		}
		else
			r = mid - 1; 
	}
	printf("%d\n", ans + 1);
	return 0; 
}