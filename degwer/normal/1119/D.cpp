#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pii;
ll d[101010];
ll r[101010];
int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)scanf("%I64d", &d[i]);
	sort(d, d + num);
	vector<pii>qs;
	for (int i = 0; i < num - 1; i++)qs.push_back(make_pair(d[i + 1] - d[i], -1));
	int query;
	scanf("%d", &query);
	qs.push_back(make_pair(0, -2));
	for (int i = 0; i < query; i++)
	{
		ll za, zb;
		scanf("%I64d%I64d", &za, &zb);
		qs.push_back(make_pair(zb - za + 1, i));
	}
	sort(qs.begin(), qs.end());
	ll ans = 0, kat = num;
	for (int i = 1; i < qs.size(); i++)
	{
		ans += kat*(qs[i].first - qs[i - 1].first);
		if (qs[i].second == -1)kat--;
		else r[qs[i].second] = ans;
	}
	for (int i = 0; i < query; i++)printf("%I64d\n", r[i]);
}