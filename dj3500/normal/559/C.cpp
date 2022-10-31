// tested by Hightail: https://github.com/dj3500/hightail
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <stack>
#include <cstring>
#include <iomanip>
#include <ctime>
#include <cassert>
using namespace std;
#define pb push_back
#define INF 1001001001
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define FORI(i,n) for(int (i)=1;(i)<=(n);++(i))
#define mp make_pair
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define SZ(x) ((int)((x).size()))
#define fi first
#define se second
#define wez(n) int (n); scanf("%d",&(n));
#define wez2(n,m) int (n),(m); scanf("%d %d",&(n),&(m));
#define wez3(n,m,k) int (n),(m),(k); scanf("%d %d %d",&(n),&(m),&(k));
inline void pisz(int n) { printf("%d\n",n); }
template<typename T,typename TT> ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &s,vector<T> t){FOR(i,SZ(t))s<<t[i]<<" ";return s; }
#define DBG(vari) cout<<"["<<__LINE__<<"] "<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (__typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

const int mod = 1000000007, MOD = mod;

ll powe (ll x, ll p) {
	if (p == 0) return 1;
	ll w = powe((x*x)%MOD, p/2);
	if (p & 1) w = (w*x)%MOD;
	return w;
}

ll modinv (ll i) {
   return powe(i,MOD-2);
}

const int N = 2002;
ll fact[200100], factinv[200100], b[N];

ll d (int dx, int dy) {
    return fact[dx+dy] * factinv[dx] % mod * factinv[dy] % mod;
}

int main () {
    wez3(h,w,n)
    vector<pii> v;
    FOR(i,n) {
        wez2(hi,wi)
        v.pb(mp(hi,wi));
    }
    sort(ALL(v));
    fact[0] = 1;
    REP(i,1,h+w) fact[i] = (fact[i-1] * i) % mod;
    REP(i,0,h+w) factinv[i] = modinv(fact[i]);

    v[n] = mp(h,w);
    ++n;
    FOR(i,n) {
        b[i] = d(v[i].fi - 1, v[i].se - 1);
        FOR(j,i) if (v[j].se <= v[i].se) {
            b[i] -= b[j] * d(v[i].fi - v[j].fi, v[i].se - v[j].se) % mod;
        }
        b[i] %= mod;
    }

    ll res = b[n-1];
    res %= mod;
    if (res < 0) res += mod;
    pisz(res);
}