#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define cost first
#define cap second

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 2e5 + 5;

vector <pll> a, b;
ll g[N];

ll getTime(ll i, ll j, ll c);
bool isPossible(ll c, ll n, ll t);

int main()
{
	ios_base::sync_with_stdio(false);
	ll n, k, s, t;
	cin >> n >> k >> s >> t;

	for (int i = 0; i < n; ++i)
	{
		ll c, v;
		cin >> c >> v;
		a.push_back({c,v});
	}

	for (int i = 1; i <= k; ++i)
		cin >> g[i];

	g[0] = 0;
	g[k+1] = s;

	sort(a.begin(), a.end());
	sort(g, g+k+2);

	int prev = 0;
	b.push_back(a[0]);

	for (int i = 1; i < n; ++i)
	{
		if (a[i].cap <= a[prev].cap);

		else
		{
			b.push_back(a[i]);
			prev = i;
		}
	}

	int m = b.size();
	ll l = 0, r = m-2, mid, ans;

	if (!isPossible(b[r+1].cap, k+2, t))
	{
		cout << -1;
		return 0;
	}

	while (l <= r)
	{
		ll mid = (l+r)/2;

		if (isPossible(b[mid].cap, k+2, t))
			r = mid-1;

		else
			l = mid+1;
	}

	cout << b[r+1].cost;
}

bool isPossible(ll c, ll n, ll t)
{
	ll ans = 0;

	for (int i = 1; i < n; ++i)
	{
		ll temp = getTime(g[i-1], g[i], c);

		if (temp == -1)
			return false;

		ans += temp;
	}

	return (ans <= t);
}

inline ll getTime(ll i, ll j, ll c)
{
	if (j-i > c)
		return -1;

	if (2*(j-i) <= c)
		return j-i;

	return (3*(j-i) - c);
}