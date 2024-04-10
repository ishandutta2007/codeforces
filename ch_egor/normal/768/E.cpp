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

map<pair<int64, int64>, int64> mem;

int64 count_dp(int n, int64 mask)
{
	if (n == 0)
	{
		return 0;
	}
	if (mem.find({ n, mask }) != mem.end())
	{
		return mem[{n, mask}];
	}
	vector<int64> kk;
	for (int i = 1; i <= n; ++i)
	{
		if (((mask >> i) & 1) == 0)
		{
			kk.push_back(count_dp(n - i, mask | (1ll << i)));
		}
	}
	sort(kk.begin(), kk.end());
	int64 best = 0;
	for (int i = 0; i < (int)kk.size(); ++i)
	{
		if (kk[i] == best)
		{
			++best;
		}
	}

	return mem[{n, mask}] = best;
}

int gg[61] = { 0,
1,
1,
2,
2,
2,
3,
3,
3,
3,
4,
4,
4,
4,
4,
5,
5,
5,
5,
5,
5,
6,
6,
6,
6,
6,
6,
6,
7,
7,
7,
7,
7,
7,
7,
7,
8,
8,
8,
8,
8,
8,
8,
8,
8,
9,
9,
9,
9,
9,
9,
9,
9,
9,
9,
10,
10,
10,
10,
10,
10};

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	//for (int i = 0; i <= 60; ++i)
	//{
	//	int64 gg = count_dp(i, 0);
	//	cerr << i << " " << gg << endl;;
	//	cout << gg << ",\n";
	//}
	//return 0;
	int n;
	scanf("%d", &n);
	int now = 0;
	for (int i = 0; i < n; ++i)
	{
		int v;
		scanf("%d", &v);
		now ^= gg[v];
	}
	//cout << gg[60] << endl;
	if (now)
	{
		printf("NO\n");
	}
	else
	{
		printf("YES\n");
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}