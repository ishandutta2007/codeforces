#include <iostream>

using namespace std;

int main()
{
	int n, a, cur = 0;

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> a;

		if (a % 2 == 0)
			++cur;

		if (cur % 2 == 0)
			cout << 2 << '\n';

		else
			cout << 1 << '\n';
	}
}