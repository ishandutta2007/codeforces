#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>get(vector<int>v)
{
	vector<int>r;
	if (v.size() == 1)r.push_back(v[0]), r.push_back(-v[0]);
	else
	{
		int t = 0;
		for (int i = 0; i < v.size(); i++)t *= 10, t += v[i];
		r.push_back(t), r.push_back(-t);
		for (int i = 1; i <= v.size() - 1; i++)
		{
			vector<int>x, y;
			for (int j = 0; j < i; j++)x.push_back(v[j]);
			for (int j = i; j < v.size(); j++)y.push_back(v[j]);
			x = get(x), y = get(y);
			for (int j = 0; j < x.size(); j++)for (int k = 0; k < y.size(); k++)r.push_back(x[j] + y[k]), r.push_back(x[j] - y[k]), r.push_back(x[j] * y[k]);
		}
	}
	sort(r.begin(), r.end());
	vector<int>rr;
	int now = -1000000;
	for (int i = 0; i < r.size(); i++)if (now != r[i])now = r[i], rr.push_back(now);
	return rr;
}
vector<int>dat[10001];
bool f[100000000];
typedef pair<int, int>pii;
int main()
{
	int num, gen;
	scanf("%d%d", &num, &gen);
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k < 10; k++)
			{
				for (int l = 0; l < 10; l++)
				{
					vector<int>z;
					z.push_back(i);
					z.push_back(j);
					z.push_back(k);
					z.push_back(l);
					vector<int>v = get(z);
					for (int m = 0; m < v.size(); m++)if (0 <= v[m] && v[m] <= 10000)dat[v[m]].push_back(i * 1000 + j * 100 + k * 10 + l);
				}
			}
		}
	}
	vector<pii>v;
	for (int i = 0; i <= 10000; i++)
	{
		if (i + num <= 10000)v.push_back(make_pair(i, i + num)), v.push_back(make_pair(i + num, i));
		if (0 <= num - i)v.push_back(make_pair(i, num - i)), v.push_back(make_pair(num - i, i));
	}
	int pt = 0;
	for (int i = 0; i < v.size(); i++)
	{
		int x = v[i].first, y = v[i].second;
		for (int j = 0; j < dat[x].size(); j++)
		{
			for (int k = 0; k < dat[y].size(); k++)
			{
				int t = dat[x][j] * 10000 + dat[y][k];
				if (!f[t])
				{
					f[t] = true;
					pt++;
					printf("%08d\n", t);
					if (pt == gen)return 0;
				}
			}
		}
	}
}