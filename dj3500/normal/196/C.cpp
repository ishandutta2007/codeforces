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
typedef long long LL;
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

#define N 1509
int size[N], parent[N];
vi adj[N];
int ans[N];

void dfs (int v, int p) {
   parent[v] = p;
   size[v] = 1;
   FOREACH(x,adj[v]) if (*x != p) {
      dfs(*x,v);
      size[v] += size[*x];
   }
}

struct Point { int x,y,index; };
inline ll sqr (int x) { return (ll)x*x; }
inline ll dist (const Point &p, const Point &q) {
   return sqr(p.x-q.x) + sqr(p.y-q.y);
}
Point wzgledem;

#define Det(a,b,c) (LL(b.x-a.x)*LL(c.y-a.y)-LL(b.y-a.y)*(c.x-a.x))
bool myCmp(const Point &a, const Point &b) {
	ll w = Det(wzgledem, a, b);
	if (w == 0) return abs(wzgledem.x - a.x) + abs(wzgledem.y - a.y) < 
		abs(wzgledem.x - b.x) + abs(wzgledem.y - b.y);
	return w > 0;
}

void go (int v, vector<Point> pts) {
   wzgledem = *pts.begin();
   ans[wzgledem.index] = v;
   sort(pts.begin()+1, pts.end(), myCmp);
   int cur = 1;
   FOREACH(x,adj[v]) if (*x != parent[v]) {
      vector<Point> pts2;
      while (size[*x]--) pts2.pb(pts[cur++]);
      // niech ten na poczatku ma minimalna odleglosc od wzgledem
      /*ll minodl = INF;
      minodl *= INF;
      minodl *= 6;
      FOR(u,SZ(pts2)) REMIN(minodl, dist(wzgledem,pts2[u]));
      FOR(u,SZ(pts2)) if (minodl == dist(wzgledem,pts2[u])) {swap(pts2[u],pts2[0]);break;}*/
      go(*x,pts2);
   }
}

int main () {
   wez(n)
   if (n == 1) {
      printf("1\n");
      return 0;
   }
   if (n == 2) {
      printf("1 2\n");
      return 0;
   }
   FOR(i,n-1) {
      wez2(u,v)
      adj[u].pb(v);
      adj[v].pb(u);
   }
   vector<Point> pts;
   FOR(i,n) {
      wez2(x,y)
      pts.pb((Point){x,y,i});
   }
   
   int minX = INF+10;
   FOR(u,SZ(pts)) REMIN(minX, pts[u].x);
   FOR(u,SZ(pts)) if (minX == pts[u].x) { swap(pts[u], pts[0]); break; }
   
   dfs(1,-1);
   go(1,pts);
   FOR(i,n) printf("%d ", ans[i]);
}