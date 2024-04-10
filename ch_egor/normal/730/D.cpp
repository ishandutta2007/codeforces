/*






le
toucan
has
arrived*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int MAX_N = 200 * 1000 + 5;

#define time time228

int n;
ll r;
ll len[MAX_N];
ll time[MAX_N];

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	
	scanf("%d %lld", &n, &r);

	for (int i = 0; i < n; ++i)
	{
		scanf("%lld", &len[i]);
		len[i] *= 2;
	}
	for (int i = 0; i < n; ++i)
	{
		scanf("%lld", &time[i]);
	}
	
	ll curev = 0;
	ll time_now = 0;
	vector<ll> ans;
	ll cnt_ans = 0;
	for (int i = 0; i < n; ++i)
	{
		ll spend = (len[i] + 1) / 2;
		if (spend <= curev)
		{
			if (spend > time[i])
				return 0 * printf("-1\n");
			curev -= spend;
			time_now += spend;
			continue;
		}
		
		len[i] -= 2 * curev;
		time[i] -= curev;
		ll need_time = 2 * curev;
		
		if (time[i] < 0)
			return 0 * printf("-1\n");

		time_now += curev;

		ll need_curev = len[i] - time[i];
		if (need_curev <= 0)
		{
			curev = 0;
			time_now += len[i];
			continue;
		}
		else
		{
			len[i] -= time[i];
			if (len[i] > time[i])
				return 0 * printf("-1\n");
			time_now += time[i] - len[i];

			if (cnt_ans + (len[i] + r - 1) / r <= 100000)
			{
				for (int j = 0; j < (len[i] + r - 1) / r; ++j)
				{
					ans.push_back(time_now + r * j);
				}
			}
			cnt_ans += (len[i] + r - 1) / r;
			curev = (r - len[i] % r) % r;
			time_now += len[i];
		}
		
	}
	if (cnt_ans > 100000)
	{
		cout << cnt_ans << endl;
	}
	else
	{
		printf("%d\n", (int)ans.size());
		for (int i = 0; ans.size() <= 100000 && i < ans.size(); ++i)
		{
			printf("%lld ", ans[i]);
		}
	}
}