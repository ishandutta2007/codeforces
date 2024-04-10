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

const int mod = 1000000007;
#define N 2002
ll dp[N][N], pd[N][N];
vi divs[N];

int main () {
   wez2(n,k)
   REP(y,1,n) divs[y].pb(0);
   REP(x,1,n) for (int y = x+x; y <= n; y += x) divs[y].pb(x);
   //REP(x,1,n) { DBG(x) DBG(divs[x]) }
   //REP(x,1,n) pd[1][x] = dp[1][x] = 1;
   dp[0][0] = pd[0][0] = 1;
   REP(len,1,k) REP(x,0,n) {
      dp[len][x] = 0;
      FOREACH(it,divs[x]) {
         dp[len][x] += pd[len-1][*it];
      }
      dp[len][x] %= mod;
      pd[len][x] = (pd[len-1][x] + dp[len][x]) % mod;
   }
   ll res = 0;
   REP(x,1,n) res += dp[k][x];
   res %= mod;
   if (res < 0) res += mod;
   pisz(res);
}