#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <tuple>
template <typename T> constexpr T my_abs(const T &x) { return x < 0 ? -x : x; }
using ll = long long;
constexpr int MOD = 1e9 + 7;
inline int quick_pow(int a, int n)
{
	int res = 1;
	while (n)
	{
		if (n & 1)
			res = (ll)res * a % MOD;
		a = (ll)a * a % MOD;
		n >>= 1;
	}
	return res;
}
inline bool query(int x1, int y1, int x2, int y2)
{
	if (x1 > x2)
	{
		std::swap(x1, x2);
		std::swap(y1, y2);
	}
	printf("? %d %d %d %d\n", x1, y1, x2, y2);
	fflush(stdout);
	int res;
	scanf("%d", &res);
	return res;
}
int arr[55][55], n;
bool ans_1[55][55][55][55], ans_2[55][55][55][55];
void fill(int x, int y)
{
	auto go = [&] (int xx, int yy)
	{
		if (xx <= 0 || xx > n || yy <= 0 || yy > n)
			return;
		if (-1 == arr[xx][yy])
		{
			arr[xx][yy] = query(x, y, xx, yy) ^ arr[x][y] ^ 1;
			fill(xx, yy);
		}
	};
	go(x + 2, y);
	go(x + 1, y + 1);
	go(x - 1, y - 1);
	go(x, y + 2);
}
inline void get_ans(bool ans[55][55][55][55])
{
	for (int dx = 0; dx < n; dx++)
	{
		for (int dy = 0; dy < n; dy++)
		{
			for (int x1 = 1; x1 + dx <= n; x1++)
			{
				for (int y1 = 1; y1 + dy <= n; y1++)
				{
					int x2 = x1 + dx, y2 = y1 + dy;
					if (arr[x1][y1] != arr[x2][y2])
						continue;
					if (dx + dy <= 1)
						ans[x1][y1][x2][y2] = true;
					else
						ans[x1][y1][x2][y2] = ans[x1][y1 + 1][x2][y2 - 1] ||
											  ans[x1][y1 + 1][x2 - 1][y2] ||
											  ans[x1 + 1][y1][x2][y2 - 1] ||
											  ans[x1 + 1][y1][x2 - 1][y2];
				}
			}
		}
	}
}
int main()
{
	memset(arr, -1, sizeof(arr));
	scanf("%d", &n);
	arr[1][1] = 1;
	arr[n][n] = 0;
	fill(1, 1);
	arr[1][2] = 1;
	fill(1, 2);
	get_ans(ans_1);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i + j & 1)
				arr[i][j] ^= 1;
		}
	}
	get_ans(ans_2);
	bool flg = false;
	for (int x1 = 1; x1 <= n && !flg; x1++)
	{
		for (int y1 = 1; y1 <= n && !flg; y1++)
		{
			for (int x2 = x1; x2 <= n && !flg; x2++)
			{
				for (int y2 = y1; y2 <= n && !flg; y2++)
				{
					if (x1 - x1 + y2 - y1 <= 1)
						continue;
					if (ans_1[x1][y1][x2][y2] == ans_2[x1][y1][x2][y2])
						continue;
					if (query(x1, y1, x2, y2) == ans_1[x1][y1][x2][y2])
					{
						for (int i = 1; i <= n; i++)
						{
							for (int j = 1; j <= n; j++)
							{
								if (i + j & 1)
									arr[i][j] ^= 1;
							}
						}
					}
					flg = true;
				}
			}
		}
	}
	if (!flg)
		throw;
	puts("!");
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			putchar(arr[i][j] + '0');
		puts("");
	}
	return 0;
}