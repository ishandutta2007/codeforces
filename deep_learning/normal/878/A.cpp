#include <iostream>
#include <cstdio>
using namespace std; 
inline int calc(int a, char c, int b)
{
	switch (c)
	{
		case '&':
		return a & b; 
		case '^':
		return a ^ b; 
		case '|':
		return a | b; 
	}
	return -1; 
}
int main()
{
	// freopen("878A.in", "r", stdin); 
	int n, a = 0, b = 1023; 
	scanf("%d", &n); 
	for (int i = 0; i < n; i++)
	{
		char c; 
		int x; 
		scanf("%*c%c%d", &c, &x); 
		a = calc(a, c, x); 
		b = calc(b, c, x); 
	}
	printf("3\n& %d\n^ %d\n| %d\n", a | b, a & (b ^ 1023), a & b);
	return 0; 
}