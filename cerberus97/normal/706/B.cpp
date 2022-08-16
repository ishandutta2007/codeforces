#include <iostream>
#include <algorithm>

using namespace std;

const int N = (int)1e5 + 5;

int x[N];

int lowerThanThis(int m, int l, int r)
{
	if (l > r)
		return 0;

	if (x[l] > m)
		return 0;

	if (x[r] <= m)
		return r - l + 1;

	int mid = (l+r)/2;

	if (x[mid] <= m)
		return mid - l + 1 + lowerThanThis(m, mid + 1, r);

	else
		return lowerThanThis(m, l, mid - 1);
}

int main()
{
	int n, q, m;
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> x[i];

	sort(x, x + n);

	cin >> q;

	while (q--)
	{
		cin >> m;
		cout << lowerThanThis(m, 0, n-1) << '\n';
	}
}