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

const int MAX_N = 1000 * 100 + 5;
const int BLOCK = 430;

int n, m, q;
int cnt_heavy = 0;
int64 arr[MAX_N];
int heavy_size[BLOCK];
int64 heavy_add[BLOCK];
int64 heavy_answer[BLOCK];
bool have_in[BLOCK][MAX_N];
int heavy_at[MAX_N];
int inv_heavy_at[BLOCK];
bool is_heavy[MAX_N];
int inter[MAX_N][BLOCK];
vector<int> mp[MAX_N];
char st[4];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &n, &m, &q);
	for (int i = 0; i < n; ++i)
	{
		scanf("%lld", &arr[i]);
	}
	
	int sz;
	memset(have_in, 0, sizeof(have_in));
	for (int i = 0; i < m; ++i)
	{
		scanf("%d", &sz);
		mp[i].resize(sz);
		for (int j = 0; j < sz; ++j)
		{
			scanf("%d", &mp[i][j]);
			--mp[i][j];
		}
		sort(mp[i].begin(), mp[i].end());

		is_heavy[i] = false;
		heavy_at[i] = -1;

		if (sz > BLOCK)
		{
			heavy_at[i] = cnt_heavy;
			inv_heavy_at[cnt_heavy] = i;
			heavy_add[cnt_heavy] = 0;
			heavy_size[cnt_heavy] = sz;
			heavy_answer[cnt_heavy] = 0;
			is_heavy[i] = true;

			for (int j = 0; j < sz; ++j)
			{
				heavy_answer[cnt_heavy] += arr[mp[i][j]];
				have_in[cnt_heavy][mp[i][j]] = true;
			}

			++cnt_heavy;
		}
	}

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < cnt_heavy; ++j)
		{
			inter[i][j] = 0;

			if (heavy_at[i] != j)
			{
				for (int k = 0; k < mp[i].size(); ++k)
				{
					if (have_in[j][mp[i][k]])
					{
						++inter[i][j];
					}
				}
			}
		}
	}


	int at;
	int64 add;
	int64 answer;
	for (int i = 0; i < q; ++i)
	{
		scanf("%s %d", st, &at);
		--at;
		
		if (strcmp(st, "+") == 0)
		{
			scanf("%lld", &add);
			if (is_heavy[at])
			{
				heavy_answer[heavy_at[at]] += heavy_size[heavy_at[at]] * add;
				heavy_add[heavy_at[at]] += add;
			}
			else
			{
				for (int j = 0; j < mp[at].size(); ++j)
				{
					arr[mp[at][j]] += add;
				}
				for (int j = 0; j < cnt_heavy; ++j)
				{
					heavy_answer[j] += inter[at][j] * add;
				}
			}
		}
		else
		{
			answer = 0;
			if (is_heavy[at])
			{
				answer = heavy_answer[heavy_at[at]];
				for (int j = 0; j < cnt_heavy; ++j)
				{
					answer += inter[at][j] * heavy_add[j];
				}
			}
			else
			{
				for (int j = 0; j < mp[at].size(); ++j)
				{
					answer += arr[mp[at][j]];
				}
				for (int j = 0; j < cnt_heavy; ++j)
				{
					answer += inter[at][j] * heavy_add[j];
				}
			}

			printf("%lld\n", answer);
		}
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}