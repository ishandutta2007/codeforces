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

const int MAX_N = 505;

const int arr_x[4] = { 1, -1, 0, 0 };
const int arr_y[4] = { 0, 0, 1, -1 };

int n, k;
char arr[MAX_N][MAX_N];
bool used[MAX_N][MAX_N];
int comp[MAX_N][MAX_N];
int size_of[MAX_N*MAX_N];
int comp_in[MAX_N*MAX_N];

int cnt_comp = 0;

bool is_correct(int x, int y)
{
	return (0 <= x && x < n) && (0 <= y && y < n);
}

int dfs(int x, int y, int cm)
{
	used[x][y] = true;
	comp[x][y] = cm;

	int x1, y1;

	int answer = 1;
	for (int i = 0; i < 4; ++i)
	{
		x1 = x + arr_x[i];
		y1 = y + arr_y[i];

		if (is_correct(x1, y1))
		{
			if (arr[x1][y1] == '.' && !used[x1][y1])
			{
				answer += dfs(x1, y1, cm);
			}
		}
	}

	return answer;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; ++i)
	{
		scanf("%s", arr[i]);
	}


	memset(comp, 0, sizeof(comp));
	memset(used, 0, sizeof(used));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (!used[i][j] && arr[i][j] == '.')
			{
				++cnt_comp;
				size_of[cnt_comp] = dfs(i, j, cnt_comp);
			}
		}
	}


	
	int answer = 0;

	memset(comp_in, 0, sizeof(comp_in));
	int cnt_zero = 0;
	int answer_now = 0;
	int magic = 0;
	for (int i = 0; i <= n - k; ++i)
	{
		cnt_zero = 0;
		answer_now = 0;
		magic = 0;
		for (int j = 1; j <= cnt_comp; ++j)
		{
			comp_in[j] = 0;
		}

		for (int j = 0; j < k; ++j)
		{
			for (int t = 0; t < k; ++t)
			{
				if (arr[j + i][t] == 'X')
				{
					++cnt_zero;
				}
				else
				{
					++comp_in[comp[j + i][t]];
					if (comp_in[comp[j + i][t]] == 1)
					{
						answer_now += size_of[comp[j + i][t]];
					}
				}
			}
		}

		magic = 0;
		for (int j = 0; j < k; ++j)
		{
			if (i - 1 >= 0)
			{
				if (arr[i - 1][j] == '.')
				{
					++comp_in[comp[i - 1][j]];
					if (comp_in[comp[i - 1][j]] == 1)
					{
						magic += size_of[comp[i - 1][j]];
					}
				}
			}

			if (i + k < n)
			{
				if (arr[i + k][j] == '.')
				{
					++comp_in[comp[i + k][j]];
					if (comp_in[comp[i + k][j]] == 1)
					{
						magic += size_of[comp[i + k][j]];
					}
				}
			}

			if (k < n)
			{
				if (arr[i + j][k] == '.')
				{
					++comp_in[comp[i + j][k]];
					if (comp_in[comp[i + j][k]] == 1)
					{
						magic += size_of[comp[i + j][k]];
					}
				}
			}
		}

		answer = max(answer, answer_now + cnt_zero + magic);

		for (int j = k; j < n; ++j)
		{
			for (int t = 0; t < k; ++t)
			{
				if (arr[i + t][j - k] == 'X')
				{
					--cnt_zero;
				}
				else
				{
					--comp_in[comp[i + t][j - k]];
					if (comp_in[comp[i + t][j - k]] == 0)
					{
						answer_now -= size_of[comp[i + t][j - k]];
					}
				}
			}

			for (int t = 0; t < k; ++t)
			{
				if (arr[i + t][j] == 'X')
				{
					++cnt_zero;
				}
				else
				{
					++comp_in[comp[i + t][j]];
					if (comp_in[comp[i + t][j]] == 1)
					{
						answer_now += size_of[comp[i + t][j]];
					}
				}
			}

			//cout << i + 1 << " " << j - k + 1  << " " << cnt_zero << " " <<  answer_now << endl;

			for (int z = 0; z < k; ++z)
			{
				if (i - 1 >= 0)
				{
					if (arr[i - 1][j - k + z] == '.')
					{
						--comp_in[comp[i - 1][j - k + z]];
						if (comp_in[comp[i - 1][j - k + z]] == 0)
						{
							magic -= size_of[comp[i - 1][j - k + z]];
						}
					}
				}

				if (i + k < n)
				{
					if (arr[i + k][j - k + z] == '.')
					{
						--comp_in[comp[i + k][j - k + z]];
						if (comp_in[comp[i + k][j - k + z]] == 0)
						{
							magic -= size_of[comp[i + k][j - k + z]];
						}
					}
				}

				if (k < n)
				{
					if (arr[i + z][j] == '.')
					{
						--comp_in[comp[i + z][j]];
						if (comp_in[comp[i + z][j]] == 0)
						{
							magic -= size_of[comp[i + z][j]];
						}
					}
				}

				if (j != k)
				{
					if (arr[i + z][j - k - 1] == '.')
					{
						--comp_in[comp[i + z][j - k - 1]];
						if (comp_in[comp[i + z][j - k - 1]] == 0)
						{
							magic -= size_of[comp[i + z][j - k - 1]];
						}
					}
				}
			}

			for (int z = 0; z < k; ++z)
			{
				if (i - 1 >= 0)
				{
					if (arr[i - 1][j - k + 1 + z] == '.')
					{
						++comp_in[comp[i - 1][j - k + 1 + z]];
						if (comp_in[comp[i - 1][j - k + 1 + z]] == 1)
						{
							magic += size_of[comp[i - 1][j - k + 1 + z]];
						}
					}
				}

				if (i + k < n)
				{
					if (arr[i + k][j - k + 1 + z] == '.')
					{
						++comp_in[comp[i + k][j - k + 1 + z]];
						if (comp_in[comp[i + k][j - k + 1 + z]] == 1)
						{
							magic += size_of[comp[i + k][j - k + 1 + z]];
						}
					}
				}

				if (j + 1 < n)
				{
					if (arr[i + z][j + 1] == '.')
					{
						++comp_in[comp[i + z][j + 1]];
						if (comp_in[comp[i + z][j + 1]] == 1)
						{
							magic += size_of[comp[i + z][j + 1]];
						}
					}
				}

	
				if (arr[i + z][j - k] == '.')
				{
					++comp_in[comp[i + z][j - k]];
					if (comp_in[comp[i + z][j - k]] == 1)
					{
						magic += size_of[comp[i + z][j - k]];
					}
				}
			}

			answer = max(answer, cnt_zero + answer_now + magic);
		}
	}

	cout << answer;

	fclose(stdin);
	fclose(stdout);

	return 0;
}