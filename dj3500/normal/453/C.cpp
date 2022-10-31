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
#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (__typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
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

#define N 100007
vi adj[N];
int parity[N];
bool seen[N];
int parent[N];
vi children[N];
int visits[N];

void dfs (int v, int p) {
   if (seen[v]++) return;
   parent[v] = p;
   if (p != -1) children[p].pb(v);
   FOREACH(x,adj[v]) dfs(*x, v);
}

vi ans;

void visit (int v) {
   ++visits[v];
   ans.pb(v);
}

void go (int v) {
   // jestem w parent[v]
   visit(v);
   // jestem w v
   FOREACH(w,children[v]) {
      // jestem w v = parent[w]
      go(*w);
      // jestem w v = parent[w]
   }
   // jestem w v
   visit(parent[v]);
   // jestem w parent[v]
   if (visits[v] % 2 != parity[v]) {
      visit(v);
      visit(parent[v]);
   }
   // jestem w parent[v]
}

int main () {
   wez2(n,m)
   while (m--) {
      wez2(a,b)
      adj[a].pb(b);
      adj[b].pb(a);
   }
   FORI(i,n) scanf("%d", parity+i);
   vector<vi> skl = podziel_na_skladowe(n, adj);
   int cnt = 0;
   vi skladowa;
   FOREACH(it,skl) {
      bool has1 = 0;
      FOREACH(jt,(*it)) {
         if (parity[*jt]) has1 = 1;
      }
      if (has1) {
         ++cnt;
         skladowa = *it;
      }
   }
   if (cnt > 1) {
      pisz(-1);
   } else if (cnt == 0) {
      pisz(0);
   } else {
      // cnt == 1
      int root = skladowa[0];
      dfs(root, -1);
      
      FOREACH(dz,children[root]) {
         go(*dz);
      }
      if (parity[root] != visits[root] % 2) {
         ans.insert(ans.begin(), root);
      }
      
      pisz(SZ(ans));
      FOREACH(it,ans) printf("%d ", *it);
   }
}