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
#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (auto i=t.begin(); i!=t.end(); i++)
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
      return tab[a] = find(tab[a]);
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


#define N 1024
char temp[N];
string s[N];
vi adj[N];
bool seen[N];

int dist (const string &a, const string &b) {
   int d = 0;
   FOR(i,SZ(a)) d += a[i] != b[i];
   return d;
}

void dfs (int v, int p) {
   if (seen[v]++) return;
   printf("%d %d\n", v + 1, p + 1);
   FOREACH(it,adj[v]) dfs(*it, v);
}

int main () {
   wez2(n,m)
   wez2(k,w)
   FOR(a,k) {
      FOR(i,n) {
         scanf("%s", temp);
         s[a] += temp;
      }
   }
   vector<pair<int,pii> > v;
   FOR(i,k) FOR(j,i) {
      int d = dist(s[i],s[j]);
      if (d*w < n*m) v.pb(mp(d, mp(i,j)));
   }
   sort(ALL(v));
   UnionFind uf(k+1);

   int cost = 0, edges = 0;
   FOREACH(it,v) {
      if (uf.unia(it->se.fi, it->se.se)) {
         ++edges;
         adj[it->se.fi].pb(it->se.se);
         adj[it->se.se].pb(it->se.fi);
         cost += w * it->fi;
      }
   }
   cost += n * m * (k - edges);
   pisz(cost);
   FOR(i,k) if (!seen[i]) dfs(i,-1);
}