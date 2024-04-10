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

void p (vi v) {
   sort(ALL(v));
   v.erase(unique(ALL(v)), v.end());
   pisz(SZ(v));
   FOREACH(x,v) printf("%d ", *x);
}

int main () {
   vi v;
   wez(n)
   FOR(i,n) {
      wez(x)
      v.pb(x);
   }
   sort(ALL(v));
   
   if (n == 1) {
      pisz(-1);
   } else if (n == 2) {
      if (v[0] == v[1]) {
         printf("1\n%d", v[0]);
      } else {
         vi res;
         int d = v[1] - v[0];
         if (d % 2 == 0) res.pb((v[0] + v[1]) / 2);
         res.pb(v[0] - d);
         res.pb(v[1] + d);
         p(res);
      }
   } else {
      vi res;
      
      vi diff;
      FOR(i,n-1) diff.pb(v[i + 1] - v[i]);
      sort(ALL(diff));
      if (diff[0] == diff.back()) {
         int d = diff[0];
         res.pb(v[0] - d);
         res.pb(v.back() + d);
      } else {
         if (diff[0] == diff[SZ(diff) - 2]) {
            int d = diff[0];
            int other = diff.back();
            if (2*d == other) FOR(i,n-1) if (v[i+1] - v[i] == other) {
               res.pb((v[i+1] + v[i]) / 2);
            }
         } else {
            // nothing
         }
      }
      
      p(res);
   }
}