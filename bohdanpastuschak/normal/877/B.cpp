#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>
#include <functional>
#include <cstring>
#include <queue>
#include <cmath>
#include <deque>
#include <list>
#include <iomanip>
#include <fstream>
#include <string>
#include <iterator>
#include <set>
#include <bitset>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<char> VCH;
typedef vector<VI> VVI;
typedef vector<VLL> VVLL;
typedef vector<VCH> VVCH;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<LD, LD> PDD;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;

#define SZ(a) (int)(a.size())
#define ALL(a) a.begin(), a.end()
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= a; --i)
#define REP(i, N) FOR(i, 0, N)
#define MP make_pair
#define X first
#define Y second
#define next fake_next
#define left fake_left
#define right fake_right

const LD PI = acos(-1.0);
const LL MAXN = 100007;
const LL mod = 1000000007;
const LL INF = 1e18;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);

	string s;
	cin >> s;

	int n = SZ(s);
	int ans = 0;

	VI a(n);
	FOR(i, 0, n)
		if (s[i] == 'a')
			a[i] = 0;
		else
			a[i] = 1;
	
	int na = 0, nb = 0;
	FOR(i, 0, n)
		if (a[i])
			++nb;
		else
			++na;

	ans = max(na, nb);

	VI n_a(n), n_b(n);
	n_a[0] = 0;
	if (a[0] == 0)
		n_a[0]++;

	FOR(i, 1, n)
	{
		n_a[i] = n_a[i - 1];
		if (a[i] == 0)
			n_a[i]++;
	}

	n_b[0] = a[0];
	FOR(i, 1, n)
		n_b[i] = n_b[i - 1] + a[i];

	int toDel;
	FOR(i, 0, n)
		FOR(j, i, n)
	{
		toDel = 0;
		if (i)
			toDel += n_b[i - 1];

		toDel += (n_b[n - 1] - n_b[j]);
		int del_a = n_a[j];
		if (i)
			del_a -= n_a[i - 1];

		toDel += del_a;

		ans = max(ans, n - toDel);
	}


	cout << ans;
	//cin >> n;
	return 0;
}