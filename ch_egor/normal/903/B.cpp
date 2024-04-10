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


int main()
{
#ifdef CH_EGOR
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
#endif 	

	ll h1, a1, c1;
	ll h2, a2;
	cin >> h1 >> a1 >> c1 >> h2 >> a2;
	
	vector<string> ans;
	while (h2 > 0)
	{
		if (h2 - a1 <= 0) ans.push_back("STRIKE"), h2 = 0;

		else if (h1 - a2 <= 0)
		{
			h1 += c1 - a2;
			ans.push_back("HEAL");
		}
		else
		{
			h2 -= a1;
			h1 -= a2;
			ans.push_back("STRIKE");
		}
	}

	printf("%d\n", (int)ans.size());
	for (int i = 0; i < (int)ans.size(); ++i)
	{
		printf("%s\n", ans[i].c_str());
	}

	return 0;
}