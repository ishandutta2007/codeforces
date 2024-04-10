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
#define DBG(vari) cout<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (__typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

vi kmp(string t, string p) { // text, pattern | zwraca 0-based indeksy trafien wzorca
   vi kn(SZ(p)+1,-1); // funkcja prefiksowa Knutha
   FORI(i,SZ(p)) {
      int j = kn[i-1];
      while (j != -1 && p[j] != p[i-1]) j=kn[j];
      kn[i] = j+1;
   }

   vi ans;
   int ppos=0,tpos=0;
   while (tpos<SZ(t)) {
      while (ppos!=-1 && (ppos == SZ(p) || p[ppos]!=t[tpos])) ppos=kn[ppos];
      ppos++;
      tpos++;
      if (ppos==SZ(p)) ans.pb(tpos-SZ(p));
   }
   return ans;
}

const int mod = 1000000007;
#define N 200007
char s[N], t[N];
bool occ[N];
int nxt[N];
ll dp[N], sufsum[N];

int main () {
   scanf("%s %s", s, t);
   int n = strlen(s), m = strlen(t);
   vi km = kmp(s, t);
   FOREACH(it,km) {
      occ[*it] = 1;
   }
   nxt[n] = INF;
   REPD(i,n-1,0) {
      nxt[i] = (occ[i]) ? i : nxt[i+1];
   }
   //DBG(vi(nxt,nxt+n));
   
   dp[n] = 1;
   sufsum[n] = 1;
   REPD(i,n-1,0) {
      dp[i] = dp[i+1];
      if (nxt[i] != INF) {
         dp[i] += sufsum[nxt[i] + m];
         dp[i] %= mod;
      }
      
      sufsum[i] = (sufsum[i+1] + dp[i]) % mod;
   }
   
   ll res = dp[0] - 1;
   res %= mod;
   if (res < 0) res += mod;
   pisz(res);
}