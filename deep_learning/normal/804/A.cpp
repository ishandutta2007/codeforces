#include <iostream>
#include <cstdio>
using namespace std; 
int main()
{
	// freopen("A.in", "r", stdin); 
	int n; 
	scanf("%d", &n); 
	if (n & 1)
		printf("%d\n", n >> 1);
	else
		printf("%d\n", (n >> 1) - 1);
	return 0;
}