#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define SIZE 3000
class unionfind
{
public:
	int par[SIZE];
	int ran[SIZE];
	int ren[SIZE];
	int dat[SIZE];
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
			dat[a] += dat[b];
		}
		else
		{
			par[a] = b;
			ren[b] += ren[a];
			dat[b] += dat[a];
		}
		if (ran[a] == ran[b])ran[b]++;
	}
};
unionfind uf;
typedef pair<int, int>pii;
typedef pair<int, pii>pi3;
int main()
{
	int num;
	scanf("%d", &num);
	if (num == 1)
	{
		printf("0\n");
		return 0;
	}
	vector<pi3>vec;
	for (int i = 0; i < num - 1; i++)
	{
		int za, zb, zc;
		scanf("%d%d%d", &za, &zb, &zc);
		vec.push_back(make_pair(zc, make_pair(za - 1, zb - 1)));
	}
	sort(vec.begin(), vec.end());
	uf.init();
	int sum = 0;
	for (int i = 0; i < num; i++)scanf("%d", &uf.dat[i]), sum += uf.dat[i];
	int ans = vec[0].first;
	for (int i = 0; i < num - 1; i++)
	{
		uf.unite(vec[i].second.first, vec[i].second.second);
		bool f = true;
		for (int j = 0; j < num; j++)
		{
			if (uf.find(j) == j)
			{
				if (sum - uf.dat[j] < uf.ren[j])f = false;
			}
		}
		if (f)ans = vec[i + 1].first;
	}
	printf("%d\n", ans);
}