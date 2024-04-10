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
const int MAX_N = 1000 * 1000 + 5;


int n, m;
int cnt_t[MAX_N];
char t[MAX_N];
int cnt_s[MAX_N];
char s[MAX_N];

int64 cnt_t1[MAX_N];
char t1[MAX_N];
int64 cnt_s1[MAX_N];
char s1[MAX_N];


int pi[MAX_N * 5];
int gs[MAX_N * 5];
int64 g_cnt[MAX_N * 5];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; ++i)
	{
		if (i != n - 1)
		{
			scanf("%d-%c ", &cnt_t[i], &t[i]);
		}
		else
		{
			scanf("%d-%c\n", &cnt_t[i], &t[i]);
		}
	}

	for (int i = 0; i < m; ++i)
	{
		if (i != n - 1)
		{
			scanf("%d-%c ", &cnt_s[i], &s[i]);
		}
		else
		{
			scanf("%d-%c\n", &cnt_s[i], &s[i]);
		}
	}

	cnt_t1[0] = cnt_t[0]; t1[0] = t[0];
	int n1 = 1;
	int m1 = 1;
	for (int i = 1; i < n; ++i)
	{
		if (t[i] == t1[n1 - 1])
		{
			cnt_t1[n1 - 1] += cnt_t[i];
		}
		else
		{
			t1[n1] = t[i];
			cnt_t1[n1] = cnt_t[i];
			++n1;
		}
	}

	cnt_s1[0] = cnt_s[0]; s1[0] = s[0];
	for (int i = 1; i < m; ++i)
	{
		if (s[i] == s1[m1 - 1])
		{
			cnt_s1[m1 - 1] += cnt_s[i];
		}
		else
		{
			s1[m1] = s[i];
			cnt_s1[m1] = cnt_s[i];
			++m1;
		}
	}

	n = n1; m = m1;

	int64 answer = 0;
	if (m == 1)
	{
		for (int i = 0; i < n; ++i)
		{
			if (t1[i] == s1[0] && cnt_t1[i] >= cnt_s1[0])
			{
				answer += cnt_t1[i] - cnt_s1[0] + 1;
				//cout << cnt_t1[i] << endl;
			}
		}
		cout << answer;
		return 0;
	}

	for (int i = 1; i < m - 1; ++i)
	{
		gs[i - 1] = s1[i];
		g_cnt[i - 1] = cnt_s1[i];
	}
	gs[m - 2] = 5;
	g_cnt[m - 2] = 1;

	for (int i = 0; i < n; ++i)
	{
		gs[m + i - 1] = t1[i];
		g_cnt[m + i - 1] = cnt_t1[i];
	}

	pi[0] = 0;
	for (int i = 1; i < n + m - 1; ++i)
	{
		pi[i] = pi[i - 1];
		while (pi[i] > 0 && (gs[i] != gs[pi[i]] || g_cnt[i] != g_cnt[pi[i]]))
			pi[i] = pi[pi[i] - 1];
		if (gs[i] == gs[pi[i]] && g_cnt[i] == g_cnt[pi[i]])
			++pi[i];
	}

	for (int i = m - 1; i < n + m - 2; ++i)
	{
		if (pi[i] >= m - 2)
		{
			//cout << "GG" << endl;
			if (t1[i - m + 2] == s1[m - 1] && cnt_s1[m - 1] <= cnt_t1[i - m + 2])
			{
				//cout << "KK" << endl;
				if (t1[i - m + 2 - m + 1] == s1[0] && cnt_s1[0] <= cnt_t1[i - m + 2 - m + 1])
				{
					++answer;
				}
			}
		}
	}

	cout << answer;

	fclose(stdin);
	fclose(stdout);

	return 0;
}