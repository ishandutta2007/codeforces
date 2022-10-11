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

const int INF = (1 << 30) + 5;
const int64 LLINF = (1ll << 59) + 5;
const int MOD = 1000 * 1000 * 1000 + 7;

const int MAX_N = 200 * 1000 + 5;
const int MAX_LOG = 19;

int n;
string st;
int xx[10] = { 2, 1, 2, 3, 1, 2, 3, 1, 2, 3 };
int yy[10] = { 4, 1, 1, 1, 2, 2, 2, 3, 3, 3 };

bool is_correct(int x, int y)
{
	return (x == 2 && y == 4) || (1 <= x && x <= 3 && 1 <= y && y <= 3);
}

vector<pair<int, int>> dd;

bool check(int x, int y)
{
	for (int i = 0; i < dd.size(); ++i)
	{
		x = x + dd[i].first;
		y = y + dd[i].second;
		if (!is_correct(x, y)) return false;
	}
	return true;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n;
	cin >> st;

	for (int i = 1; i < st.size(); ++i)
	{
		dd.push_back(make_pair(xx[st[i] - '0'] - xx[st[i - 1] - '0'], yy[st[i] - '0'] - yy[st[i - 1] - '0']));
	}

	int answer = 0;
	for (int i = 1; i <= 3; ++i)
	{
		for (int j = 1; j <= 3; ++j)
		{
			answer += check(i, j);
		}
	}
	answer += check(2, 4);

	printf("%s", ((answer == 1) ? "YES" : "NO"));

	fclose(stdin);
	fclose(stdout);

	return 0;
}