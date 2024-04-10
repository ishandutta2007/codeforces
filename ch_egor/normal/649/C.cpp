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

int n, x, y;
int arr[200228];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d %d %d", &n, &x, &y);

	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &arr[i]);
	}

	sort(arr, arr + n);

	int answer = 0;
	for (int i = 0; i < n; ++i)
	{
		//cout << arr[i] << " " << x << " " << y << "!!" << endl;
		if (arr[i] / 2 <= x)
		{
			if ((arr[i] & 1) && y > 0)
			{
				//cout << 1 << endl;
				x -= arr[i] / 2;
				--y;
				++answer;
			}
			else if ((arr[i]&1) && y == 0)
			{
				if (arr[i] / 2 < x)
				{
					//cout << 2 << endl;
					x -= arr[i] / 2 + 1;
					++answer;
				}
			}
			else if (!(arr[i] & 1))
			{
				//cout << 3 << endl;
				x -= arr[i] / 2;
			    ++answer;
			}
		}
		else
		{
			arr[i] -= 2 * x;
			x = 0;
			if (y >= arr[i])
			{
				//cout << 4 << endl;
				y -= arr[i];
				++answer;
			}
		}
	}

	cout << answer;

	fclose(stdin);
	fclose(stdout);

	return 0;
}