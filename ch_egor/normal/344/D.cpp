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

const int MAX_N = 1000 * 100 + 5;

int n;
char st[MAX_N];
vector<char> now;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%s", &st);
	n = strlen(st);

	for (int i = 0; i < n; ++i)
	{
		if (!now.empty() && now.back() == st[i])
		{
			now.pop_back();
		}
		else
		{
			now.push_back(st[i]);
		}
	}

	if (now.empty())
	{
		cout << "Yes";
	}
	else
	{
		cout << "No";
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}