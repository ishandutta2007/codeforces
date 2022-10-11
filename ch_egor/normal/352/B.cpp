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
vector<int> arr[MAX_N];
vector<pair<int, int> > answer;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);

	int x;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &x);
		arr[x].push_back(i);
	}

	for (int i = 0; i < MAX_N; ++i)
	{
		if (arr[i].size() == 1)
		{
			answer.push_back(make_pair(i, 0));
		}
		else if (arr[i].size() > 1)
		{
			sort(arr[i].begin(), arr[i].end());
			int r = arr[i][1] - arr[i][0];
			bool good = true;
			for (int j = 1; j < arr[i].size(); ++j)
			{
				good &= (arr[i][j] - arr[i][j - 1] == r);
			}
			if (good)
			{
				answer.push_back(make_pair(i, r));
			}
		}
	}

	printf("%d\n", answer.size());
	for (int i = 0; i < answer.size(); ++i) printf("%d %d\n", answer[i].first, answer[i].second);

	fclose(stdin);
	fclose(stdout);

	return 0;
}