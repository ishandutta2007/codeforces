#include <bits/stdc++.h>
#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
using namespace std;
int n;
int t[300005];
int main()
{
	scanf("%d", &n);
	ll ans = 0;
	ll ile = 0;
	for(int i = 1; n >= i; ++i)
	{
		scanf("%d", &t[i]);
		ll d = min((ll) t[i] / 2, ile);
		ans += d;
		t[i] -= 2 * d;
		ile -= d;
		ans += t[i] / 3;
		t[i] %= 3;
		ile += t[i];
	}
	printf("%lld", ans);
			
	return 0;
}