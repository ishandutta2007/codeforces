#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll d[20000];
int main()
{
	int num, kai;
	scanf("%d%d", &num, &kai);
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		d[z]++;
	}
	vector<int>v;
	for (int i = 0; i < (1 << 14); i++)
	{
		int c = 0;
		for (int j = 0; j < 14; j++)if (i&(1 << j))c++;
		if (c == kai)v.push_back(i);
	}
	ll ans = 0;
	for (int i = 0; i <= 10000; i++)for (int j = 0; j < v.size(); j++)ans += d[i] * d[i^v[j]];
	if (kai == 0)for (int i = 0; i <= 10000; i++)ans -= d[i];
	printf("%I64d\n", ans / 2);
}