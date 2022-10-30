#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pii;
typedef pair<pii, ll>pi3;
ll mod1 = 1000000007;
ll mod2 = 1000000009;
ll bs1 = 114514;
ll bs2 = 810893;
int dp[10001];
int tt[10001];
vector<pi3>dat[1001];
pii get(string s)
{
	for (int i = 0; i < s.size(); i++)
	{
		if ('A' <= s[i] && s[i] <= 'Z')s[i] += 'a' - 'A';
	}
	ll n1 = 0, n2 = 0;
	for (int i = 0; i < s.size(); i++)
	{
		n1 *= bs1;
		n2 *= bs2;
		n1 += s[i];
		n2 += s[i];
		n1 %= mod1;
		n2 %= mod2;
	}
	return make_pair(n1, n2);
}
int main()
{
	int len;
	scanf("%d", &len);
	string s;
	cin >> s;
	int num;
	scanf("%d", &num);
	vector<string>vec;
	for (int i = 0; i < num; i++)
	{
		string z;
		cin >> z;
		vec.push_back(z);
		pii d = get(z);
		dat[z.size()].push_back(make_pair(d, i));
	}
	for (int i = 0; i <= 1000; i++)sort(dat[i].begin(), dat[i].end());
	fill(dp, dp + 10001, -1);
	dp[0] = 0;
	for (int i = 1; i <= len; i++)
	{
		ll n1 = 0, n2 = 0;
		for (int j = 1; j <= min(1000, i); j++)
		{
			n1 *= bs1;
			n2 *= bs2;
			n1 += s[i - j];
			n2 += s[i - j];
			n1 %= mod1;
			n2 %= mod2;
			if (dp[i - j] != -1)
			{
				int low = lower_bound(dat[j].begin(), dat[j].end(), make_pair(make_pair(n1, n2), -1LL)) - dat[j].begin();
				if (low != dat[j].size())
				{
					if (dat[j][low].first == make_pair(n1, n2))
					{
						dp[i] = j;
						tt[i] = dat[j][low].second;
					}
				}
			}
		}
	}
	vector<string>ans;
	int now = len;
	for (;;)
	{
		if (now == 0)break;
		ans.push_back(vec[tt[now]]);
		now -= dp[now];
	}
	reverse(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
	{
		if (i != 0)cout << " ";
		cout << ans[i];
	}
	printf("\n");
}