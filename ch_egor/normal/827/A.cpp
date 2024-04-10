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

const int MAX_N = 2 * 1000 * 1000 + 228;

int n;
char st[MAX_N];
char answer[MAX_N];
string kek[100228];
vector<int> ptr[100228];
vector<pair<int, int>> kk;

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
	
	int sz;
	for (int i = 1; i <= n; ++i)
	{
		scanf("%s", st);
		sz = strlen(st);
		kek[i] = st;
		int len;
		scanf("%d", &len);
		
		for (int j = 0; j < len; ++j)
		{
			int now;
			scanf("%d", &now);
			kk.push_back({now, i});
			kk.push_back({now + sz, -i});
		}
	}
	
	sort(kk.begin(), kk.end());

	multiset<pair<int, int>> now;
	int ptr = 1;
	for (int i = 0; i < (int)kk.size(); ++i)
	{
		while (kk[i].first > ptr)
		{
			if (now.empty())
			{
				answer[ptr] = 'a';
			}
			else
			{
				auto pp = *now.begin();
				int beg = pp.first;
				int at = ptr - beg;
				answer[ptr] = kek[pp.second][at];
			}
			++ptr;
		}
		while (kk[i].first == ptr)
		{
			if (kk[i].second > 0)
			{
				now.insert(kk[i]);
			}
			else
			{
				kk[i].second = -kk[i].second;
				kk[i].first -= kek[kk[i].second].size();
				now.erase(kk[i]);
			}
			++i;
		}
		--i;
	}

	answer[ptr] = '\0';
	printf("%s\n", answer + 1);
	return 0;
}