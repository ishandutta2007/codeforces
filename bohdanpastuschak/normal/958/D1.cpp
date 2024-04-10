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
const LL MAX = 2e5 + 47;

int gcd(int x, int y)
{
	if (!y)
		return x;
	
	return gcd(y, x%y);
}

int m;
map<PII, int> mp;
PII a[MAX];

int get_a(string s)
{
	bool fg = 0;
	int a = 0, b = 0;
	FOR(i, 0, SZ(s))
	{
		if (s[i] == '+')
		{
			fg = 1;
			continue;
		}
		
		if (fg)
		{
			b*= 10;
			b += s[i] - '0';
		}
		else
		{
			a*= 10;
			a += s[i] - '0';
		}
	}
	//cout << s <<" " << a <<" " << b << endl;
	return a + b;
}

PII get(string s)
{
	int a = 0, c = 0;
	string t;
	FOR(i, 1, SZ(s))
		if (s[i + 1] == 47)
			break;
		else
			t += s[i];
	
	//cout << t << endl;
	int id = SZ(t) + 3;
	c = s[id] - '0';
	if (id < SZ(s) - 1)
	{
		c*= 10;
		c += s[id + 1] - '0';
	}
	//cout << c << endl;
	a = get_a(t);
	int g = gcd(a , c);
	return MP(a/g, c/g);
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	
	cin >> m;
	string s;
	FOR(i, 0, m)
	{
		cin >> s;
		PII r = get(s);
		mp[r]++;
		a[i] = r;
		//cout << r.X <<" " << r.Y << endl;
	}
	
	FOR(i, 0, m)
	{
		if (i)
			cout <<" ";
		cout << mp[a[i]];
	}
	
	return 0;
}