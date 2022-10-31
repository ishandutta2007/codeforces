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
#define DBG(vari) cout<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

// RMQ na przedziale od 0 do n-1
// przed uzyciem ustawic MAXX, n i odpalic init
// zwieksz zwieksza wartosci z przedzialu [aw,bw] o x
// getmin zwraca minimum z przedzialu [aw,bw]
// MAXX - 2 * (najmniejsza potega dwojki wieksza od n) + 10
namespace rm {
#define MAXX (524298*2)
int incr[MAXX];
pii minn[MAXX];
int n;

//void init () { FOR(i,MAXX) incr[i] = minn[i] = 0; }

void init (int v, int a, int b) {
   minn[v] = mp(0,a);
   if (a < b) {
      int mid = (a+b)/2;
      init(2*v, a, mid);
      init(2*v+1, mid+1, b);
   }
}
void init () {
   init(1,0,n-1);
}

int aw,bw,x; // temp
pii operator + (pii a, pii b) { return mp(a.fi + b.fi, a.se + b.se); }

void zwieksz2 (int v, int a, int b) {
   if (aw > b || bw < a) return;
   if (a >= aw && b <= bw) {
      incr[v] += x;
      minn[v].fi += x;
   } else {
      int mid = (a+b)/2;
      zwieksz2(2*v, a, mid);
      zwieksz2(2*v+1, mid+1, b);
      minn[v] = mp(incr[v],0) + max(minn[2*v], minn[2*v + 1]);
   }
}

void zwieksz (int _aw, int _bw, int _x) {
   aw = _aw; bw = _bw; x = _x;
   zwieksz2(1,0,n-1);
}

pii getmax (int v, int a, int b) {
   if (aw > b || bw < a) return mp(-INF,-1);
   if (a >= aw && b <= bw) {
      return minn[v];
   } else {
      int mid = (a+b)/2;
      return mp(incr[v],0) + max(getmax(2*v, a, mid), getmax(2*v+1, mid+1, b));
   }
}

pii getmax (int _aw, int _bw) {
   aw = _aw; bw = _bw;
   return getmax(1,0,n-1);
}
};


#define N 300007
int l[N], v[N], r[N];
vi insertAt[N], removeAt[N];

void add (int i, int x) {
   rm::zwieksz(v[i], r[i], x);
}

int main () {
   wez(n)
   FORI(i,n) scanf("%d %d %d", l+i, v+i, r+i);
   /*FORI(i,n) FORI(j,i-1) if (l[i] <= v[j] && v[j] <= r[i]) if (l[j] <= v[i] && v[i] <= r[j]) {
      DBG(mp(i,j));
   }*/
   rm::n = 300007;
   rm::init();
   FORI(i,n) {
      insertAt[l[i]].pb(i);
      removeAt[v[i] + 1].pb(i);
   }
   int best = 0, bestX = -1, bestY = -1;
   REP(x,1,300003) {
      FOREACH(it,insertAt[x]) add(*it, 1);
      FOREACH(it,removeAt[x]) add(*it,-1);
      pii res = rm::getmax(1,300000);
      if (res.fi > best) {
         best = res.fi;
         bestX = x;
         bestY = res.se;
      }
   }
   pisz(best);//pisz(bestX);pisz(bestY);
   FORI(i,n) {
      if (l[i] <= bestX && bestX <= v[i] && v[i] <= bestY && bestY <= r[i]) printf("%d ", i);
   }
}