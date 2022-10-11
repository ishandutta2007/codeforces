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

string st1, st2;
int answer = 0;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n1, n2;
	cin >> st1 >> st2;
	n1 = st1.size();
	n2 = st2.size();

	string st_c;
	for (int i = 0; i <= n1 - n2; ++i)
	{
		st_c = st1.substr(i, n2);
		if (st_c == st2)
		{
			st1[i + n2 - 1] = '#';
			++answer;
		}
	}

	cout << answer;

	fclose(stdin);
	fclose(stdout);

	return 0;
}