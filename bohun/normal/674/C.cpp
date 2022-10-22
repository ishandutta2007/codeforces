#include <bits/stdc++.h>
#define pb push_back
#define ld long double
#define fi first
#define se second
//#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
using namespace std;
const long long nax = 200005, inf = 1e18;
int n, k;
ld t[nax], pref[nax];
ld dp[nax][55];
ld sum[nax], res[nax];
void go(int lewo, int prawo, int ll, int pp, int u)
{
	if(lewo > prawo)
		return;
	int mid = (lewo + prawo) / 2;
	pair <ld, int> opt = {inf, 0};
	for(int i = ll; min(mid, pp) >= i; ++i)
	{
		ld war = dp[i - 1][u - 1] + (res[mid] - res[i - 1]) - pref[i - 1] * (sum[mid] - sum[i - 1]);
		if(war <= opt.fi)
		{
			opt = {war, i};
		}
	}
	dp[mid][u] = opt.fi;
	go(lewo, mid - 1, ll, opt.se, u);
	go(mid + 1, prawo, opt.se, pp, u);
}
	

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for(int i = 1; n >= i; ++i)
		cin >> t[i], pref[i] = pref[i - 1] + t[i];
	for(int i = 1; n >= i; ++i)
		dp[i][0] = inf;
	for(int i = 1; n >= i; ++i)
	{
		sum[i] = (ld) 1.0 / t[i] + sum[i - 1];
	}
	ld sum = 0;
	for(int i = 1; n >= i; ++i)
	{
		sum += t[i];
		res[i] = res[i - 1] + (ld) sum / t[i];
	}
	for(int i = 1;  k >= i; ++i)
		go(1, n, 1, n, i);
	printf("%.10Lf", dp[n][k]);
		
	
		
		
	return 0;
}