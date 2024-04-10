#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
#define REP(i, n) for(int i = 0;i < n;i ++)
#define REP1(i, n) for(int i = 1;i <= n;i ++)
#define FILL(i, n) memset(i, n, sizeof(i))
#define X first
#define Y second
#define pb push_back
#define ALL(_a) (_a).begin(), (_a).end()
#define SZ(_a) ((int)(_a).size())
#ifdef brian
#define IOS()
template<typename T>void _do(T &&x){cerr<<x<<endl;}
template<typename T, typename ...t>void _do(T &&x, t &&...X){cerr<<x<<", ";_do(X...);}
#define debug(...) {\
	fprintf(stderr, "%s - %d (%s) = ", __PRETTY_FUNCTION__, __LINE__, #__VA_ARGS__);\
	_do(__VA_ARGS__);\
}
#else
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(...)
#endif

const ll MAXn = 1e5 + 5;
const ll INF = ll(1e18);
const ll MOD = 998244353;

inline int trans(char c)
{
	if(islower(c))return c - 'a';
	else if(isupper(c))return c - 'A' + 26;
	else return c - '0' + 52;
}

ll ct[70][70];
ll tct[70][70][70];

ll fac[2][2][2];

int main(){
	IOS();
	ll n;
	cin>>n;
	set<string> st;
	REP(i, n)
	{
		 string s;
		 cin>>s;
		 st.insert(s);
		 reverse(ALL(s));
		 st.insert(s);
	}
	REP(a, 2)REP(b, 2)REP(c, 2)
	{
		ll t = 24;
		if(a && b && c)t /= 24;
		else if(a && b)t /= 6;
		else if(b && c)t /= 6;
		else REP(i, a + b + c)t /= 2;
		fac[a][b][c] = t;
	}
	ll tt = 0, C = 62;
	for(int l = 3;l <= 10;l ++)
	{
		FILL(ct, 0);
		for(auto s:st)if(SZ(s) == l)ct[trans(s[0])][trans(s.back())]++;
		FILL(tct, 0);
		for(int a = 0;a < C;a ++)
			for(int b = a;b < C;b ++)
				for(int c = b;c < C;c ++)
					REP(d, C)
						tct[a][b][c] = (tct[a][b][c] + ct[a][d] * ct[b][d] * ct[c][d]) % MOD;

		for(int a = 0;a < C;a ++)
			for(int b = a;b < C;b ++)
				for(int c = b;c < C;c ++)
					for(int d = c;d < C;d ++)
		{
			
			tt = (tt + tct[a][b][c] * tct[a][b][d] % MOD * tct[a][c][d] % MOD * tct[b][c][d] % MOD * fac[a == b][b == c][c == d]) % MOD;
		}
	}
	cout<<tt<<endl;
}