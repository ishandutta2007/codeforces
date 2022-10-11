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

const int MAX_N = 105;

int n, m, k;
char st1[MAX_N];
char st2[MAX_N];
char bad[MAX_N];
int dp[MAX_N][MAX_N][MAX_N];
int next_of[MAX_N][MAX_N][MAX_N];
int ff[MAX_N][MAX_N][MAX_N];
bool used[MAX_N][MAX_N][MAX_N];
int f[MAX_N];
char answer[MAX_N];

void gen(int i, int j, int t)
{
	if (i >= n || j >= m || t >= k || used[i][j][t])
	{
		if (t >= k) dp[i][j][t] = -228; // fuck
		return;
	}

	used[i][j][t] = true;

	gen(i + 1, j, t);
	gen(i, j + 1, t);
	if (dp[i + 1][j][t] > dp[i][j][t])
	{
		next_of[i][j][t] = 1;
		dp[i][j][t] = dp[i + 1][j][t];
	}
	if (dp[i][j + 1][t] > dp[i][j][t])
	{
		next_of[i][j][t] = 2;
		dp[i][j][t] = dp[i][j + 1][t];
	}

	if (st1[i] == st2[j])
	{
		int tmp = t;
		while (tmp > 0 && bad[tmp] != st1[i]) tmp = f[tmp - 1];
		if (bad[tmp] == st1[i]) ++tmp;

		gen(i + 1, j + 1, tmp);
		if (dp[i + 1][j + 1][tmp] + 1 > dp[i][j][t])
		{
			next_of[i][j][t] = 3;
			ff[i][j][t] = tmp;
			dp[i][j][t] = dp[i + 1][j + 1][tmp] + 1;
		}
	}
}

void gen_answer(int i, int j, int t, int ptr)
{
	if (next_of[i][j][t] == 0)
	{
		answer[ptr] = '\0';
		printf("%s", answer);
		exit(0);
	}
	else if (next_of[i][j][t] == 1)
	{
		gen_answer(i + 1, j, t, ptr);
	}
	else if (next_of[i][j][t] == 2)
	{
		gen_answer(i, j + 1, t, ptr);
	}
	else
	{
		answer[ptr] = st1[i];
		gen_answer(i + 1, j + 1, ff[i][j][t], ptr + 1);
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%s", st1);
	scanf("%s", st2);
	scanf("%s", bad);
	n = strlen(st1);
	m = strlen(st2);
	k = strlen(bad);

	memset(dp, 0, sizeof(dp));
	memset(used, 0, sizeof(used));
	memset(next_of, 0, sizeof(next_of));
	
	f[0] = 0;
	for (int i = 1; i < n; ++i)
	{
		f[i] = f[i - 1];
		while (f[i] > 0 && bad[i] != bad[f[i]]) f[i] = f[f[i] - 1];
		if (bad[i] == bad[f[i]]) ++f[i];
	}

	gen(0, 0, 0);
	if (dp[0][0][0] != 0)
	{
		gen_answer(0, 0, 0, 0);
	}
	else
	{
		printf("0");
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}