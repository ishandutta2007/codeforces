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

int64 a, b, c;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	cin >> a >> b >> c;


	int64 y, z;
	for (int64 x = 0; x <= 2*a; ++x)
	{
		z = a - x;
		y = b - x;

		if (x >= 0 && y >= 0 && z >= 0 && y + z == c)
		{
			cout << x << " " << y << " " << z << endl;
			return 0;
		}
	}

	cout << "Impossible";

	fclose(stdin);
	fclose(stdout);

	return 0;
}