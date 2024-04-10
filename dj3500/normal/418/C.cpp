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

#define N 100000
int dp[105][N+5];
vi ciag[105];

int main () {
   dp[0][0] = 1;
   REP(k,1,100) {
      REP(n,1,N) {
         for (int x = 1; x * x <= n; ++x) {
            if (dp[k-1][n - x*x]) {
               dp[k][n] = x;
               break;
            }
         }
      }


      for (int y = 1; y * y <= N; ++y) {
         if (dp[k][y]) {
            int x = y*y;
            REPD(kk,k,1) {
               ciag[k].pb(dp[kk][x]);
               x -= dp[kk][x] * dp[kk][x];
            }
            break;
         }
      }
   }
   ciag[2].clear();
   ciag[2].pb(3);
   ciag[2].pb(4);
   REP(k,1,100) {
      FOREACH(it,ciag[k]) if (*it < 1 || *it > 1000) DBG(k);
      int s = 0;
      FOREACH(it,ciag[k]) s += *it * *it;
      if (int(round(sqrt(s)) * round(sqrt(s))) != s) DBG(k);
   }

   wez2(n,m)
   FORI(i,n) {
      FORI(j,m) printf("%d ", ciag[m][j-1] * ciag[n][i-1]);
      printf("\n");
   }
}