#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;
#define pb push_back
#define INF (int)1e9
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define FORI(i,n) for(int (i)=1;(i)<=(n);++(i))
#define mp make_pair
#define pii pair<int,int>
#define ll long long
#define wez(n) int (n); scanf("%d",&(n));
#define IN(x,y) ((y).find((x))!=(y).end()) 
#define DBG(vari) cout<<#vari<<" = "<<vari<<endl;

template <typename U1, typename U2, typename U3>
struct T3 { // 3-tuple
   U1 u1;
   U2 u2;
   U3 u3;
   
   T3(U1 _u1, U2 _u2, U3 _u3): u1(_u1), u2(_u2), u3(_u3) { }
   bool operator < (const T3& t) const {
      if (u1 != t.u1) return u1 < t.u1;
      if (u2 != t.u2) return u2 < t.u2;
      return u3 < t.u3;
   }
};
typedef T3<int,int,int> T3i;


inline void pisz(int n) {
   printf("%d\n",n);
}

vector<int> adj[3002];
map<pii,int> vis;

int main () {
  wez(n)wez(m)wez(k)
  FOR(i,m) {
      wez(a)wez(b)
      adj[a].pb(b);
      adj[b].pb(a);
   }
   set<T3i> triples;
   
   FOR(i,k) {
      wez(a)wez(b)wez(c)
      triples.insert(T3i(a,b,c));
   }
   
   bool broken = false;
   deque<T3i> q;
   q.pb(T3i(-1,-1,1));
   while (!q.empty()) {
      int skad1 = q.front().u1;
      int skad2 = q.front().u2;
      int v = q.front().u3;
      q.pop_front();
      
      if (IN(mp(skad2,v),vis)) continue;
      vis.insert(mp(mp(skad2,v), skad1));

      if (v==n) {
         vector<int> droga;
         int akt = v, poprz = skad2;
         while (poprz != -1) {
            droga.pb(akt);
            int nakt = poprz;
            poprz = vis[mp(poprz,akt)];
            akt = nakt;
         }
         printf("%d\n",droga.size());
         printf("1 ");
         for (int i = droga.size()-1; i >= 0; --i) printf("%d ",droga[i]);
         
         broken = true;
         break;
      }
      
      FOR(i,adj[v].size()) {
         if (!IN(T3i(skad2,v,adj[v][i]),triples)) {
            q.pb(T3i(skad2,v,adj[v][i]));
         }
      }
   }
   if (!broken) printf("-1");
}