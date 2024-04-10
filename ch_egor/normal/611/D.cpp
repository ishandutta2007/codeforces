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

const int MAX_N = 5005;

int n;
int sum_len, alph_now = 256;
int tree[MAX_N * 8];
char st[MAX_N];
int64 dp[MAX_N][MAX_N];
int64 sums[MAX_N][MAX_N];

int arr[MAX_N];
int copy_arr[MAX_N];
int cnt[MAX_N];
int class_of[MAX_N];
int copy_class_of[MAX_N];
int lcp[MAX_N];
int at_dir[MAX_N];

void cnt_suff()
{
	memset(cnt, 0, sizeof(int)*alph_now);
	for (int i = 0; i < sum_len; ++i)
	{
		++cnt[st[i]];
	}
	for (int i = 1; i < alph_now; ++i)
	{
		cnt[i] += cnt[i - 1];
	}
	for (int i = 0; i < sum_len; ++i)
	{
		arr[--cnt[st[i]]] = i;
	}

	int cl = 0;
	class_of[arr[0]] = 0;

	for (int i = 1; i < sum_len; ++i)
	{
		if (st[arr[i]] != st[arr[i - 1]])
		{
			++cl;
		}
		class_of[arr[i]] = cl;
	}

	int add = 0;
	for (int m = 0; (1 << m) < sum_len; ++m)
	{
		add = (1 << m);

		for (int i = 0; i < sum_len; ++i)
		{
			copy_arr[i] = arr[i] - add;
			if (copy_arr[i] < 0)
			{
				copy_arr[i] += sum_len;
			}
		}

		memset(cnt, 0, sizeof(int)*(cl + 1));

		for (int i = 0; i < sum_len; ++i)
		{
			++cnt[class_of[copy_arr[i]]];
		}
		for (int i = 1; i <= cl; ++i)
		{
			cnt[i] += cnt[i - 1];
		}
		for (int i = sum_len - 1; i > -1; --i)
		{
			arr[--cnt[class_of[copy_arr[i]]]] = copy_arr[i];
		}

		copy_class_of[arr[0]] = 0;
		cl = 0;
		for (int i = 1; i < sum_len; ++i)
		{
			if (class_of[arr[i]] != class_of[arr[i - 1]] ||
				class_of[(arr[i] + add) % sum_len] != class_of[(arr[i - 1] + add) % sum_len])
			{
				++cl;
			}
			copy_class_of[arr[i]] = cl;
		}

		memcpy(class_of, copy_class_of, sum_len*sizeof(int));
	}

	for (int i = 0; i < sum_len; ++i)
	{
		at_dir[arr[i]] = i;
	}

	int j;
	int last = 0;
	for (int i = 0; i < sum_len; ++i)
	{
		j = at_dir[i];
		lcp[j] = last;

		if (j + 1 < sum_len)
		{
			while (arr[j] + lcp[j] < sum_len &&
				arr[j + 1] + lcp[j] < sum_len &&
				st[arr[j] + lcp[j]] == st[arr[j + 1] + lcp[j]])
			{
				++lcp[j];
			}
		}

		last = max(0, lcp[j] - 1);
	}
}

void build(int v, int l, int r)
{
	if (r - l == 1)
	{
		tree[v] = lcp[l];
	}
	else
	{
		int m = (l + r) >> 1;
		build(2 * v + 1, l, m);
		build(2 * v + 2, m, r);
		tree[v] = min(tree[2 * v + 1], tree[2 * v + 2]);
	}
}

int get_r(int v, int l, int r, int x, int y)
{
	if (y <= l || r <= x)
	{
		return INF;
	}
	else if (x <= l && r <= y)
	{
		return tree[v];
	}
	else
	{
		int m = (l + r) >> 1;
		return min(get_r(2 * v + 1, l, m, x, y),
			get_r(2 * v + 2, m, r, x, y));
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	scanf("%s", st);
	bool good;
	sum_len = n + 1;
	st[n] = '$';

	cnt_suff();
	build(0, 0, n + 1);

	memset(dp, 0, sizeof(dp));
	memset(sums, 0, sizeof(sums));
	dp[0][0] = 1;

	for (int i = 0; i < n; ++i)
	{
		sums[0][i] = 1;
	}
	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (st[i - j] == '0')
				continue;
			if (j != 0)
			{
				dp[i][j] = sums[i - j - 1][j - 1];
			}
			else
			{
				dp[i][j] = 0;
			}

			if (i - 2 * j - 1 >= 0 && st[i - j] != '0')
			{
				//good = true;
				//for (int t = 0; t <= j && good; ++t)
				//{
				//	if (st[i - j + t] > st[i - 2 * j - 1 + t])
				//	{
				//		break;
				//	}
				//	if (st[i - j + t] < st[i - 2 * j - 1 + t])
				//	{
				//		good = false;
				//		break;
				//	}
				//	//cout << i << " " << j << " " << st[i - j + t] << " " << st[i - 2 * j - 1 + t] << (st[i - j + t] > st[i - 2 * j + 1 + t]) << endl;
				//	if (t == j)
				//	{
				//		//cout << "fuck " << i << " " << j << endl;
				//		good = false;
				//	}
				//}

				good = true;
				if (at_dir[i - 2 * j - 1] < at_dir[i - j])
				{
					int lc = get_r(0, 0, n + 1, at_dir[i - 2 * j - 1], at_dir[i - j]);
					//cout << lc << endl;
					if (lc > j)
					{
						//cout << "??" << i << " " << j << endl;
						good = false;
					}
				}
				else
				{
					//cout << "!!" << i << " " << j << endl;
					good = false;
				}

				if (good)
				{
					dp[i][j] = (dp[i][j] + dp[i - j - 1][j]) % MOD;
				}
			}
		}
		
		dp[i][i] = 1;
		sums[i][0] = dp[i][0];
		for (int j = 1; j < n; ++j)
		{
			sums[i][j] = (sums[i][j - 1] + dp[i][j]) % MOD;
		}
	}
	
	int64 answer = 0;
	for (int i = 0; i < n; ++i)
	{
		answer = (answer + dp[n - 1][i]) % MOD;
	}

	//for (int i = 0; i < n; ++i)
	//{
	//	for (int j = 0; j < n; ++j)
	//	{
	//		cout << dp[i][j] << " ";
	//	}
	//	cout << endl;
	//}
	//cout << endl;
	//for (int i = 0; i < n; ++i)
	//{
	//	for (int j = 0; j < n; ++j)
	//	{
	//		cout << sums[i][j] << " ";
	//	}
	//	cout << endl;
	//}

	cout << answer;

	fclose(stdin);
	fclose(stdout);

	return 0;
}