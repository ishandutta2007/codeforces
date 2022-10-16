//  228

#include<bits/stdc++.h>
//Ctrl + B
using namespace std;
#define endl '\n'
#define nitro {std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);}
#define pi 3.141592653589793
#define mod 1000000007
#define lb lower_bound
#define ub upper_bound
#define all(v) v.begin(), v.end()
#define dbg(x) cout << x << '\n';
#define case_g(x) cout<<"Case "<<x<<": ";
#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef unsigned long ul;
typedef std::vector<int> vi;
typedef std::vector<ll> vl;
typedef std::vector<bool> vb;
typedef std::pair<int, int> pii;
typedef std::pair<ll, ll> pll;
typedef std::pair<int, bool> pib;
typedef std::vector<pii> vii;
typedef std::vector<pll> vll;
typedef std::vector<pib> vib;
typedef std::unordered_map<int, int> umapii;
typedef std::unordered_map<ll, ll> umapll;
typedef std::unordered_map<int , bool> umapib;
typedef std::map<int, int> mapii;
typedef std::map<ll, ll> mapll;
typedef std::map<int, bool> mapib;

ll modpow(ll a, ll b) { //modulo power
	ll result = 1, M=mod;
	while(b!=0) {
		if(b&1) {
			result = ((result%M)*(a%M))%M;
		}
		a = ((a%M)*(a%M))%M;
		b >>= 1;
	}
	return result;
}

ll modinv(ll a) { //modulo inverse
	ll m = mod, y = 0, x = 1;
	while (a > 1) {
		ll q = a / m, t = m;
		m = a % m;
		a = t;
		t = y;
		y = x - q * y;
		x = t;
	}
	return x < 0 ? x + mod : x;
}

void solve() 
{
	ll n;
	cin >> n;

	if((n%4==0) ||(n%7==0) || (n%47==0) || (n%74==0) || (n%444==0) || (n%447==0) || (n%474==0) || (n%477==0) ||  (n%744==0) || (n%747==0) || (n%774==0) || (n%777==0) )
	{
		dbg("YES");
	}
	else{
		dbg("NO");
	}

}

int main() 
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	#endif
	nitro
	int tc;
	tc =1;
	//cin >> tc;
	for(int i=1; i<=tc; ++i) 
	{
		//case_g(i);
		solve();
	}
}