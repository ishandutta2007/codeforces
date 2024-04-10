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

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int64 k, n, w;

	cin >> k >> n >> w;

	int64 sum = 0;

	for (int i = 1; i <= w; ++i)
	{
		sum += k*i;
	}

	if (sum > n)
	{
		cout << sum - n;
	}
	else
	{
		cout << 0;
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}