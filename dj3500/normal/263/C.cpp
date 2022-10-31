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

#define MAXN 100003
int wej[MAXN], wyj[MAXN], ojc[MAXN], t;

void dfsgo(int v, vi *adj) {
   wej[v] = ++t;
   FOREACH(it,adj[v]) if (ojc[*it] == -1) {
      ojc[*it] = v;
      dfsgo(*it,adj);
   }
   wyj[v] = ++t;
}
void dfs(int n, vi *adj, int source = -1) {
   t = -1;
   FORI(i,n) wej[i] = wyj[i] = ojc[i] = -1;
   if (source == -1) {
      FORI(i,n) if (ojc[i] == -1) dfsgo(i,adj);
   } else dfsgo(source,adj);
}

#define N 100007
vi adj[N], adj2[N];

bool sim (int i, int j) {
   int cnt = 0;
   FOREACH(x,adj[i]) {
      FOREACH(y,adj[j]) {
         if (*x == *y) ++cnt;
      }
   }
   return cnt == 2;
}

int main () {
   wez(n)
   vector<pii> input;
   FOR(i,2*n) {
      wez2(a,b)
      if (a > b) swap(a,b);
      adj[a].pb(b);
      adj[b].pb(a);
      input.pb(mp(a,b));
   }
   sort(ALL(input));
   //DBG(input)
   FORI(i,n) {
      sort(ALL(adj[i]));
      if (SZ(adj[i]) != 4) {
         pisz(-1);
         return 0;
      }
   }
   if (n <= 7) {
      vi perm;
      FORI(i,n) perm.pb(i);
      do {
         vector<pii> lista;
         FOR(i,n) FORI(k,2) lista.pb(mp(perm[i], perm[(i+k)%n]));
         FOREACH(x,lista) if (x->fi > x->se) swap(x->fi, x->se);
         sort(ALL(lista));
         //DBG(lista)
         if (lista == input) {
            FOR(i,n) printf("%d ", perm[i]);
            return 0;
         }
      } while (next_permutation(ALL(perm)));
      pisz(-1);
      return 0;
   }
   FORI(i,n) {
      FOREACH(x,adj[i]) {
         if (sim(i,*x)) {
            adj2[i].pb(*x);
         }
      }
      //DBG(adj2[i])
   }
   FORI(i,n) if (SZ(adj2[i]) != 2) { pisz(-1); return 0; }
   dfs(n,adj2,1);
   FORI(i,n) if (wej[i] == -1) { pisz(-1); return 0; }
   vector<pii> vec;
   FORI(i,n) vec.pb(mp(wej[i],i));
   sort(ALL(vec));
   //DBG(vec)
   FOREACH(x,vec) printf("%d ", x->se);
}