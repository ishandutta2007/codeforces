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
#define ll int
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
#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

#define N 400007
void add (ll *a, int n, ll x) { // val[n] += x
   for (; n < N; n |= n+1) a[n] += x;
}
ll sum (ll *a, int n) { // val[0] + val[1] + ... + val[n]
   ll s = 0;
   while (n >= 0) {
      s += a[n];
      n = (n&(n+1))-1;
   }
   return s;
}
ll sumbetween (ll *a, int le, int ri) { return sum(a,ri) - sum(a,le-1); } // ok dla le=0
int fen[N], a[N], pos[N], val[N];

void upd (int i) {
   if (pos[i+1] < pos[i]) {
      if (val[i] != 1) {
         val[i] = 1;
         add(fen,i,1);
      }
   } else {
      if (val[i] != 0) {
         val[i] = 0;
         add(fen,i,-1);
      }
   }
}

int main () {
   wez(n)
   FORI(i,n) {
      scanf("%d", a+i);
      pos[a[i]] = i;
   }
   FORI(i,n-1) if (pos[i+1] < pos[i]) {
      val[i] = 1;
      add(fen,i,1);
   }
   
   TESTS {
      wez3(typ,x,y)
      if (typ == 1) {
         pisz(1 + sumbetween(fen,x,y-1));
      } else {
         int A = a[x], B = a[y];
         pos[A] = y;
         pos[B] = x;
         a[x] = B;
         a[y] = A;
         upd(A);
         if (A > 1) upd(A-1);
         upd(B);
         if (B > 1) upd(B-1);
      }
   }
}