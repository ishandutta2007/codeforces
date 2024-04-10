#include <bits/stdc++.h>
#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
#define up(i, n) for(int i = 1; n >= i; ++i)
using namespace std;
const int nax = 100005, mod = 1e9 + 7;
int n, m;
int t[nax], d[nax];
map<int, int> bylo, B;
ll ans = 0;
int ile[nax];
set <pair<int, int>> s;
int mini = -100;
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 1; n >= i; ++i)
	{
		cin >> t[i];
		ans += (ll) t[i] * m;
	}
	ll sum = 0;
	for(int i = 1; m >= i; ++i)
	{
		cin >> d[i];
		sum += d[i];
		B[d[i]] = 1;
	}
	sort(t + 1, t + n + 1);
	sort(d + 1, d + m + 1);
	if(t[n] > d[1])
	{
		cout << -1;
		return 0;
	}
	if(B[t[n]] == 1)
	{
		ans += sum - (ll) m * t[n];
	}
	else
	{
		if(n == 1)
		{
			cout << -1;
			return 0;
		}
		ans += sum - (ll) (m - 1) * t[n];
		ans -= t[n - 1];
	}
	cout << ans;
	
	
		
	
    return 0;
}