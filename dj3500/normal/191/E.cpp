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

};

#define N 100007
ll a[N], prefsum[N];

int main () {
   ll n,k;
   cin >> n >> k;
   FORI(i,n) cin >> a[i];
   ll pos = 0, neg = 0;
   FORI(i,n) if (a[i] > 0) pos += a[i]; else neg += a[i];
   prefsum[0] = 0;
   FORI(i,n) prefsum[i] = prefsum[i-1] + a[i];
   ll best = neg;
   ll from = best+1, to = pos;
   while (from <= to) {
      ll x = (from + to) / 2;
      
      ll dobrychsum = 0, zab = 0;
      AugTreap<ll,int> tr;
      FORI(i,n) tr.insert(prefsum[i],1);
      FORI(st,n) {
         dobrychsum += tr.sumgeq(x+zab);
         
         // !
         //if (dobrychsum >= k) break;
         // !
         
         zab += a[st];
         tr.insert(zab,-1);
      }
      
      if (dobrychsum >= k) {
         best = x;
         from = x+1;
      } else {
         to = x-1;
      }
   }
   cout << best;
}