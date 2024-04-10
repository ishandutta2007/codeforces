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

int gg[4282282];
int a[2005];
int b[2005];
int n;

int main()
{
#ifdef CH_EGOR
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
#endif 	

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]), gg[a[i]] = 1;
	for (int i = 0; i < n; ++i) scanf("%d", &b[i]), gg[b[i]] = 1;

	int ans = 0;
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j)
		if (gg[a[i] ^ b[j]]) ++ans;
	
	if (ans % 2 == 0)
		printf("Karen");
	else
		printf("Koyomi");

	return 0;
}