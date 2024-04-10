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

int n;
int arr[MAX_N];
int dp[MAX_N][3];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n;
	for (int i = 0; i < n; ++i) cin >> arr[i + 1];

	dp[0][0] = dp[0][1] = dp[0][2] = 0;

	for (int i = 1; i <= n; ++i)
	{
		dp[i][0] = max(max(dp[i - 1][0], dp[i - 1][1]), dp[i - 1][2]);
		if (arr[i] == 1 || arr[i] == 3) dp[i][1] = max(dp[i - 1][2] + 1, dp[i - 1][0] + 1);
		else dp[i][1] = 0;
		if (arr[i] == 2 || arr[i] == 3) dp[i][2] = max(dp[i - 1][1] + 1, dp[i - 1][0] + 1);
		else dp[i][2] = 0;
	}
	
	int answer = max(max(dp[n][0], dp[n][1]), dp[n][2]);

	cout << n - answer;

	fclose(stdin);
	fclose(stdout);

	return 0;
}