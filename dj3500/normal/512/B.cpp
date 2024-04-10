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

vi rozklad (int x) { // rozklad: {<liczba pierwsza, krotnosc>}
   vi res;
   for (int d = 2; d*d <= x; ++d) {
      if (x % d == 0) {
         int k = 0;
         while (x % d == 0) { x /= d; ++k; }
         res.pb(d);
      }
   }
   if (x != 1) res.pb(x);
   return res;
}

const int N = 303;
int l[N], c[N];
int dp[N][1 << 10];

int main () {
   wez(n)
   FORI(i,n) scanf("%d", l+i);
   FORI(i,n) scanf("%d", c+i);
   
   int g = 0;
   FORI(i,n) g = __gcd(g, l[i]);
   if (g != 1) {
      printf("-1");
      return 0;
   }
   
   int mini = INF;
   
   FORI(st,n) {
      const vi roz = rozklad(l[st]);
      //DBG(roz)
      const int k = SZ(roz);
      FOR(mask,1<<k) dp[st][mask] = INF;
      dp[st][(1<<k)-1] = c[st];
      REP(i,st+1,n) {
         int moje = (1<<k) - 1;
         FOR(j,k) if (l[i] % roz[j] == 0) moje ^= 1 << j;
         FOR(mask,1<<k) {
            dp[i][mask] = dp[i-1][mask];
            FOR(j,k) REMIN(dp[i][mask], dp[i][mask & ~(1<<j)]); // monotone
            REMIN(dp[i][mask], c[i] + dp[i-1][mask | moje]);
         }
      }
      REMIN(mini, dp[n][0]);
   }
   
   pisz(mini);
}