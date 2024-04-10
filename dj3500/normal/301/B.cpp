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

// bierze graf skierowany waony o wierzcholkach 1..n
// zwraca vi() jesli jest ujemny cykl
// w przeciwnym wypadku zwraca dist[v] = odleglosc od src
int m;
vi bellmanFord (int n, vector<pii> *adj, int src) {
   vi dist(n+1,INF);
   dist[src] = -m;
   FOR(it,n) {
      bool changed = 0;
      FORI(v,n) FOREACH(x,adj[v]) {
         if (dist[v] + x->se < dist[x->fi] && dist[v] + x->se <= 0) {
            dist[x->fi] = dist[v] + x->se;
            changed = 1;
         }
      }
      if (!changed) return dist;
   }
   return vi();
}

#define N 207
int x[N], y[N], a[N];
vector<pii> adj[N];


int main () {
   wez2(n,d)
   a[1] = 0;
   REP(i,2,n-1) scanf("%d", a+i);
   a[n] = 0;
   REP(i,1,n) {
      scanf("%d %d", x+i, y+i);
      adj[2*i-1].pb(mp(2*i,-a[i]));
   }
   REP(i,1,n) REP(j,1,n) if (i != j) {
      adj[2*i].pb(mp(2*j-1, d * (abs(x[i]-x[j]) + abs(y[i]-y[j]))));
   }
   
   int from = 0, best = INF, to = best - 1;
   while (from <= to) {
      m = (from + to) / 2;
      // koszt lokalnie > m => le
            
      if (bellmanFord(2*n,adj,2*1-1)[2*n] != INF) {
         best = m;
         to = m-1;
      } else {
         from = m+1;
      }
   }
   pisz(best);
}