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

vector<pii> kosz[1005];
bool hasstool[1005];

int main () {
   wez2(n,k)
   FORI(i,k) hasstool[i] = 0;
   vector<pii> stools, pencils;
   ll suma = 0;
   FORI(i,n) {
      wez2(ci,ti)
      suma += ci;
      if (ti == 1) {
         stools.pb(mp(ci,i));
      } else {
         pencils.pb(mp(ci,i));
      }
   }
   sort(ALL(stools));
   //DBG(stools)
   int u = 0;
   for (int j = 1; j <= k && !stools.empty(); ++j) {
     kosz[j].pb(stools.back()); // najdrozszy stool
     hasstool[j] = 1;
     stools.pop_back();
     u = j; // max numer pelnego koszyka
   }
   if (u != k) {  // zostaly puste koszyki
      REP(i,u+1,k) {
         kosz[i].pb(pencils.back());
         pencils.pop_back();
      }
   }
   // nie ma pustych koszykow, wywalamy reszte do ostatniego
   while (!pencils.empty()) {
      kosz[k].pb(pencils.back());
      pencils.pop_back();
   }
   while (!stools.empty()) {
      kosz[k].pb(stools.back());
      stools.pop_back();
      hasstool[k] = 1;
   }
   
   ll res = 2*suma;
   FORI(j,k) if (hasstool[j]) {
      res -= min_element(ALL(kosz[j]))->fi;
   }
   bool parz = 0;
   if (res & 1) parz = 1;
   cout << res/2 << "." << (parz ? "5" : "0") << "\n";
   FORI(j,k) {
      printf("%d ", SZ(kosz[j]));
      FOREACH(x,kosz[j]) printf("%d ", x->se);
      printf("\n");
   }
}