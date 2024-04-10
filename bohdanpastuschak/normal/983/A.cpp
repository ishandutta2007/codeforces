#include <bits/stdc++.h>
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
#define MP make_pair
#define PB push_back
#define X first
#define Y second

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
const LL MAX = 1e5 + 47;

LL gcd(LL x, LL y)
{
	LL x1, y1;
	while(y)
	{
		x1 = y;
		y1 = x % y;
		
		x = x1;
		y = y1;
	}
	
	return x;
}

string solve()
{
	LL p, q, b;
	cin >> p >> q >> b;
	p %= q;
	
	if (p == 0)
		return "Finite";
	
	LL g = gcd(p, q);
	p /= g;
	q /= g;
	
	g = gcd(q, b);
	while(g != 1)
	{
		while(q % g == 0)
			q /= g;
		
		g = gcd(q, b);
	}
	
	if (q == 1)	
		return "Finite";
	else
		return "Infinite";
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	
	int t;
	cin >> t;
	while(t--)
		cout << solve() << endl;
	
	return 0;
}