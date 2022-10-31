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

const int mod = 1000000007;
int dp[203][1003][203];
int a[203], K;

void add (int i, int k, int f, int val) {
   if (k > K) return;
   dp[i][k][f] += val;
   if (dp[i][k][f] >= mod) dp[i][k][f] -= mod;
}

int main () {
   wez(n);
   scanf("%d", &K);
   FORI(i,n) {
      scanf("%d", a+i);
      //a[i] = rand() % 500 + 1;
   }
   sort(a+1, a+n+1);
   dp[0][0][0] = 1;
   REP(i,0,n-1) REP(k,0,K) REP(f,0,n) {
      if (dp[i][k][f] == 0) continue;
      int l = f * (a[i+1] - a[i]) + k;
      add(i+1, l, f, dp[i][k][f]);
      add(i+1, l, f+1, dp[i][k][f]);
      int ftimesdp = 1LL * f * dp[i][k][f] % mod;
      add(i+1, l, f, ftimesdp);
      add(i+1, l, f-1, ftimesdp);
   }
   ll res = 0;
   REP(k,0,K) res += dp[n][k][0];
   res %= mod;
   if (res < 0) res += mod;
   pisz(res);
}