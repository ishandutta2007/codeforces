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

#define N 100007
vi adj[N];
int parent[N];
vector<vi> res;
vector<pii> edges;

void dfs (int v, int p, int edgenum) {
   FOREACH(x,adj[v]) if (*x != p) {
      vi w;
      w.pb(*x);
      w.pb(v);
      res.pb(w);
      if (edgenum != SZ(res)) edges.pb(mp(edgenum,SZ(res)));
      dfs(*x,v, SZ(res));
   }
}

int main () {
   wez(n)
   FOR(i,n-1) {
      wez2(a,b)
      adj[a].pb(b);
      adj[b].pb(a);
   }
   dfs(1,-1, 1);
   pisz(SZ(res));
   FOREACH(it,res) {
      printf("%d ", SZ((*it))); FOREACH(it2,(*it)) printf("%d ", *it2); printf("\n");
   }
   FOREACH(it,edges) printf("%d %d\n", it->fi, it->se);
}