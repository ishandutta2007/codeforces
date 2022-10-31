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
#define FOREACH(i,t) for (__typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

const int all = (1 << 30) - 1;
struct MinTree {
   int* el, s;
   MinTree (int h) { // dziedzina elementow to [0..2^h-1]
      el = new int[2*(s = 1<<h)]; FOR(x,2*s) el[x] = all;
   }
   void Set (int p, int v) { // uwaga: moe overwritowa mniejsz warto
      for (p += s, el[p] = v, p /= 2; p > 0; p /= 2) el[p] = el[2*p] & el[2*p+1];
   }
   int Find (int p, int k) { // wyznacz min na [p,k]
      int m = all; p += s; k += s;
      while (p < k) {
         if (p&1)    {
            m = m & el[p];
            ++p;
         }
         if (!(k&1)) {
            m = m & el[k];
            --k;
         }
         p /= 2; k /= 2;
      }
      if (p == k) m &= el[p];
      return m;
   }
};

#define N 100007
vi addAt[N], delAt[N];
int l[N], r[N], q[N], val[N];

int main () {
   wez2(n,m)
   FOR(i,m) scanf("%d %d %d", l+i, r+i, q+i);
   FOR(j,m) {
      addAt[l[j]].pb(q[j]);
      delAt[r[j]+1].pb(q[j]);
   }
   vi cnt(32,0);
   FORI(i,n) {
      FOREACH(it,addAt[i]) {
         FOR(b,30) if ((*it) & (1<<b)) ++cnt[b];
      }
      FOREACH(it,delAt[i]) {
         FOR(b,30) if ((*it) & (1<<b)) --cnt[b];
      }
      FOR(b,30) if (cnt[b]) val[i] += 1<<b;
   }
   MinTree tr(17);
   FORI(i,n) tr.Set(i, val[i]);
   FOR(j,m) if (tr.Find(l[j],r[j]) != q[j]) { printf("NO"); return 0; }
   printf("YES\n");
   FORI(i,n) printf("%d ",val[i]);
}