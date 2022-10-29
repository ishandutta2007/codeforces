#include<stdio.h>
int d[3000];
int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)scanf("%d", &d[i]);
	int c = 0;
	for (int i = 0; i < num; i++)for (int j = i + 1; j < num; j++)if (d[i]>d[j])c++;
	if (c % 2 == 0)printf("%d\n", c + c);
	else printf("%d\n", c + c - 1);
}