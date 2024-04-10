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

char s[64][64];
bool vis[64][64];
int n,m, dx[4] = {-1,1,0,0}, dy[4] = {0,0,-1,1};

void dfs (int i, int j) {
   if (i < 0 || i >= n || j < 0 || j >= m) return;
   if (s[i][j] == '.') return;
   if (vis[i][j]++) return;
   FOR(u,4) dfs(i+dx[u], j+dy[u]);
}

bool conn() {
   FOR(i,n) FOR(j,m) vis[i][j] = 0;
   int i1,j1;
   FOR(i,n) FOR(j,m) if (s[i][j] == '#') {
      i1 = i;
      j1 = j;
   }
   dfs(i1,j1);
   FOR(i,n) FOR(j,m) if (s[i][j] == '#') if (vis[i][j] == 0) return 0;
   return 1;
}

int main () {
   scanf("%d %d", &n, &m);
   FOR(i,n) scanf("%s", s[i]);
   int cnt = 0;
   FOR(i,n) FOR(j,m) if (s[i][j] == '#') {
      ++cnt;
   }
   if (cnt <= 2) {
      pisz(-1);
      return 0;
   }
   FOR(i,n) FOR(j,m) if (s[i][j] == '#') {
      s[i][j] = '.';
      if (!conn()) {
         pisz(1);
         return 0;
      }
      s[i][j] = '#';
   }
   pisz(2);
}