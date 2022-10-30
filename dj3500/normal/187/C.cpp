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
#define INF 1000000000
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define FORI(i,n) for(int (i)=1;(i)<=(n);++(i))
#define mp make_pair
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define SZ(x) ((int)(x.size()))
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

struct UnionFind {
   vi tab, ile;

   UnionFind(int n) : // tworzy UF na 0, 1, ..., n-1
      tab(n), ile(n,1) {
      FOR(i,n) tab[i] = i;
   }

   int find(int a) {
      if (tab[a] == a) return a;
      return a = find(tab[a]);
   }

   bool unia(int a, int b) { // zwraca, czy odbylo sie polaczenie
      a = find(a), b = find(b);
      if (a==b) return 0;
      if (ile[a] <= ile[b]) {
         ile[b] += ile[a];
         tab[a] = b;
      } else {
         ile[a] += ile[b];
         tab[b] = a;
      }
      return 1;
   }
};

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


#define N 505000
vi adj[N];
bool seen[N];

int main () {
	wez3(n,m,k)
	vi frontier;
	while(k--) { wez(x) frontier.pb(x); }
	while(m--) {
		wez2(a,b)
		int nowy = ++n;
		adj[a].pb(nowy);
		adj[b].pb(nowy);
		adj[nowy].pb(a);
		adj[nowy].pb(b);
	}
	
	wez2(s,t)
	
	vi odleglosci = bfs1(n,s,adj);
	if (odleglosci[t] == -1) { pisz(-1); return 0; }	
	
	frontier.pb(t); // ?
	
	FORI(i,n) seen[i] = 0;
	
	int q = 0;
	UnionFind uf(n+5);
	while (uf.find(s) != uf.find(t)) {
		q++;
		vi newfrontier;
		FOREACH(uu,frontier) {
			int v = *uu;
			if (seen[v]) continue;
			seen[v] = 1;
			FOREACH(x,adj[v]) {
				newfrontier.pb(*x);
				uf.unia(v, *x);
			}
		}
		frontier = newfrontier;
	}
	pisz(q);
}