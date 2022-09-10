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
const LL MAX = 1e4 + 47;

inline int get(int a, int b)
{
	string s, t;
	while(a)
	{
		s.push_back('0' + a%10);
		a/= 10;
	}
	
	while(b)
	{
		t.push_back('0' + b%10);
		b/= 10;
	}

	reverse(ALL(s));
	reverse(ALL(t));
	//cout << s << " " << t << endl;
	int x = 0, y = 0;
	//cin >> x;
	x = 0;
	while(x < SZ(s))
	{
		while(y < SZ(t) && s[x] != t[y])
			++y;
		
		if (y == SZ(t))
			return INF;
			
		++y;
		++x;
	}
	
	return SZ(t) - SZ(s);
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	
	int n;
	cin >> n;
	
	int best = INF;
	for(LL i = 1; i*i <= n; ++i)
		best = min(best, get(i*i, n));	

	if (best == INF)
		best = -1;
		
	cout << best << endl;
	return 0;
}