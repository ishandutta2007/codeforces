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
#define INF 2010000000
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

int *macroCompArray;
inline bool macrocomp (int i, int j) { return macroCompArray[i] < macroCompArray[j]; }
#define SORT(a,b,r) { macroCompArray = r; sort(a,b,macrocomp); }
#define SORTV(v,r) SORT(v.begin(),v.end(),r)

int OVERWRITE = 0;

template <typename T, typename Aug>
struct AugTreap {
   struct Node {
      T v; // wartosc
      int pr; // priorytet
      Node *le, *ri;
      Aug al, ag; // aug dla samego wierzcholka i dla calego poddrzewa
   };

   Node *root;
   AugTreap() : root(0) {}

   inline static void recalc(Node* &n) { // oblicza nowe ag dla n
      Aug left = n->le ? n->le->ag + n->al : n->al;
      n->ag = n->ri ? left + n->ri->ag : left;
   }

   inline void rotle(Node* &n) { // wyciagnij lewe dziecko n do gory
      Node *syn = n->le;
      n->le = syn->ri;
      syn->ri = n;
      n = syn;

      recalc(n->ri);
      recalc(n);
   }

   inline void rotri(Node* &n) { // wyciagnij prawe dziecko n do gory
      Node *syn = n->ri;
      n->ri = syn->le;
      syn->le = n;
      n = syn;

      recalc(n->le);
      recalc(n);
   }

   void insert_aux(Node* &n, const T &x, const Aug &aug) {
      if (!n) {
         n = new Node;
         n->v = x;
         n->pr = rand();
         n->le = n->ri = 0;
         n->al = n->ag = aug;
      } else if (x < n->v) {
         insert_aux(n->le, x, aug);
         if (n->pr > n->le->pr) rotle(n);
         else recalc(n);
      } else if (x > n->v) {
         insert_aux(n->ri, x, aug);
         if (n->pr > n->ri->pr) rotri(n);
         else recalc(n);
      } else {
         // x juz jest w drzewie - robimy update przez +
         n->al = OVERWRITE ? aug : n->al + aug;
         recalc(n);
      }
   }

   void insert (const T &x, const Aug &aug) {
      insert_aux(root, x, aug);
   }
   
   Aug sumgeq_aux (const T &x, Node *n) {
      if (!n) return Aug();
      if (x > n->v) return sumgeq_aux(x, n->ri);
      if (x < n->v) {
         Aug left = sumgeq_aux(x, n->le) + n->al;
         return n->ri ? left + n->ri->ag : left;
      }
      // x == n->v
      return n->ri ? n->al + n->ri->ag : n->al;
   }

   // suma Augw po wszystkich kluczach >= x
   Aug sumgeq (const T &x) {
      return sumgeq_aux(x,root);
   }

// ****************************************
// OPCJONALNE: SUMY W PGRUPIE
// (jeli Aug to grupa, to zamiast sumbetween(L,R) mona robi sumgeq(L) - sumgeq(R+1))
// ****************************************

   Aug sumleq_aux (const T &x, Node *n) {
      if (!n) return Aug();
      if (x < n->v) return sumleq_aux(x, n->le);
      if (x > n->v) {
         Aug right = n->al + sumleq_aux(x, n->ri);
         return n->le ? n->le->ag + right : right;
      }
      // x == n->v
      return n->le ? n->le->ag + n->al : n->al;
   }
   
   // suma Augw po wszystkich kluczach <= x
   Aug sumleq (const T &x) {
      return sumleq_aux(x,root);
   }
   
   Aug sumbetween_aux (const T &x, const T &y, Node *n) {
      if (!n) return Aug();
      if (y < n->v) return sumbetween_aux(x,y,n->le);
      if (x > n->v) return sumbetween_aux(x,y,n->ri);
      // x <= n->v <= y
      return sumgeq_aux(x,n->le) + n->al + sumleq_aux(y,n->ri);
   }
   
   // suma Augw po wszystkich kluczach z [x,y]
   Aug sumbetween (const T &x, const T &y) {
      return sumbetween_aux(x,y,root);
   }
};

// Aug musi byc polgrupa (laczna) z zerem
// zero to wynik konstruktora bez parametrow
// dzialanie to operator +
// (uwaga: np. int() = 0, wiec mozna robic AugTreap<T,int>)
struct IntMax {
   int x;
   IntMax(int y = -INF) : x(y) {}
   inline IntMax operator + (const IntMax &s) const { return IntMax(max(x,s.x)); }
};


#define N 100007
int r[N], a[N], sz[N], aU[N], aL[N], rL[N], res[N];

int main () {
   wez2(n,k)
   FORI(i,n) scanf("%d",r+i);
   FORI(i,n) scanf("%d",a+i);
   vi temp;
   FORI(i,n) temp.pb(i);
   SORTV(temp,r);
   AugTreap<int,int> tr;
   for (int i = 0; i < n; ) {
      int start = i;
      while (i < n && r[temp[i]] == r[temp[start]]) {
         tr.insert(a[temp[i]], 1);
         i++;
      }
      for (int s = start; s < i; ++s) {
         sz[temp[s]] = tr.sumbetween(a[temp[s]]-k, a[temp[s]]+k);
      }
   }
   
   wez(queries)
   FOR(q,queries) {
      wez2(x,y)
      aU[q] = min(a[x],a[y]) + k;
      aL[q] = max(a[x],a[y]) - k;
      rL[q] = max(r[x],r[y]);
   }
   
   vi temp2;
   FOR(q,queries) temp2.pb(q);
   SORTV(temp2,rL);
   reverse(ALL(temp2));
   reverse(ALL(temp));
   
   int nowToAdd = 0;
   AugTreap<int,IntMax> tr2;
   FOR(kkk,queries) {
      int q = temp2[kkk];
      while (nowToAdd < n && r[temp[nowToAdd]] >= rL[q]) {
         tr2.insert(a[temp[nowToAdd]], sz[temp[nowToAdd]]);
         ++nowToAdd;
      }
      res[q] = tr2.sumbetween(aL[q], aU[q]).x;
   }
   FOR(q,queries) pisz(res[q] == -INF ? -1 : res[q]);
}