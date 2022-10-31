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
template<typename T> ostream& operator<<(ostream &s,deque<T> t){FOR(i,SZ(t))s<<t[i]<<" ";return s; }
#define DBG(vari) cout<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (__typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

const int N = 300006;
int a[N], b[N];
vector<pii> queries[N]; // yj, numer
int ans[N];

int main () {
   wez(n)
   FORI(i,n) {
      scanf("%d", a+i);
      wez(len)
      b[i] = a[i] + len;
   }
   wez(Q)
   FORI(j,Q) {
      wez2(xj,yj)
      queries[xj].pb(mp(yj,j));
      //DBG(j)
   }
   deque<pair<pii,int> > d;
   d.pb(mp(mp(2000000005,2000000006),0)); // guard
   REPD(i,n,1) {
      //DBG(i)
      int B = b[i];
      while (d.front().fi.fi <= B) {
         REMAX(B, d.front().fi.se);
         d.pop_front();
      }
      d.push_front(mp(mp(a[i],B), d.front().se + (d.front().fi.fi - B)));
      
      FOREACH(it,queries[i]) {
         int qno = it->se, yj = it->fi;
         //DBG(yj)
         //DBG(d)
         auto jt = lower_bound(ALL(d), mp(mp(a[yj], -INF),0));
         if (jt->fi.fi <= a[yj] && a[yj] <= jt->fi.se) {
            // ok
         } else {
            --jt;
         }
         int dist = jt->se;
         ans[qno] = d.front().se - dist;
      }
   }
   FORI(j,Q) pisz(ans[j]);
}