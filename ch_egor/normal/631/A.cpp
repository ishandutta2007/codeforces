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

int n, m;
int64 a[1111]; 
int64 b[2222];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	
	int64 answer = 0;
	for (int i = 0; i < n; ++i)
	{
		scanf("%I64d", &a[i]);
		answer |= a[i];
	}
	int64 answer1 = 0;
	for (int i = 0; i < n; ++i)
	{
		scanf("%I64d", &a[i]);
		answer1 |= a[i];
	}
	
	cout << answer + answer1;

	fclose(stdin);
	fclose(stdout);

	return 0;
}