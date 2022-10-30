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
#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

char s[107][128], str[1007];
//int dx[4] = {-1,1,0,0}, dy[4] = {0,0,-1,1};
//int dir[256][256];
pii pos[256];

int cost (char c) {
   if (c >= '0' && c <= '9') return c - '0';
   return 1;
}
int sgn (int x) { return x > 0 ? 1 : x < 0 ? -1 : 0; }

int main () {
   wez3(n,m,k)
   FORI(i,n) scanf("%s", s[i] + 1);
   wez2(x,y)
   scanf("%s", str);
   wez2(endx, endy)
   FORI(i,n) FORI(j,m) if (s[i][j] >= 'a' && s[i][j] <= 'z') {
      /*FOR(d,4) {
         int x = i + dx[d], y = j + dy[d];
         if (x < 1 || x > n || y < 1 || y > m) continue;
         if (s[x][y] == '#') continue;
         while (!(s[x][y] >= 'a' && s[x][y] <= 'z')) {
            x += dx[d];
            y += dy[d];
         }
         dir[s[i][j]][s[x][y]] = d;
      }*/
      pos[s[i][j]] = mp(i,j);
   }
   vector<pii> points;
   for (char *t = str; *t; ++t) points.pb(pos[*t]);
   points.pb(mp(endx,endy));
   FOREACH(it,points) {
      int dx = sgn(it->fi - x), dy = sgn(it->se - y);
      while (x != it->fi || y != it->se) {
         k -= cost(s[x][y]);
         if (k < 0) {
            printf("%d %d\n", x, y);
            return 0;
         }
         x += dx; y += dy;
      }
   }
   printf("%d %d\n", x, y);
}