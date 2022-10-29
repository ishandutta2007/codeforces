#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int d[101010];
int main()
{
	int num, s;
	scanf("%d%d", &num, &s);
	for (int i = 0; i < num - 1; i++)
	{
		int z1,z2;
		scanf("%d%d", &z1, &z2);
		z1--, z2--, d[z1]++, d[z2]++;
	}
	int c = 0;
	for (int i = 0; i < num; i++)if (d[i] == 1)c++;
	printf("%.10lf\n", double(s) / double(c)*2.0);
}