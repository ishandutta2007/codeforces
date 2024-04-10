#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

#pragma comment(linker, "/STACK:256000000")

using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n;
	long long int arr[100050];
	long long int col[100050];
	long long int answer[100050];

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < 100050; ++i)
	{
		col[i] = 0;
	}
	for (int i = 0; i < n; ++i)
	{
		++col[arr[i]];
	}
	
	answer[0] = 0;
	answer[1] = col[1];

	for (int i = 2; i < 100050; ++i)
	{
		answer[i] = max(answer[i - 1], answer[i - 2] + col[i] * i);
	}

	cout << answer[100049];

	fclose(stdin);
	fclose(stdout);

	return 0;
}