#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pii;
typedef pair<pii, ll>pi3;
ll ans[100010];
ll bef[200010];
ll now[200010];
vector<ll>uni(vector<ll>v)
{
	int now = -1145141919;
	vector<ll>ret;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] != now)
		{
			now = v[i];
			ret.push_back(now);
		}
	}
	return ret;
}
int main()
{
	int num, gen;
	scanf("%d%d", &num, &gen);
	vector<ll>zat;
	vector<pi3>vec;
	for (int i = 0; i < num; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		zat.push_back(za);
		zat.push_back(za + gen);
		vec.push_back(make_pair(make_pair(zb, za), 1));
		vec.push_back(make_pair(make_pair(zb + gen, za), 0));
	}
	sort(vec.begin(), vec.end());
	vector<int>idl, idu;
	zat.push_back(2000000000LL);
	sort(zat.begin(), zat.end());
	zat = uni(zat);
	for (int i = 0; i < vec.size(); i++)
	{
		int l1 = lower_bound(zat.begin(), zat.end(), vec[i].first.second) - zat.begin();
		int l2 = lower_bound(zat.begin(), zat.end(), vec[i].first.second + gen) - zat.begin();
		idl.push_back(l1);
		idu.push_back(l2);
	}
	for (int i = 0; i < vec.size(); i++)
	{
		for (int k = idl[i]; k < idu[i]; k++)
		{
			//printf(" %d %d\n", i, zat[k]);
			ans[now[k]] += (vec[i].first.first - bef[k])*(zat[k + 1] - zat[k]);
			bef[k] = vec[i].first.first;
			if (vec[i].second == 0)now[k]--;
			else now[k]++;
		}
	}
	for (int i = 1; i <= num; i++)
	{
		if (i != 1)printf(" ");
		printf("%I64d", ans[i]);
	}
	printf("\n");
}