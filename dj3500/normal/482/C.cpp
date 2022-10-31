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
#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (__typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

#define N 55
typedef long double real;
string s[N];
ll vec[N];
ll And[1<<20];
int ile[1<<20];
int anybit[1<<20];
real dp[1<<20];

int main () {
   wez(n)
   FOR(i,n) cin >> s[i];
   int m = SZ(s[0]);
   
   REP(mask,1,(1<<m)-1) {
      FOR(b,m) if ((1<<b) & mask) { anybit[mask] = b; break; }
   }
   
   FOR(i,n) {
      FOR(j,m) {
         // robimy vec[j]
         vec[j] = 0;
         FOR(k,n) if (k != i) if (s[i][j] == s[k][j]) vec[j] |= 1LL << k;
      }
      And[0] = (1LL<<n) - 1;
      And[0] ^= 1LL << i;
      REP(mask,1,(1<<m)-1) {
         int b = anybit[mask];
         And[mask] = And[mask ^ (1 << b)] & vec[b];
      }
      FOR(mask,1<<m) {
         if (And[mask] == 0) {
            ++ile[mask];
         }
      }
   }
   
   REPD(mask,(1<<m)-1,0) {
      int k = n - ile[mask]; // ilu stringom mask nie wystarcza
      if (k == 0) continue; // cos tam
      dp[mask] = 0;
      int mozl = 0;
      FOR(b,m) if (!( (1<<b) & mask )) {
         int l = n - ile[mask | (1<<b)];
         if (l > 0) dp[mask] += 1.0L * l / k * dp[mask | (1<<b)];
         ++mozl;
      }
      dp[mask] = 1 + dp[mask] / mozl;
   }
   
   cout << setprecision(13) << fixed << dp[0];
}