// tested by Hightail: https://github.com/dj3500/hightail
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
#include <cassert>
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
#define DBG(vari) cout<<"["<<__LINE__<<"] "<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (__typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

const int N = 2002002;
int res[N];

#define ty se.se
#define element fi.fi
#define tim se.fi
#define qindex fi.se

void add (int *a, int n, int x) { // val[n] += x
   for (; n < N; n |= n+1) a[n] += x;
}
int sum (int *a, int n) { // val[0] + val[1] + ... + val[n]
   int s = 0;
   while (n >= 0) {
      s += a[n];
      n = (n&(n+1))-1;
   }
   return s;
}
int sumbetween (int *a, int le, int ri) { return sum(a,ri) - sum(a,le-1); } // ok dla le=0

int a[N];

int main () {
   wez(Q);
   vector<pair<pii,pii> > v;
   FOR(q,Q) {
      wez3(ai,ti,xi);
      v.pb(mp(mp(xi,q),mp(ti,ai)));
      res[q] = -1;
   }
   sort(ALL(v));
   
   for (int q1 = 0; q1 < Q; ) {
      int q2 = q1;
      while (q2+1 < Q && v[q2+1].element == v[q1].element) ++q2;
      // [q1, q2]
      
      vi times;
      REP(q,q1,q2) times.pb(v[q].tim);
      sort(ALL(times));
      
      int n = SZ(times);
      REP(i,0,n+2) a[i] = 0;
      
      REP(q,q1,q2) {
         int t = lower_bound(ALL(times), v[q].tim) - times.begin();
         if (v[q].ty == 3) {
            res[v[q].qindex] = sum(a, t);
         } else {
            // 1 or 2
            int mn = (v[q].ty == 1) ? 1 : -1;
            add(a, t, mn);
         }
      }
      
      
      
      
      q1 = q2+1;
   }
   
   FOR(q,Q) if (res[q] != -1) pisz(res[q]);
}