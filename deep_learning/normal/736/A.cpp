#include <iostream>
#include <cstdio>
using namespace std; 
typedef long long ll; 
int main()
{
	// freopen("736A.in", "r", stdin); 
	ll n, a = 1, b = 2, c; 
	scanf("%lld", &n); 
	for (int i = 0; ; i++)
	{
		if (b > n)
		{
			printf("%d\n", i);
			return 0; 
		}
		c = a + b; 
		a = b; 
		b = c; 
	}
	return 0; 
}