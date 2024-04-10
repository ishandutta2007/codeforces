#include<stdio.h>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
int siz = 100000000;
typedef pair<int, int>pii;
map<pii,int>ma;
int get(int x, int y)
{
	if (ma.count(make_pair(x, y)))return ma[make_pair(x, y)];
	printf("0 %d %d\n", x, y);
	fflush(stdout);
	int z;
	scanf("%d", &z);
	return ma[make_pair(x, y)] = z;
}
vector<int>ans;
void calc(int beg, int end, int lb, int ub)
{
	if (beg > end)return;
	int med = (beg + end) / 2;
	int z = get(med, med);
	if (z != med - lb&&z != ub - med)
	{
		if (beg <= med - z &&get(med - z, med - z) == 0)
		{
			ans.push_back(med - z);
			calc(beg, med - z - 1, lb, med - z);
			calc(med + z, end, med - z, ub);
		}
		else if (med + z <= end)
		{
			ans.push_back(med + z);
			calc(beg, med - z, lb, med + z);
			calc(med + z + 1, end, med + z, ub);
		}
	}
	else if (z == med - lb)
	{
		calc(med + 1, end, lb, ub);
	}
	else if (z == ub - med)
	{
		calc(beg, med - 1, lb, ub);
	}
}
vector<int>uni(vector<int>v)
{
	sort(v.begin(), v.end());
	int now = -siz - 1;
	vector<int>r;
	for (int i = 0; i < v.size(); i++)
	{
		if (now != v[i])now = v[i], r.push_back(now);
	}
	return r;
}
int main()
{
	ans.push_back(-siz + get(-siz, -siz));
	ans.push_back(siz - get(siz, siz));
	if (ans[0] != ans[1])
	{
		calc(ans[0] + 1, ans[1] - 1, ans[0], ans[1]);
	}
	else ans.pop_back();
	sort(ans.begin(), ans.end());
	int t;
	if (ans[0] != -siz)t = ans[0] - 1;
	else if (ans[ans.size() - 1] != siz)t = ans[ans.size() - 1] + 1;
	else
	{
		for (int i = 1; i < ans.size(); i++)if (ans[i] - ans[i - 1] >= 2)t = ans[i] - 1;
	}
	vector<int>rx, ry;
	for (int i = 0; i < ans.size(); i++)
	{
		if (get(ans[i], t) == 0)rx.push_back(ans[i]);
		if (get(t, ans[i]) == 0)ry.push_back(ans[i]);
	}
	rx = uni(rx), ry = uni(ry);
	printf("1 %d %d\n", rx.size(), ry.size()); fflush(stdout);
	for (int i = 0; i < rx.size(); i++)printf("%d ", rx[i]); printf("\n"); fflush(stdout);
	for (int i = 0; i < ry.size(); i++)printf("%d ", ry[i]); printf("\n"); fflush(stdout);
}