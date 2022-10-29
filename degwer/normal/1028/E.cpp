#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll dat[805050];
ll ans[805050];
int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)scanf("%I64d", &dat[i]);
	for (int i = num; i < num + num + num + num; i++)dat[i] = dat[i - num];
	bool f = false;
	for (int i = num + num + num - 1; i >= 0; i--)
	{
		if (dat[i] > dat[(i + num - 1) % num])f = true, ans[i] = dat[i];
		else if (f)
		{
			if (ans[i + 1] > 1000000)ans[i] = ans[i + 1] + dat[i];
			else ans[i] = (1000000 / ans[i + 1] + 1)*ans[i + 1] + dat[i];
		}
	}
	if (!f)
	{
		if (dat[0] != 0)printf("NO\n");
		else
		{
			printf("YES\n");
			for (int i = 0; i < num; i++)printf("1 "); printf("\n");
		}
	}
	else
	{
		printf("YES\n");
		for (int i = 0; i < num; i++)printf("%I64d ", ans[i]); printf("\n");
	}
}