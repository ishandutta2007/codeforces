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

const int mod = 7340033;
ll sp2[32][1024], sp4[32][1024];

int main () {
   sp4[0][0] = 1;
   REP(p,1,30) {
      REP(k,0,1000) {
         REP(a,0,k) {
            sp2[p][k] += sp4[p-1][a] * sp4[p-1][k-a];
         }
         sp2[p][k] %= mod;
      }
      sp4[p][0] = 1;
      REP(k,1,1000) {
         REP(a,0,k-1) {
            sp4[p][k] += sp2[p][a] * sp2[p][k-1-a];
         }
         sp4[p][k] %= mod;
      }
   }
   
   TESTS {
      wez2(n,k)
      int p = 0;
      while ((n & 1) && n > 1) {
         p++;
         n /= 2;
      }
      //DBG(p)
      //if (k == 0) pisz(1); else
      pisz(sp4[p][k]);
   }
}