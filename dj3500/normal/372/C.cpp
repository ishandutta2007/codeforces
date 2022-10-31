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

inline ll fastMax(ll x, ll y) { return (((y-x)>>(64-1))&(x^y))^y; }

const int LOGN = 18, N = 1<<LOGN; // mozna zmniejszyc N
ll rm[LOGN][N]; // rm[k][i] = min(tab[i], ..., tab[i + 2^k - 1])
void init (ll *tab, int n) { // tab[0..n-1]
   FOR(i,n) rm[0][i] = tab[i];
   REP(k,1,LOGN-1) REP(i,0,n-(1<<k)) rm[k][i] = max(rm[k-1][i], rm[k-1][i+(1<<(k-1))]);
}
inline ll query (int a, int b) { // a <= b bo inaczej segfault
   int k = 31 - __builtin_clz(b-a+1);
   return max(rm[k][a], rm[k][b-(1<<k)+1]);
}

ll dp[2][N];

int main () {
   wez3(n,m,d)
   int prevt = -1;
   ll sumabi = 0;
   FORI(i,m) {
      wez3(ai,bi,ti)
      sumabi += bi;
      ll diff = (i == 1) ? 0 : (ti - prevt);
      int maxdist = min(diff * d, (ll)n);
      prevt = ti;
      
      init(dp[(i-1) & 1], n+1);
      
      FORI(j,n) dp[i&1][j] = query(max(1,j-maxdist), min(n,j+maxdist)) - abs(j-ai);
   }
   ll maxx = -INF;
   maxx *= INF;
   FORI(j,n) REMAX(maxx, dp[m&1][j]);
   cout << maxx + sumabi;
}