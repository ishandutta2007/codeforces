#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 5;

int a[N];

int main()
{
	int n, c;
	cin >> n >> c;

	for (int i = 0; i < n; ++i)
		cin >> a[i];

	sort(a, a+n);

	int ctr = 1;

	for (int i = n-2; i >= 0; --i)
	{
		if (a[i+1]-a[i]>c)
			break;

		++ctr;
	}

	cout << ctr;
}