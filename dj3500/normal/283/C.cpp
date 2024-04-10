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
#define DBG(vari) cout<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

#define N 305
int a[N], gt[N], lt[N];
const int mod = 1000000007;
ll dp[100007][2];

int main () {
   wez(n)
   wez2(q,TT)
   ll T = TT;
   FORI(i,n) scanf("%d", a+i);
   FORI(i,n) gt[i] = lt[i] = 0;
   while (q--) {
      wez2(bi,ci)
      gt[bi] = ci;
      lt[ci] = 1;
   }
   vi nowe;
   FORI(i,n) if (!lt[i]) {
      vi chain;
      int v = i;
      chain.pb(i);
      while (gt[v]) {
         v = gt[v];
         chain.pb(v);
      }
      //DBG(chain)
      
      int len = SZ(chain);
      FOR(u,SZ(chain)) {
         T -= a[chain[u]] * (len-1-u);
      }
      nowe.pb(a[chain[0]]);
      REP(u,1,SZ(chain)-1) {
         nowe.pb(nowe.back() + a[chain[u]]);
      }
   }
   
   if (n > SZ(nowe) || T < 0) { pisz(0); return 0; }
   FORI(i,n) a[i] = nowe[i-1];
   
   dp[0][0] = 1;
   FORI(i,T) dp[i][0] = 0;
   FORI(i,n) {
      REP(t,0,T) {
         dp[t][i&1] = dp[t][(i-1)&1];
         if (t - a[i] >= 0) {
            dp[t][i&1] += dp[t-a[i]][i&1];
            if (dp[t][i&1] > 100000000000000LL) dp[t][i&1] %= mod;
         }
      }
   }
   
   ll res = dp[T][n&1];
   res %= mod;
   if (res < 0) res += mod;
   pisz(res);
}