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

typedef vector<int> row;   // na longlongach dziala 10 razy wolniej
const int R = 6;
int mod;                // ustawic to przed uzyciem
struct macierz : vector<row> {
   macierz() : vector<row>(R,row(R,0)) {}
};

macierz id() {
   macierz w;
   FOR(i,R) w[i][i] = 1;
   return w;
}

macierz mult(const macierz &m1, const macierz &m2) {
   macierz w;
   FOR(i,R) FOR(j,R) {
      ll x = 0;
      FOR(k,R) x += (ll)m1[i][k] * m2[k][j] % mod;
      // przy mod <= 10^9+9, R <= 9 mozna wywalic poprzednie "% mod"
      w[i][j] = x % mod;
   }
   return w;
}

macierz potega(const macierz &m, ll k) {
   if (!k) return id();
   macierz x = potega(m,k/2);
   x = mult(x,x);
   if (k&1) return mult(m,x);
   return x;
}

const int tab[6][6] = 
   {
      {2,1,1,0,1,0},
      {1,2,0,1,1,0},
      {1,1,1,0,1,0},
      {1,1,0,1,1,0},
      {0,0,0,0,1,1},
      {0,0,0,0,0,1}
   };


int main () {
   scanf("%d", &mod);
   wez2(sx,sy)
   wez2(dx,dy)
   ll T;
   scanf("%lld", &T);
   macierz m;
   FOR(i,6) FOR(j,6) m[i][j] = tab[i][j];
   macierz w;
   w[0][0] = sx;
   w[1][0] = sy;
   w[2][0] = dx;
   w[3][0] = dy;
   w[4][0] = 0;
   w[5][0] = 1;
   m = mult(potega(m, T), w);
   int x = m[0][0], y = m[1][0];
   x %= mod;
   y %= mod;
   if (x <= 0) x += mod;
   if (y <= 0) y += mod;
   printf("%d %d", x, y);
}