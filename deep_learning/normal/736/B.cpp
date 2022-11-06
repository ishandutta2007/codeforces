#include <iostream>
#include <cstdio>
using namespace std; 
inline bool check(int n)
{
	for (int i = 2; i * i <= n; i++)
	{
		if (!(n % i))
			return false; 
	}
	return true; 
}
int main()
{
	// freopen("B.in", "r", stdin); 
	int n; 
	scanf("%d", &n); 
	if (check(n))
		printf("1\n");
	else if ((n & 1 ^ 1) || check(n - 2))
		printf("2\n");
	else
		printf("3\n");
	return 0; 
}