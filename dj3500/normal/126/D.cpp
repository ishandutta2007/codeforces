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

ll fib[100];

int main () {
   fib[1] = 1;
   fib[2] = 2;
   int p = 2;
   while (fib[p] <= 1000000000000000000LL) {
      fib[p+1] = fib[p] + fib[p-1];
      p++;
   }
   
   TESTS {
      ll n;
      scanf("%I64d", &n);
      int k = 1;
      while (fib[k] <= n) k++; k--;
      vi v;
      v.pb(1);
      n -= fib[k];
      REPD(i,k-1,1) {
         if (fib[i] <= n) {
            n -= fib[i];
            v.pb(1);
         } else {
            v.pb(0);
         }
      }
      reverse(ALL(v));

      vi w;
      int run = 0;
      FOREACH(it,v) {
         if (*it == 0) {
            run++;
         } else {
            w.pb(run);
            run = 0;
         }
      }

      ll prevmain = 1, prevless = 0;
      FOREACH(r,w) {
         // 0: 1 -> suma, zero
         // 1: 10 -> suma, prev
         // 2: 100 -> suma, 
         ll newmain = prevmain + prevless;
         ll newless = (*r)/2 * prevmain + (1+*r)/2 * prevless;
         prevmain = newmain;
         prevless = newless;
      }
      ll res = prevmain + prevless;
      printf("%I64d\n", res);
   }
}