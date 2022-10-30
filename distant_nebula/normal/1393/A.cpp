#include <cstdio>
#include <algorithm>
int T, n;
int main()
{
	scanf("%d", &T);
	while(T--) scanf("%d", &n), printf("%d\n", n/2+1);
	return 0;
}