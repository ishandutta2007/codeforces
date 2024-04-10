#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cassert>
#include <iomanip>
//#include <ctime>
//#include <cmath>

using namespace std;

typedef long long int int64;
typedef long double double80;

int arr[2005];
int answer[2005];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n, k, p, x, y;
	int sum = 0;
	int delta = 0;
	
	cin >> n >> k >> p >> x >> y;

	for (int i = 0; i < n; ++i)
	{
		arr[i] = 0;
	}

	for (int i = 0; i < k; ++i)
	{
		cin >> arr[i];

		sum += arr[i];
	}

	if (x < sum)
	{
		cout << -1;
	}
	else
	{
		sort(arr, arr + n);
		while (arr[n/2] < y && delta < n - k && sum <= x)
		{
			++delta;
			arr[0] = y;
			sort(arr, arr + n);
			sum += y;
		}

		if (x < sum || arr[n/2] < y || sum + n - k - delta > x)
		{
			cout << -1;
		}
		else
		{
			for (int i = 0; i < delta; ++i)
			{
				cout << y << " ";
			}
			for (int i = 0; i < n - k - delta; ++i)
			{
				cout << 1 << " ";
			}
		}
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}