#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	int n, l;
	cin >> n >> l;

	vector<int> a(n);
	vector<int> b(n);

	for (int i = 0; i < n; ++i)
		cin >> a[i];

	for (int i = 0; i < n; ++i)
		cin >> b[i];

	vector<int> c(n);
	for (int zsuv = 0; zsuv < l; ++zsuv)
	{
		for (int i = 0; i < n; ++i)
		{
			c[i] = (b[i] + zsuv) % l;
		}

		bool isequal = true;
		for (int i = 0; i < n; ++i)
		{
			bool iii = false;
			for (int j = 0; j < n; ++j)
			{
				if (c[i] == a[j])
				{
					iii = true;
					break;
				}
			}

			if (!iii)
			{
				isequal = false;
				break;
			}
		}

		if (isequal)
		{
			cout << "YES";
			return 0;
		}
	}

	cout << "NO";
	return 0;
}