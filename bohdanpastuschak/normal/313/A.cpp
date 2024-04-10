#include <iostream>
#include <set>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <map>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
#define ll unsigned long long
#define mod 1000000007

int main()
{
	int n;
	cin >> n;

	if (n >= 0) cout << n;
	else
	{
		n = -n;
		if (n < 100 && n % 10 == 0)
		{
			cout << 0;
			return 0;
		}
		if (n < 100)
		{
			int last = n % 10;
			int prelat = (n % 100 - last) / 10;

			if (last > prelat)
			{
				cout << -prelat;
			}
			else
				cout << -last;
			return 0;
		}

		int last = n % 10;
		int prelast = n % 100 - 10 * last;
		if (last > prelast)
		{
			cout <<'-'<< n / 10;
			return 0;
		}
		else
		{
			cout <<'-'<< n / 100 << last;
			return 0;
		}
	}






	return 0;
}