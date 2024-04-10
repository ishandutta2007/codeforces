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
#define IOS ios_base::sync_with_stdio(0);

int buyprice[105][105], sellprice[106][206], itemss[105][106], items[105], profit[106], dp[106];

int main () {
   wez3(n,m,k)
   FOR(i,n) {
      string syf;
      cin >> syf;
      FOR(j,m) scanf("%d %d %d", &buyprice[i][j], &sellprice[i][j], &itemss[i][j]);
   }
   int best = 0;
   FOR(i1,n) FOR(i2,n) if (i1 != i2) {
      FOR(j,m) {
         profit[j] = sellprice[i2][j] - buyprice[i1][j];
         items[j] = itemss[i1][j];
      }
      
      REP(u,0,k) dp[u] = 0;
      FOR(j,m) {
         REPD(u,k,0) {
            int to = min(u, items[j]);
            FORI(ile,to) {
               REMAX(dp[u], dp[u-ile] + profit[j]*ile);
            }
         }
      }
      REP(u,0,k) REMAX(best,dp[u]);
   }
   pisz(best);
}