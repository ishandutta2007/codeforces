#include <iostream>
#include <cstdlib>

using namespace std;

char s[100005];

int main()
{
	cin >> s;
	int l = 0, r = 0, d = 0, u = 0;

	for (int i = 0; s[i]; ++i)
	{
		if (s[i] == 'L')
			++l;

		else if (s[i] == 'R')
			++r;

		else if (s[i] == 'U')
			++u;

		else
			++d;
	}

	if ((l+r+u+d) % 2)
	{
		cout << -1;
		return 0;
	}

	int ans = 0;

	if ((l+r) % 2)
	{
		if (l < r)
			++l;

		else
			++r;

		if (u < d)
			--d;

		else
			--u;

		ans = 1;
	}

	ans += abs(l-r)/2 + abs(u-d)/2;
	cout << ans;
}