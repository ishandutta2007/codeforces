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
#include <unordered_map>

#pragma comment(linker, "/STACK:256000000")

using namespace std;

typedef long long int int64;
typedef long double double80;

const int INF = (1 << 29) + 5;
const int64 LLINF = (1ll << 59) + 5;
const int MOD = 1000 * 1000 * 1000 + 7;

const int MAX_N = 1000 * 1000 + 5;


#define x first
#define y second

int n, m;
vector<int> arr[MAX_N];
int cnt[MAX_N];
vector<pair<int, int> > gg[MAX_N];
bool used[MAX_N];
map<vector<pair<int, int> >, int> t;
int64 fact[MAX_N];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	fact[0] = 1;
	for (int i = 1; i < MAX_N; ++i)
	{
		fact[i] = (fact[i - 1] * i) % MOD;
	}

	memset(cnt, 0, sizeof(cnt));
	memset(used, 0, sizeof(used));
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
	{
		int g;
		scanf("%d", &g);
		arr[i].resize(g);
		for (int j = 0; j < g; ++j)
		{
			scanf("%d", &arr[i][j]);
			++cnt[arr[i][j]];
		}
		for (int j = 0; j < g; ++j)
		{
			if (!used[arr[i][j]])
			{
				gg[arr[i][j]].push_back({ i, cnt[arr[i][j]] });
				used[arr[i][j]] = true;
			}
		}
		for (int j = 0; j < g; ++j)
		{
			used[arr[i][j]] = false;
			cnt[arr[i][j]] = 0;
		}
	}

	/*for (int i = 1; i <= m; ++i)
	{
		for (int j = 0; j < gg[i].size(); ++j)
		{
			cout << gg[i][j].x << " " << gg[i][j].y << " | ";
		}
		cout << endl;
	}*/
	
	for (int i = 1; i <= m; ++i)
	{
		++t[gg[i]];
	}

	int64 ans = 1;
	for (auto it = t.begin(); it != t.end(); ++it)
	{

		ans = (ans * fact[it->second]) % MOD;
	}

	cout << ans;

	fclose(stdin);
	fclose(stdout);

	return 0;
}