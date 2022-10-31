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

int conv (char c) {
   if (c == 'U') return 0;
   if (c == 'D') return 1;
   if (c == 'L') return 2;
   if (c == 'R') return 3;
   if (c == '.') return 4;
   printf("fail!");
   exit(1);
}

int n,m;
vector<vector<pii> > next[4];
vector<vi> plansza;
vector<vector<bool> > jest;
int dx[] = {-1,1,0,0}, dy[] = {0,0,-1,1};
inline int ok (int x, int y) {
   return 0 <= x && x < n && 0 <= y && y < m;
}

pii nastepny (int d, int x, int y) {
   //printf("nastepny wywolano dla %d %d %d\n",d,x,y);
   if (!ok(x,y)) {
      //printf("to nie ok, zwracam syfa\n");
      return mp(-1,-1);
   }
   pii ans = next[d][x][y];
   if (!ok(ans.fi,ans.se) || jest[ans.fi][ans.se]) {
      //printf("i jest \n");
      //DBG(ans)
      return ans;
   } else {
      //printf("i nie ma\n");
      return next[d][x][y] = nastepny(d,ans.fi,ans.se);
   }
}

int main () {
   scanf("%d %d",&n,&m);
   FOR(d,4) next[d].assign(n,vector<pii>(m));
   plansza.assign(n,vi(m));
   jest.assign(n,vector<bool>(m));

   FOR(i,n) {
      char temp[m+5];
      scanf("%s",temp);
      FOR(j,m) plansza[i][j] = conv(temp[j]);
   }

   int maxscore = 0, maxcnt = 0;

   FOR(sx,n) FOR(sy,m) {
      if (plansza[sx][sy] == 4) continue;

      FOR(i,n) FOR(j,m) jest[i][j] = plansza[i][j]!=4;
      FOR(d,4) FOR(i,n) FOR(j,m) next[d][i][j] = mp(i + dx[d], j + dy[d]);
      int score = 0;
      int x=sx,y=sy;
      while (ok(x,y)) {
         ++score;
         jest[x][y] = 0;
         int d = plansza[x][y];
         pii nowy = nastepny(d,x,y);
         x = nowy.fi; y = nowy.se;
      }
      //DBG(score)
      if (score > maxscore) {
         maxscore = score;
         maxcnt = 1;
      } else if (score == maxscore) ++maxcnt;
   }
   printf("%d %d",maxscore,maxcnt);
}