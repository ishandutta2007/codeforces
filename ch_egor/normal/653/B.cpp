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

int n, q;
pair<string, string> arr[228];
map<string, bool> can;
queue<string> now;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n >> q;



	string st1, st2;
	for (int i = 0; i < q; ++i)
	{
		cin >> arr[i].first >> arr[i].second;
	}

	now.push("a");

	string dd;
	string next;
	while (!now.empty())
	{
		dd = now.front();
		now.pop();
		if (dd.size() >= 6) continue;
		for (int i = 0; i < q; ++i)
		{
			if (dd[0] == arr[i].second[0])
			{
				next = arr[i].first + dd.substr(1, (int)dd.size() - 1);
				if (!can[next])
				{
					can[next] = true;
					now.push(next);
				}
			}
		}
	}

	int answer = 0;
	for (auto it = can.begin(); it != can.end(); ++it)
	{
		if (it->first.size() == n)
		{
			++answer;
		}
	}

	cout << answer;

	fclose(stdin);
	fclose(stdout);

	return 0;
}