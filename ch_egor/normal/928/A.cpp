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

string get(string st)
{
	string ans = "";
	for (int i = 0; i < (int)st.size(); ++i)
	{
		if ('A' <= st[i] && st[i] <= 'Z') ans += st[i] - 'A' + 'a';
		else ans += st[i];
	}

	for (int i = 0; i < (int)st.size(); ++i)
	{
		if (ans[i] == '0') ans[i] = 'o';
		if (ans[i] == 'l' || ans[i] == 'i') ans[i] = '1';
	}

	return ans;
}

string st;
int n;
string now;

int main()
{
#ifdef CH_EGOR
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
#endif

	cin >> st;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> now;
		if (get(st) == get(now)) return 0 * printf("No\n");
	}

	printf("Yes\n");

	return 0;
}