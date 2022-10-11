#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <assert.h>
#include <algorithm>
#include <iomanip>
#include <time.h>
#include <math.h>
#include <bitset>

#pragma comment(linker, "/STACK:256000000")

using namespace std;

typedef long long int int64;
typedef long double double80;

const int INF = (1 << 29) + 5;
const int64 LLINF = (1ll << 59) + 5;
const int MOD = 1000 * 1000 * 1000 + 7;

int n;
string st1, st2;
string ans1, ans2;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> ans1 >> ans2;
	cin >> n;
	cout << ans1 << " " << ans2 << "\n";
	for (int i = 0; i < n; ++i)
	{
		cin >> st1 >> st2;
		if (st1 == ans1)
		{
			swap(ans1, st2);
		}
		else
		{
			swap(ans2, st2);
		}

		cout << ans1 << " " << ans2 << "\n";
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}