#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <iterator>
#include <functional>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <fstream>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <list>
#include <sstream>
#include <cstring>
#include <stdio.h>
#include <complex>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC target("sse4")

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<LD, LD> PDD;
typedef pair<LL, LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<char> VCH;
typedef vector<LD> VLD;
typedef vector<string> VS;
typedef vector<VS> VSS;
typedef vector<VI> VVI;
typedef vector<VLL> VVLL;
typedef vector<VCH> VVCH;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;
typedef vector<PDD> VPDD;
#define MP make_pair
#define PB push_back
#define X first
#define Y second
#define next fake_next
#define prev fake_prev
#define left fake_left
#define right fake_right

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(int i = (b) - 1; i >= (a); --i)
#define REP(i, t) FOR(i,0,t)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))

const LD PI = acos(-1.0);
const LD EPS = 1e-9;
const LL INF = 1e9;
const LL LINF = 1e18;
const LL mod = 1000000007;
const LL MAXN = 1e5 + 7;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);

	string s;
	cin >> s;
	int n = SZ(s);

	int cnt0 = 0, cnt1 = 0;
	FOR(i, 0, n)
		if (s[i] == '0')
			++cnt0;
		else
			++cnt1;

	if (s[0] == '1' || s[n - 1] == '1' || cnt0 <= cnt1)
	{
		cout << -1;
		return 0;
	}

	int ans = cnt0 - cnt1;
	VVI res;

	set<int> od, nul;
	FOR(i, 0, n)
		if (s[i] == '0')
			nul.insert(i);
		else
			od.insert(i);

	VI curr;
	FOR(i, 0, ans)
	{
		if (SZ(nul) == 0)
			break;

		int x = *nul.begin();
		if ((SZ(od) == 0)|| (SZ(nul) == 1))
		{
			res.push_back({ x });
			nul.erase(x);
			continue;
		}

		int y = *od.begin();
		nul.erase(x);
		od.erase(y);
		curr.clear();
		bool flag = 0;	
		if (y < x)
		{
			cout << -1;
			return 0;
		}

		curr.push_back(x);
		curr.push_back(y);

		while (1)
		{
			if (flag)
			{
				auto it = od.lower_bound(x);
				if (it == od.end())
					break;


				y = *it;
				curr.push_back(y);
			}
			else
			{
				auto it = nul.lower_bound(y);
				if (it == nul.end())
				{
					cout << -1;
					return 0;
				}

				x = *it;
				curr.push_back(x);
			}

			flag ^= 1;
		}

		for (auto i : curr)
			nul.erase(i), od.erase(i);

		res.push_back(curr);
	}

	if (SZ(nul) || SZ(od))
	{
		cout << -1;
		return 0;
	}

	cout << SZ(res) << endl;
	FOR(i, 0, SZ(res))
	{
		cout << SZ(res[i]) << " ";
		FOR(j, 0, SZ(res[i]))
			cout << res[i][j] + 1 << " ";
		cout << endl;
	}

	cin >> s;
	return 0;
}