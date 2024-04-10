#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pii;
#define B 32000
vector<pii>get(ll n)
{
	vector<pii>r;
	for (ll i = 1; i <= min(n, (ll)B); i++)
	{
		r.push_back(make_pair(i, n / i));
		r.push_back(make_pair(n / i, i));
	}
	sort(r.begin(), r.end());
	vector<pii>v;
	for (int i = 0; i < r.size(); i++)
	{
		if (i != 0)
		{
			if (v[v.size() - 1].first == r[i].first)v.pop_back();
		}
		v.push_back(r[i]);
	}
	r = v;
	//for (int i = 0; i < r.size(); i++)printf("%I64d %I64d  ", r[i].first, r[i].second); printf("\n");
	return r;
}
int main()
{
	ll na, nb, kai;
	scanf("%I64d%I64d%I64d", &na, &nb, &kai);
	kai += 2;
	if (na + nb < kai)
	{
		printf("-1\n");
		return 0;
	}
	vector<pii>va = get(na), vb = get(nb);
	ll maxi = 0;
	for (int i = 0; i < va.size(); i++)
	{
		ll t = va[i].first;
		if (kai - t < 1 || nb < kai - t)continue;
		int low = lower_bound(vb.begin(), vb.end(), make_pair(kai - t, -1LL)) - vb.begin();
		maxi = max(maxi, va[i].second*vb[low].second);
	}
	for (int i = 0; i < vb.size(); i++)
	{
		ll t = vb[i].first;
		if (kai - t < 1 || na < kai - t)continue;
		int low = lower_bound(va.begin(), va.end(), make_pair(kai - t, -1LL)) - va.begin();
		maxi = max(maxi, vb[i].second*va[low].second);
	}
	printf("%I64d\n", maxi);
}