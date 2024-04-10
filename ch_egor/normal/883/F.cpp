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
set<string> gg;

int main()
{
#ifdef CH_EGOR
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
#endif

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		string now;
		cin >> now;
		string ff = "";
		for (int i = 0; i < (int)now.size(); ++i)
		{
			if (now[i] == 'u') ff += "oo";
			else if (now[i] == 'h' && !ff.empty() && ff.back() == 'k') 
			{
				while (!ff.empty() && ff.back() == 'k') ff.pop_back();
				ff += "h";
			}
			else
			{
				ff += now[i];
			}

		}
		
		gg.insert(ff);
	}

	cout << gg.size() << "\n";

	return 0;
}