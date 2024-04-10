#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pii;
typedef pair<pii, pii>pi4;
ll r1[303030], r2[303030];
ll ans[303030];
int main()
{
	int num, ban;
	scanf("%d%d", &num, &ban);
	vector<pii>zzv;
	vector<pi4>v;
	for (int i = 0; i < num; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		zzv.push_back(make_pair(za, zb));
		v.push_back(make_pair(make_pair(za - zb, i), make_pair(za, zb)));
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < num; i++)r1[i + 1] = r1[i] + v[i].second.first, r2[i + 1] = r2[i] + v[i].second.second;
	for (int i = 0; i < num; i++)
	{
		ans[v[i].first.second] += i*v[i].second.second + r1[i];
		ans[v[i].first.second] += (num - i - 1)*v[i].second.first + r2[num] - r2[i + 1];
	}
	for (int i = 0; i < ban; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		za--, zb--;
		ll s = min(zzv[za].first + zzv[zb].second, zzv[za].second + zzv[zb].first);
		ans[za] -= s, ans[zb] -= s;
	}
	for (int i = 0; i < num; i++)printf("%I64d\n", ans[i]);
}