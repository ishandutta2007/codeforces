#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define ld long double
#define ss(v) (int)v.size()
#define fi first
#define se second
using namespace std;

int main()
{
	int n;
	int t[200005];
	scanf("%d", &n);
	for(int i = 1; n >= i; ++i)
		scanf("%d", &t[i]);
	ll ans = 0;
	ll mini = 1000000006;
	for(int i = n; i >= 1; --i)
	{
		ll c = min(mini - 1, (ll)t[i]);
		ans += c;
		if(c == 0)
		{
			cout << ans;
			return 0;
		}
		mini = min(mini , (ll)c);
	}
	cout << max((ll)0, ans);
	return 0;
}