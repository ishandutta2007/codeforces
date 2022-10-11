#include <iostream>
//#include <pair>
#include <algorithm>

using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
	return b.first < a.first;
}

int main()
{
	pair<int, int> arr[100005];
	int n;

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i].first >> arr[i].second;
	}

	sort(arr, arr + n, cmp);

	int maxAt = arr[0].second;
	int prev = arr[0].first;
	bool good=false;

	for (int i = 0; i < n; ++i)
	{
		if (arr[i].first != prev && arr[i].second>maxAt)
		{
			good = true;
			cout << "Happy Alex";
			break;
		}

		if (arr[i].first != prev)
		{
			maxAt=arr[i].second;
			prev = arr[i].first;
		}

		if (maxAt < arr[i].second)
		{
			maxAt = arr[i].second;
			prev = arr[i].first;
		}
	}

	if (!good)
	{
		cout << "Poor Alex";
	}

	/*cout << endl;
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i].first << " " << arr[i].second << endl;
	}*/

	cin.get();
	cin.get();

	return 0;
}