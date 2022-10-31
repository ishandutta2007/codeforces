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

int main () {
   int res = 0, a3 = 0, a2 = 0, a1 = 0;
   TESTS {
      wez(x)
      if (x == 4) ++res;
      else if (x == 3) ++a3;
      else if (x == 2) ++a2;
      else if (x == 1) ++a1;
   }
   
   // 3 + 1
   int full = min(a3, a1);
   res += full;
   a3 -= full;
   a1 -= full;
   
   // 3
   res += a3;
   
   // 2 + 2
   res += a2 / 2;
   a2 %= 2;
   
   if (a2 == 1) {
      if (a1 >= 2) {
         // 2 + 1 + 1
         ++res;
         a1 -= 2;
      } else if (a1 == 1) {
         // 2 + 1
         ++res;
         a1 = 0;
      } else {
         // 2
         ++res;
      }
   }
   
   // same 1
   res += a1 / 4;
   a1 %= 4;
   if (a1 != 0) ++res;
   
   pisz(res);
}