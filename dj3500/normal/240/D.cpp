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


void freop() {
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
}

vector<pii> one, two;
int n;

int get (int k) {
   if (k <= n) return one[k-1].fi;
   else return two[k-n-1].fi;
}

int main () { freop();
   scanf("%d", &n);
   FORI(i,n) {
      wez(x)
      one.pb(mp(x,i));
   }
   wez(m)
   REP(i,n+1,n+m) {
      wez(x)
      two.pb(mp(x,i));
   }
   
   int swaps[2] = {0,0};
   vi order[2];
   FOR(begin,2) {
      int cur = begin;
      int indone = 0, indtwo = 0;
      while (indone < SZ(one) || indtwo < SZ(two)) {
         while (indone < SZ(one) && one[indone].fi == cur) {
            order[begin].pb(indone + 1);
            indone++;
         }
         while (indtwo < SZ(two) && two[indtwo].fi == cur) {
            order[begin].pb(indtwo + n + 1);
            indtwo++;
         }
         ++swaps[begin];
         cur = 1 - cur;
      }
      if (get(order[begin].back()) == 0) {
         --swaps[begin];
      }
   }
   
   vi theorder;
   if (swaps[0] < swaps[1]) {
      theorder = order[0];
   } else {
      theorder = order[1];
   }
   int theswaps = min(swaps[0], swaps[1]);
   
   FOREACH(x,theorder) printf("%d ", *x); printf("\n"); pisz(theswaps);
   
   vi results;
   FOREACH(x,theorder) results.pb(get(*x));
   
   //DBG(results)
   
   results.pb(0); // !
   
   int k = 0;
   while(1) {
      int beg = k;
      while (k < SZ(results) && results[k] == results[beg]) ++k;
      if (k == SZ(results)) break;
      printf("%d ", k);
   }
}