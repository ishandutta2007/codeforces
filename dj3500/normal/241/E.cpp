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

vi bellmanFord (int n, vector<pii> *adj, int src) {
   vi dist(n+1,INF);
   dist[src] = 0;
   FOR(it,n) {
      bool changed = 0;
      FORI(v,n) FOREACH(x,adj[v]) {
         if (dist[v] + x->se < dist[x->fi]) {
            dist[x->fi] = dist[v] + x->se;
            changed = 1;
         }
      }
      if (!changed) return dist;
   }
   return vi();
}

vi bfs1 (int n, int source, vi *adj) {
   vi odl(n+1,-1);
   deque<int> q;
   q.pb(source);
   odl[source] = 0;
   while (!q.empty()) {
      int v = q.front();
      q.pop_front();
      FOREACH(it,adj[v]) if (odl[*it] == -1) {
         odl[*it] = odl[v] + 1;
         q.pb(*it);
      }
   }
   return odl;
}

#define N 1007
vector<pii> adjbf[N];
vi adj[N], adjtr[N];

int main () {
   wez2(n,m)
   vector<pii> edges;
   FORI(j,m) {
      wez2(a,b)
      edges.pb(mp(a,b));
      adj[a].pb(b);
      adjtr[b].pb(a);
   }
   vi from1 = bfs1(n,1,adj), ton = bfs1(n,n,adjtr);
   
   FORI(j,m) {
      int a = edges[j-1].fi, b = edges[j-1].se;
      if (from1[a]!=-1 && ton[a]!=-1 && from1[b]!=-1 && ton[b]!=-1) {
         adjbf[a].pb(mp(b,2));
         adjbf[b].pb(mp(a,-1));
      }
   }
   vi dist = bellmanFord(n,adjbf,1);
   if (dist.empty()) {
      printf("No\n"); // za ostro!
   } else {
      printf("Yes\n");
      FORI(j,m) {
         int a = edges[j-1].fi, b = edges[j-1].se;
         if (from1[a]!=-1 && ton[a]!=-1 && from1[b]!=-1 && ton[b]!=-1) {
            pisz(dist[b] - dist[a]);
         } else {
            pisz(1);
         }
      }
   }
}