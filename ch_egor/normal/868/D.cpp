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

const int MAX_N = 105;
const int MAX_ANS = 14;
const int MAX_LEN = 300;

struct stt
{
	string pr;
	string sf;
	bool have[MAX_ANS][1 << MAX_ANS];
	
	stt()
	{
		pr = "";
		sf = "";
		memset(have, 0, sizeof(have));
	}
};

int n, m;
stt arr[MAX_N * 2];
char buf[MAX_LEN];

stt gen(const char *now)
{
	string st = now;
	stt ans;
	
	for (int i = 0; i < (int)st.size(); ++i)
	{
		int cur = 0;
		for (int j = i; j < min((int)st.size(), i + MAX_ANS); ++j)
		{
			cur = (cur << 1) + st[j] - '0';
			ans.have[j - i][cur] = true;
		}
	}

	for (int i = 0; i < min((int)st.size(), MAX_ANS); ++i)
	{
		ans.pr += st[i];
	}

	for (int i = max(0, (int)st.size() - MAX_ANS); i < (int)st.size(); ++i)
	{
		ans.sf += st[i];
	}

	return ans;
}

stt add(stt a, stt b)
{
	stt ans;
	for (int i = 0; i < MAX_ANS; ++i)
	{
		for (int j = 0; j < (1 << (i + 1)); ++j)
		{
			ans.have[i][j] = (a.have[i][j] || b.have[i][j]);
		}
	}
	
	string st = a.sf + b.pr; 
	
	for (int i = 0; i < (int)st.size(); ++i)
	{
		int cur = 0;
		for (int j = i; j < min((int)st.size(), i + MAX_ANS); ++j)
		{
			cur = (cur << 1) + st[j] - '0';
			ans.have[j - i][cur] = true;
		}
	}

	st = a.pr + b.pr;

	for (int i = 0; i < min((int)st.size(), MAX_ANS); ++i)
	{
		ans.pr += st[i];
	}

	st = a.sf + b.sf;

	for (int i = max(0, (int)st.size() - MAX_ANS); i < (int)st.size(); ++i)
	{
		ans.sf += st[i];
	}

	return ans;
}

int get(stt a)
{
	for (int i = 0; i < MAX_ANS; ++i)
	{
		for (int j = 0; j < (1 << (i + 1)); ++j)
		{
			if (!a.have[i][j])
			{
				return i;
			}
		}
	}

	return MAX_ANS;
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

	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%s", buf);
		arr[i] = gen(buf);
	}

	scanf("%d", &m);
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		--a; --b;
		arr[n + i] = add(arr[a], arr[b]);
		printf("%d\n", get(arr[n + i]));
	}

	return 0;
}