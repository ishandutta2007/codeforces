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

typedef pair<ll,ll> pll;

int main () {
   wez3(d,n,m);
   vector<pll> stations = {{0,0}, {d,0}};
   FOR(u,m) {
      wez2(xi,pi);
      stations.pb(mp(xi,pi));
   }
   sort(ALL(stations));
   deque<pll> q;
   ll sumfi = 0;
   ll cost = 0;
   FOR(i,SZ(stations)-1) {
      ll price = stations[i].se;
      // update q
      while (!q.empty() && q.back().se >= price) {
         sumfi -= q.back().fi;
         q.pop_back();
      }
      q.push_back(mp(n - sumfi, price));
      sumfi = n;
      
      // buy enough to get to next
      ll need = stations[i+1].fi - stations[i].fi;
      while (need > 0 && !q.empty()) {
         ll buy = min(need, q.front().fi);
         cost += buy * q.front().se;
         need -= buy;
         q.front().fi -= buy;
         sumfi -= buy;
         if (q.front().fi == 0) q.pop_front();
      }
      if (need > 0) {
         pisz(-1);
         return 0;
      }
   }
   cout << cost;
}