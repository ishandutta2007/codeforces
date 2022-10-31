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


const int N = 5005, mod = 1000000007;

namespace sa {
int sa[N], lcp[N], rank[N], n, g[N], b[N], h;
inline bool comp (int i, int j) {
   if (i == j || g[i] != g[j]) return g[i] < g[j];
   return g[i+h] < g[j+h];
}
void init(const string &t) {
   n = SZ(t);
   REP(i,0,n) sa[i] = i, g[i] = t[i];
   g[n] = -1;
   h = b[0] = b[n] = 0;
   sort(sa, sa+n+1, comp);

   for (h = 1; b[n] != n; h *= 2) {
      sort(sa, sa+n+1, comp);
      FOR(i,n) b[i+1] = b[i] + comp(sa[i], sa[i+1]);
      REP(i,0,n) g[sa[i]] = b[i];
   }
   FOR(i,n) sa[i] = sa[i+1]; // 1-based -> 0-based
   FOR(i,n) rank[sa[i]] = i;
   // Kasai
   for (int i = 0, k = 0; i < n; i++) {
      if (k > 0) k--;
      if (rank[i] == n-1) { lcp[n-1] = -1; k = 0; continue; }
      int j = sa[rank[i]+1];
      while (t[i+k] == t[j+k]) k++;
      lcp[rank[i]] = k;
   }
}
const int LOGN = 13;
int rm[LOGN][N]; // rm[k][i] = min(tab[i], ..., tab[i + 2^k - 1])
void init (int *tab, int n) { // tab[0..n-1]
   FOR(i,n) rm[0][i] = tab[i];
   REP(k,1,LOGN-1) REP(i,0,n-(1<<k)) rm[k][i] = min(rm[k-1][i], rm[k-1][i+(1<<(k-1))]);
}
int query (int a, int b) { // a <= b bo inaczej segfault
   int k = 31 - __builtin_clz(b-a+1);
   return min(rm[k][a], rm[k][b-(1<<k)+1]);
}
// inicjalizacja: init(s); init(lcp, SZ(s));
int lcpBetween (int a, int b) { // zakl: a != b
   a = rank[a], b = rank[b];
   if (a > b) swap(a,b);
   return query(a, b-1);
}
};

char s[N];
ll dp[N][N], sum[N][N];

bool smaller (int a, int b, int c, int d) {
   /*for (; a <= b; ++a, ++c) {
      if (s[a] > s[c]) return 0;
      if (s[a] < s[c]) return 1;
   }
   return 0;*/
   int lcp = sa::lcpBetween(a-1, c-1);
   if (lcp >= b-a+1) return 0;
   return (s[a+lcp] < s[c+lcp]);
}

int main () {
   wez(n)
   scanf("%s", s+1);

   string ss(s+1,s+n+1);
   sa::init(ss);
   sa::init(sa::lcp, n);

   REP(k,1,n) REP(i,1,k) {
      if (i == k) dp[k][i] = 1;
      else if (s[k-i+1] == '0') dp[k][i] = 0;
      else {
         dp[k][i] = sum[k-i][min(i-1,k-i)];
         if (i <= k-i) if (smaller(k-i-i+1, k-i, k-i+1, k)) dp[k][i] += dp[k-i][i];
      }
      sum[k][i] = (sum[k][i-1] + dp[k][i]) % mod;
   }

   ll res = sum[n][n];
   res %= mod;
   if (res < 0) res += mod;
   pisz(res);
}