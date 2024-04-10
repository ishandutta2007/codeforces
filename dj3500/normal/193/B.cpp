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

int n,r;
int aa[32],b[32],p[32],power[32][32];
ll k[32];
ll res;

void go (int *a, int moves, bool teraz1) {
   if (moves == 0) {
      ll now = 0;
      FOR(i,n) now += k[i] * a[i];
      REMAX(res,now);
      return;
   }
   int anew[32];
   if (teraz1) {
      FOR(i,n) anew[i] = a[i] ^ b[i];
      go(anew,moves-1,0);
   } else {
      REP(i,1,moves) {
         FOR(j,n) anew[j] = a[power[i][j]] + i*r;
         go(anew,moves-i,1);
      }
   }
}

int main () {
   int u;
   cin >> n >> u >> r;
   FOR(i,n) cin >> aa[i];
   FOR(i,n) cin >> b[i];
   FOR(i,n) cin >> k[i];
   FOR(i,n) cin >> p[i];
   FOR(i,n) p[i]--;
   
   FOR(i,n) power[1][i] = p[i];
   REP(w,2,30) FOR(i,n) power[w][i] = p[power[w-1][i]];
   
   res = -INF;
   res *= INF;
   for (int uu = u; uu >= 0; uu -= 2) {
      go(aa,uu,1);
      go(aa,uu,0);
   }
   cout << res << endl;
}