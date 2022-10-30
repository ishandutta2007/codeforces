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

int a[26], co[32], ile[32], kinds, s, w[4][4];
const int xx[16] = {0,0,0,0,1,2,3,1,3,2,3,3,1,2,1,2};
const int yy[16] = {0,1,2,3,1,2,3,2,2,1,1,0,0,0,3,3};
typedef bool (*checkFunction)(void);

bool checkNothing () { return 1; }
bool check3 () {
   return s == w[0][0] + w[0][1] + w[0][2] + w[0][3];
}
bool check6 () {
   return s == w[0][0] + w[1][1] + w[2][2] + w[3][3];
}
bool check8 () {
   return s == w[0][2] + w[1][2] + w[2][2] + w[3][2];
}
bool check10() {
   return s == w[0][1] + w[1][1] + w[2][1] + w[3][1];
}
bool check11() {
   return (s == w[3][0] + w[3][1] + w[3][2] + w[3][3])
   && (s == w[0][3] + w[1][2] + w[2][1] + w[3][0]);
}
bool check13() {
   return s == w[0][0] + w[1][0] + w[2][0] + w[3][0];
}
bool check14() {
   return s == w[1][0] + w[1][1] + w[1][2] + w[1][3];
}
bool check15() {
   return (s == w[2][0] + w[2][1] + w[2][2] + w[2][3]) &&
   (s == w[0][3] + w[1][3] + w[2][3] + w[3][3]);
}

checkFunction performCheck[16] = {checkNothing, checkNothing, checkNothing, checkNothing, checkNothing, checkNothing, checkNothing, checkNothing, checkNothing, checkNothing, checkNothing, checkNothing, checkNothing, checkNothing, checkNothing, checkNothing};

void backtrack (int ktory) {
   if (ktory == 16) {
      FOR(i,4) {
         printf("%d %d %d %d\n", w[i][0], w[i][1], w[i][2], w[i][3]);
      }
      exit(0);
   }
   int x = xx[ktory], y = yy[ktory];
   
   // wybierz
   FOR(kind,kinds) if (ile[kind]) {
      w[x][y] = co[kind];
      --ile[kind];
      // spr
      bool res = performCheck[ktory]();
      if (res) {
         // spr. ok
         backtrack(ktory+1);
      }
      // spr. nie bylo ok lub tamto sie zepsulo; wracamy
      ++ile[kind];      
   }
}

/*int main () {
   int ff[4][4];
   FOR(i,16) ff[xx[i]][yy[i]] = i;
   FOR(i,4) { printf("\n"); DBG(vi(ff[i], ff[i]+4)) }
}*/

int main () {
   performCheck[3] = &check3;
   performCheck[6] = &check6;
   performCheck[8] = &check8;
   performCheck[10] = &check10;
   performCheck[11] = &check11;
   performCheck[13] = &check13;
   performCheck[14] = &check14;
   performCheck[15] = &check15;
   
   wez(n)
   int nn = n*n;
   s = 0;
   FOR(i,nn) {
      scanf("%d", a+i);
      s += a[i];
   }
   sort(a,a+nn);
   s /= n;
   pisz(s);
   if (n == 1) {
      pisz(s);
   } else if (n == 2) {
      do {
         if (
         // poziome
         s == a[0] + a[1] &&
         s == a[2] + a[3] &&
         // pionowe
         s == a[0] + a[2] &&
         s == a[1] + a[3] &&
         // przekatne
         s == a[0] + a[3] &&
         s == a[1] + a[2]) {
            printf("%d %d\n%d %d\n", a[0], a[1], a[2], a[3]);
            return 0;
         }
      } while (next_permutation(a,a+4));
   } else if (n == 3) {
      do {
         if (
         // poziome
         s == a[0] + a[1] + a[2] &&
         s == a[3] + a[4] + a[5] &&
         s == a[6] + a[7] + a[8] &&
         // pionowe
         s == a[0] + a[3] + a[6] &&
         s == a[1] + a[4] + a[7] &&
         s == a[2] + a[5] + a[8] &&
         // przekatne
         s == a[0] + a[4] + a[8] &&
         s == a[2] + a[4] + a[6]) {
            printf("%d %d %d\n%d %d %d\n%d %d %d\n", a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8]);
            return 0;
         }
      } while (next_permutation(a,a+9));
   } else { // n == 4
      kinds = 0;
      FOR(i,nn) {
         if (i != 0 && a[i] == a[i-1]) {
            ++ile[kinds-1];
         } else {
            co[kinds] = a[i];
            ile[kinds] = 1;
            kinds++;
         }
      }
      backtrack(0);
   }
}