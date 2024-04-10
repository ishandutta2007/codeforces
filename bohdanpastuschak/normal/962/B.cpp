#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC target("sse4")

typedef long double LD;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LD, LD> PDD;
typedef pair<LL, LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<LD> VLD;
typedef vector<string> VS;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;
#define MP make_pair
#define PB push_back
#define X first
#define Y second
#define next fake_next
#define prev fake_prev
#define left fake_left
#define right fake_right

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define REP(i, t) FOR(i, 0, t)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))

const LD PI = acos(-1.0);
const LD EPS = 1e-6;
const LL INF = 1e9;
const LL LINF = 1e18;
const LL mod = 1e9 + 7;
const LL MAX = 1e6 + 47;

LL n, a, b;
string s;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	
	cin >> n >> a >> b >> s;
	LL ans = 0;
	bool ok1 = 1, ok2 = 1;
	FOR(i, 0, SZ(s))
	{
		if (s[i] == '*')
		{
			ok1 = 1;
			ok2 = 1;
			continue;
		}
		
		if (a >= b)
		{
			if (ok1 && a)
				{
				ok1 = 0;
				ok2 = 1;
				--a;
				++ans;
				}
				else
				{
					if (b && ok2)
					{
					ok2 = 0;
					ok1 = 1;
					--b;
					++ans;
					}
					else
					{
					ok1 = ok2 = 1;
					}
				}
		}
		else
		{
			if (ok2 && b)
							{
							ok2 = 0;
							ok1 = 1;
							--b;
							++ans;
							}
							else
							{
								if (a && ok1)
								{
								ok1 = 0;
								ok2 = 1;
								--a;
								++ans;
								}
								else
								{
								ok1 = ok2 = 1;
								}
							}
		
		
		
		}
	}
	
	
	cout << ans  << endl;
	return 0;
}