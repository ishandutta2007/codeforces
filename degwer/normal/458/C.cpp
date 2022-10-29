#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
vector<int>dat[100001];
typedef pair<int, int>pii;
#define SIZE 16384
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
BIT bi1, bi2;
int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		if (zb == 0)za = 0;
		dat[za].push_back(zb);
	}
	for (int i = 0; i < 100001; i++)sort(dat[i].begin(), dat[i].end());
	set<int>se;
	for (int i = 1; i < 100001; i++)if (dat[i].size() >= 1)se.insert(i);
	int mini = 1050000000;
	int nows = 0;
	int nc = dat[0].size();
	for (int i = 1; i < 100001; i++)for (int j = 0; j < dat[i].size(); j++)nows += dat[i][j], nc++;
	for (int mok = 1; mok <= num; mok++)
	{
		if (nc >= mok)mini = min(mini, nows);
		else
		{
			int x = mok - nc;
			int beg = 0, end = 10100;
			if (bi1.get(end) >= x)
			{
				for (;;)
				{
					if (beg == end)break;
					int med = (beg + end + 1) / 2;
					if (bi1.get(med) >= x)end = med - 1;
					else beg = med;
				}
				mini = min(mini, nows + bi2.get(beg) + (x - bi1.get(beg))*(beg + 1));
			}
		}
		set<int>::iterator it = se.begin();
		for (;;)
		{
			if (it == se.end())break;
			int t = dat[*it][dat[*it].size() - 1];
			nows -= t;
			bi1.add(t, 1);
			bi2.add(t, t);
			nc--;
			dat[*it].pop_back();
			if (dat[*it].empty())se.erase(it++);
			else it++;
		}
	}
	printf("%d\n", mini);
}