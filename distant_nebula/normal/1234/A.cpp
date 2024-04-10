#include <cstdio>
int q, n, s;
int main()
{
	scanf("%d", &q);
	while(q--)
	{
		scanf("%d", &n);
		s=0;
		for(int i=1, a; i<=n; ++i) scanf("%d", &a), s+=a;
		printf("%d\n", s/n+(s%n!=0));
	}
	return 0;
}