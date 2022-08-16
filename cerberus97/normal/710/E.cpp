#include <iostream>

using namespace std;

long long dist[(int)2e7 + 5];

void init()
{
	for (int i = 0; i <= 1e7; ++i)
		dist[i] = 1e18;
}

int main()
{
	int n, x, y;
	cin >> n >> x >> y;

	init();
	dist[0] = 0;

	for (int i = 1; i <= n; ++i)
	{
		dist[i] = min(dist[i], x + dist[i-1]);
		long long c = dist[i] + y;

		for (int j = 2*i; j > i; --j, c += x)
		{
			if (c < dist[j])
				dist[j] = c;

			else
				break;
		}
	}

	cout << dist[n];
}