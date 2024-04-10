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

vi bfs1 (int n, int source, vi *adj) {
   vi odl(n+1,-1);
   deque<int> q;
   q.pb(source);
   odl[source] = 0;
   while (!q.empty()) {
      int v = q.front();
      q.pop_front();
      FOREACH(it,adj[v]) if (odl[*it] == -1) {
         odl[*it] = odl[v] + 1;
         q.pb(*it);
      }
   }
   return odl;
}


int id[64][64][2];
vi adj[5006];
vector<pair<int,ll> > ways[5006];
const int mod = 1000000007;
ll dp[5006];

#define NEED 66
ll nt[NEED+1][NEED+1];

void initnewton () {
	FOR(n,NEED+1) nt[n][0] = 1;
	FORI(k,NEED) nt[0][k] = 0;
	FORI(n,NEED) FORI(k,NEED) nt[n][k] = (nt[n-1][k-1] + nt[n-1][k]) % mod;
}

int main () {
   initnewton();
   wez2(n,k)
   k /= 50;
   int a1 = 0, a2 = 0;
   FOR(i,n) {
      wez(x)
      if (x == 50) a1++; else a2++;
   }
   int next = 1;
   REP(i,0,a1) REP(j,0,a2) FOR(u,2) id[i][j][u] = next++;
   REP(b1,0,a1) REP(b2,0,a2) {
      // u = 0
      REP(c1,0,b1) REP(c2,0,b2) if (c1 + 2*c2 <= k && c1 + c2 > 0) {
         adj[id[b1-c1][b2-c2][1]].pb(id[b1][b2][0]);
         ways[id[b1-c1][b2-c2][1]].pb(mp(id[b1][b2][0], (nt[b1][c1] * nt[b2][c2])%mod));
      }
      // u = 1
      REP(c1,0,a1-b1) REP(c2,0,a2-b2) if (c1 + 2*c2 <= k && c1 + c2 > 0) {
         adj[id[b1+c1][b2+c2][0]].pb(id[b1][b2][1]);
         ways[id[b1+c1][b2+c2][0]].pb(mp(id[b1][b2][1], (nt[a1-b1][c1] * nt[a2-b2][c2]) % mod));
      }
   }
   vi dist = bfs1(next,id[0][0][1],adj);
   if (-1 == dist[id[a1][a2][0]]) {
      pisz(-1);
      pisz(0);
      return 0;
   }
   
   pisz(dist[id[a1][a2][0]]);
   
   FORI(i,next) dp[i] = 0;
   dp[id[0][0][1]] = 1;
   vector<pii> srt;
   FORI(i,next) if (-1 != dist[i]) srt.pb(mp(dist[i],i));
   sort(ALL(srt));
   FOREACH(it,srt) {
      int v = it->se;
      FOREACH(x,ways[v]) {
         int w = x->fi;
         if (dist[w] == dist[v]+1) {
            dp[w] += dp[v] * x->se;
            dp[w] %= mod;
         }
      }
   }
   dp[id[a1][a2][0]] %= mod;
   if (dp[id[a1][a2][0]] < 0) dp[id[a1][a2][0]] += mod;
   pisz(dp[id[a1][a2][0]]);
}