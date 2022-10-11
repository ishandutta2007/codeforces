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
		
	int n, k;
	scanf("%d%d", &n, &k);
	vector<int> gg;
	gg.resize(n);
	for (int i = 0; i < n; ++i)
	{
	   string st;
	   cin >> st;
	   gg[i] = st.size();
	}

	sort(gg.begin(), gg.end());
	string st;
	cin >> st;

	int need = st.size();

	int ans = 0;
	int cnt = 0;
	int ans1 = 0, ans2 = 0;
	for (int i = 0; i < n; ++i)
	{
		++ans;
		++cnt;
		if (gg[i] == need && ans1 == 0) ans1 = ans;
		if (gg[i] == need) ans2 = ans;
		if (cnt == k)
		{
			cnt = 0;
			ans += 5;
		}
	}

	printf("%d %d", ans1, ans2);
	
	return 0;
}