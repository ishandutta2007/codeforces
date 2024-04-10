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

int a[5], b[5];

int main () {
   wez(n)
   int suma = 0;
   FOR(i,n) {
      wez(x)
      a[x]++;
      suma += x;
   }
   int res = INF;
   
   /*vector<pii> a;
   FOR(k,5) a.pb(mp(k,a[k]));*/
   
   REP(ile33,0,n) {
      int ile3 = ile33;
      int masa4 = suma - 3*ile3;
      if (masa4 < 0 || (masa4 % 4 != 0)) continue;
      int ile4 = masa4 / 4;
      int ile0 = n - ile3 - ile4;
      /*vector<pii> b;
      b.pb(mp(0,ile0));
      b.pb(mp(3,ile3));
      b.pb(mp(4,ile4));*/
      
      FOR(k,5) b[k] = a[k];
      int koszt = 0;
      
      // 0
      FOR(k,5) {
         if (ile0) {
            int m = min(b[k], ile0);
            ile0 -= m;
            b[k] -= m;
            koszt += k * m;
         }
      }
      // 3
      FOR(k,5) {
         if (ile3) {
            int m = min(b[k], ile3);
            ile3 -= m;
            b[k] -= m;
            koszt += abs(k-3) * m;
         }
      }
      // 4
      FOR(k,5) {
         if (ile4) {
            int m = min(b[k], ile4);
            ile4 -= m;
            b[k] -= m;
            koszt += (4-k) * m;
         }
      }
      
      res = min(res, koszt);
   }
   
   pisz(res == INF ? -1 : res/2);
}