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
#define IN(x,y) ((y).find((x))!=(y).end())
#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

void freop() {
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
}

#define N 208
int h[N], prefsum[N], dp[256][2][40007];

int main () {
   freop();
   wez(n)
   wez2(a,b)
   prefsum[0] = 0;
   FORI(i,n) {
      scanf("%d", h+i);
      prefsum[i] = prefsum[i-1] + h[i];
   }

   /*if (prefsum[n] > a + b) {
      pisz(-1);
      return 0;
   }*/

   REP(k,1,n) FOR(last,2) FOR(red,40007) dp[k][last][red] = INF;
   // k = 1
   if (h[1] <= a) {
      dp[1][0][h[1]] = 0;
   }
   if (h[1] <= b) {
      dp[1][1][0] = 0;
   }
   
   REP(k,2,n) {
      // wypelniamy dp[k][*][*]
      FOR(red,40007) {
         if (red + h[k] <= a) {
            REMIN(dp[k][0][red+h[k]], dp[k-1][0][red]); // 0 -> 0
            REMIN(dp[k][0][red+h[k]], dp[k-1][1][red] + min(h[k-1], h[k])); // 1 -> 0
         }
         if (prefsum[k] - red <= b) {
            REMIN(dp[k][1][red], dp[k-1][0][red] + min(h[k-1], h[k])); // 0 -> 1
            REMIN(dp[k][1][red], dp[k-1][1][red]); // 1 -> 1
         }
      }
   }
   
   int res = INF;
   FOR(last,2) FOR(red,40007) REMIN(res, dp[n][last][red]);
   if (res == INF) pisz(-1);
   else pisz(res);
}