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
#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

int main () {
   wez(n)
   vi v;
   while (n--) {
      wez(x)
      if (x != 0) {
         v.pb(x);
      } else {
         vector<pii> w;
         FOR(i,SZ(v)) w.pb(mp(v[i],i));
         sort(ALL(w)); reverse(ALL(w));
         while (SZ(w) > 3) w.pop_back();
         FOR(i,SZ(v)) {
            if (SZ(w) > 0 && i == w[0].se) {
               printf("pushStack\n");
            } else if (SZ(w) > 1 && i == w[1].se) {
               printf("pushQueue\n");
            } else if (SZ(w) > 2 && i == w[2].se) {
               printf("pushFront\n");
            } else {
               printf("pushBack\n");
            }
         }
         printf("%d", SZ(w));
         if (SZ(w) > 0) {
            printf(" popStack");
         }
         if (SZ(w) > 1) {
            printf(" popQueue");
         }
         if (SZ(w) > 2) {
            printf(" popFront");
         }
         printf("\n");
         v.clear();
      }
   }
   FOR(i,SZ(v)) {
      printf("pushQueue\n");
   }
}