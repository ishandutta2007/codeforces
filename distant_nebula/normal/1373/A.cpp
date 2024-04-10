#include <cstdio>
int T, a, b, c;
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d%d", &a, &b, &c);
		printf("%d %d\n", (a<c?1:-1), (1ll*a*b>c?b:-1));
	}
	return 0;
}