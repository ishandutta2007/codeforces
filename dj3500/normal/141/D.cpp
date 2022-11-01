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
#define ll long long
#define pii pair<ll,int>
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

   // ZMIENIC TO W RAZIE POTRZEBY!
   inline Aug plus (Aug a1, Aug a2) { // dzialanie w polgrupie Aug
      return max(a1,a2);
   }
   Aug identity;


   struct Node {
      T val;
      int prio;
      Node *left, *right;
      Aug aug_local, aug_global; // aug dla samego wierzcholka i dla calego poddrzewa
   };

   Node *root;
   AugTreap () : root(NULL) {
      identity = mp(-INF,-INF);
   }

   inline Aug get_aug_global(Node* &n) {
      if (n==NULL) return identity;
      return n->aug_global;
   }

   inline void recalc_aug(Node* &n) {
      n->aug_global = plus(plus(get_aug_global(n->left), n->aug_local), get_aug_global(n->right));
   }

   inline void rotate_left(Node* &n) { // wyciagnij lewe dziecko n do gory
      Node *syn = n->left;
      n->left = syn->right;
      syn->right = n;
      n = syn;

      recalc_aug(n->right);
      recalc_aug(n);
   }

   inline void rotate_right(Node* &n) { // wyciagnij prawe dziecko n do gory
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
         n->prio = rand();
         n->left = n->right = NULL;
         n->aug_local = n->aug_global = aug;
      } else if (x < n->val) {
         insert_aux(n->left, x, aug);
         if (n->prio > n->left->prio) rotate_left(n);
         else recalc_aug(n);
      } else if (x > n->val) {
         insert_aux(n->right, x, aug);
         if (n->prio > n->right->prio) rotate_right(n);
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
      if (n == NULL) return 0;
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
      return 1;
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
      if (n->left->prio < n->right->prio) {
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


#define N 100006
int x[N],t[N],d[N],p[N];
int doWhat[N]; // co robic po skoku z i
bool bad[N];

int main () {
   wez2(n,L)
   FOR(i,n) scanf("%d %d %d %d",x+i,d+i,t+i,p+i);
   FOR(i,n) bad[i] = (p[i] > x[i]) || (t[i] >= d[i]);
   
   vector<pii> srt;
   FOR(i,n) if (!bad[i]) srt.pb(mp(-(x[i]-p[i]),i));
   sort(ALL(srt));
   
   AugTreap<int,pii> tr,tr2;
   tr.insert(L,mp(0,-2));
   //wstaw do struktury1 (0,-2) z pos = L

   FOR(j,SZ(srt)) {
      int i = srt[j].se, posB = x[i]-p[i], posBp = x[i]+d[i], gainB = d[i]-t[i];
      //DBG(i)
      /*DBG(i)
      DBG(posB)
      DBG(posBp)
      DBG(gainB)*/
      
      // robie skok
      //pii maxZeStr = (maksymalny (val,k) po pos >= posBp)
      pii maxZeStr = tr.sum_of_augs_over_all_xs_geq_than_x(posBp);
      //DBG(maxZeStr)
      ll maxx = gainB + maxZeStr.fi;
      doWhat[i] = maxZeStr.se; // skacz potem z k
      
      //pii maxZeStr2 = (maksymalny (pos+val,k) po pos < posBp), lub gdy brak: -INF
      pii maxZeStr2 = tr2.sum_of_augs_over_all_xs_geq_than_x(-posBp+1);
      //DBG(maxZeStr2)
      ll maxx2 = gainB - 2*posBp + maxZeStr2.fi;
      /*DBG(gainB)
      DBG(posBp)
      DBG(maxx2)
      DBG(maxx)*/
      if (maxx2 > maxx) {
         maxx = maxx2;
         doWhat[i] = maxZeStr2.se;
      }
      
      // aktualizacja obu struktur
      if (tr.sum_of_augs_over_all_xs_geq_than_x(posB) < mp(maxx,i)) {
         tr.insert(posB, mp(maxx,i));
      }
      if (tr2.sum_of_augs_over_all_xs_geq_than_x(-posB) < mp((ll)maxx+2*posB,i)) {
         tr2.insert(-posB, mp((ll)maxx+2*posB,i));
      }
   }
   pii res = tr.sum_of_augs_over_all_xs_geq_than_x(0);
   pisz(L - res.fi);
   vi history;
   int ramp = res.se;
   while (ramp != -2) {
      history.pb(ramp);
      ramp = doWhat[ramp];
   }
   pisz(SZ(history));
   FOR(i,SZ(history)) pisz(history[i]+1);
}