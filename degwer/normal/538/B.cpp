#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	scanf("%d", &n);
	vector<int>d;
	for (;;)
	{
		if (n == 0)break;
		d.push_back(n % 10);
		n /= 10;
	}
	reverse(d.begin(), d.end());
	vector<int>ans;
	for (int i = 0; i < 9; i++)
	{
		int t = 0;
		for (int j = 0; j < d.size(); j++)
		{
			t *= 10;
			if (d[j] != 0)
			{
				d[j]--;
				t++;
			}
		}
		if (t != 0)ans.push_back(t);
	}
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++)
	{
		if (i != 0)printf(" ");
		printf("%d", ans[i]);
	}
	printf("\n");
}