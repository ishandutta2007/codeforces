#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <cassert>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <bitset>

#pragma comment(linker, "/STACK:256000000")

using namespace std;

typedef long long int int64;
typedef long double double80;

const int INF = (1 << 29) + 5;
const int64 LLINF = (1ll << 59) + 5;
const int MOD = 1000 * 1000 * 1000 + 7;

bool arr[1555];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	memset(arr, 0, sizeof(arr));
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{

		int x;
		cin >> x;
		arr[x] = true;
	}

	for (int i = 1; i < 1200; ++i)
	{
		if (arr[i] && arr[i + 1] && arr[i + 2])
		{
			cout << "YES";
			return 0;
		}
	}

	cout << "NO";

	fclose(stdin);
	fclose(stdout);

	return 0;
}