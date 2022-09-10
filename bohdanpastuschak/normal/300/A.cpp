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

int n;
int a[MAX];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);

	while (cin >> n)
	{
		FOR(i, 0, n)
			cin >> a[i];

		VI p, z, m;
		FOR(i, 0, n)
			if (a[i] == 0)
				z.push_back(a[i]);

		int pl = 0, mi = 0;
		FOR(i, 0, n)
			if (a[i] > 0)
				++pl;
			else
				if (a[i] < 0)
					++mi;

		if (mi & 1)
		{
			if (pl)
			{
				FOR(i, 0, n)
					if (a[i] > 0)
						p.push_back(a[i]);
					else
						if (a[i] < 0)
							m.push_back(a[i]);
			}
			else
			{
				FOR(i, 0, n)
				{
					if (a[i] == 0)
						continue;

					if (SZ(p) < 2)
					{
						p.push_back(a[i]);
						continue;
					}

					
					m.push_back(a[i]);	
				}
			}
		}
		else
		{
			if (pl)
			{
				bool wtf = 0;
				FOR(i, 0, n)
					if (a[i] > 0)
						p.push_back(a[i]);
					else
					{
						if (a[i] < 0)
						{
							if (wtf)
								m.push_back(a[i]);
							else
								z.push_back(a[i]);

							wtf = 1;
						}
					}					
			}
			else
			{
				bool wtf = 0;
				FOR(i, 0, n)
				{
					if (a[i] == 0)
						continue;

					if (SZ(p) < 2)
					{
						p.push_back(a[i]);
						continue;
					}

					if (wtf)
						m.push_back(a[i]);
					else
						z.push_back(a[i]);

					wtf = 1;
				}
			}
		}

		cout << SZ(m);
		FOR(i, 0, SZ(m))
			cout << " " << m[i];
		cout << endl;

		cout << SZ(p);
		FOR(i, 0, SZ(p))
			cout << " " << p[i];
		cout << endl;

		cout << SZ(z);
		FOR(i, 0, SZ(z))
			cout << " " << z[i];
		cout << endl;
	}

	return 0;
}