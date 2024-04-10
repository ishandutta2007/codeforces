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
using namespace std;
#define pb push_back
#define INF 2147483647
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define FORI(i,n) for(int (i)=1;(i)<=(n);++(i))
#define mp make_pair
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define sz size()
#define fi first
#define se second
#define wez(n) int (n); scanf("%d",&(n));
#define wez2(n,m) int (n),(m); scanf("%d %d",&(n),&(m));
#define wez3(n,m,k) int (n),(m),(k); scanf("%d %d %d",&(n),&(m),&(k));
inline void pisz(int n) { printf("%d\n",n); }
template<typename T,typename TT> ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &s,vector<T> t){FOR(i,t.size())s<<t[i]<<" ";return s; }
#define IN(x,y) ((y).find((x))!=(y).end()) 
#define DBG(vari) cout<<#vari<<" = "<<vari<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));

struct qq {
   ll a,b,c,d,e;
   int size;
   qq() {size=a=b=c=d=e=0;}
   qq(ll _a, ll _b, ll _c, ll _d, ll _e, int _size) :a(_a),b(_b),c(_c),d(_d),e(_e),size(_size){}
};

//ostream& operator<<(ostream &s,qq t) {return s<<"("<<t.a<<","<<t.b<<","<<t.c<<","<<t.d<<","<<t.e<<")";}

inline qq operator + (qq a1, qq a2) {
   int s = a1.size % 5;
   if (s==0) return qq(a1.a + a2.a, a1.b + a2.b, a1.c + a2.c, a1.d + a2.d, a1.e + a2.e, a1.size+a2.size);
   if (s==1) return qq(a1.a + a2.e, a1.b + a2.a, a1.c + a2.b, a1.d + a2.c, a1.e + a2.d, a1.size+a2.size);
   if (s==2) return qq(a1.a + a2.d, a1.b + a2.e, a1.c + a2.a, a1.d + a2.b, a1.e + a2.c, a1.size+a2.size);
   if (s==3) return qq(a1.a + a2.c, a1.b + a2.d, a1.c + a2.e, a1.d + a2.a, a1.e + a2.b, a1.size+a2.size);
   if (s==4) return qq(a1.a + a2.b, a1.b + a2.c, a1.c + a2.d, a1.d + a2.e, a1.e + a2.a, a1.size+a2.size);
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



int main () {
   AugTreap<int,qq> tr;
   ios_base::sync_with_stdio(0);
   int te;
   cin >> te;
   while (te--) {
      int x;
      string s;
      cin >> s;
      if (s == "add") {
         cin >> x;
         tr.insert(x,qq(x,0,0,0,0,1));
      }
      else if (s == "del") {
         cin >> x;
         //tr.remove(x);
         tr.insert(x,qq(0,0,0,0,0,0));
      }
      else cout << (tr.root ? tr.root->ag.c : 0) << "\n";
   }
}