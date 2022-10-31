#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
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

// w drzewie nie moga pojawiac sie duplikaty; w takim wypadku insert
// uywa +, tzn. np. gdy + to suma, to:
// tr.insert(6,2); tr.insert(6,3); daje drzewo zawierajce <6,5>
// mozna to zmienic na zastepowanie odkomentowujac przedostatnia linijke
// w insert_aux, tzn. wtedy byloby drzewo zaw. <6,3>

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

int g[10], x1[370000], x2[370000], y1[370000], y2[370000], ok[370000];
struct Q {
   int thr, query, yfrom, yto, res;
   bool operator < (const Q &q) const {
      return thr < q.thr;
   }
};
/* 0    1    2
        x1
   3 y1 4 y2 5
        x2   
   6    7    8 */
   
void go (vector<pii> &px, vector<Q> &xl, vector<Q> &xg) {
   sort(ALL(xl));
   sort(ALL(xg));
   int nowToAdd = 0;
   AugTreap<int,int> tr;
   FOREACH(q,xl) {
      while (nowToAdd < SZ(px) && px[nowToAdd].fi <= q->thr) {
         tr.insert(px[nowToAdd++].se, 1);
      }
      if (tr.sumbetween(q->yfrom, q->yto) == q->res) {
         ++ok[q->query];
      }
   }
   AugTreap<int,int> tr2;
   nowToAdd = SZ(px) - 1;
   reverse(ALL(xg));
   FOREACH(q,xg) {
      while (nowToAdd >= 0 && px[nowToAdd].fi >= q->thr) {
         tr2.insert(px[nowToAdd--].se, 1);
      }
      if (tr2.sumbetween(q->yfrom, q->yto) == q->res) {
         ++ok[q->query];
      }
   }
}
vector<Q> xl, xg, yl, yg;
   
int main () {
    wez(n)
    vector<pii> px, py;
    FOR(i,n) {
       wez2(xi,yi)
       px.pb(mp(2*xi,2*yi));
       py.pb(mp(2*yi,2*xi));
    }
    sort(ALL(px));
    sort(ALL(py));
    FOR(i,9) scanf("%d", g+i);
    vi perm;
    FOR(i,9) perm.pb(i);
    int k = 0;
    do {
       x1[k] = px[g[perm[0]] + g[perm[1]] + g[perm[2]]].fi - 1;
       x2[k] = px[g[perm[0]] + g[perm[1]] + g[perm[2]] + g[perm[3]] + g[perm[4]] + g[perm[5]]].fi - 1;
       y1[k] = py[g[perm[0]] + g[perm[3]] + g[perm[6]]].fi - 1;
       y2[k] = py[g[perm[0]] + g[perm[3]] + g[perm[6]] + g[perm[1]] + g[perm[4]] + g[perm[7]]].fi - 1;
       xl.pb((Q){x1[k],k,-2*INF,y1[k],g[perm[0]]});
       xl.pb((Q){x1[k],k,y1[k],y2[k],g[perm[1]]});
       xl.pb((Q){x1[k],k,y2[k],2*INF,g[perm[2]]});
       yl.pb((Q){y1[k],k,x1[k],x2[k],g[perm[3]]});
       yg.pb((Q){y2[k],k,x1[k],x2[k],g[perm[5]]});
       xg.pb((Q){x2[k],k,-2*INF,y1[k],g[perm[6]]});
       xg.pb((Q){x2[k],k,y1[k],y2[k],g[perm[7]]});
       xg.pb((Q){x2[k],k,y2[k],2*INF,g[perm[8]]});
       k++;
    } while(next_permutation(ALL(perm)));
    go(px,xl,xg);
    go(py,yl,yg);
    FOR(i,k) {
       if (ok[i] == 8) {
          printf("%.1lf %.1lf\n%.1lf %.1lf", x1[i]/2.0, x2[i]/2.0, y1[i]/2.0, y2[i]/2.0);
          return 0;
       }
    }
    pisz(-1);
}