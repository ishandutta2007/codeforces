// tested by Hightail: https://github.com/dj3500/hightail
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
#include <cassert>
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
#define DBG(vari) cout<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (__typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

struct MaxTree {
   int* el; int s;
   MaxTree (int h) { // dziedzina elementow to [0..2^h-1]
      el = new int[2*(s = 1<<h)]; FOR(x,2*s) el[x] = -INF;
   }
   void Set (int p, int v) { // uwaga: moe overwritowa mniejsz warto
      for (p += s, el[p] = v, p /= 2; p > 0; p /= 2) el[p] = max(el[2*p],el[2*p+1]);
   }
   int Find (int p, int k) { // wyznacz max na [p,k]
      int m = -INF; p += s; k += s;
      while (p < k) {
         if (p&1)    m = max(m, el[p++]);
         if (!(k&1)) m = max(m, el[k--]);
         p /= 2; k /= 2;
      }
      if (p == k) m = max(m, el[p]);
      return m;
   }
};

#define N 500500
int a[N];
map<int,vi> lastpos;
int pocz[N];
vi insertAt[N];
int best[N];
pair<int,pair<int,pii> >  dp[N];

int main () {
   wez(n)
   FORI(i,n) scanf("%d", a+i);
   
   vector<pii> queries;
   
   FORI(i,n) {
      best[i] = -INF;
      
      if (lastpos.count(a[i])) {
         vi& V = lastpos[a[i]];
         pocz[i] = V.back(); // przedzia [pocz[i], i]
         queries.pb(mp(pocz[i] - 1, i));
         insertAt[pocz[i]].pb(i);
         
         if (SZ(V) >= 3) {
            best[i] = V[SZ(V) - 3];
         }
      }
      
      lastpos[a[i]].pb(i);
   }
   
   sort(ALL(queries));
   
   MaxTree tr(20);
   int nowToAdd = 0;
   FOREACH(it,queries) {
      int i = it->se;
      int limit = it->fi;
      while (nowToAdd <= limit) {
         FOREACH(x,insertAt[nowToAdd]) {
            tr.Set(*x, pocz[*x]);
         }
         ++nowToAdd;
      }
      REMAX(best[i], tr.Find(pocz[i] + 1, i - 1));
   }
   
   FORI(i,n) {
      dp[i] = dp[i-1];
      if (best[i] != -INF) {
         int start = best[i];
         REMAX(dp[i], mp(dp[start-1].fi + 1, mp(start-1, mp(a[start], a[i]))));
      }
   }
   pisz(4 * dp[n].fi);
   vi res;
   int k = n;
   while (dp[k].fi != 0) {
      int a = dp[k].se.se.fi, b = dp[k].se.se.se;
      int prv = dp[k].se.fi;
      res.pb(b);
      res.pb(a);
      res.pb(b);
      res.pb(a);
      k = prv;
   }
   reverse(ALL(res));
   FOREACH(it,res) printf("%d ", *it);
}