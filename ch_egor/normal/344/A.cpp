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

int n;
int answer = 1;
string st1;
string st2;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n;
	cin >> st1;

	for (int i = 0; i < n - 1; ++i)
	{
		cin >> st2;
		if (st1[1] == st2[0]) ++answer;
		swap(st1, st2);
	}

	cout << answer;

	fclose(stdin);
	fclose(stdout);

	return 0;
}