#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int num;
	scanf("%d", &num);
	int cnt = 0;
	vector<int>ans;
	for (int p = 1;; p++)
	{
		int now = p;
		for (;;)
		{
			if (now % 5 == 0)
			{
				now /= 5;
				cnt++;
			}
			else break;
		}
		if (cnt == num)ans.push_back(p);
		if (cnt > num)break;
	}
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++)
	{
		if (i != 0)printf(" ");
		printf("%d", ans[i]);
	}
	printf("\n");
}