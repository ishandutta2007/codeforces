#include <iostream>
#include <cstdio>
using namespace std; 
typedef long long ll; 
int main()
{
	// freopen("A.in", "r", stdin); 
	int n; 
	scanf("%d", &n); 
	for (int i = 1; i <= n; i++)
	{
		if (i == 1)
			printf("2\n");
		else
			printf("%lld\n", (ll)(i + 1) * (i + 1) * i - i + 1);
	}
	return 0; 
}