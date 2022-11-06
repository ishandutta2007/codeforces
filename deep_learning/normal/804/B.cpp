#include <iostream>
#include <cstring>
#include <cstdio>
#define MOD 1000000007
using namespace std; 
typedef long long ll; 
ll p[1000005]; 
char str[1000005]; 
int main()
{
	// freopen("B.in", "r", stdin); 
	p[0] = 1; 
	for (int i = 1; i < 1000005; i++)
		p[i] = p[i - 1] * 2 % MOD; 
	scanf("%s", str); 
	int n = strlen(str), b = 0, ans = 0; 
	for (int i = n - 1; i >= 0; i--)
	{
		if (str[i] == 'b')
			b = (b + 1) % MOD; 
		else
		{
			ans = (ans + b) % MOD; 
			b = b * 2 % MOD; 
		}
	}
	printf("%d\n", ans);
	return 0; 
}