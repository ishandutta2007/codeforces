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

int main () {
   wez3(n,m,i)
   wez3(j,a,b)
   vector<pii> v;
   v.pb(mp(1,m));
   v.pb(mp(n,1));
   v.pb(mp(1,1));
   v.pb(mp(n,m));
   int res = INF;
   FOREACH(cor,v) {
      int dx = abs(cor->fi - i), dy = abs(cor->se - j);
      if (dx % a) continue;
      if (dy % b) continue;
      dx /= a;
      dy /= b;
      if (dx % 2 != dy % 2) continue;
      if (dy > 0 && dx == 0) {
         if (i-a >= 1 || i+a <= n) {
            REMIN(res, dy);
         }
      } else if (dy == 0 && dx > 0) {
         if (j-b >= 1 || j+b <= m) {
            REMIN(res, dx);
         }
      } else {
         REMIN(res, max(dx, dy));
      }
   }
   if (res == INF) printf("Poor Inna and pony!");
   else pisz(res);
}