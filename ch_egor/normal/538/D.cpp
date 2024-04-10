#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cassert>
#include <iomanip>
//#include <ctime>
//#include <cmath>

using namespace std;

typedef long long int int64;
typedef long double double80;

int n;
string answer[200];
string desk[100];
string check[100];

bool is_correct(int x, int y)
{
	return (0 <= x && x < n && 0 <= y & y < n);
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
	{
		cin >> desk[i];
		for (int j = 0; j < n; ++j)
		{
			check[i] += '.';
		}
	}

	for (int i = 0; i < 2 * n - 1; ++i)
	{
		for (int j = 0; j < 2 * n - 1; ++j)
		{
			answer[i] += "x";
		}
	}

	int dx, dy;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (desk[i][j] == 'o')
			{
				for (int k = 0; k < n; ++k)
				{
					for (int q = 0; q < n; ++q)
					{
						if (desk[k][q] == '.')
						{
							dx = k - i + n - 1;
							dy = q - j + n - 1;

							if (answer[dx][dy] == 'x' || answer[dx][dy] == '?')
							{
								answer[dx][dy] = '.';
							}
						}
						else
						{
							dx = k - i + n - 1;
							dy = q - j + n - 1;

							if (answer[dx][dy] == '?')
							{
								answer[dx][dy] = 'x';
							}
						}
					}
				}

				//for (int k = -j; k < n - j - 1; ++k)
				//{
				//	for (int q = -i; q < n - i - 1; ++q)
				//	{
				//		if (answer[n + k][n + q] == '?')
				//		{
				//			answer[n + k][n + q] = '.';
				//		}
				//	}
				//}
			}
		}
	}

	for (int i = 0; i < 2 * n - 1; ++i)
	{
		for (int j = 0; j < 2 * n - 1; ++j)
		{
			if (answer[i][j] == '?')
			{
				answer[i][j] = '.';
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (desk[i][j] == 'o')
			{
				check[i][j] = 'o';

				for (int k = 0; k < 2 * n - 1; ++k)
				{
					for (int q = 0; q < 2 * n - 1; ++q)
					{
						if (answer[k][q] == 'x')
						{
							dx = k - n + 1;
							dy = q - n + 1;

							if (is_correct(i+dx, j+dy) && check[i+dx][j+dy] != 'o')
							{
								check[i+dx][j+dy] = 'x';
							}
						}
					}
				}
			}
		}
	}

	bool good = true;

	for (int i = 0; i < n; ++i)
	{
		good = (good && (desk[i] == check[i]));
	}

	//for (int i = 0; i < n; ++i)
	//{
	//	cout << desk[i] << endl;
	//}
	//cout << endl;
	//for (int i = 0; i < n; ++i)
	//{
	//	cout << check[i] << endl;
	//}

	if (good)
	{
		cout << "YES\n";
		answer[n - 1][n - 1] = 'o';
		for (int i = 0; i < 2 * n - 1; ++i)
		{
			cout << answer[i] << endl;
		}
	}
	else
	{
		cout << "NO";
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}