// tested by Hightail: https://github.com/dj3500/hightail
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
#include <cassert>
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
#define DBG(vari) cout<<"["<<__LINE__<<"] "<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (__typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

const int N = 105;
char s[N][N];
bool attacked[N][N];
char res[N][N];
int n;

bool rob (int dx, int dy, bool mark) {
   FOR(i,n) FOR(j,n) if (s[i][j] == 'o') {
      int i1 = i + dx, j1 = j + dy;
      if (i1 >= 0 && i1 < n && j1 >= 0 && j1 < n) {
         if (s[i1][j1] == 'o' || s[i1][j1] == 'x') {
            // ok
            if (mark) attacked[i1][j1] = 1;
            //DBG(mp(i1,j1));
         } else {
            // not ok
            //DBG(mp(i1,j1));
            return false;
         }
      }
   }
   return true;
}

int main () {
   scanf("%d", &n);
   FOR(i,n) scanf("%s", s[i]);
   REP(dx,1-n,n-1) REP(dy,1-n,n-1) {
      res[n-1+dx][n-1+dy] = '.';
      if (rob(dx,dy,0)) {
         //DBG(mp(dx,dy));
         rob(dx,dy,1);
         res[n-1+dx][n-1+dy] = 'x';
      }
   }
   //DBG(rob(0,2,0));
   
   bool bad = 0;
   FOR(i,n) FOR(j,n) if (s[i][j] == 'x' && !attacked[i][j]) bad = 1;
   if (bad) {
      printf("NO");
      return 0;
   }
   
   res[n-1][n-1] = 'o';
   printf("YES\n");
   FOR(i,2*n-1) {
      res[i][2*n-1] = 0;
      printf("%s\n", res[i]);
   }
}