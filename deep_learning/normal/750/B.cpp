#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;  
int main()
{
#ifndef ONLINE_JUDGE
	freopen("750B.in", "r", stdin); 
#endif
	int n, pos = 0; 
	scanf("%d", &n); 
	for (int i = 0; i < n; i++)
	{
		int t; 
		char str[8]; 
		scanf("%d%s", &t, str); 
		if (!pos && str[0] != 'S')
		{
			printf("NO\n");
			return 0; 
		}
		if (pos == 20000 && str[0] != 'N')
		{
			printf("NO\n");
			return 0; 
		}
		if (str[0] == 'S')
			pos += t; 
		if (str[0] == 'N')
			pos -= t; 
		if (pos < 0 || pos > 20000)
		{
			printf("NO\n");
			return 0; 
		}
	}
	printf("%s\n", pos ? "NO" : "YES");
	return 0; 
}