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
#define DBG(vari) cout<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

double dp[1<<20];
int x[22], y[22], aa[22];
double k[22];

int main () {
   wez3(n,le,ri)
   FOR(i,n) {
      scanf("%d %d %d", x+i, y+i, aa+i);
      k[i] = aa[i] * M_PI / 180;
      //DBG(k[i])
   }
   dp[0] = le;
   for (int m = 1; m < (1 << n); ++m) {
      dp[m] = le;
      FOR(i,n) if ((1<<i) & m) {
         double s = dp[m ^ (1 << i)];
         double a = cos(k[i]) * (s-x[i]) + sin(k[i]) * y[i] + x[i];
         double b = sin(k[i]) * (s-x[i]) - cos(k[i]) * y[i] + y[i];
         //DBG(mp(a,b))
         double xx = -1;
         //DBG(b - y[i])
         if (b - y[i] > -1e-9) xx = ri;
         else
         xx = a + (a - x[i]) * b / (y[i] - b);
         //DBG(xx)
         REMAX(dp[m], xx);
      }
   }
   printf("%.13lf\n", min(1.0 * (ri-le), dp[(1<<n) - 1] - le));
}