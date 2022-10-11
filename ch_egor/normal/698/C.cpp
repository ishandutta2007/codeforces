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
const double80 eps = 1e-9;

const int MAX_N = 200 * 1000 + 5;

int n, k;
double80 p[MAX_N];
bool used[MAX_N];
double80 answer[MAX_N];


void calc(int v, int cnt, double80 now)
{
	if (v == n && cnt != k) return;

	if (cnt == k)
	{
		cout << now << endl;
		for (int i = 0; i < v; ++i)
		{
			if (used[i]) answer[i] += now;
		}
	}
	else
	{
		calc(v + 1, cnt, now);
		used[v] = true;
		calc(v + 1, cnt + 1, now*p[v]);
	}
}

double80 dp[1 << 20];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n >> k;
	for (int i = 0; i < n; ++i) cin >> p[i];
	for (int i = 0; i < n; ++i) answer[i] = 0.0;

	int new_k = 0;
	for (int i = 0; i < n; ++i) if (p[i] > eps) ++new_k;
	k = min(k, new_k);

	dp[0] = 1.0;

	double80 sum = 0;
	for (int i = 1; i < (1 << n); ++i)
	{
		dp[i] = 0.0;
		sum = 0;
		for (int j = 0; j < n; ++j)
		{
			if (!((1 << j)&i) && p[j] > eps)
			{
				sum += p[j];
			}
		}

		for (int j = 0; j < n; ++j)
		{
			if (((1 << j)&i) && p[j] > eps)
			{
				dp[i] += dp[i ^ (1 << j)] * (p[j] / (p[j] + sum));
			}
		}
	}

	for (int i = 0; i < (1 << n); ++i)
	{
		int cnt = 0;
		for (int j = 0; j < n; ++j)
		{
			if (i&(1 << j))
			{
				++cnt;
			}
		}

		if (cnt == k)
		{
			for (int j = 0; j < n; ++j)
			{
				if (i&(1 << j))
				{
					answer[j] += dp[i];
				}
			}
		}
	}

	cout << fixed << setprecision(20);
	for (int i = 0; i < n; ++i) cout << answer[i] << " ";

	fclose(stdin);
	fclose(stdout);

	return 0;
}