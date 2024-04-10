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

	string st;
	cin >> st;

	bool f1 = true;
	for (int i = 1; i < (int)st.size(); ++i)
		f1 &= (st[i] >= 'A' && st[i] <= 'Z');
	
	if (f1)
	{
		if (st[0] >= 'A' && st[0] <= 'Z')
			st[0] += 'a' - 'A';
		else
			st[0] += 'A' - 'a';
		for (int i = 1; i < (int)st.size(); ++i)
			st[i] += 'a' - 'A';
		cout << st;
	}
	else
		cout << st;

	return 0;
}