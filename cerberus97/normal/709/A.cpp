#include <iostream>

using namespace std;

int main()
{
	int n, ans = 0;
	long long b, d, a, sum = 0;

	cin >> n >> b >> d;

	for (int i = 0; i < n; ++i)
	{
		cin >> a;

		if (a <= b)
			sum += a;

		if (sum > d)
		{
			sum = 0;
			++ans;
		}
	}

	cout << ans;
}