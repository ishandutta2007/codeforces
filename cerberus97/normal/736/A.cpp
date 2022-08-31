#include <iostream>

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 100;

ll players[N];

int main()
{
	ll n;
	cin >> n;

	players[0] = 1;
	players[1] = 2;
	// int ans;

	for (int i = 2; i < N; ++i)
	{
		players[i] = players[i-1] + players[i-2];
		
		if (players[i] > n)
		{
			cout << i-1;
			break;
		}
	}

	// cout << ans;
}