#include <bits/stdc++.h>
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

#define N 100007
vi p[N], q[N];

ll ha (int x, int y) { return 100005LL * (x+1) + y; }

int main () {
   int res = 0;
   
   wez(n)
   unordered_set<ll> pts;
   //pts.reserve(n);
   FOR(i,n) {
      wez2(x,y)
      pts.insert(ha(x,y));
      p[x].pb(y);
   }
   
   const int SQ = sqrt(n);
   REP(x,0,100000) {
      sort(ALL(p[x]));
      if (SZ(p[x]) > SQ) {
         FOREACH(y,p[x]) q[*y].pb(x);
      } else {
         FOR(i,SZ(p[x])) REP(j,i+1,SZ(p[x])-1) {
            int y1 = p[x][i], y2 = p[x][j];
            int d = y2 - y1;
            if (pts.count(ha(x - d, y1)) && pts.count(ha(x - d, y2))) ++res;
            if (pts.count(ha(x + d, y1)) && pts.count(ha(x + d, y2))) ++res;
         }
         FOREACH(y,p[x]) pts.erase(ha(x,*y));
      }
   }
   
   REP(y,0,100000) {
      sort(ALL(q[y]));
      //assert(SZ(q[y]) <= SQ + 5);
      FOR(i,SZ(q[y])) REP(j,i+1,SZ(q[y])-1) {
         int x1 = q[y][i], x2 = q[y][j];
         int d = x2 - x1;
         if (pts.count(ha(x1, y - d)) && pts.count(ha(x2, y - d))) ++res;
         if (pts.count(ha(x1, y + d)) && pts.count(ha(x2, y + d))) ++res;
      }
      FOREACH(x,q[y]) pts.erase(ha(*x,y));
   }
   
   pisz(res);
}