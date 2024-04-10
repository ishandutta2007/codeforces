//#include <bits/stdc++.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <cstring>
#include <queue>
#include <deque>
#include <cmath>
#include <ctime>
#include <cassert>
#include <set>
#include <bitset>
#include <iomanip> 
#include <stack>

//#pragma comment(linker, "/STACK:256000000")

using namespace std;

#define make_pair mp
#define push_back pb
#define insert ins
#define erase er

typedef long long int ll;
typedef long double ld;	

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef vector<int> vvi;
typedef vector<ll> vvl;
typedef vector<string> vvs;

const int INF = 1000 * 1000 * 1000 +5;
const ll LLINF = 1ll * INF * INF + 5;
const int MOD = 1000 * 1000 * 1000 + 7;


int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	string st;
	cin >> st;

	string gg = "AHIMOoTUVvWwXxY";

	int hl = (st.size() + 1) >> 1;

	for (int i = 0; i < (st.size() >> 1); ++i)
	{
		if (gg.find(st[i]) == string::npos)
		{
			if (st[i] != 'd' && st[i] != 'b' && st[i] != 'q' && st[i] != 'p')
			{
				printf("NIE");
				return 0;
			}
			else
			{
				if ((st[i] == 'b' && st[(int)st.size() - i - 1] == 'd') ||
					(st[i] == 'd' && st[(int)st.size() - i - 1] == 'b') ||
					(st[i] == 'p' && st[(int)st.size() - i - 1] == 'q') ||
					(st[i] == 'q' && st[(int)st.size() - i - 1] == 'p'))
				{
					continue;
				}
				printf("NIE");
				return 0;
			}
		}
		else if (st[i] != st[(int)st.size() - i - 1])
		{
			printf("NIE");
			return 0;
		}
	}

	if (st.size() % 2 == 1 && gg.find(st[st.size() >> 1]) == string::npos)
	{
		printf("NIE");
		return 0;
	}	

	printf("TAK");

	fclose(stdin);
	fclose(stdout);

	return 0;
}