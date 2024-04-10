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
const LL mod = 1e9 + 9;
const LL MAX = 1e5 + 47;

LL n, a, b, k;
string s;

LL power(LL x, LL y)
{
	LL r = 1;
	while(y)
	{
		if (y  & 1)
			r = (r*x)%mod;
		x=(x*x)%mod;
		y>>=1;
	}

	return r;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	
	cin >> n >> a >> b >> k;
	cin >> s;
	
	LL ans = 0;
	
	LL times = (n + 1)/k;
	
	LL val = 0;
	
	LL inv_a = power(a, mod - 2);
	LL curr_a = power(a, n), curr_b = 1;
	
	FOR(i, 0, k)
	{
		bool plus = (s[i] == '+');
		LL add = curr_a*curr_b;
		add%=mod;		
		if (plus)
		{
			val += add;
			val%=mod;
		}
		else
		{
			val -= add;
			val+=mod;
			val%=mod;
		}
		
		curr_a *= inv_a;
		curr_b*= b;
		curr_a%= mod;
		curr_b%=mod;
	}
	
	LL v = power(b, k);
	v*= power(power(a, k), mod - 2);
	v%=mod;
	
	if (v == 1)
	{
		ans = val * times;
		ans%=mod;
		cout << ans << endl;
		return 0;
	}
	
	LL shos = power(v, times) - 1;
	shos *= power(v - 1, mod - 2);
	shos%=mod;
	ans = shos;
	ans*= val;
	ans%=mod;
	
	cout << ans << endl;
	return 0;
}