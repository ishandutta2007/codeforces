/*
Hanit Banga
*/

#include <iostream>
#include <vector>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 5;
const ll INF = 1e12;

ll a[N], b[N];
int p[N], pos[N];

int main()
{
	int n; ll l, r;
	cin >> n >> l >> r;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	for (int i = 1; i <= n; ++i)
	{
		cin >> p[i];
		pos[p[i]] = i;
	}	

	ll cur = -INF;
	for (int i = 1; i <= n; ++i)
	{
		int j = pos[i];
		if (cur + a[j] >= r)
		{
			cout << -1;
			return 0;
		}

		b[j] = max(l, cur + a[j] + 1);
		cur = b[j] - a[j];
	}

	for (int i = 1; i <= n; ++i)
		cout << b[i] << ' ';
}