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
using namespace std;
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
typedef long long LL;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<LD, LD> PDD;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<VI> VVI;
typedef vector<VLL> VVLL;
typedef vector<char> VCH;
typedef vector<VCH> VVCH;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;
#define X first
#define Y second
#define MP make_pair

#define SZ(a) (int)(a.size())
#define ALL(a) a.begin(), a.end()
#define FOR(i,a,b)  for(LL i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(LL i= (b) - 1; i >= (a); --i)

const LL MAXN = 100000;
const LL INF = 1e9;
const LL mod = 1000000007;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	int n;
	cin >> n;

	VI ans;

	int from = max(0, n - 1000);
	int sum, t;
	FOR(i, from, n + 1)
	{
		t = i;
		sum = 0;
		while (t)
		{
			sum += t % 10;
			t /= 10;
		}

		if (sum + i == n)
			ans.push_back(i);
	}



	cout << ans.size() << endl;
	FOR(i, 0, ans.size())
		cout << ans[i] << endl;

	//cin >> n;
	return 0;
}