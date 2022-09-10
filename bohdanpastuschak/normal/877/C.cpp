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
	int n;
	cin >> n;

	if (n == 1)
	{
		cout << 2 << endl;
		cout << 1 << " " << 1;
		return 0;
	}

	if (n == 2)
	{
		cout << 3 << endl;
		cout << "2 1 2";
		return 0;
	}

	if (n == 3)
	{
		cout << 4 << endl;
		cout << "2 1 3 2";
		return 0;
	}

	if (n & 1)
	{
		int k = n / 2;
		cout << n + k << endl;

		cout << 2 << " " << 1 << " " << n - 1 << " " << n << " ";
		for (int i = 4; i <= n - 3; i += 2)
			cout << i << " ";
		for (int i = 3; i <= n - 2; i += 2)
			cout << i << " ";
		for (int i = 2; i <= n - 1; i += 2)
			cout << i << " ";
	}
	else
	{
		cout << n + n / 2 << endl;
		int k = n / 2;

		cout << "2 1 " << n - 1 << " " << n << " ";
		for (int i = 4; i <= n - 2; i += 2)
			cout << i << " ";
		for (int i = 3; i <= n - 3; i += 2)
			cout << i << " ";
		for (int i = 2; i <= n - 2; i += 2)
			cout << i << " ";
		cout << n - 1;
	}

	//cin >> n;
	return 0;
}