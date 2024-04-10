#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
using namespace std;
typedef long double ld;
typedef pair<ld, ld>pdd;
typedef pair<pdd, int>pddi;
typedef pair<int, int>pii;
typedef pair<pii, int>pi3;
ld eps = 1e-12;
pdd get(pdd a, pdd b)
{
	ld x = (b.first - a.first) / (a.second - b.second);
	ld y = x*a.second + a.first;
	return make_pair(x, y);
}
bool isok[200000];
int main()
{
	int num;
	scanf("%d", &num);
	vector<pi3>zv;
	vector<pddi>vec;
	for (int i = 0; i < num; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		zv.push_back(make_pair(make_pair(za, zb), i));
	}
	sort(zv.begin(), zv.end());
	reverse(zv.begin(), zv.end());
	for (int i = 0; i < num; i++)vec.push_back(make_pair(make_pair((1.0 / (ld)zv[i].first.first) + eps*(1.0 / (ld)zv[i].first.second), 1.0 / (ld)zv[i].first.second), zv[i].second));
	vector<int>now;
	for (int i = 0; i < num; i++)
	{
		bool f = true;
		for (;;)
		{
			if (now.size() == 0)break;
			pdd z = vec[now[now.size() - 1]].first;
			if (z.second<vec[i].first.second + eps) { f = false; break; }
			if (now.size() <= 1)break;
			pdd t = vec[now[now.size() - 2]].first;
			if (get(t, z).first>eps + get(z, vec[i].first).first)
			{
				now.pop_back();
			}
			else break;
		}
		if (f)now.push_back(i);
	}
	fill(isok, isok + 200000, false);
	vector<int>ans;
	for (int i = 0; i < now.size(); i++)
	{
		isok[zv[now[i]].second] = true;
	}
	for (int i = 0; i < num - 1; i++)
	{
		if (zv[i].first == zv[i + 1].first)
		{
			if (isok[zv[i].second])isok[zv[i + 1].second] = true;
		}
	}
	for (int i = 0; i < num; i++)if (isok[i])ans.push_back(i);
	for (int i = 0; i < ans.size(); i++)
	{
		if (i != 0)printf(" ");
		printf("%d", ans[i] + 1);
	}
	printf("\n");
}