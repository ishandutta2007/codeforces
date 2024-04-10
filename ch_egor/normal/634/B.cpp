#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <cassert>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <bitset>

#pragma comment(linker, "/STACK:256000000")

using namespace std;

typedef long long int int64;
typedef long double double80;

const int INF = (1 << 29) + 5;
const int64 LLINF = (1ll << 60) + 5;
const int MOD = 1000 * 1000 * 1000 + 7;

int n;
int64 s, x;
int64 a, b;
int64 dp[65];
vector<int64> possible;
vector<int64> can[2];

void gen(int64 sum, int poz, int en, int at)
{
	if (poz == en)
	{
		can[at].push_back(sum);
	}
	else
	{
		gen(sum + possible[poz], poz + 1, en, at);
		gen(sum, poz + 1, en, at);
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);


	int64 have = 0;
	int64 ans = 0;
	cin >> s >> x;

	int64 det = 0;

	if (0 ^ s == x)
	{
		det += 2;
	}

	int cnt = 0;
	for (int i = 50; i >= 0; --i)
	{
		if (x & (1ll << i))
		{
			dp[i] = 1ll * (1ll << i);
			s -= (1ll << i);
			++cnt;
		}
		else
		{
			dp[i] = 2ll * (1ll << i);
			possible.push_back(dp[i]);
		}
	}

	if (s < 0)
	{
		cout << 0;
		return 0;
	}

	sort(possible.begin(), possible.end());

	for (int i = (int)possible.size() - 1; i >= 0; --i)
	{
		if (possible[i] > s)
		{
			possible.pop_back();
		}
	}

	n = possible.size();

	gen(0, 0, n / 2, 0);
	gen(0, n / 2, n, 1);

	sort(can[0].begin(), can[0].end());
	sort(can[1].begin(), can[1].end());

	//for (int i = 0; i < can[0].size(); ++i)
	//{
	//	cout << can[0][i] << " ";
	//}
	//cout << endl;
	//for (int i = 0; i < can[1].size(); ++i)
	//{
	//	cout << can[1][i] << " ";
	//}
	//cout << endl;

	for (int i = 0; i < can[0].size(); ++i)
	{
		int64 k = upper_bound(can[1].begin(), can[1].end(), s - can[0][i]) - lower_bound(can[1].begin(), can[1].end(), s - can[0][i]);
		ans += k;
	}

	cout << ans * (1ll << cnt) - det;

	fclose(stdin);
	fclose(stdout);

	return 0;
}