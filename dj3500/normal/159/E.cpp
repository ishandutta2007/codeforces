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

vector<pii> coc[100007]; // cubes of color
ll sumsofar[100007];
struct comp { bool operator () (int i, int j) { return sumsofar[i] != sumsofar[j] ? sumsofar[i] > sumsofar[j] : i < j; } };
set<int,comp> st;
void add (int i, int ile) {
   st.erase(i);
   sumsofar[i] += ile;
   st.insert(i);
}

vi tyluelementowe[100007], conajmniejtyluelementowe[100007];

int main () {
   wez(n)
   vector<pii> input;
   map<int,int> kompresor;
   int k = 0;
   FOR(i,n) {
      wez2(a,b)
      kompresor[a] = ++k;
      input.pb(mp(a,b));
   }
   FOR(i,n) {
      input[i].fi = kompresor[input[i].fi];
      coc[input[i].fi].pb(mp(input[i].se, i+1));
   }
   
   FORI(i,k) {
      sort(ALL(coc[i]));
      reverse(ALL(coc[i]));
      sumsofar[i] = 0;
      if (!coc[i].empty()) {
         st.insert(i);
         tyluelementowe[SZ(coc[i])].pb(i);
         REP(j,1,SZ(coc[i])) conajmniejtyluelementowe[j].pb(i);
      }
   }
   
   // po jednym
   FOREACH(x,conajmniejtyluelementowe[1]) {
      add(*x, coc[*x][0].fi);
   }
   
   ll best = 0, besti, bestj;
   REP(p,2,100001) {
      FOREACH(x,conajmniejtyluelementowe[p]) {
         add(*x, coc[*x][p-1].fi);
      }
      FOREACH(x,tyluelementowe[p-1]) {
         int bestie = *st.begin();
         if (bestie == *x) {
            bestie = *(++st.begin());
         }
         ll cand = sumsofar[*x] + sumsofar[bestie];
         /*if (cand == 11) {
            DBG(*x)
            DBG(bestie)
            DBG(p)
         }*/
         if (cand > best) {
            best = cand;
            besti = *x;
            bestj = bestie;
         }
      }
      FOREACH(x,tyluelementowe[p-1]) st.erase(*x);
      if (SZ(st) <= 1) break;
   }
   printf("%I64d\n", best);
   if (SZ(coc[besti]) > SZ(coc[bestj])) {
      swap(besti,bestj);
   }
   if (SZ(coc[besti]) < SZ(coc[bestj])) {
      printf("%d\n", 2*SZ(coc[besti]) + 1);
      FOR(i, SZ(coc[besti])) {
         printf("%d %d ", coc[bestj][i].se, coc[besti][i].se);
      }
      printf("%d", coc[bestj][SZ(coc[besti])].se);
   } else { // ==
      printf("%d\n", 2*SZ(coc[besti]));
      FOR(i, SZ(coc[besti])) {
         printf("%d %d ", coc[bestj][i].se, coc[besti][i].se);
      }
   }
}