#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define SIZE 400000
class unionfind
{
public:
	int par[SIZE];
	int ran[SIZE];
	int ren[SIZE];
	void init(int num)
	{
		for (int i = 0; i<SIZE; i++)
		{
			par[i] = i;
			ran[i] = 0;
		}
		for (int i = 0; i < num; i++)
		{
			ren[i*2] = 1;
			ren[i*2+1] = 0;
			ren[i*2 + num * 2] = 1;
			ren[i*2 + num * 2 + 1] = 0;
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
unionfind uf;
bool isok[400000];
int main()
{
	int num, way;
	scanf("%d%d", &num, &way);
	uf.init(num);
	for (int i = 0; i < way; i++)
	{
		int za, zb;
		char zc;
		scanf("%d%d %c", &za, &zb, &zc);
		za--;
		zb--;
		if (zc == 'R')
		{
			uf.unite(za * 2, zb * 2);
			uf.unite(za * 2 + 1, zb * 2 + 1);
			uf.unite(num * 2 + za * 2, num * 2 + zb * 2 + 1);
			uf.unite(num * 2 + za * 2 + 1, num * 2 + zb * 2);
		}
		else
		{
			uf.unite(za * 2, zb * 2 + 1);
			uf.unite(za * 2 + 1, zb * 2);
			uf.unite(num * 2 + za * 2, num * 2 + zb * 2);
			uf.unite(num * 2 + za * 2 + 1, num * 2 + zb * 2 + 1);
		}
	}
	vector<int>ans;
	int mini = 1000000000;
	for (int p = 0; p < 2; p++)
	{
		bool f = true;
		fill(isok, isok + num * 4, false);
		for (int i = 0; i < num; i++)
		{
			if (uf.find(p*num * 2 + i * 2) == uf.find(p*num * 2 + i * 2 + 1))f = false;
			if (uf.find(p*num * 2 + i * 2) == p*num * 2 + i * 2)
			{
				int t = p*num * 2 + i * 2, s = uf.find(p*num * 2 + i * 2 + 1);
				if (uf.ren[t] < uf.ren[s])isok[t] = true;
				else isok[s] = true;
			}
		}
		if (!f)continue;
		vector<int>v;
		for (int i = 0; i < num; i++)
		{
			if (isok[uf.find(i * 2 + p*num * 2)])v.push_back(i);
		}
		if (mini > v.size())
		{
			mini = v.size();
			ans = v;
		}
	}
	if (mini == 1000000000)
	{
		printf("-1\n");
		return 0;
	}
	printf("%d\n", mini);
	for (int i = 0; i < ans.size(); i++)
	{
		if (i != 0)printf(" ");
		printf("%d", ans[i] + 1);
	}
	printf("\n");
}