#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int num, gen;
	scanf("%d%d", &num, &gen);
	if (num*(num - 1) / 2 <= gen)printf("no solution\n");
	else for (int i = 0; i < num; i++)printf("0 %d\n", i);
}