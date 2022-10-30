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
#define IN(x,y) ((y).find((x))!=(y).end())
#define DBG(vari) cout<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

#define N 200005
ll a[N], typ[N], b[N], res[N];
bool reachableFrom1[N];
vi incoming[N];

int main () {
   wez(n)
   REP(i,2,n) { wez(ai) a[i] = ai; res[i] = -1; }
   res[1] = 0;
   typ[1] = 3;
   REP(x,2,n) {
      if (x + a[x] > n) {
         typ[x] = 1; // zielony
         res[x] = a[x];
      } else {
         b[x] = a[x] - a[x+a[x]];
         if (x + b[x] <= 0) {
            typ[x] = 2; // niebieski
            res[x] = a[x] + a[x+a[x]];
         } else {
            typ[x] = 0;
            incoming[x + b[x]].pb(x);
         }
      }
   }
   //DBG(vi(typ+1,typ+5))
   vi noout;
   noout.pb(1);
   while (!noout.empty()) {
      int v = noout.back(); noout.pop_back();
      reachableFrom1[v] = 1;
      if (typ[v] > 0) {
      } else {
         res[v] = res[v + b[v]] + a[v] + a[v+a[v]];
      }
      FOREACH(it,incoming[v]) {
         noout.pb(*it);
      }
   }
   REP(x,2,n) if (typ[x] > 0) noout.pb(x);
   while (!noout.empty()) {
      int v = noout.back(); noout.pop_back();
      if (typ[v] > 0) {
      } else {
         res[v] = res[v + b[v]] + a[v] + a[v+a[v]];
      }
      FOREACH(it,incoming[v]) {
         noout.pb(*it);
      }
   }
   FORI(st,n-1) {
      a[1] = st;
      if (1 + a[1] > n) {
         pisz(a[1]);
      } else {
         b[1] = a[1] - a[1+a[1]];
         if (1 + b[1] <= 0) {
            pisz(a[1] + a[1+a[1]]);
         } else {
            // idzie do 1+b[1]
            if (reachableFrom1[1+b[1]] || res[1+b[1]] == -1) {
               pisz(-1);
            } else {
               printf("%I64d\n", res[1+b[1]] + a[1] + a[1+a[1]]);
            }
         }
      }
   }
}