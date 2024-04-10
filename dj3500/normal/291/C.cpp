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

int main () {
   vector<unsigned> v;
   wez2(n,k)
   FOR(i,n) {
      int x1,x2,x3,x4;
      scanf("%d.%d.%d.%d", &x1, &x2, &x3, &x4);
      unsigned x = x1;
      x = 256 * x + x2;
      x = 256 * x + x3;
      x = 256 * x + x4;
      v.pb(x);
   }
   sort(ALL(v));
   REP(ones,1,31) {
      unsigned mask = (1LL << 32) - (1LL << (32-ones));
      int cnt = 1;
      REP(i,1,SZ(v)-1) if ((v[i] & mask) != (v[i-1] & mask)) ++cnt;
      if (cnt == k) {
         int x1 = mask >> 24, x2 = (mask >> 16) & 255, x3 = (mask >> 8) & 255, x4 = mask & 255;
         printf("%d.%d.%d.%d", x1,x2,x3,x4);
         return 0;
      }
   }
   pisz(-1);
}