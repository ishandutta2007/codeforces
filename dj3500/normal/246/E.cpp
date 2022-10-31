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
#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

#define N 100006
int parent[N], name[N], newnum[N], maxnum[N], depth[N];
char s[30];
vi children[N];
int ans[N];
int nextnum = 0;

void dfs (int v, int d) {
   depth[v] = d;
   newnum[v] = nextnum++;
   maxnum[v] = newnum[v];
   FOREACH(x,children[v]) {
      dfs(*x, 1+d);
      REMAX(maxnum[v], maxnum[*x]);
   }
}

vector<pair<pii,int> > todo[N];

namespace Fenwick {
   int a[N];
   vi nonzero;
   // value[n] += x
   void add(int n, int x) { for (; n < N; n |= n + 1) { a[n] += x; nonzero.pb(n); } }
   // Returns value[0] + value[1] + ... + value[n]
   int sum(int n) { int s=0; while (n>=0) { s+=a[n]; n=(n&(n+1))-1; } return s; }
   void clear () {
      FOREACH(x,nonzero) a[*x] = 0;
      nonzero.clear();
   }
   int sumbetween (int x, int y) {
      int res = sum(y);
      if (x > 0) res -= sum(x-1);
      return res;
   }
};

vector<pii> onDepth[N];

int main () {
   wez(n)
   parent[0] = -1;
   name[0] = 0;
   map<string,int> mapa;
   int q = 1;
   FORI(i,n) {
      scanf("%s %d", s, parent+i);
      if (!IN(s,mapa)) mapa[s] = q++;
      name[i] = mapa[s];
   }
   FORI(i,n) children[parent[i]].pb(i);
   dfs(0,0);
   wez(queries)
   FOR(q,queries) {
      wez2(v,lev)
      ans[q] = 0;
      if (depth[v] + lev <= 100000) todo[depth[v]+lev].pb(mp(mp(newnum[v],maxnum[v]),q));
   }
   FORI(i,n) {
      onDepth[depth[i]].pb(mp(newnum[i], name[i]));
   }
   FORI(lv,100000) {
      map<int,int> lastOccurOnThisLevel;
      sort(ALL(onDepth[lv]));
      vector<pii> pts;
      FOREACH(it,onDepth[lv]) {
         int v = it->fi, nm = it->se;
         int prev = lastOccurOnThisLevel[nm] - 1;
         lastOccurOnThisLevel[nm] = v + 1;
         pts.pb(mp(prev,v));
      }
      sort(ALL(pts));
      int nowToAdd = 0;
      Fenwick::clear();
      sort(ALL(todo[lv]));
      // ile jest v na tym levelu tze prev < fi, v in [fi,se]
      FOREACH(qr,todo[lv]) {
         int le = qr->fi.fi, ri = qr->fi.se, queryNumber = qr->se;
         while (nowToAdd < SZ(pts) && pts[nowToAdd].fi < le) {
            Fenwick::add(pts[nowToAdd].se, 1);
            nowToAdd++;
         }
         ans[queryNumber] = Fenwick::sumbetween(le, ri);
      }
   }
   FOR(q,queries) pisz(ans[q]);
}