#include <cstdio>
#include <cstdlib>
int main()
{
	int n;
	scanf("%d", &n);
	if (n == 1)
	{
		printf("2\n");
	} else
	if (n == 2) //!2
	{
		printf("3\n");
	} else
	if (n == 3) //test 1
	{
		printf("1\n");
	} else
	if (n == 4) //!2
	{
		printf("2\n");
	} else
	if (n == 5)
	{
		printf("1\n");
	}
	return 0;
}