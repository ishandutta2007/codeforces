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
//#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

const int N = 404;
int pref[N], val[N];
ll sum (int i, int j) {
   return pref[j] - pref[i-1];
}
ll dp[N][N], dpP[N][N], dpM[N][N];
// dpP[k][i] = max (|s_1 - s_2| + ... + |s_k - s_{k-1}| + s_k), s_k ends on i or before
// dpP[1][i] = max (s_1), s_1 ends on i or before
// dpM[k][i] = max (|s_1 - s_2| + ... + |s_k - s_{k-1}| - s_k), s_k ends on i or before
// dpM[1][i] = max (-s_1), s_1 ends on i or before

int main () {
   wez2(n,K)
   FORI(i,n) scanf("%d", val+i);
   FORI(i,n) pref[i] = pref[i-1] + val[i];
   
   dpP[1][0] = -INF;
   dpM[1][0] = -INF;
   FORI(i,n) {
      dpP[1][i] = -INF;
      if (i > 1) REMAX(dpP[1][i], dpP[1][i-1]);
      REP(j,1,i) REMAX(dpP[1][i], sum(j,i));
      dpM[1][i] = -INF;
      if (i > 1) REMAX(dpM[1][i], dpM[1][i-1]);
      REP(j,1,i) REMAX(dpM[1][i], -sum(j,i));
   }
   /*DBG(dpP[1][1])
   DBG(dpP[1][2])
   DBG(dpM[1][1])
   DBG(dpM[1][2])*/
   
   REP(k,2,K) {
      dpP[k][0] = -INF;
      dpM[k][0] = -INF;
      dp[k][0] = -INF;
      FORI(i,n) {
         dp[k][i] = -INF;
         if (i > 1) REMAX(dp[k][i], dp[k][i-1]);
         REP(j,1,i) {
            REMAX(dp[k][i], dpP[k-1][j-1] - sum(j,i));
            REMAX(dp[k][i], dpM[k-1][j-1] + sum(j,i));
         }
         
         dpP[k][i] = -INF;
         if (i > 1) REMAX(dpP[k][i], dpP[k][i-1]);
         REP(j,1,i) {
            REMAX(dpP[k][i], dpP[k-1][j-1]);
            REMAX(dpP[k][i], dpM[k-1][j-1] + 2 * sum(j,i));
         }
         
         dpM[k][i] = -INF;
         if (i > 1) REMAX(dpM[k][i], dpM[k][i-1]);
         REP(j,1,i) {
            REMAX(dpM[k][i], dpP[k-1][j-1] - 2 * sum(j,i));
            REMAX(dpM[k][i], dpM[k-1][j-1] );
         }
      }
   }
   
   ll res = dp[K][n];
   cout << res;
}