/*
Hanit Banga
Problem: 
*/

#include <iostream>
#include <vector>

using namespace std;

#define pb push_back

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 105;

int a[N];
bool seen[N] = {0};

ll gcd(ll a, ll b);
ll lcm(ll a, ll b);
int cycleLength(int st);

int main()
{
	int n;
	cin >> n;

	ll ans = 1;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	for (int i = 1; i <= n; ++i)
	{
		if (!seen[i])
		{
			ll temp = cycleLength(i);

			if (temp == -1)
			{
				cout << -1;
				return 0;
			}

			else if (temp % 2 == 1)
				ans = lcm(ans, temp);

			else
				ans = lcm(ans, temp/2);
		}
	}

	cout << ans;
}

ll gcd(ll x, ll b)
{
	if (!b)
		return x;

	return gcd(b, x%b);
}

ll lcm(ll x, ll b)
{
	return (x/gcd(x,b))*b;
}

int cycleLength(int st)
{
	seen[st] = true;
	int cur = a[st], ans = 1;

	if (cur == st)
		return 2;

	while (cur != st)
	{
		if (seen[cur])
			return -1;

		seen[cur] = true;
		cur = a[cur];
		++ans;
	}

	return ans;
}