#include <bits/stdc++.h>
//#include "RNG.h"
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define inf 1000000005
#define linf (1ll << 60)
#define all(a) (a).begin(), (a).end()
#define ms(a,x) memset(a, x, sizeof(a))
#define mod 1000000007
#define sz(a) ((int)(a).size())

template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcount(s);}
#define Rep(i,n) for(int i = 0; i < (n); ++i)
#define Repd(i,n) for(int i = (n)-1; i >= 0; --i)
#define For(i,a,b) for(int i = (a); i <= (b); ++i)
#define Ford(i,a,b) for(int i = (a); i >= (b); --i)

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define eps 1e-6
typedef pair<int, int> II;
template<class T> T gcd(T a, T b){ T r; while (b != 0) { r = a % b; a = b; b = r; } return a;}
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
#define PI 2 * acos(0)

#define maxn 500005

ll mu(ll x, ll k){
	if(k == 0) return 1;
	if(k & 1) return mu(x, k - 1) * x % mod;
	ll T = mu(x, k >> 1);
	return T * T % mod;
}

ll w,h,k,n,m;
II P1, P2;

void solve(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    cin >> w >> h >> k >> n >> m;
    cin >> P1.fi >> P1.se >> P2.fi >> P2.se;

    if(P1.fi > P2.fi) swap(P1, P2);
    if(P1.se > P2.se) P2.se = (P1.se + P1.se - P2.se);

    II giao = II(max(0ll, P1.fi + n - P2.fi), max(0ll, P1.se + m - P2.se));
    ll res = w * 1ll * h - n * 2ll * m + giao.fi * 1ll * giao.se;
//    cout << giao.fi * 1ll * giao.se << " " << res << endl;

    ll r = P2.fi - P1.fi, c = P2.se - P1.se;
    if((r >= n || c >= m) || (r == 0 && c == 0)){
    	res += n * 1ll * m;
    } else{
    	res += r * m + c * n - r * c;
    }
//    cout << res << endl;
    res = mu(k, res);
    cout << res << endl;

}

int main(){
  solve();

  return 0;
}