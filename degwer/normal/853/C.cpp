#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pii;
#define DEP 19
class wavelettree
{
public:
	int lko[1000000];
	int rko[1000000];
	vector<int>rui[1000000];
	vector<ll>r2[1000000];
	int wpt;
	void makenode()
	{
		lko[wpt] = rko[wpt] = -1;
		rui[wpt].resize(1);
		r2[wpt].resize(1);
		wpt++;
		return;
	}
	void init(vector<pii>vec)
	{
		makenode();
		wpt = 1;
		for (int i = 0; i < vec.size(); i++)
		{
			int node = 0;
			for (int j = DEP - 1; j >= 0; j--)
			{
				if ((vec[i].first & (1 << j)) == 0)
				{
					rui[node].push_back(rui[node][rui[node].size() - 1]);
					if (lko[node] == -1)
					{
						lko[node] = wpt;
						makenode();
					}
					node = lko[node];
				}
				else
				{
					rui[node].push_back(rui[node][rui[node].size() - 1] + 1);
					if (rko[node] == -1)
					{
						rko[node] = wpt;
						makenode();
					}
					node = rko[node];
				}
				r2[node].push_back(r2[node][r2[node].size() - 1] + vec[i].second);
			}
		}
	}
	ll rangecount(int beg, int end, int lb, int ub, int node, int d)//[beg,end][lb,ub]l node=0, d=DEP
	{
		if (node == -1)return 0;
		if (lb == 0 && ub == (1 << d) - 1)return r2[node][end + 1] - r2[node][beg];
		int b0, b1, e0, e1;
		b0 = beg - rui[node][beg];
		b1 = rui[node][beg];
		e0 = end - rui[node][end + 1];
		e1 = rui[node][end + 1] - 1;
		if (ub < (1 << (d - 1)))
		{
			return rangecount(b0, e0, lb, ub, lko[node], d - 1);
		}
		else if ((1 << (d - 1)) <= lb)
		{
			return rangecount(b1, e1, lb - (1 << (d - 1)), ub - (1 << (d - 1)), rko[node], d - 1);
		}
		else
		{
			return rangecount(b0, e0, lb, (1 << (d - 1)) - 1, lko[node], d - 1) + rangecount(b1, e1, 0, ub - (1 << (d - 1)), rko[node], d - 1);
		}
	}
};
wavelettree tree;
int main()
{
	vector<pii>v;
	int num, query;
	scanf("%d%d", &num, &query);
	v.push_back(make_pair(0, 0));
	for (int i = 0; i < num; i++)
	{
		int x;
		scanf("%d", &x);
		v.push_back(make_pair(x, 1));
	}
	v.push_back(make_pair(0, 0));
	tree.init(v);
	for (int i = 0; i < query; i++)
	{
		int za, zb, zc, zd;
		scanf("%d%d%d%d", &za, &zc, &zb, &zd);
		int a[4] = { 0,za,zb + 1,num + 2 };
		int b[4] = { 0,zc,zd + 1,num + 2 };
		ll t[3][3];
		for (int j = 0; j < 2; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				t[j][k] = tree.rangecount(a[j], a[j + 1] - 1, b[k], b[k + 1] - 1, 0, DEP);
			}
		}
		t[2][0] = zc - 1 - t[1][0] - t[0][0];
		t[2][1] = zd - zc + 1 - t[1][1] - t[0][1];
		t[0][2] = za - 1 - t[0][1] - t[0][0];
		t[1][2] = zb - za + 1 - t[1][1] - t[1][0];
		t[2][2] = num - zb - t[2][1] - t[2][0];
		ll r = t[1][1] * num;
		r += t[0][0] * (t[1][1] + t[1][2] + t[2][1] + t[2][2]);
		r += t[0][2] * (t[1][1] + t[1][0] + t[2][1] + t[2][0]);
		r += t[2][0] * (t[1][1] + t[1][2] + t[0][1] + t[0][2]);
		r += t[2][2] * (t[1][1] + t[1][0] + t[0][1] + t[0][0]);
		r += t[0][1] * (num - t[0][0] - t[0][1] - t[0][2]);
		r += t[1][0] * (num - t[0][0] - t[1][0] - t[2][0]);
		r += t[2][1] * (num - t[2][0] - t[2][1] - t[2][2]);
		r += t[1][2] * (num - t[0][2] - t[1][2] - t[2][2]);
		printf("%I64d\n", (r - t[1][1]) / 2);
	}
}