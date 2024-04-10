#include<stdio.h>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
map<ll, ll>ma;
vector<ll>get(ll a, ll b)
{
	vector<ll>v;
	for (;;)
	{
		if (a == b)return v;
		if (a > b)swap(a, b);
		v.push_back(b);
		b /= 2;
	}
}
int main()
{
	int num;
	scanf("%d", &num);
	for (int p = 0; p < num; p++)
	{
		int za;
		scanf("%d", &za);
		if (za == 1)
		{
			ll zb, zc, zd;
			scanf("%I64d%I64d%I64d", &zb, &zc, &zd);
			vector<ll>t = get(zb, zc);
			for (int i = 0; i < t.size(); i++)ma[t[i]] += zd;
		}
		else
		{
			ll zb, zc;
			scanf("%I64d%I64d", &zb, &zc);
			ll ans = 0;
			vector<ll>t = get(zb, zc);
			for (int i = 0; i < t.size(); i++)ans += ma[t[i]];
			printf("%I64d\n", ans);
		}
	}
}