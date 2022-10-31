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
         //if (OVR) n->al = aug; // OVERWRITE
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
   
      // zwraca [najmniejsze y z drzewa tze y >= x] lub min, ktorekolwiek jest mniejsze (jesli nie ma takiego y, to tez zwraca min)
   T upper (const T &x, T min) {
      Node *n = root;
      while (n) {
         if (x < n->v) {
            if (n->v < min) min = n->v;
            n = n->le;
         } else if (x > n->v) {
            n = n->ri;
         } else return x;
      }
      return min;
   }

   // zwraca [najwieksze y z drzewa tze y <= x] lub max, ktorekolwiek jest wieksze (jesli nie ma takiego y, to tez zwraca max)
   T lower (const T &x, T max) {
      Node *n = root;
      while (n) {
         if (x > n->v) {
            if (n->v > max) max = n->v;
            n = n->ri;
         } else if (x < n->v) {
            n = n->le;
         } else return x;
      }
      return max;
   }

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
};

#define N 100007
int startsWaiting[N], wantedFloor[N], waitingFloor[N];
vi waitingAtFloor[N], wantingFloor[N];
ll res[N];
AugTreap<int,int> tr;

void add (int p, int x) {
   tr.insert(p,x);
}
void wywal(int p) {
   tr.remove(p);
}
int sum (int a, int b) {
   return tr.sumgeq(a) - tr.sumgeq(b+1);
}
int min_niezerowy_ponad (int p) {
   return tr.upper(p+1, INF);
}
int max_niezerowy_ponizej (int p) {
   return tr.lower(p-1, -INF);
}

int main () {
   wez2(n,m)
   FORI(i,n) scanf("%d %d %d", startsWaiting+i, waitingFloor+i, wantedFloor+i);
   
   vector<pii> startWaiting;
   FORI(i,n) startWaiting.pb(mp(startsWaiting[i], i));
   sort(ALL(startWaiting));
   int startWaitingPos = 0;
   
   ll t = 0;
   int nextDuration = 0;
   int floor = 1;
   int direction = 0;
   while(1) {
      t += nextDuration;
      floor += direction * nextDuration;
      
      while (startWaitingPos < SZ(startWaiting) && startWaiting[startWaitingPos].fi == t) {
         int i = startWaiting[startWaitingPos++].se;
         // dodaj i do listy oczekujacych
         waitingAtFloor[waitingFloor[i]].pb(i);
         add(waitingFloor[i], 1);
      }
      
      FOREACH(x, waitingAtFloor[floor]) {
         // dodaj *x do zawartosci windy
         wantingFloor[wantedFloor[*x]].pb(*x);
         add(wantedFloor[*x], 1);
      }
      waitingAtFloor[floor].clear();
      
      FOREACH(x, wantingFloor[floor]) {
         // wyrzuc *x z zawartosci windy
         res[*x] = t;
      }
      wantingFloor[floor].clear();
      
      wywal(floor);
      
      
      
      
      int p_up = sum(floor+1, m),
          p_down = sum(1, floor-1);
      if (p_up + p_down == 0) {
         direction = 0;
         nextDuration = INF;
      } else if (p_up >= p_down) {
         direction = 1;
         nextDuration = min_niezerowy_ponad(floor) - floor;
      } else {
         direction = -1;
         nextDuration = floor - max_niezerowy_ponizej(floor);
      }
      
      // koniec: gdy winda dojedzie do czegos niezerowego lub nowy sie zarejestruje
      if (startWaitingPos < SZ(startWaiting)) {
         ll maxDuration = startWaiting[startWaitingPos].fi - t;
         if (maxDuration < nextDuration) nextDuration = maxDuration;
      }
      
      if (nextDuration == INF) break;
   }
   
   FORI(i,n) printf("%I64d\n", res[i]);
}