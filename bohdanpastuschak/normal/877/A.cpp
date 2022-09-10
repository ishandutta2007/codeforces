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

	vector<string> im = { "Danil", "Olya", "Ann", "Slava", "Nikita" };

	int ans = 0;


	FOR(i, 0, 5)
	{
		FOR(j, 0, SZ(s) - SZ(im[i]) + 1)
		{
			bool ok = 1;

			FOR(t, 0, SZ(im[i]))
				if (im[i][t] != s[t + j])
					ok = 0;

			if (ok)
				++ans;
		}
	}

	if (ans == 1)
		cout << "YES";
	else
		cout << "NO";
	
	return 0;
}