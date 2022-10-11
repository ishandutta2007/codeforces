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
const double80 eps = 1e-9;

int n;
double80 v1, v2, d;
int k;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n >> d >> v1 >> v2 >> k;

	n = (n + k - 1) / k;
	double80 answer = (d * (2 * n * v2 - v2 + v1)) / (v2 * (2 * n * v1 - v1 + v2));
	cout << fixed << setprecision(20) << answer << endl;

	fclose(stdin);
	fclose(stdout);

	return 0;
}