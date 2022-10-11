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
const int MAX_N = 505;

int n;
vector<int> answer;
int arr[MAX_N*MAX_N];
map<int, int> cnt;
map<int, int> have;
vector<int> answer_at[MAX_N];
bool good[MAX_N];

int gcd(int a, int b)
{
	if (a%b == 0)
	{
		return b;
	}
	else
	{
		return gcd(b, a%b);
	}
}

int near(int x)
{
	int i;
	for (i = 1; i*i <= x; ++i)
	{

	}
	return i - 1;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);

	for (int i = 0; i < n*n; ++i)
	{
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < n*n; ++i)
	{
		++cnt[arr[i]];
	}

	sort(arr, arr + n*n);

	for (int i = n*n - 1; i >= 0; --i)
	{
		if (cnt[arr[i]] != 0)
		{
			--cnt[arr[i]];
			for (int j = 0; j < answer.size(); ++j)
			{
				cnt[gcd(arr[i], answer[j])] -= 2;
			}
			answer.push_back(arr[i]);
		}
	}

	for (int i = 0; i < answer.size(); ++i)
	{
		printf("%d ", answer[i]);
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}