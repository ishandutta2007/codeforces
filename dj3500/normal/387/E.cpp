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
#define DBG(vari) cout<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

void go (int *t, int *erased, int *distLeft, int n) {
   vector<pii> q;
   q.pb(mp(0,-INF));
   FORI(i,n) {
      if (!erased[i]) {
         while (!q.empty() && q.back().se > t[i]) q.pop_back();
         q.pb(mp(i, t[i]));
      } else {
         int best = 0, from = 1, to = SZ(q) - 1;
         // best = max tze q[best].se < t[i]
         while (from <= to) {
            int m = (from + to) / 2;
            if (q[m].se < t[i]) {
               best = m;
               from = m+1;
            } else {
               to = m-1;
            }
         }
         distLeft[i] = i - q[best].fi - 1;
      }
   }
}

#define N 1000007
int t[N], t1[N];
int erased[N];
int distRight[N];
int tr[N], erasedr[N], distLeft[N];

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
   wez2(n,k)
   FORI(i,n) scanf("%d", t+i);
   int pos = 1;
   while(k--) {
      wez(x)
      while (t[pos] != x) {
         erased[pos] = 1;
         ++pos;
      }
      ++pos;
   }
   while (pos <= n) {
      erased[pos] = 1;
      ++pos;
   }
   //DBG(vi(erased+1, erased+1+n))
   
   go(t,erased,distLeft,n);
   FORI(i,n) {
      tr[i] = t[n+1-i];
      erasedr[i] = erased[n+1-i];
   }
   go(tr,erasedr,distRight,n);
   reverse(distRight + 1, distRight + 1 + n);
   
   //DBG(vi(distLeft + 1, distLeft + 1 + n));
   
   FORI(i,n) t1[t[i]] = i;
   ll res = 0;
   REPD(num,n,1) {
      int i = t1[num];
      add(a,i,1);
      if (erased[i]) {
         res += sumbetween(a, i - distLeft[i], i + distRight[i]);
      }
   }
   cout << res;
}