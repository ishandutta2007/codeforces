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
#define DBG(vari)
//cerr<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));

bool lucky (int x) {
   while (x) {
      if (x%10 != 4 && x%10 != 7) return false;
      x /= 10;
   }
   return true;
}

#define N 100006
int pos[N], ciag[N], wartosc[N];

int main () {
   wez(n)
   vector<pii> v;
   bool mamy = 0, nondec = 1;
   int poprz = -1, kuniq, uniq = 0;
   FORI(i,n) {
      wez(x)
      if (poprz > x) nondec = 0;
      poprz = x;

      if (!mamy && lucky(x)) {
         mamy = 1;
         kuniq = uniq;
      }
      v.pb(mp(x,uniq));
      pos[uniq] = i;
      ciag[i] = uniq;
      wartosc[uniq] = x;
      uniq++;
   }
   if (!mamy && !nondec) {
      printf("-1\n");
      return 0;
   }

   vector<pii> wyn;
   sort(ALL(v));

#define swapnij(_pos1,_pos2) { if (_pos1 != _pos2) { int pos1 = _pos1, pos2 = _pos2, uniq1 = ciag[pos1], uniq2 = ciag[pos2]; pos[uniq1] = pos2; pos[uniq2] = pos1; ciag[pos1] = uniq2; ciag[pos2] = uniq1; wyn.pb(mp(pos1,pos2)); DBG(mp(pos1,pos2)) } }

   REPD(it,SZ(v)-1,0) {
      int mabyc_pos_w = it+1;
      int uniq_w = v[it].se;
      int obecna_pos_w = pos[uniq_w];

      if (uniq_w == kuniq) continue;

      if (obecna_pos_w == mabyc_pos_w) continue;
      swapnij(pos[kuniq], mabyc_pos_w);
      /*
      // DBG!
      printf("dbg: ");
      FORI(i,n) printf("%d ",wartosc[ciag[i]]);
      printf("\n");*/
      swapnij(obecna_pos_w, mabyc_pos_w);
      /*
      // DBG!
      printf("dbg: ");
      FORI(i,n) printf("%d ",wartosc[ciag[i]]);
      printf("\n");*/
   }

   pisz(SZ(wyn));
   FOR(uj,SZ(wyn)) printf("%d %d\n",wyn[uj].fi, wyn[uj].se);
}