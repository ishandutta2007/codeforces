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

// w drzewie nie moga pojawiac sie duplikaty; w takim wypadku insert:
// - przy OVERWRITE = 0: uywa +, tzn. np. gdy + to suma, to:
//   tr.insert(6,2); tr.insert(6,3); daje drzewo zawierajce <6,5>
// - przy OVERWRITE = 1: zastpuje, tzn. byoby drzewo zaw. <6,3>
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
         // x juz jest w drzewie - robimy update
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

// np. dla aaaa parzysty zwraca: 0 1 2 1, nieparzysty: 0 1 1 0
vector<int> manacher(string s, bool p) { // p = parzysty
   int n = SZ(s);
   vector<int> res(n);
   int l = 0, r = -1;
   FOR(i,n) {
   	int k;
   	if (i>r) k = 1;
   	else k = min(res[l+r-i+p], r-i+p) + 1;
   	while (i+k-p < n && i-k >= 0 && s[i+k-p] == s[i-k]) ++k;
   	res[i] = --k;
   	if (i+k-p > r) {
         l = i-k;
         r = i+k-p;
      }
   }
   return res;
}

char s[2048];
ll u[2048], ups[2048], ile1[2048], ile2[2048];

int main () {
   scanf("%s",s);
   int n = strlen(s);
   vi p = manacher(s,1), r = manacher(s,0);
   u[n-1] = 1;
   AugTreap<int,int> tr1, tr2;
   REPD(i,n-1,0) {
      tr1.insert(-(i-r[i]), 1);
      ile1[i] = tr1.sumgeq(-i);
      ile2[i] = tr2.sumgeq(-i);
      tr2.insert(-(i-p[i]), 1);
   }
   REPD(k,n-2,0) {
      u[k] = u[k+1];
      u[k] += ile1[k];
      u[k] += ile2[k];
   }
   ups[0] = u[0];
   REP(i,1,n-1) ups[i] = ups[i-1] + u[i];
   ups[n] = ups[n-1];
   ll res = 0;
   REP(x,0,n-1) {
      res += ups[x+r[x]+1] - ups[x];
      res += ups[x+p[x]] - ups[x];
   }
   cout << res << endl;
}