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
#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (__typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

const int MOD = 1000000007, mod = MOD;

ll powe (ll x, ll p) {
	if (p == 0) return 1;
	ll w = powe((x*x)%MOD, p/2);
	if (p & 1) w = (w*x)%MOD;
	return w;
}


ll modinv (ll i) {
   return powe(i,MOD-2);
}

#define N 100007
int black[N];
vi adj[N];
ll dp0[N], dp1[N];

void go (int v) {
   ll s = 1;
   FOREACH(x,adj[v]) {
      go(*x);
      s *= dp0[*x] + dp1[*x];
      s %= mod;
   }
   dp0[v] = black[v] ? 0 : s;
   if (black[v]) {
      dp1[v] = s;
   } else {
      ll suma = 0;
      FOREACH(x,adj[v]) {
         suma += dp1[*x] * modinv(dp0[*x] + dp1[*x]) % mod;
      }
      suma %= mod;
      dp1[v] = s * suma % mod;
   }
}

int main () {
   wez(n)
   FORI(i,n-1) {
      wez(pi)
      adj[pi].pb(i);
   }
   FOR(i,n) scanf("%d", black + i);
   go(0);
   ll res = dp1[0];
   res %= mod;
   if (res < 0) res += mod;
   pisz(res);
}