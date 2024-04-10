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
#define INF 2147483647
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define FORI(i,n) for(int (i)=1;(i)<=(n);++(i))
#define mp make_pair
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define sz size()
#define fi first
#define se second
#define wez(n) int (n); scanf("%d",&(n));
#define wez2(n,m) int (n),(m); scanf("%d %d",&(n),&(m));
#define wez3(n,m,k) int (n),(m),(k); scanf("%d %d %d",&(n),&(m),&(k));
inline void pisz(int n) { printf("%d\n",n); }
template<typename T,typename TT> ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &s,vector<T> t){FOR(i,t.size())s<<t[i]<<" ";return s; }
#define IN(x,y) ((y).find((x))!=(y).end()) 
#define DBG(vari) cout<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));

bool literka (char c) {
   return c <= 'Z' && c >= 'A';
}

int wid[4][1002][1002];
int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};
char s[1004][1004];
char ss[1004][1004];
#define posx xpos
#define posy ypos
int xpos[300], ypos[300], przetw[300];
bool aktywna[300];

int main () {
   przetw['N'] = 0;
   przetw['S'] = 2;
   przetw['E'] = 3;
   przetw['W'] = 1;
   FOR(i,300) aktywna[i] = 1;
   
   wez2(n,m)
   FORI(i,n) scanf("%s",ss[i]);
   FORI(i,n) FORI(j,m) s[i][j] = ss[i][j-1];
   FOR(k,4) {
      FORI(i,n) wid[k][i][1] = wid[k][i][m] = 0;
      FORI(j,m) wid[k][1][j] = wid[k][n][j] = 0;
   }
   REP(k,0,1) REP(i,2,n-1) REP(j,2,m-1) wid[k][i][j] = (s[i][j] == '#') ? 0 : wid[k][i+dx[k]][j+dy[k]]+1;
   REP(k,2,3) REPD(i,n-1,2) REPD(j,m-1,2) wid[k][i][j] = (s[i][j] == '#') ? 0 : wid[k][i+dx[k]][j+dy[k]]+1;
   
//   FOR(k,4) {
//      DBG(k)
//      FORI(i,n) DBG(vi(wid[k][i],wid[k][i]+m))
//   }
   
   vector<char> literki;
   FORI(i,n) FORI(j,m) if (literka(s[i][j])) {
      literki.pb(s[i][j]);
      xpos[s[i][j]] = i;
      ypos[s[i][j]] = j;
   }
   
   TESTS {
      char kier = 0;
      while (!literka(kier)) kier = getchar();
      wez(ile)
      int kieru = przetw[kier];
      FOR(u,literki.sz) {
         char c = literki[u];
         if (!aktywna[c]) continue;
         if (wid[kieru][posx[c]][posy[c]] <= ile) {
            aktywna[c] = 0;
         } else {
            posx[c] += dx[kieru]*ile;
            posy[c] += dy[kieru]*ile;
         }
      }
   }
   
   string wyn;
   FOR(u,literki.sz) if (aktywna[literki[u]]) wyn += literki[u];
   sort(ALL(wyn));
   if (wyn=="") wyn = "no solution";
   printf("%s\n",wyn.c_str());
}