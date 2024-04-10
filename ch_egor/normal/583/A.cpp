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
const int MAX_N = 55;

int n;
bool arr_x[MAX_N];
bool arr_y[MAX_N];
vector<int> answer;


int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	for (int i = 0; i < MAX_N; ++i)
	{
		arr_x[i] = false;
		arr_y[i] = false;
	}

	scanf("%d", &n);

	int x, y;
	for (int i = 1; i <= n*n; ++i)
	{
		scanf("%d %d", &x, &y);
		if (!arr_x[x] && !arr_y[y])
		{
			printf("%d ", i);
			arr_x[x] = true;
			arr_y[y] = true;
		}
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}