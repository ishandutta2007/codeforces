#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <cmath>
#include <iterator>
#include <iomanip>
#include <cassert>
#include <string.h>
#include <cstdio>
#include <complex>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC target("sse4")

typedef double LD;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LD, LD> PDD;
typedef pair<LL, LL> PLL;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef vector<VI> VVI;
typedef vector<LL> VLL;
#define MP make_pair
#define PB push_back
#define X first
#define Y second
#define next fake_next

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define REP(i, t) FOR(i, 0, t)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))

const LD PI = acos(-1.0);
const LD EPS = 1e-9;
const LL INF = 1e9;
const LL LINF = 1e18;
const LL mod = 1e9 + 7;
const LL MAX = 1e6 + 47;

string go(int x)
{
	string res;
	while (x)
	{
		int r = x % 26;
		if (r == 0)
			res.push_back('Z');
		else
			res.push_back('A' + r - 1);

		x /= 26;
		if (!r)
			--x;
	}

	reverse(ALL(res));
	return res;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);

	int n;
	cin >> n;
	while (n--)
	{
		string s, t;
		cin >> s;
		int n = SZ(s);

		bool first = 0;
		bool wzhe = 0;
		FOR(i, 0, n)
		{
			if (wzhe && s[i] == 'C')
			{
				first = 1;
				break;
			}

			if (s[i] >= 'A' && s[i] <= 'Z')
				continue;

			wzhe = 1;
		}

		if (first)
		{
			int x = 0, y = 0;
			bool wtf = 0;
			FOR(i, 1, n)
			{
				if (s[i] >= '0' && s[i] <= '9')
				{
					if (!wtf)
					{
						x *= 10;
						x += s[i] - '0';
					}
					else
					{
						y *= 10;
						y += s[i] - '0';
					}
				}
				else
					wtf = 1;
			}

			t = go(y);

			//reverse(ALL(t));
			cout << t << x << endl;
		}
		else
		{
			int x = 0;
			int id = -1;
			FOR(i, 0, n)
			{
				if (s[i] >= '0' && s[i] <= '9')
				{
					id = i;
					break;
				}

				x *= 26;
				x += s[i] - 'A' + 1;
			}

			cout << "R";
			FOR(i, id, n)
				cout << s[i];

			cout << "C";
			cout << x;
			cout << endl;
		}
	}

	return 0;
}