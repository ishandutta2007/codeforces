#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>pat[500000];
vector<int>rev[500000];
vector<bool>flag[500000];
int pt[500000];
void adde(int a, int b)//Ot
{
	pat[a].push_back(b);
	flag[a].push_back(false);
}
vector<int>euler;
void calceuler(int node)//eulerHeuler n_
{
	for (;;)
	{
		if (pt[node] == pat[node].size())break;
		if (!flag[node][pt[node]])
		{
			flag[node][pt[node]] = true;
			pt[node]++;
			calceuler(pat[node][pt[node] - 1]);
		}
		else pt[node]++;
	}
	euler.push_back(node);
}
#define SIZE 500000
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
unionfind uf;
int dat[204020];
int cnt[204020];
int kou[504020];
bool isok[204020];
int zat[202020];
int curr[202020];
void check(vector<vector<int> >v, int num)
{
	for (int p = 0; p < v.size(); p++)
	{
		vector<int>zi = v[p];
		int t = curr[zi[zi.size() - 1]];
		for (int i = 0; i < zi.size(); i++)
		{
			int s = curr[zi[i]];
			curr[zi[i]] = t;
			t = s;
		}
	}
	//for (int i = 0; i < num; i++)printf("%d ", curr[i]); printf("\n");
	for (int i = 0; i < num - 1; i++)if (curr[i]>curr[i + 1])abort();
}
int main()
{
	int num, gen;
	scanf("%d%d", &num, &gen);
	for (int i = 0; i < num; i++)scanf("%d", &dat[i]), zat[i] = curr[i] = dat[i];
	sort(zat, zat + num);
	for (int i = 0; i < num; i++)dat[i] = 1 + lower_bound(zat, zat + num, dat[i]) - zat;
	for (int i = 0; i < num; i++)cnt[dat[i]]++;
	for (int j = 1; j < 202020; j++)cnt[j] += cnt[j - 1];
	uf.init();
	int opes = 0;
	for (int i = 0; i < num; i++)isok[i] = (cnt[dat[i] - 1] <= i&&i < cnt[dat[i]]);
	for (int i = 0; i < num; i++)if (!isok[i])uf.unite(i, num + dat[i]), opes++;
	for (int i = 1; i < 202020; i++)for (int j = cnt[i - 1]; j < cnt[i]; j++)if (!isok[j])uf.unite(j, num + i);
	//for (int i = 0; i < 10; i++)printf("%d ", uf.find(i)); printf("\n");
	fill(kou, kou + 502020, -1);
	for (int i = 0; i < num; i++)if (!isok[i])kou[uf.find(i)] = i;
	int rr = 0;
	for (int i = 0; i < 502020; i++)if (kou[i] != -1)rr++;
	vector<vector<int> >ret;
	if (opes > gen)
	{
		printf("-1\n");
		return 0;
	}
	vector<int>zi;
	for (int i = 0; i < 502020; i++)if (kou[i] != -1 && zi.size() < gen - opes)zi.push_back(kou[i]);
	if (zi.size() >= 3)
	{
		int t = dat[zi[zi.size() - 1]];
		for (int i = 0; i < zi.size(); i++)
		{
			int s = dat[zi[i]];
			dat[zi[i]] = t;
			t = s;
		}
		ret.push_back(zi);
	}
	uf.init();
	for (int i = 0; i < num; i++)if (!isok[i])uf.unite(i, num + dat[i]);
	for (int i = 1; i < 202020; i++)for (int j = cnt[i - 1]; j < cnt[i]; j++)if (!isok[j])uf.unite(j, num + i);
	fill(kou, kou + 502020, -1);
	for (int i = 0; i < num; i++)if (!isok[i])kou[uf.find(i)] = i;
	for (int i = 0; i < num; i++)if (!isok[i])adde(i, num + dat[i]);
	for (int i = 1; i < 202020; i++)for (int j = cnt[i - 1]; j < cnt[i]; j++)if (!isok[j])adde(num + i, j);
	for (int i = 0; i < 502020; i++)
	{
		if (kou[i] == -1)continue;
		euler.clear();
		calceuler(i);
		reverse(euler.begin(), euler.end());
		vector<int>z;
		for (int j = 0; j < euler.size() - 1; j++)if (euler[j] < num)z.push_back(euler[j]);
		ret.push_back(z);
	}
	int sum = 0;
	for (int i = 0; i < ret.size(); i++)sum += ret[i].size();
	printf("%d\n", ret.size());
	for (int i = 0; i < ret.size(); i++)
	{
		printf("%d\n", ret[i].size());
		for (int j = 0; j < ret[i].size(); j++)printf("%d ", ret[i][j] + 1);
		printf("\n");
	}
	check(ret, num);
}