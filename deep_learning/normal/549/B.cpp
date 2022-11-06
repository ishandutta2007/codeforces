#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#define pb push_back
using namespace std; 
string arr[128]; 
int a[128], b[128];
int main()
{
	// freopen("549B.in", "r", stdin); 
	int n; 
	scanf("%d", &n); 
	for (int i = 0; i < n; i++)
		cin >> arr[i]; 
	for (int i = 0; i < n; i++)
		scanf("%d", a + i);
	vector<int> ans; 
	bool f; 
	do
	{
		f = false; 
		for (int i = 0; i < n; i++)
		{
			if (a[i] == b[i])
			{
				for (int j = 0; j < n; j++)
				{
					if (arr[i][j] == '1')
						b[j]++; 
				}
				ans.pb(i); 
				f = true; 
				break; 
			}
		}
	} while (f); 
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++)
		printf("%d ", ans[i] + 1);
	printf("\n");
	return 0; 
}