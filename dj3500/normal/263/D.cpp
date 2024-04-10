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
int wej[MAXN], wyj[MAXN], ojc[MAXN], t, curdepth[MAXN], k;
int lastvertex; vi cycle;

void dfsgo(int v, vi *adj, int depth = 0) {
   //DBG(v)
   try {
   wej[v] = ++t;
   curdepth[v] = depth;
   FOREACH(it,adj[v]) {
      if (wej[*it] == -1) {
         ojc[*it] = v;
         dfsgo(*it,adj,depth+1);
      } else if (wyj[*it] == -1) {
         if (depth - curdepth[*it] >= k) {
            lastvertex = *it;
            //cycle.pb(v);
            throw false;
         }
      }
   }
   wyj[v] = ++t;
   } catch (bool exc) {
      cycle.pb(v);
      if (v != lastvertex) {
         throw false;
      } else {
         pisz(SZ(cycle));
         FOREACH(x,cycle) printf("%d ", *x);
         exit(0);
      }
   }
}
void dfs(int n, vi *adj, int source = -1) {
   t = -1;
   FORI(i,n) wej[i] = wyj[i] = ojc[i] = -1;
   if (source == -1) {
      FORI(i,n) if (ojc[i] == -1) dfsgo(i,adj);
   } else dfsgo(source,adj);
}

vi adj[MAXN];

int main () {
   wez2(n,m)
   scanf("%d", &k);
   while(m--) {
      wez2(a,b)
      adj[a].pb(b);
      adj[b].pb(a);
   }
   dfs(n,adj,1);
}