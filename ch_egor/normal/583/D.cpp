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
const int MAX_N = 105;
const int MAX_A = 305;

int n;
int64 t;
int arr[MAX_N];
int dp[MAX_N];
int64 max_of[MAX_A];
int64 next_of[MAX_A];
//int64 mat[MAX_A][MAX_A];
//int64 answer[MAX_A][MAX_A];
//int64 buff[MAX_A][MAX_A];

//void mult(int64 a[MAX_A][MAX_A], int64 b[MAX_A][MAX_A], int64 out[MAX_A][MAX_A])
//{
//	for (int i = 0; i < MAX_A; ++i)
//	{
//		for (int j = 0; j < MAX_A; ++j)
//		{
//			buff[i][j] = 0;
//			for (int k = 0; k < MAX_A; ++k)
//			{
//				buff[i][j] = max(buff[i][j], a[i][k] + b[k][j]);
//			}
//		}
//	}
//
//	for (int i = 0; i < MAX_A; ++i)
//	{
//		for (int j = 0; j < MAX_A; ++j)
//		{
//			out[i][j] = buff[i][j];
//		}
//	}
//}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d %I64d", &n, &t);

	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < n; ++i)
	{
		dp[i] = 1;
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = i - 1; j >= 0; --j)
		{
			if (arr[j] <= arr[i] && dp[j] + 1 > dp[i])
			{
				dp[i] = dp[j] + 1;
			}
		}
	}

	for (int i = 0; i < MAX_A; ++i)
	{
		max_of[i] = 0;
	}
	for (int i = 0; i < n; ++i)
	{
		max_of[arr[i]] = max(max_of[arr[i]], 1ll*dp[i]);
	}

	//for (int i = 0; i < MAX_A; ++i)
	//{
	//	for (int j = 0; j < MAX_A; ++j)
	//	{
	//		if (j <= i)
	//		{
	//			mat[i][j] = 1;
	//		}
	//		else
	//		{
	//			mat[i][j] = 0;
	//		}
	//	}
	//}

	//for (int i = 0; i < MAX_A; ++i)
	//{
	//	for (int j = 0; j < MAX_A; ++j)
	//	{
	//		answer[i][j] = mat[i][j];
	//		//printf("%d ", answer[i][j]);
	//	}
	//	//printf("\n");
	//}

	--t;
	//while (t != 0)
	//{
	//	if (t & 1)
	//	{
	//		mult(mat, mat, mat);
	//		--t;
	//	}
	//	
	//	mult(answer, mat, answer);
	//	t >>= 1;
	//}

	//for (int i = 1; i <= 10; ++i)
	//{
	//	cout << max_of[i] << " ";
	//}
	//cout << endl;
	for (int i = 0; i < min(2000ll, t); ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			for (int k = arr[j]; k >= 0; --k)
			{
				max_of[arr[j]] = max(max_of[arr[j]], max_of[k] + 1);
			}
		}

		//for (int i = 1; i <= 10; ++i)
		//{
		//	cout << max_of[i] << " ";
		//}
		//cout << endl;
	}

	if (t > 2000)
	{
		for (int i = 0; i < MAX_A; ++i)
		{
			next_of[i] = max_of[i];
		}

		for (int j = 0; j < n; ++j)
		{
			for (int k = arr[j]; k >= 0; --k)
			{
				next_of[arr[j]] = max(next_of[arr[j]], next_of[k] + 1);
			}
		}

		for (int i = 0; i < MAX_A; ++i)
		{
			max_of[i] = max_of[i] + (next_of[i] - max_of[i])*(t - 2000);
		}
	}

	int64 ans = 0;

	for (int i = 0; i < MAX_A; ++i)
	{
		ans = max(ans, max_of[i]);
	}

	printf("%I64d", ans);

	fclose(stdin);
	fclose(stdout);

	return 0;
}