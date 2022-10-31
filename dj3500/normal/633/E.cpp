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

const int LOGN = 20, N = 1<<LOGN;
int rm[LOGN][N]; // rm[k][i] = min(tab[i], ..., tab[i + 2^k - 1])
void init (int *tab, int n) { // tab[0..n-1]
   FOR(i,n) rm[0][i] = tab[i];
   REP(k,1,LOGN-1) REP(i,0,n-(1<<k)) rm[k][i] = min(rm[k-1][i], rm[k-1][i+(1<<(k-1))]);
}
int query (int a, int b) { // a <= b bo inaczej segfault
   if (a > b) { DBG(a); DBG(b); exit(1); }
   int k = 31 - __builtin_clz(b-a+1);
   return min(rm[k][a], rm[k][b-(1<<k)+1]);
}

int vis[N], rev[N], q[N], k, n;
typedef long double real;
real prb[N];

real prob (int x) {
   if (x < k) return 0;
   return prb[x];
}

int main () {
   scanf("%d %d", &n, &k);
   FOR(i,n) scanf("%d", vis + i);
   FOR(i,n) vis[i] *= 100;
   FOR(i,n) scanf("%d", rev + i);
   init(rev, n);
   vector<pii> deq = {{INF,INF}};
   REPD(l,n-1,0) {
      while (deq.back().fi <= vis[l]) deq.pop_back();
      deq.push_back({vis[l], l});
      q[l] = 0;
      int from = 1, to = 10000000;
      while (from <= to) {
         int x = (from + to) / 2;
         int id = lower_bound(deq.rbegin(), deq.rend(), pii(x, -1))->se;
         if (id == INF || query(l, id) < x) {
            to = x-1;
         } else {
            from = x+1;
            q[l] = x;
         }
      }
      //DBG(l) DBG(q[l])
   }
   
   prb[n] = 1.0L;
   REPD(x,n,k+1) prb[x-1] = prb[x] * (x-k) / x;
   
   map<int,int,greater<int> > v;
   FOR(l,n) v[q[l]]++;
   real res = 0;
   int seen = 0;
   for (auto it : v) {
      res += it.fi * (prob(seen + it.se) - prob(seen));
      seen += it.se;
   }
   cout << setprecision(13) << fixed << double(res);
}