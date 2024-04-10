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

const int N = 200200;
vi adj[N];
int dp[N], pd[N];

void dfs (int v, int p) {
   int sumpd = 0, sons = 0;
   vi lol = {0,0};
   for (int w : adj[v]) if (w != p) {
      ++sons;
      dfs(w, v);
      sumpd += pd[w];
      lol.pb(dp[w] - pd[w] - 1);
   }
   sort(ALL(lol));
   dp[v] = sumpd + sons + lol[0];
   pd[v] = dp[v] + lol[1];
}

int main () {
   wez(n);
   ll x, y;
   cin >> x >> y;
   FOR(u,n-1) {
      wez2(a,b);
      adj[a].pb(b);
      adj[b].pb(a);
   }
   if (x >= y) {
      // drzewo jest drozsze
      bool isStar = 0;
      FORI(i,n) if (SZ(adj[i]) == n-1) isStar = 1;
      if (isStar) {
         cout << x + (n-2) * y;
      } else {
         cout << (n-1) * y;
      }
   } else {
      dfs(1,-1);
      // pd[1] = ilu trzeba obciac
      cout << pd[1] * y + (n-1-pd[1]) * x;
   }
}