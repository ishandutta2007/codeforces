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
#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (__typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define FOREACH(i,t) for (__typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

struct IntMin {
   int x;
   IntMin(int y = INF) : x(y) {}
   inline IntMin operator + (const IntMin &s) const { return IntMin(min(x,s.x)); }
};

int currentX;
bool enough (IntMin a) {
   return a.x <= currentX;
}

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
         // x juz jest w drzewie - robimy update
         //n->al = n->al + aug;
         n->al = aug; // OVERWRITE
         recalc(n);
      }
   }

   void insert (const T &x, const Aug &aug) {
      insert_aux(root, x, aug);
   }
   
   Aug get_aux (Node *n, const T &x) const {
      if (!n) return Aug();
      if (n->v < x) return get_aux(n->ri, x);
      if (n->v > x) return get_aux(n->le, x);
      return n->al;
   }
   
   Aug get (const T &x) const {
      return get_aux(root,x);
   }

// ****************************************
// BINARY SEARCHE
// ****************************************
   
   // glowna funkcja: minquery(s) ktora zwraca jak daleko trzeba pociagnac
   // przedzial [s,t] tak zeby zaczelo zachodzic enough(sumbetween(s,t))
   
   // nie trzeba przepisywac sumgeq/sumleq/sumbetween
   
   // wszystkie funkcje dzialaja w O(log n) ale dosc wolno
   
   // bool enough(const Aug &aug) to globalna funkcja
   // ktora ma spelniac enough(x) => enough(x+y)
   // (lub dla wersji rev: enough(x) => enough(y+x))
   // np. dla AugTreap<int,unsigned> moze byc enough(x) = (x >= 56)
   // np. dla AugTreap<int,IntMin> moze byc enough(a) = (a.x < 34)
   
      // wyjatek 0 jest rzucany gdy odpowiedz nie istnieje;
      // zamiast go rzucac/probowac lapac znacznie wygodniej i wydajniej
      // jest ustawic straznika na koncu tak zeby wyniki zawsze istnialy
      
      // oprocz tego mozna zaoszczedzic kilkanascie % wydajnosci
      // zamieniajac vector<Node*> na statyczna tablice w minquery

   // zwraca min t z poddrzewa n tze enough(sum + [sumleq(t) w tym poddrzewie])
   // precondition: takie t istnieje (inaczej RE)
   T minsubtreequery (Node *n, Aug sum) const {
      if (n->le) {
         Aug sum2 = sum + n->le->ag;
         if (enough(sum2)) {
            return minsubtreequery(n->le, sum);
         }
         sum = sum2;
      }
      sum = sum + n->al;
      if (enough(sum)) return n->v;
      return minsubtreequery(n->ri, sum);
   }

   // zwraca min t tze: t >= s, t nalezy do drzewa, enough(sumbetween(s,t))
   // jesli takie t nie istnieje to rzuca wyjatek None
   // s nie musi nalezec do drzewa
   
   T minquery (const T &s) const {
      vector<Node*> roots;
      Node *n = root;
      while (n) {
         if (n->v < s) {
            n = n->ri;
         } else if (n->v > s) {
            roots.pb(n);
            n = n->le;
         } else {
            roots.pb(n);
            break;
         }
      }
      // { wezel n + drzewo n->ri | n in roots } = { wezly w drzewie ktore sa >= s }
      
      Aug sum;
      REPD(i,SZ(roots)-1,0) {
         sum = sum + roots[i]->al;
         if (enough(sum)) {
            return roots[i]->v;
         }
         if (roots[i]->ri) {
            Aug sum2 = sum + roots[i]->ri->ag;
            if (enough(sum2)) {
               // zwroc min t z poddrzewa zaczepionego w roots[i]->ri
               // tze enough(sum + [sumleq(t) w tym poddrzewie])
               // (wiemy juz ze taki istnieje)
               return minsubtreequery(roots[i]->ri, sum);
            }
            sum = sum2;
         }
      }
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

#define N 200007
vector<pii> sets[N];
vector<pair<int,pii> > eventsAt[N]; // (0, query (od,do)) lub (1, ustaw k na x)
vector<pii> addAt[N], removeAt[N]; // poziome paski modulo

int main () {
   wez2(n,m)
   
   FORI(i,n) {
      wez(x)
      sets[i].pb(mp(i,x));
   }
   FORI(j,m) {
      wez(ty)
      if (ty == 3) {
         wez2(k,x)
         sets[k].pb(mp(n+j,x));
      } else if (ty == 1) {
         wez2(l,r)
         eventsAt[n+j].pb(mp(0,mp(l,r)));
      } else {
         wez3(l,r,x)
         addAt[l].pb(mp(n+j,x));
         removeAt[r+1].pb(mp(n+j,x));
      }
   }
   
   AugTreap<int,IntMin> paski; // czas, modulo
   paski.insert(INF, -1);
   FORI(i,n) {
      FOREACH(it,addAt[i]) paski.insert(it->fi, it->se);
      FOREACH(it,removeAt[i]) paski.insert(it->fi, INF);
      
      FOREACH(it,sets[i]) {
         int t = it->fi, x = it->se;
         int next_t = next(it) == sets[i].end() ? INF : next(it)->fi;
         eventsAt[t].pb(mp(1,mp(i,x)));
         while (1) {
            currentX = x;
            t = paski.minquery(t);
            if (t >= next_t) break;
            x = x % paski.get(t).x;
            eventsAt[t].pb(mp(1,mp(i,x)));
         }
      }
   }
   
   AugTreap<int,ll> sumator;
   REP(t,1,n+m) {
      //DBG(t)DBG(eventsAt[t])
      FOREACH(it,eventsAt[t]) {
         if (it->fi == 0) {
            // query
            printf("%lld\n", sumator.sumbetween(it->se.fi, it->se.se));
         } else {
            sumator.insert(it->se.fi, it->se.se);
         }



      }
   }
}