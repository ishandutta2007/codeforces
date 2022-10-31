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
#define INF 2147483647
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

int main () {
   ll l,r;
   scanf("%I64d %I64d",&l,&r);
   ll pot = 1;
   vector<pair<ll,ll> > v;
   while (pot <= l) pot *= 10;
   v.pb(mp(l,pot-1));
   while (pot <= r) {
      pot *= 10;
      v.pb(mp(pot/10,pot-1));
   }
   v.back().se = r;
   
   ll maxx = -INF;
   
   FOR(i,v.sz) {
      ll p = 1;
      while (p <= v[i].fi) p *= 10;
      --p;

      vector<ll> punkty;
      punkty.pb(v[i].fi);
      punkty.pb(v[i].se);
      
      ll maks = p/2;
      if (maks+1 >= v[i].fi && maks+1 <= v[i].se) {
         punkty.pb(maks+1);
      }
      if (maks >= v[i].fi && maks <= v[i].se) {
         punkty.pb(maks);
      }
      if (maks-1 >= v[i].fi && maks-1 <= v[i].se) {
         punkty.pb(maks-1);
      }
      FOR(j,punkty.sz) {
         ll pr = punkty[j] * (p-punkty[j]);
         if (pr > maxx) maxx=pr;
      }
   }
   
   printf("%I64d\n",maxx);
}