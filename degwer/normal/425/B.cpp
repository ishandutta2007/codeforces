#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int mx, my;
int zm[100][100];
int map[100][100];
int mini = 1000;
int get(vector<int>v, int pt)
{
	int r = 0;
	for (int i = 0; i < v.size(); i++)r += min(v[i], pt - v[i]);
	return r;
}
void calc(vector<int>v, int pt, int gen)
{
	int x = get(v, pt);
	if (x > gen)return;
	if (pt == mx)
	{
		mini = min(mini, x);
		return;
	}
	for (int i = 0; i < my; i++)v[i] += map[pt][i];
	calc(v, pt + 1, gen);
	for (int i = 0; i < my; i++)v[i] -= map[pt][i];
	for (int i = 0; i < my; i++)v[i] += 1 - map[pt][i];
	if (pt != 0)calc(v, pt + 1, gen);
}
int main()
{
	int gen;
	scanf("%d%d%d", &mx, &my, &gen);
	if (mx < my)for (int i = 0; i < mx; i++)for (int j = 0; j < my; j++)scanf("%d", &zm[i][j]);
	else
	{
		swap(mx, my);
		for (int i = 0; i < my; i++)for (int j = 0; j < mx; j++)scanf("%d", &zm[j][i]);
	}
	vector<int>x,y;
	for (int i = 0; i < mx; i++)x.push_back(i);
	for (int j = 0; j < my; j++)y.push_back(j);
	random_shuffle(x.begin(), x.end());
	random_shuffle(y.begin(), y.end());
	for (int i = 0; i < mx; i++)for (int j = 0; j < my; j++)map[i][j] = zm[x[i]][y[j]];
	vector<int>v;
	v.resize(my);
	calc(v, 0, gen);
	if (mini == 1000)printf("-1\n");
	else printf("%d\n", mini);
}