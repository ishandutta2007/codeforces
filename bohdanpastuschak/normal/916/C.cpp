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
#include <complex>
#include <stdio.h>
#include <unordered_set>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC target("sse4")

typedef double LD;
typedef long long LL;
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

const LD PI = acos(-1.0);
const LL mod = 1000000007;
const LL INF = 1e6;
const LL LINF = 1e18;

bool prime(int n)
{
	if (n == 1)
		return 0;
	if (n < 4)
		return 1;
	for (int i = 2; i * i <= n; ++i)
		if (n%i == 0)
			return 0;
	return 1;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);

	/*LL n, k;
	cin >> n >> k;

	int bt = 0;
	LL t = n;
	while (t)
	{
		if (t & 1)
			++bt;
		t >>= 1;
	}

	if (bt > k)
	{
		cout << "NO";
		return 0;
	}

	FOR(ans, 0, 60)
	{


	}

	cout << "NO";*/

	int n, m;
	cin >> n >> m;

	if (n == 2)
	{
		cout << 2 << " " << 2 << endl;
		cout << "1 2 2" << endl;
		return 0;
	}

	int p = n - 1;
	while (!prime(p))
		++p;

	vector<pair<int, PII>> e;
	FOR(i, 0, n - 2)
		e.push_back(MP(1, MP(i, i + 1)));

	e.push_back(MP(p - (n - 2), MP(n - 2, n - 1)));
	
	m -= (n - 1);
	int curr = 0;
	int curr_y = 2;
	while (m)
	{
		if (curr_y == n)
		{
			curr++;
			curr_y = curr + 2;
		}

		--m;
		e.push_back(MP(INF, MP(curr, curr_y)));
		curr_y++;
	}

	cout << p << " " << p << endl;
	for (auto i : e)
		cout << i.Y.X + 1 << " " << i.Y.Y + 1 << " " << i.X << endl;

	cin >> n;
	return 0;
}