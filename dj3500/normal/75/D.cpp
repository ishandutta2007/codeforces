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
using namespace std;
#define pb push_back
#define INF (int)1e9
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define FORI(i,n) for(int (i)=1;(i)<=(n);++(i))
#define mp make_pair
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define sz size()
#define fi first
#define se second
#define wez(n) int (n); scanf("%d",&(n));
#define wez2(n,m) int (n),(m); scanf("%d %d",&(n),&(m));
#define wez3(n,m,k) int (n),(m),(k); scanf("%d %d %d",&(n),&(m),&(k));
inline void pisz(int n) { printf("%d\n",n); }
template<typename T,typename TT> ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &s,vector<T> t){FOR(i,t.size())s<<t[i]<<" ";return s; }
#define IN(x,y) ((y).find((x))!=(y).end()) 
#define DBG(vari) cout<<#vari<<" = "<<vari<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));

int pocz[250002],srodek[250002],kon[250002],cale[250002],max_uj[250002];
bool bylplus[250002];
int a[5005];

ll max (ll a, int b) { return a > b ? a : b; }

int main () {
   
   wez2(n,m)
   FORI(i,n) {
      wez(l)
      FOR(k,l) scanf("%d",a+k);
      int poczsum = 0, konsum = 0;
      FOR(k,l) {
         cale[i] += a[k];
         poczsum += a[k];
         REMAX(pocz[i],poczsum)
         konsum += a[l-1-k];
         REMAX(kon[i],konsum)
      }
      int aktnajl = 0;
      FOR(k,l) {
         aktnajl += a[k];
         if (aktnajl < 0) aktnajl = 0;
         REMAX(srodek[i],aktnajl)
      }
      
      bylplus[i] = 0;
      max_uj[i] = -INF;
      
      FOR(k,l) {
         if (a[k] >= 0) bylplus[i] = 1;
         else REMAX(max_uj[i],a[k])
      }
//      DBG(cale[i])DBG(pocz[i])DBG(srodek[i])DBG(kon[i])
      
   }

   bool bylplusglobal = 0;
   int max_ujglobal = -INF;
   
   ll aktnajl = 0, woglenajl = 0;
   FOR(fgsfds,m) {
      wez(x)
      if (bylplus[x]) bylplusglobal = 1;
      else REMAX(max_ujglobal,max_uj[x])
      
      REMAX(woglenajl,srodek[x])
      
      REMAX(woglenajl,aktnajl + pocz[x]) // moglibysmy tu skonczyc
      aktnajl = kon[x] > aktnajl + cale[x] ? kon[x] :  aktnajl + cale[x];
      
      if (aktnajl < 0) aktnajl = 0;
   }
   //REMAX(woglenajl,aktnajl)
   
   if (!bylplusglobal) pisz(max_ujglobal);
   else printf("%I64d\n",woglenajl);
}