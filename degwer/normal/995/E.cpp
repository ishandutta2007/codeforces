#include<stdio.h>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pii;
typedef pair<ll, pii>pi3;
ll mod;
ll po(ll a, ll b)
{
	if (b == 0)return 1;
	ll z = po(a, b / 2);
	z = z*z%mod;
	if (b & 1)z = z*a%mod;
	return z;
}
ll inv(ll a)
{
	return po(a, mod - 2);
}
int main()
{
	ll s, t;
	scanf("%I64d%I64d%I64d", &s, &t, &mod);
	queue<pi3>que;
	que.push(make_pair(s, make_pair(0, -1)));
	que.push(make_pair(t, make_pair(1, -1)));
	map<ll, pii>ma;
	vector<ll>ans;
	for (;;)
	{
		if (que.empty())break;
		pi3 z = que.front();
		que.pop();
		ll x = z.first, beg = z.second.first, fr = z.second.second;
		if (ma.count(x))
		{
			if (ma[x].first == beg)continue;
			vector<ll>v;
			if (ma[x].first != 0)swap(x, fr);
			ll now = x;
			for (;;)
			{
				if (now == -1 || ma[now].second == -1)break;
				ll p = ma[now].second;
				if ((p + 1) % mod == now)v.push_back(1);
				else if ((p + mod - 1) % mod == now)v.push_back(2);
				else v.push_back(3);
				now = p;
			}
			reverse(v.begin(), v.end());
			if ((x + 1) % mod == fr)v.push_back(1);
			else if ((x + mod - 1) % mod == fr)v.push_back(2);
			else v.push_back(3);
			now = fr;
			for (;;)
			{
				if (now == -1 || ma[now].second == -1)break;
				ll p = ma[now].second;
				if ((p + 1) % mod == now)v.push_back(2);
				else if ((p + mod - 1) % mod == now)v.push_back(1);
				else v.push_back(3);
				now = p;
			}
			ans = v;
			break;
		}
		ma[x] = z.second;
		que.push(make_pair((x + 1) % mod, make_pair(beg, x)));
		que.push(make_pair((x + mod - 1) % mod, make_pair(beg, x)));
		que.push(make_pair(inv(x), make_pair(beg, x)));
	}
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++)printf("%I64d ", ans[i]); printf("\n");
}