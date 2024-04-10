#include <bits/stdc++.h>
using namespace std;long long n, m, k;

long long calculate(int x, int y)
{
	if (n == 1)
	{
		long long rows = k / m;
		if (y > k - rows * m)
			return rows;
		return rows + 1;
	}
	long long rows = k / m;
	long long cycles = rows / (2 * n - 2); //how many full cycles did she do
	long long ans = 0;
	if (x != n && x != 1)
		ans += 2 * cycles;
	else
		ans += cycles;	
	long long kleft = k - cycles * m * (2 * n - 2);
	for (int i = 1; kleft && i <= n; ++i)
		for (int j = 1; kleft && j <= m; ++j, --kleft)
			if (i == x && j == y)
				++ans;
	for (int i = n - 1; kleft && i >= 1; --i)
		for (int j = 1; kleft && j <= m; ++j, --kleft)
			if (i == x && j == y)
				++ans;
	return ans;
}

int main()
{
	int x, y;
	cin >> n >> m >> k >> x >> y;
	if (n == 1)
		cout << max(calculate(1, 1), calculate(n - 1, 1))<< " " << calculate(n, m) << " " << calculate(x, y) << endl;
	else
		cout << max(max(calculate(1, 1), calculate(2, 1)), calculate(n - 1, 1)) << " " << calculate(n, m) << " " << calculate(x, y) << endl;

	return 0;
}