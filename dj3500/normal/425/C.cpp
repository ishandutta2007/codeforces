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
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

#define N 100007
int a[N], b[N], dp[N][306];
vi occ[N];

int main () {
   wez2(n,m)
   wez2(s,e)
   FORI(i,n) scanf("%d", a+i);
   FORI(j,m) scanf("%d", b+j);
   
   FORI(j,m) occ[b[j]].pb(j);
   REP(x,1,100000) occ[x].pb(INF+5);
   
   dp[0][0] = 0;
   REP(k,1,300) dp[0][k] = INF;
   
   int best = 0;
   
   REP(i,1,n) {
      dp[i][0] = 0;
      REP(k,1,300) {
         dp[i][k] = min(dp[i-1][k], *upper_bound(ALL(occ[a[i]]), dp[i-1][k-1]));
      }
      
      REP(k,0,300) if (dp[i][k] != INF) {
         if (s >= 1LL * e * k + i + dp[i][k]) REMAX(best, k);
      }
   }
   
   pisz(best);
}