#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cassert>
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

#define N 200007
vi adj[N];
int ofd[N];

void dfs (int v, int p, int d) {
   ofd[d]++;
   FOREACH(x,adj[v]) if (*x != p) {
      dfs(*x,v,d+1);
   }
}

int main () {
   wez3(m,k,p)
   k = min(k, m-1);
   
   FOR(i,m-1) {
      wez2(a,b)
      adj[a].pb(b);
      adj[b].pb(a);
   }
   dfs(1,-1,0);
   int best = 0;
   
   vi v;
   int maxd = 0;
   REP(d,1,N-1) if (ofd[d]) maxd = d;
   REPD(d,N-1,1) {
      while (ofd[d]--) v.pb(d);
   }
   assert(SZ(v) == m-1);
   
   int from = 0, to = -1; // [from, to]
   REPD(d,maxd,1) {
      while (v[from] != d) {
         ++from;
      }
      // to >= from - 1
      p += to - from + 1;
      while (to+1 < m-1 && d - v[to+1] <= p) {
         p -= d - v[to+1];
         ++to;
      }
      REMAX(best, to - from + 1);
   }
   
   pisz(min(best,k));
}