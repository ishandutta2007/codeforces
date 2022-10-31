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
#define DBG(vari) cout<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (__typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

#define N 111
int a[N];
pii dp[N][1<<16];
int divs[N];

int main () {
   int q = 0;
   REP(x,2,58) if (divs[x] == 0) {
      for (int y = x; y <= 59; y += x) divs[y] |= 1 << q;
      ++q;
   }
   //REP(x,2,58) { DBG(x) DBG(divs[x]) }
   
   wez(n)
   FORI(i,n) scanf("%d", a+i);
   REP(i,0,n) FOR(mask,1<<16) dp[i][mask].fi = INF;
   dp[0][0].fi = 0;
   REP(i,0,n-1) {
      int A = a[i+1];
      FOR(mask,1<<16) if (dp[i][mask].fi != INF) {
         for (int x = 1; x == 1 || x < 2*A - 1; ++x) {
            if (0 == (divs[x] & mask)) {
               REMIN(dp[i+1][mask | divs[x]], mp(dp[i][mask].fi + abs(x - A), x));
            }
         }
      }
   }
   pair<pii,int> res;
   res.fi.fi = INF;
   FOR(mask,1<<16) REMIN(res, mp(dp[n][mask], mask));
   //DBG(res)
   vi ans;
   REPD(i,n-1,0) {
      ans.pb(res.fi.se);
      //res.fi.fi -= abs(a[i+1] - res.fi.se);
      res.se &= ~divs[res.fi.se];
      res.fi.se = dp[i][res.se].se;
   }
   reverse(ALL(ans));
   FOREACH(it,ans) printf("%d ", *it);
}