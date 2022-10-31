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
#include <bitset>
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

bool wz[16][2][2];
char s[506][506];
bool dp[512][512][10][16];

int main () {
   // gen
   int k = 0;
   FOR(a,2) FOR(b,2) FOR(c,2) FOR(d,2) {
      wz[k][0][0] = a;
      wz[k][0][1] = b;
      wz[k][1][0] = c;
      wz[k][1][1] = d;
      k++;
   }
   
   wez2(n,m)
   FOR(i,n) scanf("%s", s[i]);
   FOR(i,n) FOR(j,m) s[i][j] = (s[i][j] == '*') ? 1 : 0;
   
   int res = 0;
   // z = 1
   FOR(x,n-1) FOR(y,m-1) FOR(w,16) {
      dp[x][y][1][w] = 1;
      FOR(a,2) FOR(b,2) dp[x][y][1][w] &= (s[x+a][y+b] == wz[w][a][b]);
   }
   REP(z,2,9) for (int x = 0; x + (1<<z) <= n; ++x) for (int y = 0; y + (1<<z) <= m; ++y) FOR(w,16) {
      dp[x][y][z][w] = 1;
      FOR(a,2) FOR(b,2) dp[x][y][z][w] &= dp[x+a*(1<<(z-1))][y+b*(1<<(z-1))][z-1][ wz[w][a][b] ? 15 : w ];
      if (dp[x][y][z][w]) ++res;
   }
   pisz(res);
}