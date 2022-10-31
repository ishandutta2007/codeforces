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

#define N 5555
int dp[N][N]; // dp[i][j] = ile na pozycjach 1..j jest rzeczy z przedzialu 1..i
int x[N];

int main () {
   wez(n)
   FORI(i,n) {
      scanf("%d", x+i);
      x[i]++;
   }
   int swaps = 0;
   FORI(i,n) {
      FORI(j,n) {
         dp[i][j] = dp[i][j-1] + (x[j] <= i);
      }
   }
   int best = 0, ile = 0;
   FORI(a,n-1) REP(b,a+1,n) {
      if (x[a] > x[b]) {
         ++swaps;
         // elementow miedzy x[a] a x[b] na pozycjach a+1 .. b-1
         int d = dp[x[a]][b-1] - dp[x[a]][a] - (dp[x[b]][b-1] - dp[x[b]][a]);
         if (best < 1 + 2*d) {
            best = 1 + 2*d;
            ile = 1;
         } else if (best == 1 + 2*d) {
            ++ile;
         }
      }
   }
   printf("%d %d", swaps - best, ile);
}