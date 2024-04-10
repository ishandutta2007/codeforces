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
const LL mod = 10000000000000061;
const LL MAX = 2e5 + 47;
int n , m;
string s[2000];
string t[200];
LL h[200][2000];
vector<pair<LL , int> > h1 , h2;
LL baseInStep = 1 , bin = 1;
LL mult(LL a, LL b)
{
	return (a * b) % mod;
}
LL add(LL a , LL b)
{
	return (a + b) >= mod ? a + b - mod : a + b;
}
LL sub(LL a , LL b)
{
	a -= b;
	if(a < 0)
		a += mod;
	return a;
}
vector<LL> ost;
int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	cin >> n >> m;
	for(int i = 0; i < m - 1; i++)
		bin = 29 * bin;
	for(int i = 0; i < m * m - 1; i++)
	{
		if(i % m == 0)
			ost.PB(baseInStep);
		baseInStep *= 29;
	}
	if(!ost.size())
		ost.PB(1);
	for(int i = 0; i < n; i++)
		cin >> s[i];
	for(int i = 0; i < m; i++)
		cin >> t[i];
	LL hash = 0;
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < m; j++)
		{
			hash *= 29;
			hash += s[i][j] - 'a';
		}
		
	}
	h1.PB(MP(hash , 1));

	for(int i = 0; i < n - m; i++)
	{
		for(int j = 0; j < m; j++)
		{
			hash -= (s[i][j] - 'a') * baseInStep;
			hash *= 29;
			hash += s[i + m][j] - 'a';
		}
		h1.PB(MP(hash , i + 2));
	}

	for(int i = 0; i < m; i++)
	{
		hash = 0;
		for(int j = 0; j < m; j++)
		{
			hash *= 29;
			hash += t[i][j] - 'a';
			
		}
		h[i][0] = hash;
		for(int j = 0; j < n - m; j++)
		{	
			hash -= (t[i][j] - 'a') * bin;
			hash *= 29;
			hash += (t[i][j + m] - 'a');
			h[i][j + 1] = hash;
		}
	}
	
	for(int i = 0; i < n - m + 1; i++)
	{
		LL curHash = 0;
		for(int j = 0; j < m; j++)
		{
			curHash += ost[m - j - 1] * h[j][i];
		}
		h2.PB(MP(curHash , i + 1));
	}
	hash = 0;
	sort(h2.begin() , h2.end());
	for(int i = 0; i < h1.size(); i++)
	{
		vector<pair<LL , int> > ::iterator it = lower_bound(h2.begin() , h2.end() , MP(h1[i].first , 0));
		if(it == h2.end())
			continue;
		if(h1[i].first == it->first)
		{
			cout << h1[i].second << " " << it->second << endl;
			return 0;
		}
	}
	
	return 0;
}