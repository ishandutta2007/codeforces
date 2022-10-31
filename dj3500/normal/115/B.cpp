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

char s[160][160],ss[160];
int rm[160],lm[160];

int main () {
   wez2(n,m)
   FORI(i,n) {
      scanf("%s",ss);
      FORI(j,m) s[i][j] = ss[j-1];
   }
   FORI(i,n) {
      lm[i] = m+1;
      rm[i] = 0;
      FORI(j,m) if (s[i][j] == 'W') rm[i] = j;
      REPD(j,m,1) if (s[i][j] == 'W') lm[i] = j;
   }
   rm[n+1] = 0;
   lm[n+1] = m+1;
   //DBG(vi(rm+1,rm+n+2))
   //DBG(vi(lm+1,lm+n+2))
   int w = 0, unmowed = 0;
   FORI(i,n) FORI(j,m) if (s[i][j] == 'W') ++unmowed;
   int row = 1, col = 1;
   while (unmowed > 0) {
      if (row & 1) {
         // w prawo
         if (max(rm[row],rm[row+1]) > col) ++col;
         else ++row;
      } else {
         // w lewo
         if (min(lm[row],lm[row+1]) < col) --col;
         else ++row;
      }
      if (s[row][col] == 'W') --unmowed;
      ++w;
      //DBG(mp(row,col))
   }
   pisz(w);
}