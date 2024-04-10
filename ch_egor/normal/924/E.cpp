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

const int MAX_N = 10000 + 5;

int n, l, r;
int arr[MAX_N];
vector<int> fr;
vector<int> sc;
bool can[MAX_N];
int dp[MAX_N];
int sz = 0;

int solve1(int l, int r)
{
	for (int i = 0; i <= sz; ++i) 
	{
		if (can[i]) dp[i] = 0;
		else dp[i] = -1;
	}

	for (int i = 0; i < (int)fr.size(); ++i)
	{
		for (int j = sz; j >= fr[i]; --j)
		{
			if (dp[j - fr[i]] == -1) continue; 
			int cost = 0;
			if (l <= j - fr[i] && j - fr[i] <= r) cost = 1;
			dp[j] = max(dp[j], dp[j - fr[i]] + cost);	
		}
	}

	int ans = 0;
	for (int i = 0; i <= sz; ++i) ans = max(ans, dp[i]);
	
	return ans;
}

int solve2(int l, int r)
{
	for (int i = 0; i <= sz; ++i) 
	{
		if (can[i]) dp[i] = 0;
		else dp[i] = -1;
	}

	for (int i = 0; i < (int)fr.size(); ++i)
	{
		for (int j = sz; j >= fr[i]; --j)
		{
			if (dp[j - fr[i]] == -1) continue; 
			int cost = 0;
			if (l <= j && j <= r) cost = 1;
			dp[j] = max(dp[j], dp[j - fr[i]] + cost);	
		}
	}

	int ans = 0;
	for (int i = 0; i <= sz; ++i) ans = max(ans, dp[i]);
	
	return ans;
}

int main()
{
#ifdef CH_EGOR
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
#endif 	

	scanf("%d%d%d", &n, &l, &r);
	for (int i = 0; i < n; ++i) scanf("%d", &arr[i]), sz += arr[i];
	for (int i = 0; i < n; ++i)
	{
		int v;
		scanf("%d", &v);
		if (v) fr.push_back(arr[i]);
		else sc.push_back(arr[i]);
	}
	
	can[0] = 1;
	for (int i = 0; i < (int)sc.size(); ++i)
	{
		for (int j = sz; j >= sc[i]; --j) can[j] |= can[j - sc[i]];
	}
	
	int ans = 0;
	sort(fr.begin(), fr.end());
	ans = max(ans, max(solve1(l, r), solve2(sz - r, sz - l)));
	reverse(fr.begin(), fr.end());
	ans = max(ans, max(solve1(l, r), solve2(sz - r, sz - l)));
	
	printf("%d\n", ans);

	return 0;
}