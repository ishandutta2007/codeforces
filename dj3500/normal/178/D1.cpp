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

int a[26];

int main () {
   wez(n)
   int nn = n*n;
   int s = 0;
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
   }
}