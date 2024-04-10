#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pii;
#define B 200000
int main()
{
	int num;
	scanf("%d", &num);
	vector<int>now;
	vector<pii>qs;
	ll len = 0;
	for (int i = 0; i < num; i++)
	{
		int za;
		scanf("%d", &za);
		if (za == 1)
		{
			int zb;
			scanf("%d", &zb);
			if (now.size() <= B)now.push_back(zb);
			else qs.push_back(make_pair(len, -zb));
			len++;
		}
		else
		{
			int zb, zc;
			scanf("%d%d", &zb, &zc);
			ll cnt = 0;
			for (int i = 0; i < zc; i++)
			{
				if (now.size() > B)break;
				for (int j = 0; j < zb; j++)now.push_back(now[j]);
				cnt++;
			}
			if (cnt != zc)
			{
				qs.push_back(make_pair(len + cnt*zb, zb));
			}
			len += (ll)zb*zc;
		}
	}
	int query;
	scanf("%d", &query);
	for (int i = 0; i < query; i++)
	{
		ll z;
		scanf("%I64d", &z);
		z--;
		if (z < now.size())printf("%d\n", now[z]);
		else
		{
			int upp = upper_bound(qs.begin(), qs.end(), make_pair((ll)z, 1000000000LL)) - qs.begin() - 1;
			if (qs[upp].second < 0)printf("%I64d\n", -qs[upp].second);
			else printf("%d\n", now[(z - qs[upp].first) % qs[upp].second]);
		}
	}
}