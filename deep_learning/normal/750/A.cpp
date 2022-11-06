#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;  
int main()
{
#ifndef ONLINE_JUDGE
	freopen("750A.in", "r", stdin); 
#endif
	int n, k, sum = 0; 
	scanf("%d%d", &n, &k); 
	for (int i = 1; i <= n; i++)
	{
		if ((sum += 5 * i) + k > 240)
		{
			printf("%d\n", i - 1);
			return 0; 
		}
	}
	printf("%d\n", n);
	return 0; 
}