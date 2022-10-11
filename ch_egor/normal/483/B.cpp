#include <iostream>
#include <algorithm>

#define int64 long long int

using namespace std;

inline bool good(int64 m, int cnt1, int cnt2, int x, int y)
{
	int byX = m / x;
	int byY = m / y;
	int byXY = m / x / y;

	int to1 = byY - byXY;
	int to2 = byX - byXY;

	cnt1 -= to1;
	cnt2 -= to2;

	cnt1 = max(0, cnt1);
	cnt2 = max(0, cnt2);

	return m - byX - byY + byXY >= cnt1 + cnt2;
}

int main()
{
	int cnt1, cnt2, x, y;

	cin >> cnt1 >> cnt2 >> x >> y;

	int64 l = -1;
	int64 r = 2147000005;
	int64 m;

	while (r - l > 1)
	{
		m = (l + r) / 2;

		if (good(m, cnt1, cnt2, x, y))
		{
			r = m;
		}
		else
		{
			l = m;
		}
	}

	cout << r;

	return 0;
}