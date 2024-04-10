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
#define INF (1001001001LL * 1001001001LL)
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

ll gg (ll x) { return x == INF ? -1 : x; }

#define N 100007
ll dp[307][307];
ll mincost[307][307];
int l[N], r[N], c[N];

int main () {
   wez3(n,m,k);
   REP(i,0,n) REP(j,0,n) dp[i][j] = mincost[i][j] = INF;
   FOR(i,m) {
      scanf("%d %d %d", l+i, r+i, c+i);
      REP(f,l[i],r[i]) REMIN(mincost[f][r[i]], (ll)c[i]);
   }
   dp[0][0] = 0;
   REP(i,1,n) {
      REP(kk,0,k) REMIN(dp[i][kk], dp[i-1][kk]);
      REP(kk,0,k) REP(poprz,0,i-1) REMIN(dp[i][kk], mincost[poprz+1][i] + dp[poprz][max(0,kk-(i-poprz))]);
      REPD(kk,k-1,0) REMIN(dp[i][kk], dp[i][kk+1]);
   }
   cout << gg(dp[n][k]) << endl;
   
   //REP(i,0,n) { REP(j,0,n) cout << gg(mincost[i][j]) << " "; cout << "\n"; }
}