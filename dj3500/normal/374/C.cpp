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

#define N ((1<<20)+7)
inline int id (int x, int y) { return x * 1024 + y; }
char s[1024][1024];
const int dx[4] = {-1,1,0,0}, dy[4] = {0,0,-1,1};

namespace lo {
int n; // input
vi adj[N]; // input
int dp[N]; // temp; -1 = unseen, -2 = processing, nonnegative = computed value
bool good[N];

void dfs (int v) {
	if (dp[v] == -2) throw 0;
	if (dp[v] != -1) return;
	dp[v] = -2;
	int best = 0;
	FOREACH(x,adj[v]) {
		dfs(*x);
		best = max(best, 1 + dp[*x]);
	}
	dp[v] = best;
}

int longestPathInDAG () {
	try {
		FORI(i,n) dp[i] = -1;
		FORI(i,n) if (good[i]) dfs(i);
		int best = 0;
		FORI(i,n) best = max(best, dp[i]);
		return best; // number of edges
	} catch (int x) {
		return -1; // cycle
	}
}
};


int main () {
   wez2(n,m)
   FORI(i,n) scanf("%s", s[i] + 1);
   REP(i,0,n+1) REP(j,0,m+1) if (i == 0 || i == n+1 || j == 0 || j == m+1) s[i][j] = '#';
   vector<char> nxt(256, '$');
   nxt['D'] = 'I';
   nxt['I'] = 'M';
   nxt['M'] = 'A';
   nxt['A'] = 'D';
   FORI(i,n) FORI(j,m) FOR(d,4) {
      int x = i + dx[d], y = j + dy[d];
      if (s[x][y] == nxt[s[i][j]]) lo::adj[id(i,j)].pb(id(x,y));
   }
   lo::n = 1 << 20;
   FORI(i,n) FORI(j,m) lo::good[id(i,j)] = ('D' == s[i][j]);
   int res = lo::longestPathInDAG();
   if (res == -1) {
      printf("Poor Inna!");
   } else {
      ++res;
      res /= 4;
      if (res == 0) {
         printf("Poor Dima!");
      } else {
         pisz(res);
      }
   }
}