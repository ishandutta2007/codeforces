#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
int m[2500][2500];
typedef pair<int, int>pii;
vector<pii>dat[2500];
bool flag = true;
void calc(vector<int>v)
{
	if (!flag)return;
	int maxi = 0;
	for (int i = 0; i < v.size(); i++)
	{
		maxi = max(maxi, dat[v[i]][dat[v[i]].size() - 1].first);
	}
	if (maxi == 0)return;
	vector<vector<int> >vec;
	for (int i = 0; i < v.size(); i++)
	{
		vector<int>z;
		for (int j = dat[v[i]].size() - 1; j >= 0; j--)
		{
			if (dat[v[i]][j].first == maxi)z.push_back(dat[v[i]][j].second);
			else break;
			dat[v[i]].pop_back();
		}
		if (z.empty())
		{
			flag = false;
			return;
		}
		vec.push_back(z);
	}
	vector<bool>zf;
	for (int i = 0; i < v.size(); i++)zf.push_back(false);
	for (int i = 0; i < v.size(); i++)
	{
		if (!zf[i])
		{
			vector<bool>f;
			for (int j = 0; j < v.size(); j++)f.push_back(false);
			for (int j = 0; j < vec[i].size(); j++)
			{
				int low = lower_bound(v.begin(), v.end(), vec[i][j]) - v.begin();
				f[low] = true;
			}
			for (int j = 0; j < v.size(); j++)
			{
				if (!f[j])
				{
					if (vec[i] != vec[j])
					{
						flag = false;
						return;
					}
				}
			}
			vector<int>nv;
			for (int j = 0; j < v.size(); j++)
			{
				if (!f[j])nv.push_back(v[j]), zf[j] = true;
			}
			calc(nv);
		}
	}
}
int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)for (int j = 0; j < num; j++)scanf("%d", &m[i][j]);
	for (int i = 0; i < num; i++)
	{
		if (m[i][i] != 0)
		{
			printf("NOT MAGIC\n");
			return 0;
		}
		for (int j = 0; j < num; j++)
		{
			if (m[i][j] != m[j][i])
			{
				printf("NOT MAGIC\n");
				return 0;
			}
		}
	}
	for (int i = 0; i < num; i++)
	{
		vector<pii>v;
		for (int j = 0; j < num; j++)
		{
			v.push_back(make_pair(m[i][j], j));
		}
		sort(v.begin(), v.end());
		dat[i] = v;
	}
	vector<int>vec;
	for (int i = 0; i < num; i++)vec.push_back(i);
	calc(vec);
	if (flag)printf("MAGIC\n");
	else printf("NOT MAGIC\n");
}