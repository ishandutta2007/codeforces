#include<iostream>
#include<math.h>
#include<cstring>
#include<set>
#include<algorithm>
#include<vector>
#include<map>
#include<iomanip>
#include<queue>
#include<string>
#include<list>
#include<bitset>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
typedef long long ll;
using namespace std;
const int N = 1e5;
const int INF = 1e9;
ll MOD = 998244353;
ll sum(ll n)
{
	ll sm = 0;
	while (n)
	{
		sm += n % 10;
		n /= 10;
	}
	return sm;
}
int main()
{
	list<int> a;
	list<int> b;
	ll n;
	cin >> n;
	int ans = 0;
	vector<ll> res;
	for (ll i = max(n - 100, 0LL); i <= n; i++)
	{
		if (sum(i) + i == n)
		{
			ans++;
			res.pb(i);
        }
	}
	cout << ans << "\n";
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << " ";
	}
	return 0;
}