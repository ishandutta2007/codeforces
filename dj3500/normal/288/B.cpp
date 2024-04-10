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
#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

vector<int> adj[10];
bool seen[10];
int q[10];

const int mod = 1000000007;
int main () {
   wez2(n,k)
   int rest = n-k;
   ll res = k; // wybor dla 1
   FOR(u,rest) res = (res * rest) % mod; // wybor dla reszty
   int ukl = 0;
   int limit = 1 << (3 * (k-1));
   FOR(mask,limit) {
      int val[10];
      FOR(i,k-1) val[i+1] = (mask >> (3*i)) & 7;
      bool zle = 0;
      FORI(i,k-1) if (val[i] > k-1) zle = 1;
      if (zle) continue;
      REP(i,0,k-1) adj[i].clear();
      FORI(i,k-1) adj[val[i]].pb(i);
      memset(seen,0,sizeof(seen));
      int qs = 0, qe = 1;
      q[0] = 0;
      seen[0] = 1;
      while (qs < qe) {
         int v = q[qs++];
         FOREACH(it,adj[v]) if (!seen[*it]) {
            seen[*it] = 1;
            q[qe++] = *it;
         }
      }
      FORI(i,k-1) if (seen[i] == 0) zle = 1;
      if (zle) continue;
      ukl++;
   }
   res = (res * ukl) % mod;
   if (res < 0) res += mod;
   pisz(res);
}