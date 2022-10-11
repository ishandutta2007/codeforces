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

int n;
int arr[228228];
set<pair<int, int>> bad;
set<pair<int, int>> good;
vector<pair<int, int>> answer;

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
	scanf("%d", &arr[0]);
	good.insert({arr[0], 1});
	for (int i = 1; i < n; ++i)
	{
		scanf("%d", &arr[i]);
		bad.insert({-arr[i], i + 1});
	}
	
	while (!bad.empty() && !good.empty())
	{
		auto it = good.begin();
		pair<int, int> now = *it;
		good.erase(it);
		if (now.first == 0) continue;
		--now.first;
		good.insert(now);
		auto er = bad.begin();
		pair<int, int> kk = *er;
		bad.erase(er);
		answer.push_back({now.second, kk.second});
		kk.first = -kk.first;
		good.insert(kk);
	}
	
	if (bad.empty())
	{
		printf("%d\n", (int)answer.size());
		for (int i = 0; i < (int)answer.size(); ++i)
			printf("%d %d\n", answer[i].first, answer[i].second);
	}
	else
	{
		printf("-1\n");
	}

	return 0;
}