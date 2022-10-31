#define SYF freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
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

// zwraca LICZBE KRAWEDZI na najdluzszej sciezce w drzewie
// n = najwiekszy numer wierzcholka, root = jakikolwiek wierzcholek z drzewa
int longest_path_in_tree(vector<int> *adj, int n, int root) {
   int longestpath = 0;
   vector<int> depth(n+3,0);

   stack<pii> s;
   s.push(mp(root,-1));
   while (!s.empty()) {
      int v = s.top().fi, skad = s.top().se;
      s.pop();

      if (v < 0) {
         v=-v;
         // zbierz info od dzieci
         int maxst=0,drugimaxst=0;
         FOR(i,SZ(adj[v])) if (adj[v][i] != skad) {
            if (depth[adj[v][i]]+1 > maxst) {
               drugimaxst = maxst;
               maxst = depth[adj[v][i]]+1;
            } else if (depth[adj[v][i]]+1 > drugimaxst) {
               drugimaxst = depth[adj[v][i]]+1;
            }
         }
         depth[v] = maxst;
         longestpath = max(longestpath, maxst+drugimaxst);
      } else {
         s.push(mp(-v,skad));
         FOR(i,SZ(adj[v])) {
            if (adj[v][i] != skad) {
               s.push(mp(adj[v][i],v));
            }
         }
      }
   }
   return longestpath;
}


int main () {
   SYF
   int res = 0;
   TESTS {
      wez(n)
      vi adj[103];
      FOR(i,n-1) {
         wez2(a,b)
         adj[a].pb(b);
         adj[b].pb(a);
      }
      res += longest_path_in_tree(adj,n,1);
   }
   pisz(res);
}