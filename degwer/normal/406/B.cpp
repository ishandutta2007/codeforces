#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int d[1000000];
int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		z--;
		d[z]++;
	}
	int cnt = 0;
	vector<int>ans, v;
	for (int i = 0; i < 500000; i++)
	{
		if (d[i] && d[999999 - i])cnt++;
		else if (d[i])ans.push_back(999999 - i);
		else if (d[999999 - i])ans.push_back(i);
		else v.push_back(i);
	}
	for (int i = 0; i < cnt; i++)ans.push_back(v[i]), ans.push_back(999999 - v[i]);
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++)printf("%d\n", ans[i] + 1);
}