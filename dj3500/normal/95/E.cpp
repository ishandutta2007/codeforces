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
using namespace std;
#define pb push_back
#define INF 2147483647
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define FORI(i,n) for(int (i)=1;(i)<=(n);++(i))
#define mp make_pair
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define sz size()
#define fi first
#define se second
#define wez(n) int (n); scanf("%d",&(n));
#define wez2(n,m) int (n),(m); scanf("%d %d",&(n),&(m));
#define wez3(n,m,k) int (n),(m),(k); scanf("%d %d %d",&(n),&(m),&(k));
inline void pisz(int n) { printf("%d\n",n); }
template<typename T,typename TT> ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &s,vector<T> t){FOR(i,t.size())s<<t[i]<<" ";return s; }
#define IN(x,y) ((y).find((x))!=(y).end()) 
#define DBG(vari) cout<<#vari<<" = "<<vari<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));

int bfs (int n, vector<int> *adj, vector<bool> &odwiedzony, int i) {
   int skl = 0;
   deque<pair<int,int> > kol;
   kol.pb(mp(i,0));
   while (!kol.empty()) {
      int v = kol.front().first;
      int skad = kol.front().second;
      kol.pop_front();
      
      if (odwiedzony[v]) continue;
      odwiedzony[v] = true;
      // odwiedzamy wierzcholek
      ++skl;
      
      for (vector<int>::iterator it = adj[v].begin(); it != adj[v].end(); ++it) {
         kol.pb(mp(*it,v));
      }
   }
   return skl;
}

bool lucky (int x) {
   while (x) {
      if (x%10 != 4 && x%10 != 7) return false;
      x /= 10;
   }
   return true;
}


vi adj[100005];

int main () {
   wez2(n,m)
   FOR(i,m) {
      wez2(a,b)
      adj[a].pb(b);
      adj[b].pb(a);
   }
   
   vi skladowe;
   vector<bool> odwiedzony(n+1,false);
   FORI(i,n) {
      int w = bfs(n,adj,odwiedzony,i);
      if (w > 0) skladowe.pb(w);
   }
   
   map<int,int> sk;
   FOR(i,skladowe.sz) sk[skladowe[i]]++; // grupujemy skladowe - bardzo wazne dla wydajnosci

   int best = INF;
   map<int,int> mapa;
   mapa[0]=0;
   FOREACH(itsk,sk) {
      vector<pii> v;
      
      int r = itsk->fi, ile = itsk->se;
      
      FORI(d,ile) {
         // probujemy dolozyc d zbiorow mocy r kazdy
         FOREACH(it,mapa) {
            int nowy = it->fi + d*r, koszt = it->se + d;
            if (nowy > 77777) continue;
            if (lucky(nowy)) {
               REMIN(best,koszt)
            } else {
               v.pb(mp(nowy,koszt));
            }
         }
      }
      
      FOR(j,v.sz) {
         if (!IN(v[j].fi,mapa) || mapa[v[j].fi] > v[j].se) {
            mapa[v[j].fi] = v[j].se;
         }
      }
      
      map<int,int>::iterator it = mapa.begin();
      while (it != mapa.end()) {
         if (it->se >= best-1) {
            map<int,int>::iterator toDel = it;
            it++;
            mapa.erase(toDel);
         } else it++;
      }
   }
   
   if (best == INF) pisz(-1);
   else pisz(best-1);     
}