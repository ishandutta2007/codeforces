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

// graf o wierzchokach 1..n (0..n-1 -> zmienic FORI na FOR)

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

// zadania testowe:
// http://www.spoj.pl/problems/TOUR/ (tylko spr. spojnosci grafu)
// uva 10129 (glownie spr. spojnosci grafu)


#define N 1005
vi adj[N];

int main () {
   wez2(n,m)
   while(m--) {
      wez2(a,b)
      adj[a].pb(b);
      adj[b].pb(a);
   }
   vector<vi> s = podziel_na_skladowe(n,adj);
   vector<vi> res, grp[4];
   bool fail = 0;
   FOREACH(x,s) {
      if (SZ((*x)) > 3) fail = 1;
      else grp[SZ((*x))].pb(*x);
   }
   if (fail) pisz(-1);
   else {
      if (SZ(grp[2]) > SZ(grp[1])) {
         pisz(-1);
      } else {
         while (!grp[2].empty()) {
            printf("%d %d %d\n", grp[2].back()[0], grp[2].back()[1], grp[1].back()[0]);
            grp[2].pop_back();
            grp[1].pop_back();
         }
         while (!grp[1].empty()) {
            FOR(u,3) {
               printf("%d ", grp[1].back()[0]);
               grp[1].pop_back();
            }
            printf("\n");
         }
         while (!grp[3].empty()) {
            printf("%d %d %d\n", grp[3].back()[0], grp[3].back()[1], grp[3].back()[2]);
            grp[3].pop_back();
         }
      }
   }
}