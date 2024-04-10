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
#define DBG(vari) cout<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

const int mod = 1000000007;
#define N 1000007
int jest[N], sum[N], pot2[N];

int main () {
   wez3(n,m,k)
   while(m--) {
      wez2(u,v)
      if (v-u==1) continue;
      if (v-u != k+1) {
         pisz(0);
         return 0;
      }
      jest[u] = 1;
   }
   
   sum[0] = 0;
   REP(a,1,n) sum[a] = sum[a-1] + jest[a];
   
   pot2[0] = 1;
   REP(a,1,n) pot2[a] = (2*pot2[a-1]) % mod;
   
   ll res = 0;
   if (sum[n] == 0) ++res; // pusty   
   
   for (int a = 1; a+k+1 <= n; ++a) {
      // a bedzie: a -> a+k+1
      if (sum[a-1] > 0 || sum[a+k] < sum[n]) {
         // sa rzeczy poza przedzialem
         continue;
      }
      int pr = min(a+k, n-k-1);
      int opcji = (pr - a) - (sum[pr] - sum[a]);
      //DBG(a)
      //DBG(opcji)
      res += pot2[opcji];
   }
   
   res %= mod;
   if (res < 0) res += mod;
   pisz(res);
}