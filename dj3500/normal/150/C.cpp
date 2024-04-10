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

#define N 230000
int x[N], p[N];
ll w[N], d[N];

struct Q {
   ll le, ri, whole, mi;
};


template <class Aug>
struct ITree {

   // ZMIENIC TO W RAZIE POTRZEBY!
   inline static Aug plus (Aug a1, Aug a2) { // dzialanie w polgrupie Aug
      Q q;
      q.whole = a1.whole + a2.whole;
      q.ri = max(a1.ri + a2.whole, a2.ri);
      q.le = max(a1.le, a1.whole + a2.le);
      q.mi = max(max(a1.mi, a2.mi), a1.ri + a2.le);
      return q;
   }
   Aug identity;

   int leftend, rightend;
   Aug *state;

   ITree (int _leftend, int _rightend) :
      leftend(_leftend), rightend(_rightend) {
      identity.le = identity.ri = identity.mi = identity.whole = 0;
      int pot = 1;
      while (pot <= _rightend-_leftend+5) pot <<= 1;
      pot <<= 1;
      state = new Aug[pot+20];
      FOR(i,pot+20) state[i]=identity;
   }

   ~ITree() {
      delete [] state;
   }

   // jeszcze konstruktor kopiujacy trzeba by bylo napisa

   void set_aux (int x, Aug ile, int v, int from, int to) {
      if (from==to) {
         state[v] = ile;
         return;
      }
      int mid = (from+to)/2;
      if (x <= mid) set_aux(x,ile,2*v+1,from,mid);
      else set_aux(x,ile,2*v+2,mid+1,to);
      state[v] = plus(state[2*v+1],state[2*v+2]);
   }

   void set (int x, Aug ile) {
      set_aux(x,ile,0,leftend,rightend);
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

   Aug sumofaugsoverkeyssmallerorequal (int x) {
      return sumofaugsoverkeyssmallerorequal_aux(x,0,leftend,rightend);
   }

   Aug sumofaugsoverkeysbiggerorequal (int x) {
      return sumofaugsoverkeysbiggerorequal_aux(x,0,leftend,rightend);
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

   

int main () {
   wez3(n,m,fine)
   FORI(i,n) scanf("%d", x+i);
   n--;
   FORI(i,n) d[i] = x[i+1] - x[i];
   FORI(i,n) scanf("%d", p+i);
   FORI(i,n) w[i] = 50LL * d[i] - fine * p[i];  
   
   ITree<Q> tr(1,n);
   FORI(i,n) {
      Q q;
      q.whole = w[i];
      q.mi = q.ri = q.le = max(0LL,w[i]);
      tr.set(i, q);
   }
   
   
   ll res = 0;
   
   while (m--) {
      wez2(a,b)
      b--;
      // odcinki z numerami od a do b wlacznie
      Q ans = tr.sumofaugsoverkeysbetween(a,b);
      res += ans.mi;
      //DBG(ans.mi)
   }
   
   int koniec = res % 100;
   res /= 100;
   cout << res << "." << koniec;
}