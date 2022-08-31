#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 2e5 + 5;

vector <int> shots, cells;
int maxShips[N];

int main()
{
	int n, a, b, k;
	cin >> n >> a >> b >> k;

	shots.push_back(0);

	for (int i = 1; i <= n; ++i)
	{
		char c;
		cin >> c;

		if (c == '1')
			shots.push_back(i);
	}

	shots.push_back(n+1);
	k += 2;
	int totalShips = 0;

	for (int i = 1; i < k; ++i)
	{
		maxShips[i] = (shots[i]- shots[i-1]-1)/b;
		totalShips += maxShips[i];
	}

	int ans = 0;
	totalShips -= (a-1);

	for (int i = 1; i < k and totalShips; ++i)
	{
		int	temp = min(totalShips, maxShips[i]);
		totalShips -= temp;
		ans += temp;

		for (int j = 1; j <= temp; ++j)
			cells.push_back(b*j + (shots[i-1]));
	}

	cout << ans << endl;

	for (auto &i : cells)
		cout << i << ' ';
}