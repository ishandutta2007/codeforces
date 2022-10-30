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

#define N 1506
int n,m;
char s[N][N];
bool vis[N][N];
pii when[N][N];
const int dx[4] = {0,0,-1,1}, dy[4] = {-1,1,0,0};

void go (int x, int y, int a, int b) {
   if (x == -1) return go(n-1,y,a-1,b);
   if (y == -1) return go(x,m-1,a,b-1);
   if (x == n) return go(0,y,a+1,b);
   if (y == m) return go(x,0,a,b+1);
   if (s[x][y] == '#') return;
   if (vis[x][y]) {
      if (mp(a,b) == when[x][y]) return;
      printf("Yes\n");
      exit(0);
   }
   vis[x][y] = 1;
   when[x][y] = mp(a,b);
   FOR(u,4) {
      go(x+dx[u], y+dy[u], a, b);
   }
}

int main () {
   scanf("%d %d", &n, &m);
   FOR(i,n) scanf("%s", s[i]);
   int sx,sy;
   FOR(i,n) FOR(j,m) if (s[i][j] == 'S') {
      s[i][j] = '.';
      sx = i;
      sy = j;
   }
   FOR(i,n) FOR(j,m) vis[i][j] = 0;
   go(sx,sy,0,0);
   printf("No\n");
}