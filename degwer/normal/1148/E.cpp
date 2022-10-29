#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pii;
typedef pair<pii, ll>pi3;
ll mok[303030];
int main()
{
	int num;
	scanf("%d", &num);
	vector<pii>v;
	vector<pii>now;
	vector<pi3>ans;
	ll sum = 0;
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		v.push_back(make_pair(z, i));
		sum += z;
	}
	for (int i = 0; i < num; i++)scanf("%I64d", &mok[i]), sum -= mok[i];
	sort(mok, mok + num);
	if (sum != 0)goto l01;
	sort(v.begin(), v.end());
	for (int i = 0; i < num; i++)
	{
		if (v[i].first <= mok[i])
		{
			now.push_back(make_pair(v[i].second, mok[i] - v[i].first));
		}
		else
		{
			ll s = v[i].first - mok[i];
			for (;;)
			{
				if (s == 0)break;
				if (now.empty())goto l01;
				pii z = now[now.size() - 1];
				now.pop_back();
				ans.push_back(make_pair(make_pair(z.first, v[i].second), min(z.second, s)));
				if (z.second > s)z.second -= s, now.push_back(z), s = 0;
				else s -= z.second;
			}
		}
	}
	printf("YES\n");
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++)printf("%I64d %I64d %I64d\n", ans[i].first.first + 1, ans[i].first.second + 1, ans[i].second);
	if (false)
	{
	l01:;
		printf("NO\n");
	}
}