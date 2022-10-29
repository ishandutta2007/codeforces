#include<stdio.h>
#include<vector>
#include<algorithm>
#include<bitset>
using namespace std;
#define SIZE 1000000
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
#define B 100
int dat[B + 1];
bitset<1048576>bi1, bi2;
int main()
{
	int num, kai;
	scanf("%d%d", &num, &kai);
	uf.init();
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		z--;
		uf.unite(i, z);
	}
	vector<int>vec;
	vector<int>large;
	for (int i = 0; i < num; i++)
	{
		if (uf.find(i) == i)
		{
			vec.push_back(uf.ren[i]);
			if (uf.ren[i] > B)large.push_back(uf.ren[i]);
			else dat[uf.ren[i]]++;
		}
	}
	bi1[0] = true;
	for (int i = 0; i < large.size(); i++)
	{
		bi1 |= bi1 << large[i];
	}
	bi2[0] = true;
	for (int i = 1; i <= B; i++)
	{
		for (int j = 0; j < i; j++)
		{
			int now = 0;
			for (int k = j; k <= num; k += i)
			{
				if (bi2[k])now = dat[i] + 1;
				if (now > 0)bi2[k] = true;
				now--;
			}
		}
	}
	bool f = false;
	for (int i = 0; i <= kai; i++)if (bi1[i] && bi2[kai - i])f = true;
	int ans1, ans2;
	if (f)ans1 = kai;
	else ans1 = kai + 1;
	int sum = 0;
	for (int i = 0; i < vec.size(); i++)sum += vec[i] / 2;
	if (kai * 2 <= sum * 2)ans2 = kai * 2;
	else ans2 = min(num, sum * 2 + (kai - sum));
	printf("%d %d\n", ans1, ans2);
}