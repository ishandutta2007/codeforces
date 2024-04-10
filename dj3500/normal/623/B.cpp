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

typedef vector<pair<ll,int> > Roz;
Roz rozklad (ll x) { // rozklad: {<liczba pierwsza, krotnosc>}
   Roz res;
   for (int d = 2; (ll)d*d <= x; ++d) {
      if (x % d == 0) {
         int k = 0;
         while (x % d == 0) { x /= d; ++k; }
         res.pb(mp(d,k));
      }
   }
   if (x != 1) res.pb(mp(x,1));
   return res;
}

const int N = 1001007;
int prefcost[N];
ll Amin[N], a, b;

ll solve (const vi &cost) {
   int n = SZ(cost) - 1;

   int minkill = n+1, maxkill = 0;
   FORI(i,n) if (cost[i] == 2) {
      REMIN(minkill, i);
      REMAX(maxkill, i);
   }

   prefcost[0] = 0;
   FORI(i,n) prefcost[i] = prefcost[i-1] + cost[i];

   if (maxkill == 0) {
      // no cost 2
      ll ans = b * prefcost[n];

      Amin[n+1] = 1LL * INF * INF;
      REPD(j,n,1) {
         ll Aj = j * a + (prefcost[n] - prefcost[j]) * b;
         Amin[j] = min(Amin[j+1], Aj);
      }
      FORI(i,n) {
         // zabijam [i,j]
         REMIN(ans, Amin[i] + prefcost[i-1] * b - (i - 1) * a);
      }
      return ans;
   } else {
      // has cost 2
      ll leftMin = 1LL * INF * INF;
      REPD(le,minkill,1) {
         REMIN(leftMin, prefcost[le - 1] * b + (minkill - le) * a);
      }
      ll rightMin = 1LL * INF * INF;
      REP(ri,maxkill,n) {
         REMIN(rightMin, (prefcost[n] - prefcost[ri]) * b + (ri - maxkill) * a);
      }
      return a * (maxkill - minkill + 1) + leftMin + rightMin;
   }
}

int getcost (int pi, int pr) {
   if (pi % pr == 0) {
      return 0;
   } else if (((pi - 1) % pr == 0) || ((pi + 1) % pr == 0)) {
      return 1;
   } else {
      return 2;
   }
}



int p[N];

int main () {
   wez(n);
   cin >> a >> b;
   ll res = (n-1) * a;
   FORI(i,n) scanf("%d", p+i);
   for (int i : {1,n}) {
      set<int> primes;
      REP(x,-1,1) {
         Roz r = rozklad(p[i] + x);
         for (auto it : r) primes.insert((int)it.fi);
      }
      // p[i] przezywa
      for (int pr : primes) {
         vi v = {0};
         FORI(j,n) if (j != i) {
            v.pb(getcost(p[j], pr));
         }
         REMIN(res, b * getcost(p[i], pr) + solve(v));
      }
   }
   cout << res;
}