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

#define N 200007
vector<pii> adj[N];
bool seen[N];
ll res[N];
vector<pii> cycle;
int end, n;

int dfs (int v, int p) {
   if (seen[v]++) {
      end = v;
      return 1;
   } else {
      FOREACH(x,adj[v]) if (x->fi != p) {
         if (dfs(x->fi,v)) {
            if (cycle.empty() || cycle.back().fi != end) cycle.pb(mp(v,x->se));
            return 1;
         }
      }
   }
   return 0;
}

ll size[N], totalCost[N], distToRoot[N], root[N];

void dig (int v, int p1, int p2, int dist, int rt) {
   size[v] = 1;
   totalCost[v] = 0;
   distToRoot[v] = dist;
   root[v] = rt;
   FOREACH(x,adj[v]) if (x->fi != p1 && x->fi != p2) {
      dig(x->fi,v,-1,dist + x->se,rt);
      size[v] += size[x->fi];
      totalCost[v] += size[x->fi] * x->se + totalCost[x->fi];
   }
}
void compute (int v, int p1, int p2) {
   FOREACH(x,adj[v]) if (x->fi != p1 && x->fi != p2) {
      int w = x->fi;
      res[w] = res[v] + (n - 2*size[w]) * x->se;
      compute(w,v,-1);
   }
}

int main () {
   scanf("%d", &n);
   FOR(i,n) {
      wez3(a,b,c)
      adj[a].pb(mp(b,c));
      adj[b].pb(mp(a,c));
   }
   dfs(1,-1);
   reverse(ALL(cycle));
   int m = SZ(cycle);
   ll baseCost = 0;
   FOR(u,m) {
      dig(cycle[u].fi,cycle[(u+1)%m].fi,cycle[(u+m-1)%m].fi,0,cycle[u].fi);
      baseCost += totalCost[cycle[u].fi];
   }
   
   // oblicz dla r
   int r = cycle[0].fi;
   int cycleLen = 0;
   FOREACH(x,cycle) cycleLen += x->se;
   res[r] = baseCost;
   ll straightCost = 0; // tymczasowa
   ll numOfStraights = 1;
   ll sumOfSizesOverStraights = size[r];
   ll distToLastStraight = 0;
   REP(u,1,m-1) {
      straightCost += cycle[u-1].se;
      #define backwardCost (cycleLen - straightCost)
      if (backwardCost >= straightCost) {
         numOfStraights++;
         sumOfSizesOverStraights += size[cycle[u].fi];
         distToLastStraight = straightCost;
      }
      res[r] += size[cycle[u].fi] * min(straightCost, backwardCost);
   }
   
   // oblicz dla innych rootw
   REP(u,1,m-1) {
      res[cycle[u].fi] = res[cycle[u-1].fi];
      numOfStraights--; // u-1 wypada
      distToLastStraight -= cycle[u-1].se;
      sumOfSizesOverStraights -= size[cycle[u-1].fi];
      res[cycle[u].fi] -= sumOfSizesOverStraights * cycle[u-1].se;
      res[cycle[u].fi] += (n - sumOfSizesOverStraights) * cycle[u-1].se;
      straightCost = distToLastStraight;
      while (numOfStraights < m) {
         int cand = (u + numOfStraights) % m;
         straightCost += cycle[(cand-1+m)%m].se;
         if (backwardCost >= straightCost) {
            numOfStraights++;
            sumOfSizesOverStraights += size[cycle[cand].fi];
            distToLastStraight = straightCost;
            res[cycle[u].fi] += (straightCost - backwardCost) * size[cycle[cand].fi];
         } else {
            break;
         }
      }
   }
   
   // oblicz dla reszty
   FOR(u,m) compute(cycle[u].fi,cycle[(u+1)%m].fi,cycle[(u+m-1)%m].fi);
   
   FORI(i,n) printf("%I64d ", res[i]);
}