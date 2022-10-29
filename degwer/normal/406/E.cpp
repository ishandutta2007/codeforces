#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pii;
ll INF = 1000000000000000000LL;
pii solve1(vector<pii>vec, ll len)
{
	sort(vec.begin(), vec.end());
	ll cnt = 0;
	ll n0 = 0;
	ll s0 = 0;
	ll las = -INF;
	ll zc = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i].second == 0)s0++;
	}
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i].first != las)n0 += zc, zc = 0;
		if (vec[i].second == 1)cnt += n0*(s0 - n0 - zc);
		else zc++, las = vec[i].first;
	}
	if (cnt == 0)return make_pair(-1, cnt);
	else return make_pair(len * 2, cnt);
}
pii solve2(vector<pii>vec, ll len)
{
	sort(vec.begin(), vec.end());
	ll cnt = 0;
	ll n0 = 0;
	ll maxi = -1;
	ll las = -INF;
	ll lk = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i].second == 1)
		{
			ll ad = lk*(lk - 1) / 2 + lk*(n0 - lk);
			if (las == vec[i].first)ad = lk*(n0 - lk);
			if (maxi < len * 2 - (vec[i].first - las) * 2 && n0 >= 2)
			{
				maxi = len * 2 - (vec[i].first - las) * 2;
				cnt = ad;
			}
			else if (maxi == len * 2 - (vec[i].first - las) * 2 && n0 >= 2)cnt += ad;
		}
		else
		{
			n0++;
			if (las == vec[i].first)lk++;
			else las = vec[i].first, lk = 1;
		}
	}
	return make_pair(maxi, cnt);
}
pii solve3(vector<pii>vec)
{
	ll mini = INF, maxi = -INF;
	for (int i = 0; i < vec.size(); i++)if (vec[i].second == 0)mini = min(mini, vec[i].first), maxi = max(maxi, vec[i].first);
	ll c1 = 0, c2 = 0, c3 = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i].second == 0)
		{
			if (vec[i].first == mini)c1++;
			else if (vec[i].first == maxi)c3++;
			else c2++;
		}
	}
	if (c1 + c2 + c3 < 3)return make_pair(-1, 0);
	if (mini == maxi)
	{
		return make_pair((maxi - mini) * 2, c1*(c1 - 1)*(c1 - 2) / 6);
	}
	return make_pair((maxi - mini) * 2, c1*c2*c3 + c1*(c1 - 1) / 2 * c3 + c1*c3*(c3 - 1) / 2);
}
pii solve4(vector<pii>vec, ll len)
{
	sort(vec.begin(), vec.end());
	ll t0 = 0, t1 = 0;
	ll las = -INF;
	ll cnt = 0;
	for (int i = 0; i <= vec.size(); i++)
	{
		if (vec.size() == i || las != vec[i].first)cnt += t0*(t0 - 1) / 2 * t1 + t1*(t1 - 1) / 2 * t0, t0 = t1 = 0;
		if (vec.size() == i)break;
		if (vec[i].second == 0)t0++;
		else t1++;
		las = vec[i].first;
		
	}
	if (cnt > 0)return make_pair(len * 2, cnt);
	else return make_pair(-1, 0);
}
int main()
{
	int len, num;
	scanf("%d%d", &len, &num);
	vector<pii>vec;
	for (int i = 0; i < num; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		vec.push_back(make_pair(zb, za));
	}
	vector<pii>ans;
	ans.push_back(solve1(vec, len));
	for (int i = 0; i < num; i++)vec[i].second ^= 1;
	ans.push_back(solve1(vec, len));
	for (int i = 0; i < num; i++)vec[i].second ^= 1;
	ans.push_back(solve2(vec, len));
	for (int i = 0; i < num; i++)vec[i].second ^= 1;
	ans.push_back(solve2(vec, len));
	for (int i = 0; i < num; i++)vec[i].first = len - 1 - vec[i].first;
	ans.push_back(solve2(vec, len));
	for (int i = 0; i < num; i++)vec[i].second ^= 1;
	ans.push_back(solve2(vec, len));
	for (int i = 0; i < num; i++)vec[i].first = len - 1 - vec[i].first;
	ans.push_back(solve3(vec));
	for (int i = 0; i < num; i++)vec[i].second ^= 1;
	ans.push_back(solve3(vec));
	for (int i = 0; i < num; i++)vec[i].second ^= 1;
	ans.push_back(solve4(vec, len));
	ll maxi = 0, cnt = 0;
	for (int i = 0; i < ans.size(); i++)
	{
		//printf(":::%I64d %I64d\n", ans[i].first, ans[i].second);
		if (maxi < ans[i].first)
		{
			maxi = ans[i].first;
			cnt = ans[i].second;
		}
		else if (maxi == ans[i].first)cnt += ans[i].second;
	}
	printf("%I64d\n", cnt);
}