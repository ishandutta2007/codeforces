#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll; 
pair<ll, ll> team[409600]; 
int main()
{
#ifndef ONLINE_JUDGE
	freopen("725D.in", "r", stdin); 
#endif
	int n; 
	scanf("%d", &n); 
	for (int i = 0; i < n; i++)
		scanf("%lld%lld", &team[i].first, &team[i].second); 
	sort(team + 1, team + n, greater<pair<ll, ll> >()); 
	int cur = 1, cnt = 0; 
	int ans = n; 
	multiset<ll> se; 
	while (cur <= n)
	{
		while (cur < n && team[cur].first > team[0].first)
		{
			se.insert(team[cur].second - team[cur].first + 1); 
			cur++; 
		}
		// cout << cur << " " << cnt << " " << team[0].first << endl; 
		// cout << *se.begin() << endl; 
		ans = min(ans, cur - cnt); 
		if (!se.empty() && team[0].first >= *se.begin())
		{
			cnt++; 
			team[0].first -= *se.begin(); 
			se.erase(se.begin()); 
		}
		else
			break; 
	}
	printf("%d\n", min(ans, cur - cnt));
	return 0; 
}