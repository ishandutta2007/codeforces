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

#pragma comment(linker, "/STACK:256000000")

using namespace std;

typedef long long int int64;
typedef long double double80;

int n;
int arr[50000];
int64 answer = 0;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	for (int i = 0; i < 40000; ++i)
	{
		arr[i] = 0;
	}

	int x;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &x);
		++arr[x];
	}

	for (int i = 1; i < 35000; ++i)
	{
		if (arr[i]>1)
		{
			answer += arr[i] - 1;
			arr[i + 1] += arr[i] - 1;
		}
	}

	cout << answer;

	fclose(stdin);
	fclose(stdout);

	return 0;
}