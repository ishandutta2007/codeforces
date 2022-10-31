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

#define N 50007
vi adj[N], ch[N];
ll res;
int dp[N][512];
ll odj[N];
int k;

void go (int v, int p) {
   FOREACH(it,adj[v]) if (*it != p) {
      ch[v].pb(*it);
      go(*it, v);
   }
}

void godp (int v) {
   dp[v][0] = 1;
   REP(i,1,k) {
      dp[v][i] = 0;
   }
   FOREACH(x,ch[v]) {
      godp(*x);
      REP(i,1,k) dp[v][i] += dp[*x][i-1];
   }
   //cerr << "\n";
   //DBG(v)
   
   // k
   ll r = 0;
   int maks = k/2;
   if (!(k&1)) --maks;
   //DBG(maks)
   REP(a,0,maks) {
      r += (ll)dp[v][a] * dp[v][k-a];
   }
   //DBG(r)
   if (!(k&1)) {
      r += (ll)dp[v][k/2] * (dp[v][k/2] - 1) / 2;
   }
   //DBG(r)
   FOREACH(x,ch[v]) r -= odj[*x];
   //DBG(r)
   res += r;
   //DBG(res)
   
   // k-2
   odj[v] = 0;
   REP(a,0,maks - 1) {
      odj[v] += (ll)dp[v][a] * dp[v][k-2-a];
   }
   if (!(k&1)) {
      odj[v] += (ll)dp[v][k/2 - 1] * (dp[v][k/2 - 1] - 1) / 2;
   }
   //DBG(odj[v])
   //DBG(vi(dp[v],dp[v]+k+1))
}

int main () {
   wez(n)
   scanf("%d",&k);
   FOR(i,n-1) {
      wez2(a,b)
      adj[a].pb(b);
      adj[b].pb(a);
   }
   go(1,-1);
   //FORI(i,n) {DBG(i)DBG(ch[i])}
   
   res = 0;
   godp(1);
   
   cout << res << endl;
}