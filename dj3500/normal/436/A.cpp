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
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

int makeMove (vector<pii> &v, int x) {
   pii best(-1,-1);
   FOR(i,SZ(v)) if (x >= v[i].fi) REMAX(best, mp(v[i].se, i));
   if (best.fi == -1) throw 0;
   v.erase(v.begin() + best.se);
   return best.fi;
}

int go (vector<pii> v0, vector<pii> v1, int x) {
   int eaten = 0;
   try { while (1) {
      x += makeMove(v0, x);
      ++eaten;
      x += makeMove(v1, x);
      ++eaten;
   } } catch (int _) {}
   return eaten;
}

int main () {
   vector<pii> v[2];
   wez2(n,x)
   FOR(i,n) {
      wez3(ti,hi,mi)
      v[ti].pb(mp(hi,mi));
   }
   FOR(u,2) sort(ALL(v[u]));
   int res = max(go(v[0], v[1], x), go(v[1], v[0], x));
   pisz(res);
}