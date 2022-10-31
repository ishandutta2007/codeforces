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
#define DBG(vari) cout<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (auto i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

typedef pair<int,ll> pil;
pil operator + (const pil &a, const pil &b) { return mp(a.fi + b.fi, a.se + b.se); }

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
         n->al = n->al + aug;
         // n->al = aug; // OVERWRITE
         recalc(n);
      }
   }

   void insert (const T &x, const Aug &aug) {
      //DBG(x)DBG(aug)
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

// ****************************************
// OPCJONALNE: USUWANIE
// (zamiast usuwac mozna ustawiac Aug na zero)
// ****************************************

   bool remove (const T &x) {
      return remove_aux(root,x);
   }

   bool remove_aux (Node* &n, const T &x) {
      if (!n) return 0;
      if (x < n->v) {
         bool wyn = remove_aux(n->le, x);
         if (wyn) recalc(n);
         return wyn;
      }
      if (x > n->v) {
         bool wyn = remove_aux(n->ri, x);
         if (wyn) recalc(n);
         return wyn;
      }
      // mamy go!
      remove_node(n);
      return 1;
   }

   void remove_node (Node* &n) {
      if (!n->le) {
         Node *syn = n->ri;
         delete n;
         n = syn;
      } else if (!n->ri) {
         Node *syn = n->le;
         delete n;
         n = syn;
      } else
      // n ma dwoje dzieci - trzeba rotowac
      if (n->le->pr < n->ri->pr) {
         rotle(n);
         remove_node(n->ri);
         recalc(n);
      } else {
         rotri(n);
         remove_node(n->le);
         recalc(n);
      }
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

   // zwraca min t z poddrzewa n tze enough(sum + [sumleq(t) w tym poddrzewie])
   // precondition: takie t istnieje (inaczej RE)
   /*T minsubtreequery (Node *n, Aug sum) const {
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
   // jesli takie t nie istnieje to rzuca wyjatek 0
   // s nie musi nalezec do drzewa
   T minquery (const T &s) const {
      static vector<Node*> roots;
      roots.clear();
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
      throw 0;
   }*/

   ll find_kth_sum (int k, Node *n) {
      if (k == 0) return 0;
      if (!n->le) {
         if (k <= n->al.fi) return n->al.se / n->al.fi * k;
         else return n->al.se + find_kth_sum(k - n->al.fi, n->ri);
      } else {
         if (k <= n->le->ag.fi) return find_kth_sum(k, n->le);
         else if (k <= n->le->ag.fi + n->al.fi) return n->le->ag.se + n->al.se / n->al.fi * (k - n->le->ag.fi);
         else return n->le->ag.se + n->al.se + find_kth_sum(k - n->le->ag.fi - n->al.fi, n->ri);
      }
   }

   ll find_kth_sum (int k) {
      return find_kth_sum(k, root);
   }
};




#define a first.second
#define b first.first
#define N 1000007
char ans[N];
int newindex[N];

int main () {
   wez2(n,w)
   vector<pair<pii,int>> v;
   FOR(i,n) {
      wez2(aa,bb)
      v.pb(mp(mp(bb,aa),i));
   }
   sort(ALL(v));
   AugTreap<int,pair<int,ll> > tr;
   int niskich = 0;
   ll sumniskich = 0;
   FOREACH(it,v) {
      tr.insert(it->a, mp(1, it->a));
   }
   pair<ll,int> res(1001001001001001001LL,-1);
   if (w <= n) {
      //DBG(tr.find_kth_sum(w))
      REMIN(res, mp(tr.find_kth_sum(w),0));
   }
   //DBG("nic")
   FOREACH(it,v) {
      //DBG(*it)
      newindex[it->se] = niskich;
      niskich++;
      sumniskich += it->a;
      tr.insert(it->a, mp(-1, -it->a));
      tr.insert(it->b - it->a, mp(1, it->b - it->a));
      if (w <= n + niskich && w >= niskich) REMIN(res, mp(sumniskich + tr.find_kth_sum(w - niskich), niskich));
   }
   //DBG("nic")

   printf("%lld\n", res.fi);
   vector<pii> opcje;
   FOR(i,res.se) {
      ans[i] = '1';
      opcje.pb(mp(v[i].b - v[i].a, i));
   }
   REP(i,res.se,n-1) {
      ans[i] = '0';
      opcje.pb(mp(v[i].a, i));
   }
   sort(ALL(opcje));
   //DBG(w - res.se)
   //DBG(opcje)
   FOR(u,w - res.se) {
      ans[opcje[u].se]++;
   }
   FOR(i,n) printf("%c", ans[newindex[i]]);
}