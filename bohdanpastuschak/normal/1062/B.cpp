#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:16777216")
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <utility>
#include <time.h>
#include <bitset>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
#define MP make_pair
#define PB push_back
#define X first
#define Y second

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define ITER(it, a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))
#define debug(a) cout << #a << " = " << a << endl;

const double PI = acos(-1.0);
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;

const int MAX = 1 << 10;
int n;
int a[MAX];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);


	cin >> n;
	/*FOR(i, 0, n)
		cin >> a[i];

	int ans = 0;
	int curr = 0;

	FOR(i, 0, n - 1)
	{

	}


	ans = min(n - 2, ans);
	cout << ans << endl;*/

	int rest = n;
	VI pr;
	for (int i = 2; i * i <= n; ++i)
	{
		if (n % i)
			continue;
		while (n % i == 0)
			n /= i;
		pr.push_back(i);
	}

	if (n > 1)
		pr.push_back(n);

	int ans = 1;
	for (auto i : pr)
		ans *= i;

	cout << ans << " ";
	if (ans == rest)
	{
		cout << 0;
		return 0;
	}

	int ans2 = 0;
	n = rest;
	int mx = 1;
	int mn = 1000;
	for (int i = 2; i * i <= n; ++i)
	{
		if (n % i)
			continue;

		int cnt = 0;
		while (n % i == 0)
			++cnt, n /= i;

		mx = max(mx, cnt);
		mn = min(mn, cnt);
	}

	if (n > 1)
		mn = 1;

	if (mn != mx || __builtin_popcount(mx) != 1)
		ans2++;

	while (mx > 1)
		mx = (mx + 1) / 2, ans2++;

	cout << ans2 << endl;

	cerr << "Time elapsed : " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}