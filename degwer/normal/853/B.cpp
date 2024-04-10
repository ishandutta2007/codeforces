#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
typedef pair<int, int>pii;
vector<pii>q1[1000000];
vector<pii>q2[1000000];
typedef long long ll;
ll mini[100000];
multiset<ll>se[100000];
ll INF = 2000000000000LL;
int main()
{
	int num, way, gen;
	scanf("%d%d%d", &num, &way, &gen);
	for (int i = 0; i < way; i++)
	{
		int za, zb, zc, zd;
		scanf("%d%d%d%d", &za, &zb, &zc, &zd);
		za--, zb--, zc--;
		if (zc == -1)q1[za].push_back(make_pair(zb, zd));
		else q2[max(0, za - gen)].push_back(make_pair(zc, zd)), se[zc].insert(zd);
	}
	fill(mini, mini + num, INF);
	for (int i = 0; i < num; i++)se[i].insert(INF);
	ll ans = INF;
	ll sum = INF*num;
	for (int i = 0; i < num; i++)
	{
		multiset<ll>::iterator it = se[i].begin();
		ll t = *it;
		sum += t;
	}
	for (int i = 0; i < 1000000; i++)
	{
		for (int j = 0; j < q1[i].size(); j++)
		{
			ll t = mini[q1[i][j].first];
			mini[q1[i][j].first] = min(mini[q1[i][j].first], (ll)q1[i][j].second);
			sum -= t - mini[q1[i][j].first];
		}
		for (int j = 0; j < q2[i].size(); j++)
		{
			multiset<ll>::iterator it = se[q2[i][j].first].begin();
			ll t = *it;
			it = se[q2[i][j].first].find(q2[i][j].second);
			se[q2[i][j].first].erase(it);
			it = se[q2[i][j].first].begin();
			sum += (*it) - t;
		}
		ans = min(ans, sum);
	}
	if (ans == INF)printf("-1\n");
	else printf("%I64d\n", ans);
}