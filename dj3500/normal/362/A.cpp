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

char s[16][16];
bool r[8][8][8][8];
int dx[4] = {-2,2,-2,2}, dy[4] = {2,2,-2,-2};

bool good (int x) { return x >= 0 && x < 8; }

void go (int i, int j, int k, int l) {
   if (r[i][j][k][l]++) return;
   FOR(d,4) FOR(e,4) {
      int i1 = i + dx[d], j1 = j + dy[d], k1 = k + dx[e], l1 = l + dy[e];
      if (good(i1) && good(j1) && good(k1) && good(l1)) go(i1,j1,k1,l1);
   }
}

int main () {
   TESTS {
      FOR(i,8) scanf("%s", s[i]);
      FOR(i,8) FOR(j,8) FOR(k,8) FOR(x,8) r[i][j][k][x] = 0;
      vector<pii> kn;
      FOR(i,8) FOR(j,8) if ('K' == s[i][j]) kn.pb(mp(i,j));
      go(kn[0].fi, kn[0].se, kn[1].fi, kn[1].se);
      bool ok = 0;
      FOR(i,8) FOR(j,8) if ('#' != s[i][j]) if (r[i][j][i][j]) ok = 1;
      printf(ok ? "YES\n" : "NO\n");
   }
}