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
#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

#define N 2048
#define NN (N*N)
char s[N][N];
int par[NN], seen[NN];

void dfs (int v) {
   if (v == -1) return;
   if (seen[v] == 2) return;
   if (seen[v] == 1) throw 1;
   seen[v] = 1;
   dfs(par[v]);
   seen[v] = 2;
}

int res;
int depth[NN], deg[NN], times[NN];

int main () {
   wez2(n,m)
   FOR(i,n) scanf("%s", s[i]);
   FOR(i,n) FOR(j,m) {
      if (s[i][j] != '#') {
         if (s[i][j] == '^') par[i*m + j] = (i-1)*m + j;
         if (s[i][j] == 'v') par[i*m + j] = (i+1)*m + j;
         if (s[i][j] == '<') par[i*m + j] = i*m + j - 1;
         if (s[i][j] == '>') par[i*m + j] = i*m + j + 1;
         deg[par[i*m+j]]++;
      } else {
         par[i*m+j] = -1;
      }
   }
   try {
      FOR(v,n*m) if (!seen[v]) dfs(v);
   } catch (int syf) {
      pisz(-1);
      return 0;
   }
   
   vi deg0;
   FOR(v,n*m) if (deg[v] == 0) deg0.pb(v);
   while (!deg0.empty()) {
      int v = deg0.back();
      deg0.pop_back();
      if (par[v] != -1) {
         if (depth[par[v]] < 1 + depth[v]) {
            depth[par[v]] = 1 + depth[v];
            times[par[v]] = 1;
         } else if (depth[par[v]] == 1 + depth[v]) {
            times[par[v]]++;
         }
         if (--deg[par[v]] == 0) deg0.pb(par[v]);
      }
   }
   
   res = 0;
   multiset<int> depths;
   FOR(v,n*m) if (par[v] == -1) {
      int d = depth[v];
      if (times[v] >= 2) REMAX(res, 2*d)
      else REMAX(res, 2*d - 1);
      depths.insert(d);
      if (SZ(depths) > 2) depths.erase(depths.begin());
   }
   if (SZ(depths) > 1) {
      REMAX(res, *depths.begin() + *++depths.begin());
   }
   pisz(res);
}