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

int n;
const int MAX_N = 105;// 1000 * 100 + 5;
int arr[MAX_N];

struct pv
{
	int a;
	int b;
	int c;

	pv(int _a, int _b, int _c)
	{
		a = _a;
		b = _b;
		c = _c;
	}
};

//int n, m, k;
//char st1[MAX_N];
//char st2[MAX_N];
//char bad[MAX_N];
//int dp[MAX_N][MAX_N][MAX_N];
//pv prev_of[MAX_N][MAX_N][MAX_N];
//bool add_to_ans[MAX_N][MAX_N][MAX_N];
//
//void upd(pv a, pv b, int inc, bool add)
//{
//	if (b.a >= 0 && b.b >= 0 && b.c >= 0)
//	{
//		if (dp[a.a][a.b][a.c] < dp[b.a][b.b][b.c] + inc)
//		{
//			dp[a.a][a.b][a.c] = dp[b.a][b.b][b.c] + inc;
//			prev_of[a.a][a.b][a.c] = b;
//			add_to_ans[a.a][a.b][a.c] = add;
//		}
//	}
//}

int gcd(int a, int b)
{
	return (b) ? gcd(b, a % b) : a;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &arr[i]);
	}

	int tmp = arr[0];
	for (int i = 0; i < n; ++i)
	{
		tmp = gcd(tmp, arr[i]);
	}

	int to_end = (*max_element(arr, arr + n)) / tmp;

	if ((to_end - n) % 2 == 1)
	{
		printf("Alice");
	}
	else
	{
		printf("Bob");
	}

	//scanf("%s", st1);
	//scanf("%s", st2);
	//scanf("%s", bad);
	//n = strlen(st1);
	//m = strlen(st2);
	//k = strlen(bad);

	//memset(dp, 0, sizeof(dp));

	//for (int i = 0; i < n; ++i)
	//{
	//	for (int j = 0; j < m; ++j)
	//	{
	//		for (int t = 0; t < k; ++t)
	//		{
	//			prev_of[i][j][t] = pv(i, j, t);

	//			if (st1[i] == st2[j])
	//			{
	//				if (st1[i] == bad[t])
	//				{

	//				}
	//				else
	//				{
	//					upd(pv(i, j, t), pv(i - 1, j, t), 0, false);
	//					upd(pv(i, j, t), pv(i, j - 1, t), 0, false);
	//					upd(pv(i, j, t), pv(i - 1, j - 1, t), 0, false);
	//				}
	//			}
	//			else
	//			{
	//				upd(pv(i, j, t), pv(i - 1, j, t), 0, false);
	//				upd(pv(i, j, t), pv(i, j - 1, t), 0, false);
	//				upd(pv(i, j, t), pv(i - 1, j - 1, t), 0, false);
	//			}
	//		}
	//	}
	//}


	fclose(stdin);
	fclose(stdout);

	return 0;
}