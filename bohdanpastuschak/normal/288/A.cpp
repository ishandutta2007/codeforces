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

#define SZ(a) (LL)(a.size())
#define ALL(a) a.begin(), a.end()
#define FOR(i, a, b) for( uint32_t i = (a); i < (b); ++i)
#define RFOR(i, b, a) for( uint32_t i = (b) - 1; i >= a; --i)
#define REP(i, N) FOR(i, 0, N)
#define MP make_pair
#define X first
#define Y second
#define next fake_next
#define left fake_left
#define right fake_right
#define delete fake_delete
const LD PI = acos(-1.0);
const LL MAXN = 200001;
const LL mod = 1000000007;
const LL INF = 1e9;

int main()
{
	//ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);

	int n, k;
	cin >> n >> k;
	if (k > n)
	{
		cout << -1;
		return 0;
	}

	if (k == 1)
	{
		if (n == 1)
			cout << 'a';
		else
			cout << -1;
		return 0;
	}

	FOR(i, 0, (n + 2 - k) / 2)
		cout << "ab";

	if ((n % 2) == (k % 2))
	{
		FOR(i, 0, k - 2)
			cout << (char)('c' + i);
	}
	else
	{
		cout << 'a';
		FOR(i,0,k - 2)
			cout << (char)('c' + i);
	}

	return 0;
}