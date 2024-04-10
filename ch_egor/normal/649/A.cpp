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
const int MAX_N = 105;

int n;
int arr[MAX_N];

int cnt(int x)
{
	int answer = 0;
	while (x % 2 == 0)
	{
		++answer; 
		x /= 2;
	}
	return answer;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	int max_a = 0;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &arr[i]);
		max_a = max(cnt(arr[i]), max_a);
	}

	int ans = 0;

	for (int i = 0; i < n; ++i)
	{
		if (cnt(arr[i]) == max_a)
		{
			++ans;
		}
	}

	cout <<  (1<< max_a) << " " << ans << endl;

	fclose(stdin);
	fclose(stdout);

	return 0;
}