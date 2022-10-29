#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>ko[200000];
typedef long long ll;
typedef pair<ll, ll>pii;
ll dat[200000];
pii calc(int node)
{
	ll e = 0, o = -1000000000000000000;
	for (int i = 0; i < ko[node].size(); i++)
	{
		pii z = calc(ko[node][i]);
		ll ne = max(e + z.first, o + z.second);
		ll no = max(e + z.second, o + z.first);
		e = ne;
		o = no;
	}
	return make_pair(e, max(o, e + dat[node]));
}
int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		dat[i] = zb;
		if (i != 0)ko[za - 1].push_back(i);
	}
	pii z = calc(0);
	printf("%I64d\n", max(z.first, z.second));
}