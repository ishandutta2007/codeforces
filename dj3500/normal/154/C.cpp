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
      int fa = find(tab[a]);
      return tab[a] = fa;
   }
   
   bool unia(int a, int b) { // zwraca, czy odbylo sie polaczenie
   int fa = find(a), fb = find(b);
   
   if (fa==fb) return 0;
   if (ile[fa] <= ile[fb]) {
      ile[fb] += ile[fa];
      tab[fa] = fb;
   } else {
      ile[fa] += ile[fb];
      tab[fb] = fa;
   }
   return 1;
   }
};

#define N 1000007
vi adj[N];
UnionFind *uf;

unsigned ll haszuj (vi &v, int bez) {
   unsigned ll res = 0, p = 1000000007, pot = 1;
   FOREACH(x,v) if ((*x) != bez) {
      res += pot * (*x);
      pot *= p;
   }
   return res;
}

/*void dodaj (map<unsigned ll, int> &mapa, int i, unsigned ll hasz) {
   if (IN(hasz,mapa)) {
      uf->unia(mapa[hasz]-1,i-1);
      //DBG(mp(mapa[hasz]-1,i-1))
   } else {
      mapa[hasz] = i;
   }
}*/

int main () {
   wez2(n,m)
   while(m--) {
      wez2(a,b)
      adj[a].pb(b);
      adj[b].pb(a);
   }
   //map<unsigned ll, int> h1, h2;
   vector<pair<unsigned ll, int> > vp[2];
   uf = new UnionFind(n);
   FORI(i,n) {
      //DBG(i)DBG(adj[i])
      adj[i].pb(i);
      sort(ALL(adj[i]));
      vp[0].pb(mp(haszuj(adj[i],-1),i));
      vp[1].pb(mp(haszuj(adj[i], i),i));
      //dodaj(h1,i,haszuj(adj[i],-1));
      //dodaj(h2,i,haszuj(adj[i],i));
   }
   
   FOR(u,2) {
      sort(ALL(vp[u]));
      FOR(i,SZ(vp[u])-1) {
         if (vp[u][i].fi == vp[u][i+1].fi) uf->unia(vp[u][i].se - 1, vp[u][i+1].se - 1);
      }
   }
   
   ll res = 0;
   FOR(i,n) if (i == uf->find(i)) {
      //DBG(i)
      //DBG(uf->ile[i])
      res += ((ll)uf->ile[i]) * (uf->ile[i] - 1) / 2;
   }
   cout << res << endl;
}