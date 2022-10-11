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

const int  MAX_K = 5005;

int n, k;
string arr[MAX_K];
char buf[MAX_K];

bool check(string &a, string &b)
{
	if (a == b)
	{
		int cnt[27] = {0};
		for (int i = 0; i < n; ++i) ++cnt[a[i] - 'a'];
		for (int i = 0; i < 26; ++i) if (cnt[i] >= 2) return true;
		return false;
	}
	vector<int> df;
	for (int i = 0; i < n; ++i)
	{
		if (a[i] != b[i]) df.push_back(i);
	}

	if ((int)df.size() == 0) return true;

	if ((int)df.size() == 2)
	{
		swap(a[df[0]], a[df[1]]);
		bool good = (a == b);
		swap(a[df[0]], a[df[1]]);
		return good;
	}
	return false;
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

	scanf("%d%d", &k, &n);

	for (int i = 0; i < k; ++i)
	{
		scanf("%s", buf);
		arr[i] = buf;
	}

	if (k == 1)
	{
		if (n >= 2) swap(arr[0][0], arr[0][1]);
		return 0 * printf("%s\n", arr[0].c_str());
	}
	vector<int> df_p;
	
	for (int j = 0; j < k; ++j)
	{
		if (arr[0] != arr[j])
		{
			for (int i = 0; i < n; ++i)
			{
				if (arr[0][i] != arr[j][i])
				{
					df_p.push_back(i);
				}
			}
		}
		sort(df_p.begin(), df_p.end());
		df_p.resize(unique(df_p.begin(), df_p.end()) - df_p.begin());
		while (df_p.size() > 7) df_p.pop_back();
		if (df_p.size() >= 7) break;
	}
	if (df_p.size() == 0) df_p.push_back(0);
	if (df_p.size() == 1 && n >= 2) df_p.push_back(1);
	if (df_p.size() > 7) return 0 * printf("-1\n");

	vector<int> cp = df_p;
	sort(df_p.begin(), df_p.end());
	
	do {
		string now = arr[0];
		
		for (int i = 0; i < (int)cp.size(); ++i)
		{
			now[cp[i]] = arr[0][df_p[i]];
		}
		
		bool good = true;
		for (int i = 0; i < k && good; ++i)
		{
			good &= check(now, arr[i]);
		}
		if (good) return 0 * printf("%s\n", now.c_str());

	} while (next_permutation(df_p.begin(), df_p.end()));
	
	printf("-1\n");

	return 0;

}