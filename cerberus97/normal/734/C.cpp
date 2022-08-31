#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 2e5 + 5;

ll a[N], b[N], c[N], d[N];
set <pll> st;

int main()
{
	ll n, m, k, x, s;
	cin >> n >> m >> k >> x >> s;

	for (int i = 0; i < m; ++i)
		cin >> a[i];

	for (int i = 0; i < m; ++i)
		cin >> b[i];

	for (int i = 0; i < k; ++i)
		cin >> c[i];

	for (int i = 0; i < k; ++i)
		cin >> d[i];

	for (int i = 0; i < k; ++i)
		st.insert({d[i], c[i]});

	ll ans = n*x;

	auto j = st.upper_bound({s, 5e9});

	if (j != st.begin())
	{
		--j;
		ans = min(ans, (n-j->second)*x);
	}

	for (int i = 0; i < m; ++i)
	{
		if (b[i] > s)
			continue;

		auto j = st.upper_bound({s-b[i], 5e9});

		if (j != st.begin())
		{
			--j;
			ans = min(ans, (n-j->second)*a[i]);
		}

		else
			ans = min(ans, n*a[i]);
	}

	cout << ans;
}