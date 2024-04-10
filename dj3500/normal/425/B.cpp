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

inline int dist (int a, int b) {
   return __builtin_popcount(a ^ b);
}

int a[111], t[111][111];

int main () {
   wez3(n,m,k)
   FOR(i,n) {
      FOR(j,m) {
         wez(x)
         if (x == 1) {
            if (m <= 10) a[i] |= 1<<j;
            t[i][j] = 1;
         }
      }
   }
   
   int best = INF;
   if (m <= 10) {
      FOR(mask,1<<m) {
         int c = 0;
         FOR(i,n) c += min(dist(a[i],mask), dist(a[i],(1<<m) - 1 - mask));
         REMIN(best, c);
      }
   } else {
      // m > 10 >= k
      FOR(j,m) {
         int c = 0;
         FOR(J,m) {
            int c1 = 0;
            FOR(i,n) {
               if (t[i][j] == t[i][J]) ++c1;
            }
            c += min(c1,n-c1);
         }
         REMIN(best, c);
      }
   }
   
   pisz(best > k ? -1 : best);
}