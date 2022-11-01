#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define pb push_back
#define mp make_pair
#define pf push_front
typedef long long ll;
int INF = 9999999;

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int N, S, L;
	cin >> N >> S >> L;
	int a[N];
	for(int i = 0; i < N; i++)
		cin >> a[i];
	deque<pair<int, int> > mn, mx, num;
	int start = 0;
	int dp[N];
	if(L == 1) dp[0] = 1;
	else dp[0] = INF;
	mn.pb(mp(0, a[0]));
	mx.pb(mp(0, a[0]));
	for(int i = 1; i < N; i++)
	{
		while(!mn.empty() && a[i] <= mn.back().second)
			mn.pop_back();
		mn.pb(mp(i, a[i]));
		while(!mx.empty() && a[i] >= mx.back().second)
			mx.pop_back();
		mx.pb(mp(i, a[i]));
		while(mx.front().second - mn.front().second > S)
		{
			if(mx.front().first == start) mx.pop_front();
			if(mn.front().first == start) mn.pop_front();
			if(!num.empty() && num.front().first == start-1) num.pop_front();
			start++;
		}
		if(i-start + 1 >= L)
		{
			if(start != 0)
			{
				while(!num.empty() && dp[i-L] <= num.back().second)
					num.pop_back();
				num.pb(mp(i-L, dp[i-L]));
				dp[i] = 1 + num.front().second;
			}
			else
				dp[i] = 1;
		}
		else
		{
			dp[i] = INF;
		}
		//cout << dp[i] << endl;
	}
	if(dp[N-1] < INF)
		cout << dp[N-1] << endl;
	else
		cout << -1 << endl;
}