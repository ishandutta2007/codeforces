#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int h1, a1, d1, h2, a2, d2, h, a, d;
	scanf("%d%d%d%d%d%d%d%d%d", &h1, &a1, &d1, &h2, &a2, &d2, &h, &a, &d);
	int mini = 1000000000;
	for (int i = 0; i <= 200; i++)
	{
		for (int j = 0; j <= 100; j++)
		{
			int at = a1 + i, de = d1 + j;
			if (at <= d2)continue;
			int t = (h2 + (at - d2 - 1)) / (at - d2);
			int mh = t*max(0, a2 - de) + 1;
			mini = min(mini, i*a + j*d + max(0, mh - h1)*h);
		}
	}
	printf("%d\n", mini);
}