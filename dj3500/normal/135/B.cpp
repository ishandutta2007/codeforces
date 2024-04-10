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
#define x first
#define y second
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

bool straight (pii p, pii q, pii r) {
   int a = q.x - p.x, b = q.y - p.y, c = r.x - q.x, d = r.y - q.y;
   //DBG(a)DBG(b)DBG(c)DBG(d)
   return a*c + b*d == 0;
}

int distsq (pii p, pii q) {
   return (q.x - p.x)*(q.x - p.x) + (q.y - p.y)*(q.y - p.y);
}

int main () {
   //DBG(straight(mp(0,0),mp(0,1),mp(1,1)))
   vector<pii> points;
   FOR(i,8) {
      wez2(x,y)
      points.pb(mp(x,y));
   }
   vi v;
   FOR(i,8) v.pb(i);
   do {
      bool ok = 1;
      ok = ok && straight(points[v[0]], points[v[1]], points[v[2]]);
      ok = ok && straight(points[v[1]], points[v[2]], points[v[3]]);
      ok = ok && straight(points[v[2]], points[v[3]], points[v[0]]);
      ok = ok && straight(points[v[4]], points[v[5]], points[v[6]]);
      ok = ok && straight(points[v[5]], points[v[6]], points[v[7]]);
      ok = ok && straight(points[v[6]], points[v[7]], points[v[4]]);
      ok = ok && (distsq(points[v[0]],points[v[1]]) == distsq(points[v[1]], points[v[2]]));
      if (ok) {
         printf("YES\n%d %d %d %d\n%d %d %d %d",v[0]+1,v[1]+1,v[2]+1,v[3]+1,v[4]+1,v[5]+1,v[6]+1,v[7]+1);
         return 0;
      }
   } while (next_permutation(ALL(v)));
   printf("NO\n");
}