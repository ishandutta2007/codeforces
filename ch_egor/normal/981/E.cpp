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

typedef long long int ll;
typedef long double ld;

const int INF = 1000 * 1000 * 1000 + 21;
const ll LLINF = (1ll << 60) + 5;
const int MOD = 1000 * 1000 * 1000 + 7;

const int MAX_N = 10000 + 228;
const int MAX_LOG = 21;

int n, q;
vector<int> tree[4 * MAX_N];
bitset<MAX_N> dp[MAX_LOG];
bitset<MAX_N> ans;
vector<int> answer;

void add(int v, int l, int r, int x, int y, int value)
{
	if (r <= x || y <= l) return;
	else if (x <= l && r <= y) tree[v].push_back(value);
	else
	{
		int m = (l + r) >> 1;

		add(2 * v + 1, l, m, x, y, value);
		add(2 * v + 2, m, r, x, y, value);
	}
}

void get_ans(int v, int l, int r, int cur)
{
	if (cur) dp[cur] = dp[cur - 1];
	for (int i = 0; i < (int)tree[v].size(); ++i) dp[cur] |= (dp[cur] << tree[v][i]);

	if (r - l == 1) ans |= dp[cur];
	else
	{
		int m = (l + r) >> 1;

		get_ans(2 * v + 1, l, m, cur + 1);
		get_ans(2 * v + 2, m, r, cur + 1);
	}
}

int main()
{
#ifdef CH_EGOR
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
#endif

	scanf("%d%d", &n, &q);

	for (int i = 0; i < q; ++i)
	{
		int l, r, x;
		scanf("%d%d%d", &l, &r, &x);
		--l; --r;
		add(0, 0, n, l, r + 1, x);
	}

	dp[0][0] = true;
	get_ans(0, 0, n, 0);

	for (int i = 1; i <= n; ++i) if (ans[i]) answer.push_back(i);

	printf("%d\n", (int)answer.size());
	for (int i = 0; i < (int)answer.size(); ++i)
	{
		printf("%d%c", answer[i], " \n"[i == (int)answer.size() - 1]);
	}

	return 0;
}