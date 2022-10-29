#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int getd(int a)
{
	int ret = 0;
	for (;;)
	{
		if (a == 0)return ret;
		ret++;
		a /= 7;
	}
}
int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	int da = max(1,getd(a - 1)), db = max(1,getd(b - 1));
	if (da + db >= 8)
	{
		printf("0\n");
		return 0;
	}
	int ans = 0;
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			int c[7];
			fill(c, c + 7, 0);
			int ta = i, tb = j;
			for (int k = 0; k < da; k++)
			{
				c[ta % 7]++;
				ta /= 7;
			}
			for (int k = 0; k < db; k++)
			{
				c[tb % 7]++;
				tb /= 7;
			}
			bool f = true;
			for (int k = 0; k < 7; k++)if (c[k]>1)f = false;
			if (f)ans++;
		}
	}
	printf("%d\n", ans);
}