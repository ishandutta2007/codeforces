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
template<typename T> ostream& operator<<(ostream &s,vector<T> t){FOR(i,t.size())s<<t[i]<<" ";return s; }
#define IN(x,y) ((y).find((x))!=(y).end())
#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));

const int modul = 1000000007;


template <typename T, typename Aug>
struct AugTreap {

   // ZMIENIC TO W RAZIE POTRZEBY!
   inline static Aug plus (Aug a1, Aug a2) { // dziaanie w pgrupie Aug
      return (a1+a2)%modul;
   }
   static const Aug identity = 0;


   struct Node {
      T val;
      int priority;
      Node *left, *right;
      Aug aug_local, aug_global; // aug dla samego wierzchoka i dla caego poddrzewa
   };

   Node *root;
   AugTreap () : root(NULL) {}

   inline static Aug get_aug_global(Node* &n) {
      if (n==NULL) return identity;
      return n->aug_global;
   }

   inline static void recalc_aug(Node* &n) {
      n->aug_global = plus(plus(get_aug_global(n->left), n->aug_local), get_aug_global(n->right));
   }

   inline void rotate_left(Node* &n) { // wycignij lewe dziecko n do gry
      Node *syn = n->left;
      n->left = syn->right;
      syn->right = n;
      n = syn;

      recalc_aug(n->right);
      recalc_aug(n);
   }

   inline void rotate_right(Node* &n) { // wycignij prawe dziecko n do gry
      Node *syn = n->right;
      n->right = syn->left;
      syn->left = n;
      n = syn;

      recalc_aug(n->left);
      recalc_aug(n);
   }

   void insert_aux(Node* &n, T x, Aug aug) {
      if (n == NULL) {
         n = new Node;
         n->val = x;
         n->priority = rand();
         n->left = n->right = NULL;
         n->aug_local = n->aug_global = aug;
      } else if (x < n->val) {
         insert_aux(n->left, x, aug);
         if (n->priority > n->left->priority) rotate_left(n);
         else recalc_aug(n);
      } else if (x > n->val) {
         insert_aux(n->right, x, aug);
         if (n->priority > n->right->priority) rotate_right(n);
         else recalc_aug(n);
      } else {
         // x juz jest w drzewie - robimy update
         n->aug_local = aug;
         recalc_aug(n);
      }
   }

   void insert (T x, Aug aug) {
      insert_aux(root, x, aug);
   }

   bool remove (T x) {
      return remove_aux(root,x);
   }

   bool remove_aux (Node* &n, T x) {
      if (n == NULL) return false;
      if (x < n->val) {
         bool wyn = remove_aux(n->left, x);
         if (wyn) recalc_aug(n);
         return wyn;
      }
      if (x > n->val) {
         bool wyn = remove_aux(n->right, x);
         if (wyn) recalc_aug(n);
         return wyn;
      }
      // mamy go!
      remove_node(n);
      return true;
   }

   void remove_node (Node* &n) {
      if (n->left == NULL) {
         Node *dziecko = n->right;
         delete n;
         n = dziecko;
         return;
      }
      if (n->right == NULL) {
         Node *dziecko = n->left;
         delete n;
         n = dziecko;
         return;
      }
      // n ma dwoje dzieci - trzeba rotowac
      if (n->left->priority < n->right->priority) {
         rotate_left(n);
         remove_node(n->right);
         recalc_aug(n);
      } else {
         rotate_right(n);
         remove_node(n->left);
         recalc_aug(n);
      }
   }

   Aug sum_of_augs_over_all_xs_geq_than_x (T x) {
      return sum_of_augs_over_all_xs_geq_than_x_aux(x,root);
   }

   Aug sum_of_augs_over_all_xs_geq_than_x_aux (T x, Node *n) {
      if (n==NULL) return identity;
      if (x > n->val) return sum_of_augs_over_all_xs_geq_than_x_aux(x, n->right);
      if (x < n->val) return plus(plus(sum_of_augs_over_all_xs_geq_than_x_aux(x, n->left), n->aug_local), get_aug_global(n->right));
      // x == n->val
      return plus(n->aug_local, get_aug_global(n->right));
   }
};

int main () {
   wez2(n,m)

   map<int,vi> mapa;
   FOR(i,m) {
      wez2(si,ti)
      if (!IN(ti,mapa)) mapa.insert(mp(ti,vi()));
      mapa[ti].pb(si);
   }

   AugTreap<int,int> tr;
   tr.insert(0,1);

   FOREACH(it,mapa) {
      int ti = it->fi;
      int sposobow = 0;
      FOR(j,SZ(it->se)) {
         int sj = it->se[j];
         sposobow += tr.sum_of_augs_over_all_xs_geq_than_x(sj);
         sposobow %= modul;
      }
      tr.insert(ti,sposobow);
   }
   pisz(tr.sum_of_augs_over_all_xs_geq_than_x(n));
}