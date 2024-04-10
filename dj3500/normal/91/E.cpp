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



ll a[100005];
ll b[100005];
int timenow = 0;
set<pii> czas;


template <class Aug>
struct ITree {
   
   // ZMIENIC TO W RAZIE POTRZEBY!
   inline static Aug plus (Aug i, Aug j) { // dziaanie w pgrupie Aug (chyba moe nie dziaa dla Aug nieprzemiennej)
      ll ci = a[i]+b[i]*timenow,
         cj = a[j]+b[j]*timenow;
      return ci > cj ? i : j;
   }
   static const Aug identity = -700;
   
   int leftend, rightend;
   Aug *state;
   
   ITree (int _leftend, int _rightend) :
      leftend(_leftend), rightend(_rightend) {
      int pot = 1;
      while (pot <= _rightend-_leftend+5) pot <<= 1;
      pot <<= 1;
      state = new Aug[pot+20];
      FOR(i,pot+20) state[i]=identity;
   }
   
   ~ITree() {
      delete [] state;
   }
   
   // jeszcze konstruktor kopiujcy trzeba by bylo napisa
   
   void recalc_local (int v) {
      int i = state[2*v+1], j = state[2*v+2];
      state[v] = plus(i,j);
      if (b[i] != b[j]) {
         ll spotkanie = (a[i]-a[j])/(b[j]-b[i]) + 1;
         if (spotkanie > timenow) {
            czas.insert(mp(spotkanie,v));
         }
      }
   }
   
   void recalc_and_up (int v) {
      recalc_local(v);
      if (v != 0) {
         int half = (v&1) ? v/2 : v/2 - 1;
         recalc_and_up(half);
      }
   }

   void set_aux (int x, Aug ile, int v, int from, int to, bool justset) {
      if (from==to) {
         state[v] = ile;
         return;
      }
      int mid = (from+to)/2;
      if (x <= mid) set_aux(x,ile,2*v+1,from,mid,justset);
      else set_aux(x,ile,2*v+2,mid+1,to,justset);
      if (!justset) recalc_local(v);
   }

   void set (int x, Aug ile, bool justset = false) {
      set_aux(x,ile,0,leftend,rightend,justset);
   }
   
   void recalc_all_aug(int v, int from, int to) {
      if (from==to) return;
      int mid = (from+to)/2;
      recalc_all_aug(2*v+1,from,mid);
      recalc_all_aug(2*v+2,mid+1,to);
      recalc_local(v);
   }
   
   void recalc_all() {
      recalc_all_aug(0,leftend,rightend);
   }
   
   Aug sumofaugsoverkeyssmallerorequal_aux (int x, int v, int from, int to) {
      if (x < from) return identity;
      if (from==to) return state[v];
      int mid = (from+to)/2;
      if (x >= mid+1) return plus(state[2*v+1],sumofaugsoverkeyssmallerorequal_aux(x,2*v+2,mid+1,to));
      return sumofaugsoverkeyssmallerorequal_aux(x,2*v+1,from,mid);
   }
   
   Aug sumofaugsoverkeysbiggerorequal_aux (int x, int v, int from, int to) {
      if (x > to) return identity;
      if (from==to) return state[v];
      int mid = (from+to)/2;
      if (x <= mid) return plus(sumofaugsoverkeysbiggerorequal_aux(x,2*v+1,from,mid), state[2*v+2]);
      return sumofaugsoverkeysbiggerorequal_aux(x,2*v+2,mid+1,to);
   }

   Aug sumofaugsoverkeysbetween_aux(int x, int y, int v, int from, int to) {
      if (y < from) return identity;
      if (x > to) return identity;
      if (from==to) return state[v];
      int mid = (from+to)/2;
      if (y < mid+1) return sumofaugsoverkeysbetween_aux(x,y,2*v+1,from,mid);
      if (x > mid) return sumofaugsoverkeysbetween_aux(x,y,2*v+2,mid+1,to);
      return plus(sumofaugsoverkeysbiggerorequal_aux(x,2*v+1,from,mid), sumofaugsoverkeyssmallerorequal_aux(y,2*v+2,mid+1,to));
   }
   
   Aug sumofaugsoverkeysbetween (int x, int y) {
      if (x > y) return identity; // przedzial pusty
      return sumofaugsoverkeysbetween_aux(x,y,0,leftend,rightend);
   }
};

int ql[100005],qr[100005],qans[100005];


int main () {
   wez2(n,q)
   FORI(i,n) {
      wez2(aa,bb)
      a[i]=aa;
      b[i]=bb;
   }
   ITree<int> tr(1,n);
   FORI(i,n) tr.set(i,i,true);
   tr.recalc_all();
   
   vector<pii> queries;
   FOR(j,q) {
      wez3(l,r,t)
      ql[j]=l;
      qr[j]=r;
      queries.pb(mp(t,j));
   }
   sort(ALL(queries));
   FOR(j,q) {
      int l = ql[queries[j].se], r = qr[queries[j].se], t = queries[j].fi;
      
      timenow = t;
      while (!czas.empty() && czas.begin()->fi <= timenow) {
         tr.recalc_and_up(czas.begin()->se);
         czas.erase(czas.begin());
      }
      
      qans[queries[j].se] = tr.sumofaugsoverkeysbetween(l,r);
   }
   FOR(j,q) pisz(qans[j]);
}