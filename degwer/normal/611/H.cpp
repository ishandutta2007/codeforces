#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
#define SIZE 100
vector<int>pat[SIZE];
vector<int>cap[SIZE];
vector<int>rev[SIZE];
//vector<bool>ise[SIZE];
//vector<bool>isvl[SIZE];
void adde(int a, int b, int c)
{
	pat[a].push_back(b);
	pat[b].push_back(a);
	cap[a].push_back(c);
	cap[b].push_back(0);
	rev[a].push_back(pat[b].size() - 1);
	rev[b].push_back(pat[a].size() - 1);
}
int frv[SIZE], fre[SIZE];
bool flag[SIZE];
void dfs(int node)
{
	if (flag[node])return;
	flag[node] = true;
	for (int i = 0; i<pat[node].size(); i++)
	{
		if (cap[node][i]>0 && (!flag[pat[node][i]]))
		{
			frv[pat[node][i]] = node;
			fre[pat[node][i]] = i;
			dfs(pat[node][i]);
		}
	}
}
int nod;
//int flow=0;
int maxflow(int st, int go)
{
	int ret = 0;
	for (;;)
	{
		fill(flag, flag + nod, false);
		dfs(st);
		if (!flag[go])return ret;
		int mini = 1000000000;
		int now = go;
		for (;;)
		{
			if (now == st)break;
			int t = fre[now];
			now = frv[now];
			mini = min(mini, cap[now][t]);
		}
		ret += mini;
		//flow++;
		now = go;
		for (;;)
		{
			if (now == st)break;
			int t = fre[now];
			int nx = now;
			now = frv[now];
			cap[now][t] -= mini;
			cap[nx][rev[now][t]] += mini;
		}
	}
}
int dat[6][6];
int rem[6];
int pt[6];
int base[6];
typedef pair<int, int>pii;
#define SIZE 6
class unionfind
{
public:
	int par[SIZE];
	int ran[SIZE];
	int ren[SIZE];
	void init()
	{
		for (int i = 0; i<SIZE; i++)
		{
			par[i] = i;
			ran[i] = 0;
			ren[i] = 1;
		}
	}
	int find(int a)
	{
		if (a == par[a])return a;
		else return par[a] = find(par[a]);
	}
	void unite(int a, int b)
	{
		a = find(a);
		b = find(b);
		if (a == b)return;
		if (ran[a]>ran[b])
		{
			par[b] = a;
			ren[a] += ren[b];
		}
		else
		{
			par[a] = b;
			ren[b] += ren[a];
		}
		if (ran[a] == ran[b])ran[b]++;
	}
};
int mxdig;
bool isok = false;
vector<pii>ans;
void calc(vector<pii>vec)
{
	//for (int i = 0; i < vec.size(); i++)printf("%d %d  ", vec[i].first, vec[i].second); printf("\n");
	nod = 100;
	for (int i = 0; i < 100; i++)
	{
		pat[i].clear();
		cap[i].clear();
		rev[i].clear();
	}
	int d[6][6];
	for (int i = 0; i <= mxdig; i++)
	{
		for (int j = 0; j <= mxdig; j++)
		{
			if (i != j)d[i][j] = dat[i][j];
		}
	}
	for (int i = 0; i < vec.size(); i++)d[vec[i].first][vec[i].second]--, d[vec[i].second][vec[i].first]--;
	for (int i = 0; i <= mxdig; i++)
	{
		for (int j = i + 1; j <= mxdig; j++)
		{
			//printf("%d %d  %d\n", i, j, d[i][j]);
			if (d[i][j] < 0)return;
			adde(0, i * 6 + j + 1, d[i][j]);
			adde(i * 6 + j + 1, 50 + i, 1000000000);
			adde(i * 6 + j + 1, 50 + j, 1000000000);
		}
	}
	int mok = 0;
	for (int i = 0; i <= mxdig; i++)
	{
		adde(50 + i, 99, rem[i] - 1);
		mok += rem[i] - 1;
	}
	int fl = maxflow(0, 99);
	if (fl == mok)
	{
		isok = true;
		for (int i = 0; i < vec.size(); i++)ans.push_back(make_pair(base[vec[i].first], base[vec[i].second]));
		for (int i = 0; i <= mxdig; i++)
		{
			for (int j = i + 1; j <= mxdig; j++)
			{
				for (int k = 0; k < pat[i * 6 + j + 1].size(); k++)
				{
					if (pat[i * 6 + j + 1][k] == 50 + i)
					{
						for (int l = 0; l < 1000000000 - cap[i * 6 + j + 1][k]; l++)
						{
							ans.push_back(make_pair(pt[i]++, base[j]));
						}
					}
					if (pat[i * 6 + j + 1][k] == 50 + j)
					{
						for (int l = 0; l < 1000000000 - cap[i * 6 + j + 1][k]; l++)
						{
							ans.push_back(make_pair(base[i], pt[j]++));
						}
					}
				}
			}
		}
	}
}
void dfs(vector<pii>vec, int pt1, int pt2)
{
	if (isok)return;
	unionfind uf;
	uf.init();
	for (int i = 0; i < vec.size(); i++)uf.unite(vec[i].first, vec[i].second);
	int n1 = pt1, n2 = pt2 + 1;
	if (n2 == mxdig + 1)
	{
		n1++;
		n2 = n1 + 1;
	}
	if (n2 == mxdig + 1)
	{
		if (vec.size() == mxdig)
		{
			calc(vec);
		}
		return;
	}
	dfs(vec, n1, n2);
	if (uf.find(n1) != uf.find(n2))
	{
		vec.push_back(make_pair(n1, n2));
		dfs(vec, n1, n2);
	}
}
int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num - 1; i++)
	{
		string sa, sb;
		cin >> sa >> sb;
		dat[sa.size() - 1][sb.size() - 1]++;
		if (sa.size() != sb.size())dat[sb.size() - 1][sa.size() - 1]++;
	}
	for (int i = 1; i <= num; i++)
	{
		if (i <= 9)rem[0]++;
		else if (i <= 99)rem[1]++;
		else if (i <= 999)rem[2]++;
		else if (i <= 9999)rem[3]++;
		else if (i <= 99999)rem[4]++;
		else rem[5]++;
	}
	for (int i = 5; i >= 0; i--)
	{
		if (rem[i] > 0)
		{
			mxdig = i;
			break;
		}
	}
	if(mxdig==0)
	{
		for (int i = 0; i < num - 1; i++)printf("1 %d\n", i + 2);
		return 0;
	}
	pt[0] = 1, pt[1] = 10, pt[2] = 100, pt[3] = 1000, pt[4] = 10000, pt[5] = 100000;
	for (int i = 0; i < 6; i++)base[i] = pt[i];
	for (int i = 0; i < 6; i++)
	{
		pt[i]++;
		for (int j = 0; j < dat[i][i]; j++)
		{
			ans.push_back(make_pair(base[i], pt[i]++));
			rem[i]--;
			if (rem[i] <= 0)
			{
				printf("-1\n");
				return 0;
			}
		}
	}
	//for (int i = 0; i < ans.size(); i++)printf("%d %d\n", ans[i].first, ans[i].second);
	vector<pii>zv;
	dfs(zv, 0, 0);
	if (!isok)
	{
		printf("-1\n");
	}
	else
	{
		for (int i = 0; i < ans.size(); i++)printf("%d %d\n", ans[i].first, ans[i].second);
	}
}