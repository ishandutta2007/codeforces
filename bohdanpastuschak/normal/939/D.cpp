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
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC target("sse4")

typedef double LD;
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
const LL mod = 1000000007;
const LL LINF = 1e18 + 10;
const LL MAXN = 1e5 + 7;

VVI g;
VCH used;
VI cnt;

void dfs(int v)
{
	cnt.push_back(v);
	used[v] = 1;
	for (auto i : g[v])
		if (used[i] == 0)
			dfs(i);
}


int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);

	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;
	g.resize(26);
	FOR(i, 0, n)
		if (a[i] != b[i])
			g[a[i] - 'a'].push_back(b[i] - 'a'), g[b[i] - 'a'].push_back(a[i] - 'a');

	used.assign(26, 0);
	VVI c;
	FOR(i, 0, 26)
	{
		if (used[i] == 0)
		{
			cnt.clear();
			dfs(i);
			if (SZ(cnt) > 1)
				c.push_back(cnt);
		}
	}

	int ans = 0;
	for (auto i : c)
		ans += SZ(i) - 1;
	cout << ans << endl;
	
	for (auto i : c)
	{
		char x = i[0] + 'a';
		FOR(j, 1, SZ(i))
			cout << x << " " << (char)('a' + i[j]) << endl;
	}

	cin >> n;
	return 0;
}