#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
typedef pair<int, int>pii;
#define SIZE 524288
#define INF 1000000000
class segtree
{
public:
	int seg[SIZE * 2];
	int conv[SIZE * 2];
	void init()
	{
		for (int i = 1; i < SIZE * 2; i++)conv[i] = INF;
	}
	pii merge(pii a, pii b)
	{
		pii r;
		r.first = a.first + b.first;
		if (b.second - b.first < a.second)r.second = b.second;
		else r.second = a.second + b.first;
		return r;
	}
	void update(int a, int b)
	{
		a += SIZE;
		seg[a] = 1, conv[a] = b;
		for (;;)
		{
			a /= 2;
			if (a == 0)break;
			pii z = merge(make_pair(seg[a * 2], conv[a * 2]), make_pair(seg[a * 2 + 1], conv[a * 2 + 1]));
			seg[a] = z.first, conv[a] = z.second;
		}
	}
	pii get(int beg, int end, int node, int lb, int ub)
	{
		if (ub < beg || end < lb)return make_pair(0, INF);
		if (beg <= lb&&ub <= end)return make_pair(seg[node], conv[node]);
		return merge(get(beg, end, node * 2, lb, (lb + ub) / 2), get(beg, end, node * 2 + 1, (lb + ub) / 2 + 1, ub));
	}
};
segtree tree;
int dat[SIZE];
int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)scanf("%d", &dat[i]);
	tree.init();
	vector<pii>zat;
	for (int i = 0; i < num; i++)zat.push_back(make_pair(dat[i], i));
	sort(zat.begin(), zat.end());
	set<pii>se;
	set<pii>::iterator it;
	int now = INF;
	for (int i = 0; i < num; i++)
	{
		int idx = lower_bound(zat.begin(), zat.end(), make_pair(dat[i], i)) - zat.begin();
		tree.update(idx, dat[i]);
		bool f = true;
		if (now == INF)
		{
			se.insert(make_pair(dat[i], i));
			set<pii>::iterator zit = se.end();
			zit--;
			if ((*zit).first >= -i)now = i, it = zit;
			f = false;
		}
		if (now == INF)printf("%d\n", -(i + 1));
		else
		{
			if (f)
			{
				if (dat[i] < (*it).first)now++;
				se.insert(make_pair(dat[i], i));
			}
			for (;;)
			{
				if (it == se.begin())break;
				it--;
				if ((*it).first >= -(now - 1))now--;
				else
				{
					it++;
					break;
				}
			}
			int beg = lower_bound(zat.begin(), zat.end(), (*it)) - zat.begin();
			pii ans = tree.get(beg, SIZE - 1, 1, 0, SIZE - 1);
			printf("%d\n", min(ans.second, -now + ans.first));
		}
		//printf("   %d    %d %d\n", now, (*it).first, (*it).second);
	}
}