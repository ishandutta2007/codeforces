#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int>pii;
int d[303030], rd[303030];
vector<pii>ans;
void sw(int s, int t)
{
	ans.push_back(make_pair(s + 1, t + 1));
	swap(rd[d[s]], rd[d[t]]);
	swap(d[s], d[t]);
}
int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)scanf("%d", &d[i]), d[i]--, rd[d[i]] = i;
	for (int i = num / 2; i < num; i++)
	{
		if (rd[i] < num / 2)sw(rd[i], num - 1);
		sw(rd[i], 0);
		sw(0, i);
	}
	for (int i = 0; i < num / 2; i++)
	{
		if (d[i] == i)continue;
		sw(i, num - 1), sw(rd[i], num - 1), sw(i, num - 1);
	}
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++)printf("%d %d\n", ans[i].first, ans[i].second);
}