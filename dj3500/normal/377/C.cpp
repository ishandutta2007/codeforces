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
#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

#define N 102
int m;
int a[N], act[N], who[N];
int cache[1 << 20];

// wynik gracza 1
int go (int mask, int now) {
   //assert(__builtin_popcount(mask) == m - now);
   if (cache[mask] != INF) return cache[mask];
   if (now == m) return 0;
   if (who[now] == 1) {
      int ma = -INF;
      FOR(i,m) if ((1<<i) & mask) {
         REMAX(ma, act[now] * a[i] + go(mask ^ (1<<i), now + 1));
      }
      return cache[mask] = ma;
   } else {
      int mi = INF;
      FOR(i,m) if ((1<<i) & mask) {
         REMIN(mi, -act[now] * a[i] + go(mask ^ (1<<i), now + 1));
      }
      return cache[mask] = mi;
   }
}

int main () {
   wez(ss)
   vi v;
   FOR(i,ss) {
      wez(x)
      v.pb(x);
   }
   sort(ALL(v));
   reverse(ALL(v));
   scanf("%d", &m);
   FOR(i,m) a[i] = v[i];
   FOR(i,m) {
      char cc;
      scanf(" %c %d", &cc, who+i);
      if (cc == 'b') act[i] = 0;
      else act[i] = 1; // pick
   }
   FOR(i,1<<m) cache[i] = INF;
   pisz(go((1 << m) - 1, 0));
}