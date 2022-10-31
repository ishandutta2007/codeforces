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

int dp[102][102][2][12];
bool seen[102][102][2][12];

int main () {
   wez2(n1,n2)
   wez2(k1,k2)
   
   const int mod = 100000000;
   
   FOR(a,102)FOR(b,102)FOR(c,2)FOR(d,12)dp[a][b][c][d] = seen[a][b][c][d] = 0;
   
   dp[1][0][0][1] = 1;
   dp[0][1][1][1] = 1;
   
   deque<pair<pii,pii> > q;
   q.pb(mp(mp(1,0),mp(0,1)));
   q.pb(mp(mp(0,1),mp(1,1)));
   while (!q.empty()) {
      int a1 = q.front().fi.fi, a2 = q.front().fi.se, kto = q.front().se.fi, ilu = q.front().se.se;
      q.pop_front();
      
      if (seen[a1][a2][kto][ilu]) continue;
      seen[a1][a2][kto][ilu] = 1;
      
      bool ok1 = 1, ok2 = 1;
      
      if (a1 == n1) ok1 = 0;
      if (a2 == n2) ok2 = 0;
      if (kto == 0 && ilu == k1) ok1 = 0;
      if (kto == 1 && ilu == k2) ok2 = 0;
      
#define b1 a2
      
      if (ok1) {
         int a1p = a1+1, b1p = b1, ktop = 0, ilup = (kto == 0) ? ilu+1 : 1;
         q.push_back(mp(mp(a1p,b1p),mp(ktop,ilup)));
         dp[a1p][b1p][ktop][ilup] += dp[a1][b1][kto][ilu];
         if (dp[a1p][b1p][ktop][ilup] > mod) dp[a1p][b1p][ktop][ilup] -= mod;
      }
      
      if (ok2) {
         int a1p = a1, b1p = b1+1, ktop = 1, ilup = (kto == 1) ? ilu+1 : 1;
         q.push_back(mp(mp(a1p,b1p),mp(ktop,ilup)));
         dp[a1p][b1p][ktop][ilup] += dp[a1][b1][kto][ilu];
         if (dp[a1p][b1p][ktop][ilup] > mod) dp[a1p][b1p][ktop][ilup] -= mod;
      }
   }
   
   ll wyn = 0;
   FOR(kto,2) FORI(ilu,10) wyn += dp[n1][n2][kto][ilu];
   pisz(wyn % mod);
}