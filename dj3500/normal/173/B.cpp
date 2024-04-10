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

bool visitedColumn[1005], visitedRow[1005];
int dist[1005][1005];
char s[1005][1005];

int main () {
   wez2(n,m)
   FORI(i,n) scanf("%s",(s[i])+1);
   FOR(i,1005) visitedColumn[i] = visitedRow[i] = 0;
   visitedColumn[m+1] = 1;
   FOR(i,1005) FOR(j,1005) dist[i][j] = -1;

   deque<pii> q;
   dist[n][m+1] = 0;
   q.pb(mp(n,m+1));

   while (!q.empty()) {
      pii p = q.front();
      q.pop_front();
      if (p.fi == 1) {
         pisz(dist[p.fi][p.se]);
         return 0;
      }
      if (!visitedRow[p.fi]) {
         FORI(j,m) if (s[p.fi][j] == '#') {
            if (dist[p.fi][j] == -1) {
               dist[p.fi][j] = dist[p.fi][p.se] + 1;
               q.pb(mp(p.fi, j));
            }
         }
      }
      if (!visitedColumn[p.se] && p.se != m+1) {
         FORI(i,n) if (s[i][p.se] == '#') {
            if (dist[i][p.se] == -1) {
               dist[i][p.se] = dist[p.fi][p.se] + 1;
               q.pb(mp(i, p.se));
            }
         }
      }
      visitedColumn[p.se] = 1;
      visitedRow[p.fi] = 1;
   }
   pisz(-1);
}