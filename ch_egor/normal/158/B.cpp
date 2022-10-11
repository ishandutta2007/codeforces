#include <bits/stdc++.h>

using namespace std;

int arr[5];

int main()
{
	int n;

	cin >> n;

	int x;
	for (int i = 0; i < n; ++i)
	{
		cin >> x;
		++arr[x];
	}

	int answer = 0;
	if (arr[1] > arr[3])
	{
		answer = arr[4] + arr[3];
		arr[1] -= arr[3];
		answer += (arr[1] + 2*arr[2] + 3) / 4;
	}
	else
	{
		answer = arr[4] + arr[3];
		answer += (2 * arr[2] + 3) / 4;
	}
	

	cout << answer;

    return 0;
}