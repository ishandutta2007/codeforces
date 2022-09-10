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
const LL MAX = 2e5 + 1;

int n;
int a[MAX];
VI g[MAX];
LL DP[MAX];
VI vert[MAX];
bool ye[MAX];
bool pozn[MAX];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);

	cin >> n;
	FOR(i, 0, n)
	{
		cin >> a[i];
		vert[a[i]].push_back(i);
	}

	int u, v;
	FOR(i, 0, n - 1)
	{
		cin >> u >> v;
		--u; --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	FOR(i, 1, MAX)
	{
		VI marked;
		for (int j = i; j < MAX; j += i)
		{
			for(auto k: vert[j])
			{
				marked.push_back(k);
				ye[k] = 1;
				pozn[k] = 0;
			}
		}

		queue<int> q;
		LL tut = 0;
		for(auto k: marked)
		{
			if (pozn[k])
				continue;
						
			q.push(k);
			pozn[k] = 1;
			int ye1 = 1;
			while (!q.empty())
			{
				int t = q.front();
				q.pop();

				for(auto su: g[t])
				{
					if (pozn[su] || ye[su] == 0)
						continue;

					pozn[su] = 1;
					++ye1;
					q.push(su);
				}
			}

			tut += ye1 * 1LL * (ye1 - 1) / 2LL;
		}

		DP[i] = tut;
		for(auto k: marked)
			ye[k] = 0;
	}

	RFOR(i, MAX, 1)
		for (int j = i * 2; j < MAX; j += i)
			DP[i] -= DP[j];

	FOR(i, 1, MAX)
		DP[i] += SZ(vert[i]);

	FOR(i, 1, MAX)
		if (DP[i])
			cout << i << " " << DP[i] << endl;

	//cin >> n;
	return 0;
}