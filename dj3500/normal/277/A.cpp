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

vector<vi> podziel_na_skladowe (int n, vi *adj) {
	vector<bool> vis(n+1,0);
	vector<vi> wyn;
	FORI(i,n) {
		if (vis[i]) continue;
		vi skladowa;
		deque<int> q;
		q.pb(i);
		while (!q.empty()) {
			int v = q.front();
			q.pop_front();
			if (vis[v]) continue;
			vis[v]=1;
			skladowa.pb(v);
			FOR(j,SZ(adj[v])) q.pb(adj[v][j]);
		}
		wyn.pb(skladowa);
	}
	return wyn;
}

#define N 306
vi adj[N];

int main () {
   wez2(n,m)
   FORI(a,n) {
      wez(ki)
      while (ki--) {
         wez(b)
         b += n;
         adj[a].pb(b);
         adj[b].pb(a);
      }
   }
   vector<vi> v = podziel_na_skladowe(n+m,adj);
   int x = 0, y = 0;
   FOREACH(skladowa,v) {
      if (1 == SZ((*skladowa))) {
         if ((*skladowa)[0] > n) {
            // ignore
         } else {
            y++;
         }
      } else {
         x++;
      }
   }
   if (x > 0) x--;
   pisz(x+y);
}