#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pii;
typedef pair<ll, pii>pi3;
#define INF 1000000000
#define INFFF 1000000000000000000LL
#define SIZE 524288
class segtree
{
public:
	int seg[SIZE * 2][4][4];
	int e[4][4];//P
	void merge(int node)
	{
		for (int i = 0; i < 4; i++)for (int j = 0; j < 4; j++)seg[node][i][j] = -INF;
		for (int i = 0; i < 4; i++)for (int j = 0; j < 4; j++)for (int k = 0; k < 4; k++)seg[node][i][k] = max(seg[node][i][k], seg[node * 2][i][j] + seg[node * 2 + 1][j][k]);
	}
	void initv(int node, ll t)//m[h
	{
		for (int j = 0; j < 4; j++)for (int k = 0; k < 4; k++)seg[node][j][k] = e[j][k];
		if (t > 0)seg[node][0][1] = seg[node][1][1] = 1;
		if (t < 0)seg[node][0][2] = seg[node][1][2] = seg[node][2][2] = 1;
	}
	void init(vector<ll>vec)
	{
		for (int i = 0; i < 4; i++)for (int j = 0; j < 4; j++)e[i][j] = -INF;
		e[0][0] = e[0][3] = e[1][3] = e[2][3] = e[3][3] = 0;
		for (int i = 0; i < vec.size(); i++)initv(i + SIZE, vec[i]);
		for (int i = vec.size(); i < SIZE; i++)initv(i + SIZE, 0);
		for (int i = SIZE - 1; i >= 1; i--)merge(i);
	}
	void update(int a, ll b)
	{
		a += SIZE;
		initv(a, b);
		for (;;)
		{
			a >>= 1;
			merge(a);
			if (a == 1)break;
		}
	}
};
segtree tree;
int main()
{
	int num;
	scanf("%d", &num);
	vector<ll>vec;
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		vec.push_back(z);
	}
	vector<ll>dat;
	dat.push_back(0);
	for (int i = 0; i < num - 1; i++)dat.push_back(vec[i + 1] - vec[i]);
	dat.push_back(0);
	tree.init(dat);
	int query;
	scanf("%d", &query);
	for (int p = 0; p < query; p++)
	{
		int za, zb, zc;
		scanf("%d%d%d", &za, &zb, &zc);
		dat[za - 1] += zc;
		dat[zb] -= zc;
		dat[0] = dat[num] = 0;
		tree.update(za - 1, dat[za - 1]);
		tree.update(zb, dat[zb]);
		printf("%d\n", tree.seg[1][0][3] + 1);
	}	
}