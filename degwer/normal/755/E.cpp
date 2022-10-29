#include<stdio.h>
#include<vector>
#include<algorithm>
#include<stdlib.h>
using namespace std;
void no()
{
	printf("-1\n");
	exit(0);
}
int main()
{
	int num, kai;
	scanf("%d%d", &num, &kai);
	if (kai == 1 || kai >= 4)no();
	if (kai == 2)
	{
		if (num == 2)no();
		if (num == 3)no();
		if (num == 4)no();
		printf("%d\n", num - 1);
		for (int i = 1; i < num; i++)printf("%d %d\n", i, i + 1);
	}
	if (kai == 3)
	{
		if (num == 2)no();
		if (num == 3)no();
		printf("%d\n", 3 + (num - 4) * 2);
		printf("1 2\n");
		printf("2 3\n");
		printf("3 4\n");
		for (int i = 5; i <= num; i++)printf("%d %d\n%d %d\n", i, 2, i, 3);
	}
}