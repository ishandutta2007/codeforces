// tested by Hightail: https://github.com/dj3500/hightail
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
#define DBG(vari) cout<<"["<<__LINE__<<"] "<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (__typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

const int N = 100100;
set<int> adj[N];
bool removed[N];

int main () {
   wez(n)
   FOR(u,n-1) {
      wez2(a,b)
      adj[a].insert(b);
      adj[b].insert(a);
   }

   int vert = n;

   if (vert <= 5) {
      printf("Yes");
      return 0;
   }

   vi leaves;
   FORI(i,n) if (SZ(adj[i]) == 1) leaves.pb(i);
   while (!leaves.empty()) {
      int v = leaves.back();
      leaves.pop_back();
      if (removed[v]) continue; // never
      int w = *adj[v].begin();
      if (SZ(adj[w]) == 2) {
         // kill v
         removed[v] = 1;
         adj[w].erase(v);
         leaves.pb(w);
         --vert;
      }
   }

   if (vert <= 5) {
      printf("Yes");
      return 0;
   }

   set<int> nonlin;
   FORI(i,n) if (!removed[i]) {
      if (SZ(adj[i]) == 1) {
         // lisc
         continue;
      }
      if (SZ(adj[i]) == 3) {
         //auto it = adj[i].begin();
         //int a = *it; ++it; int b = *it; ++it; int c = *it;
         int lisci = 0;
         //if (SZ(adj[a])
         FOREACH(it,adj[i]) if (SZ(adj[*it]) == 1) ++lisci;
         if (lisci >= 2) continue; // linear
      }
      nonlin.insert(i);
   }

   // indukuj drzewo na nonlin
   FOREACH(it,nonlin) {
      int nonlinnei = 0;
      FOREACH(jt,adj[*it]) if (nonlin.count(*jt)) ++nonlinnei;
      if (nonlinnei >= 3) {
         printf("No");
         return 0;
      }
   }

   printf("Yes");
}