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

#define N 2005
char s[N][N], str[N][N];
bool invx[N], invy[N], invx1[N], invy1[N];
int n;
int w = 0;

void go() {
   FOR(i,n) {
      invx[i] = invy[i] = 0;
   }
   REP(y,0,n-2) REPD(x,n-1,y+1) {
      bool mabyc = (s[x][y] == '1') ^ invx[x] ^ invy[y];
      if (mabyc) {
         ++w;
         //DBG(mp(x,y))
         invx[x] = !invx[x];
         invy[y] = !invy[y];
      }
   }

   FOR(i,n) {
      invx1[i] ^= invx[i];
      invy1[i] ^= invy[i];
   }
}

int main () {
   scanf("%d",&n);
   FOR(i,n) {
      scanf("%s",s[i]);
      invx1[i] = invy1[i] = 0;
   }
      
   // pierwsza polowka
   go();
   //DBG(w)
   
   // transpozycja
   FOR(x,n) FOR(y,n) str[x][y] = s[y][x];
   FOR(x,n) FOR(y,n) s[x][y] = str[x][y];
   
   // druga polowka
   go();
   //DBG(w)
   
   // przekatna
   FOR(i,n) if ((s[i][i] == '1') ^ invx1[i] ^ invy1[i]) ++w;
   
   pisz(w);
}