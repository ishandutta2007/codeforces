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
using namespace std;
#define pb push_back
#define INF 1000000000
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define FORI(i,n) for(int (i)=1;(i)<=(n);++(i))
#define mp make_pair
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define SZ(x) ((int)(x.size()))
#define fi first
#define se second
#define wez(n) int (n); scanf("%d",&(n));
#define wez2(n,m) int (n),(m); scanf("%d %d",&(n),&(m));
#define wez3(n,m,k) int (n),(m),(k); scanf("%d %d %d",&(n),&(m),&(k));
inline void pisz(int n) { printf("%d\n",n); }
template<typename T,typename TT> ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &s,vector<T> t){FOR(i,SZ(t))s<<t[i]<<" ";return s; }
#define IN(x,y) ((y).find((x))!=(y).end())
#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));

const int MOD = 1000000007;
ll powe (ll x, ll pwr) {
    if (pwr==0) return 1;
    ll w = powe((x*x)%MOD,pwr/2);
    if (pwr&1) w = (w*x)%MOD;
    return w;
}
ll modinvv (ll i) {
   return powe(i,MOD-2);
}

#define NEED 1000
ll nt[NEED+1][NEED+1];
void initnewton () {
    FOR(n,NEED+1) nt[n][0] = 1;
    FORI(k,NEED) nt[0][k] = 0;
    FORI(n,NEED) FORI(k,NEED) nt[n][k] = (nt[n-1][k-1] + nt[n-1][k]) % MOD;
}

ll modinv[1005], kol[1005], d[1005][1005];
// kol[i] - liczba kolorowan n obiektow za pomoca dokladnie i kolorow
// d[a][b] = uogolniony newton: (k nad a,b,b)


int main () {
   FORI(i,1001) modinv[i] = modinvv(i);
   wez3(n,m,k)
   initnewton();

   kol[0] = 0;
   FORI(i,1000) {
      kol[i] = powe(i,n);
      REP(j,1,i-1) {
         kol[i] -= nt[i][j] * kol[j];
         kol[i] %= MOD;
      }
   }

   if (m == 1) {
      ll w = powe(k,n);
      if (w < 0) w += MOD;
      pisz(w);
      return 0;
   }

   d[0][0] = 1;
   FOR(a,1000) d[a+1][0] = (((d[a][0] * (k-a)) % MOD) * modinv[a+1]) % MOD;
   FOR(b,1000) {
      FOR(a,1001) {
         ll u = d[a][b];
         u *= ((ll)(k-2*b-a) * (k-2*b-a-1)) % MOD;
         u %= MOD;
         FOR(f,2) {
            u *= modinv[b+1];
            u %= MOD;
         }
         d[a][b+1] = u;
      }
   }

   ll suma = 0;
   for (ll a = 0; a <= n && a <= k; ++a) {
      for (ll b = 0; a+b <= n && a+2*b <= k; ++b) {
         ll wyr = d[a][b];
         wyr *= powe(a,(m-2)*n);
         wyr %= MOD;
         FOR(f,2) {
            wyr *= kol[a+b];
            wyr %= MOD;
         }
         suma = (suma+wyr)%MOD;
      }
   }
   if (suma < 0) suma += MOD;
   pisz(suma);
}