#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int num, q;
	scanf("%d%d", &num, &q);
	int a = 1, b = num;
	for (int i = 0; i < q; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		a = max(a, min(za, zb));
		b = min(b, max(za, zb));
	}
	if (b - a <= 0)printf("0\n");
	else printf("%d\n", b - a);
}