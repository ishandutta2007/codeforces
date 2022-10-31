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
using namespace std;
#define pb push_back
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

ll dp[1<<20];
#define INF 1001001001001001001LL


int main () {
   wez3(fr,n,monitor)
   vector<pair<int,pii> > v;
   while(fr--) {
      wez3(xi,ki,mi)
      int ma = 0;
      while (mi--) {
         wez(pr)
         ma |= 1<<(pr-1);
      }
      v.pb(mp(ki,mp(xi,ma)));
   }
   sort(ALL(v));
   FOR(mask,1<<n) dp[mask] = INF;
   dp[0] = 0;
   ll best = INF;
   FOREACH(it,v) {
      int money = it->se.fi, can = it->se.se, monitors = it->fi;
      FOR(mask,1<<n) REMIN(dp[mask | can], dp[mask] + money);
      REMIN(best, 1LL * monitor * monitors + dp[(1<<n) - 1]);
   }
   if (best == INF) pisz(-1); else cout << best;
}