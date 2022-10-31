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
#define DBG(vari) cout<<"["<<__LINE__<<"] "<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (__typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

typedef long double real;
const int N = 102*1005;
real dp[2][N], sum[2][N];

int main () {
   wez2(n,m);
   if (m == 1) {
      printf("1.000");
      return 0;
   }
   dp[0][0] = 1.0;
   REP(i,0,n*m) sum[0][i] = 1.0;
   int kleofas = 0;
   FORI(i,n) {
      wez(rnk);
      kleofas += rnk;
      int nu = i & 1, old = (i-1) & 1;
      dp[nu][0] = 0;
      sum[nu][0] = 0;
      REP(j,1,n*m) {
         dp[nu][j] = 0;
         int a = j - rnk, b = j - 1;
         if (a >= 0) dp[nu][j] -= sum[old][a];
         if (b >= 0) dp[nu][j] += sum[old][b];
         a = j - m - 1, b = j - rnk - 1;
         if (a >= 0) dp[nu][j] -= sum[old][a];
         if (b >= 0) dp[nu][j] += sum[old][b];
         dp[nu][j] /= m-1;
         sum[nu][j] = sum[nu][j-1] + dp[nu][j];
      }
   }
   cout << setprecision(15) << fixed << double(1 + (m-1) * sum[n&1][kleofas-1]);
}