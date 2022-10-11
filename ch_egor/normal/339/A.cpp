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

string st;

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
	int n = st.size();
	vector<int> arr;
	for (int i = 0; i < (int)st.size(); i += 2)
		arr.push_back(st[i] - '0');
	sort(arr.begin(), arr.end());
	for (int i = 0; i < (int)arr.size(); ++i)
		printf("%d%c", arr[i], "+\n"[i == (int)arr.size() - 1]);

	return 0;
}