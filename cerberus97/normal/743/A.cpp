/*
Hanit Banga
Problem: 
*/

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 5;

char t[N];

int main()
{
	int n, a, b;
	cin >> n >> a >> b;
	--a;
	--b;

	cin >> t;

	if (t[a] == t[b])
	{
		cout << 0;
		return 0;
	}

	else
	{
		cout << 1;
		return 0;
	}

	// int ans = abs(a-b);

	// for (int i = 1; i <= n; ++i)
	// {
	// 	if (t[i] == t[a])
	// 	{
	// 		ans = min(ans, abs(b-i));
	// 	}

	// 	else
	// 	{
	// 		ans = min(ans, abs(a-i));
	// 	}
	// }

	// cout << ans;
}