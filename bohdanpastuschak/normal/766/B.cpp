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
	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	if (n > 49)
	{
		cout << "YES";
		return 0;
	}

	for (int i = 0; i < n - 2; ++i)
	{
		for (int j = i + 1; j < n - 1; ++j)
		{
			for (int k = j + 1; k < n; ++k)
			{
				if (a[i] + a[j] > a[k] && a[i] + a[k] > a[j] && a[k] + a[j] > a[i])
				{
					cout << "YES";
					return 0;
				}
			}
		}
	}

	cout << "NO";
	return 0;
}