#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define SIZE 262144
class BIT
{
public:
	int bit[SIZE + 1];
	void add(int a, int b)
	{
		a++;
		for (;;)
		{
			bit[a] += b;
			a += a&-a;
			if (a > SIZE)return;
		}
	}
	int get(int a)
	{
		a++;
		int ret = 0;
		for (;;)
		{
			ret += bit[a];
			a -= a&-a;
			if (a == 0)return ret;
		}
	}
};
BIT bi;
#define B 320
#define NB 320
int arr[120000];
vector<int>dat[120000];
typedef pair<int, int>pii;
typedef pair<pii, int>pi3;
vector<pi3>qs[NB];
int ans[100000];
int now[100000];
int sum = 0;
void add(int x)
{
	sum -= (0 < now[arr[x]]);
	now[arr[x]]++;
	sum += (0 < now[arr[x]]);
}
void del(int x)
{
	sum -= (0 < now[arr[x]]);
	now[arr[x]]--;
	sum += (0 < now[arr[x]]);
}
int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)scanf("%d", &arr[i]), arr[i]--, dat[arr[i]].push_back(i);
	vector<pi3>vec;
	for (int i = 0; i < 100000; i++)
	{
		if (dat[i].empty())continue;
		if (dat[i].size() == 1)
		{
			vec.push_back(make_pair(make_pair(0, dat[i][0]), -1));
			vec.push_back(make_pair(make_pair(dat[i][0] + 1, dat[i][0]), -2));
			vec.push_back(make_pair(make_pair(0, num), -2));
			vec.push_back(make_pair(make_pair(dat[i][0] + 1, num), -1));
			//printf("%d %d  %d %d\n", dat[i][0], dat[i][0], dat[i][0], dat[i][0]);
			continue;
		}
		int dif = -1;
		int st = 1;
		for (int j = 1; j <= dat[i].size(); j++)
		{
			if (j == dat[i].size() || dif != dat[i][j] - dat[i][j - 1])
			{
				int beg, end;
				if (st == 0)beg = 0;
				else beg = dat[i][st - 1] + 1;
				if (j == dat[i].size())end = num - 1;
				else end = dat[i][j] - 1;
				for (int k = st; k <= j - 1; k++)
				{
					vec.push_back(make_pair(make_pair(beg, dat[i][k]), -1));
					vec.push_back(make_pair(make_pair(dat[i][k] + 1, dat[i][k]), -2));
					vec.push_back(make_pair(make_pair(beg, end + 1), -2));
					vec.push_back(make_pair(make_pair(dat[i][k] + 1, end + 1), -1));
					//printf("%d %d  %d %d\n", beg, dat[i][k], dat[i][k], end);
				}
				if (j == dat[i].size())break;
				dif = dat[i][j] - dat[i][j - 1];
				st = j - 1;
			}
		}
	}
	int query;
	scanf("%d", &query);
	for (int i = 0; i < query; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		za--, zb--;
		qs[za / B].push_back(make_pair(make_pair(zb, za), i));
		vec.push_back(make_pair(make_pair(za, zb), i));
	}
	sort(vec.begin(), vec.end());
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i].second == -1)bi.add(vec[i].first.second, 1);
		else if (vec[i].second == -2)bi.add(vec[i].first.second, -1);
		else if (bi.get(vec[i].first.second) == 0)ans[vec[i].second] = 1;
	}
	for (int i = 0; i < NB; i++)
	{
		sum = 0;
		fill(now, now + 100000, 0);
		int lb = i*B, ub = i*B - 1;
		sort(qs[i].begin(), qs[i].end());
		for (int j = 0; j < qs[i].size(); j++)
		{
			for (int k = ub + 1; k <= qs[i][j].first.first; k++)add(k);
			ub = qs[i][j].first.first;
			if (lb < qs[i][j].first.second)for (int k = lb; k < qs[i][j].first.second; k++)del(k);
			else for (int k = lb - 1; k >= qs[i][j].first.second; k--)add(k);
			lb = qs[i][j].first.second;
			ans[qs[i][j].second] += sum;
			//printf("%d %d %d\n", qs[i][j].first.second, qs[i][j].first.first, sum);
		}
	}
	for (int i = 0; i < query; i++)printf("%d\n", ans[i]);
}