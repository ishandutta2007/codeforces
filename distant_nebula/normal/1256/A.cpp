#include <cstdio>
#include <vector>
#include <algorithm>
#define ll long long
int T, a, b, n, s;
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d%d%d", &a, &b, &n, &s);
		puts((ll)a*n+b<(ll)s?"NO":b>=(s%n)?"YES":"NO");
	}
	return 0;
}