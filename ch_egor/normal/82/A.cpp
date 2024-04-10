#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <assert.h>
#include <algorithm>
#include <iomanip>
#include <time.h>
#include <math.h>
#include <bitset>

#pragma comment(linker, "/STACK:256000000")

using namespace std;

typedef long long int ll;
typedef long double ld;

const int INF = 1000 * 1000 * 1000 + 21;
const ll LLINF = (1ll << 60) + 5;
const int MOD = 1000 * 1000 * 1000 + 7;

string arr[] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};

int main()
{
#ifdef CH_EGOR
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
#endif

	ll len = 5;
	int n;
	cin >> n;
	while (n > len)
	{
		n -= len;
		len *= 2;
	}

	ll pp = len / 5;
	int ptr = 0;
	while (pp < n)
	{
		++ptr;
		pp += len / 5;
	}
	cout << arr[ptr];
	return 0;
}