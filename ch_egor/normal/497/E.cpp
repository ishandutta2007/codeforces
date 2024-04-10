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
const int64 LLINF = (1ll << 60) + 5;
const int MOD = 1000 * 1000 * 1000 + 7;
const int MAX_K = 31;
const int MAX_DIV = 70;

int64 n, k;
int64 dp[MAX_DIV][MAX_K][MAX_K];
int64 calc[MAX_K][MAX_K][MAX_K];
int64 mat[MAX_K][MAX_K];
int64 member[MAX_K][MAX_K];
int64 buff[MAX_K][MAX_K];
int64 powers[MAX_DIV];
bool used[MAX_DIV];

int64 mult(int64 a, int64 b)
{
	if (a == 0 || b == 0)
	{
		return 0;
	}
	else if (a > LLINF / b)
	{
		return LLINF;
	}
	else
	{
		return a*b;
	}
}

void mult_mat(int64 a[MAX_K][MAX_K], int64 b[MAX_K][MAX_K], int64 out[MAX_K][MAX_K])
{
	for (int i = 0; i < MAX_K; ++i)
	{
		for (int j = 0; j < MAX_K; ++j)
		{
			buff[i][j] = 0;
			for (int t = 0; t < MAX_K; ++t)
			{
				buff[i][j] = (buff[i][j] + a[i][t] * b[t][j]) % MOD;
			}
		}
	}
	
	for (int i = 0; i < MAX_K; ++i)
	{
		for (int j = 0; j < MAX_K; ++j)
		{
			out[i][j] = buff[i][j];
		}
	}
}

void get_answer(int64 start, int64 now, int64 mat_now[MAX_K][MAX_K])
{
	if (mult(start, powers[now]) < n)
	{
		mult_mat(mat_now, calc[start%k], mat_now);
		if (now == 0)
		{
			mult_mat(mat_now, mat, mat_now);
		}
		else
		{
			auto at_now = ((mult(start, powers[now]) + powers[now] <= n) ? dp[now] : mat_now);

			if (mult(start, powers[now]) + powers[now] <= n && !used[now])
			{
				for (int i = 0; i < MAX_K; ++i)
				{
					at_now[i][i] = 1;
				}
			}
			if (mult(start, powers[now]) + powers[now] > n || !used[now])
			{
				for (int i = 0; i < k; ++i)
				{
					get_answer(start*k + i, now - 1, at_now);
				}
			}
			if (mult(start, powers[now]) + powers[now] <= n)
			{
				used[now] = true;
				mult_mat(mat_now, at_now, mat_now);
			}
		}

		mult_mat(mat_now, calc[(k - start%k) % k], mat_now);
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%I64d %I64d", &n, &k);

	memset(mat, 0, sizeof(mat));
	for (int i = 0; i <= k; ++i)
	{
		mat[i][i] = 1;
		mat[i][0] = 1;
	}

	memset(calc, 0, sizeof(calc));
	for (int i = 0; i < k; ++i)
	{
		for (int j = 0; j < k; ++j)
		{
			calc[i][j][(i + j) % k] = 1;
		}
		for (int j = k; j < MAX_K; ++j)
		{
			calc[i][j][j] = 1;
		}
	}

	memset(member, 0, sizeof(member));
	member[0][k] = 1;

	powers[0] = 1;
	for (int i = 1; i < MAX_DIV; ++i)
	{
		powers[i] = mult(powers[i - 1], k);
	}

	memset(used, 0, sizeof(used));
	memset(dp, 0, sizeof(dp));
	get_answer(0, MAX_DIV - 1, member);


	int64 answer = 1;
	for (int i = 0; i < k; ++i)
	{
		answer = (answer + member[0][i]) % MOD;
	}

	printf("%I64d", answer);

	fclose(stdin);
	fclose(stdout);

	return 0;
}