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

#define N 300007
int l[N], r[N], t[N], res[N];

int main () {
   wez2(linii,scian)
   FOR(i,scian) scanf("%d %d %d", l+i,r+i,t+i);
   
   vector<pair<pii,int> > realWalls;
   
   multiset<int> st;
   vector<pii> events;
   FOR(i,scian) {
      events.pb(mp(l[i],t[i]+1));
      events.pb(mp(r[i],-(t[i]+1)));
   }
   int prev = -1;
   sort(ALL(events));
   FOREACH(ev,events) {
      int y = ev->fi;
      
      // jesli poprzednio byla jakas sciana i prev != y
      if (prev != y && !st.empty()) {
         realWalls.pb(mp(mp(prev,y), *st.begin()));
      }
      
      if (ev->se > 0) {
         int h = ev->se - 1;
         st.insert(h);
      } else {
         int h = -ev->se - 1;
         st.erase(st.find(h));
      }
      prev = y;
   }
   
   //DBG(realWalls)
   
   vector<pair<int,pii> > ev;
   FOREACH(it,realWalls) {
      int le = it->fi.fi, ri = it->fi.se, ti = it->se;
      ev.pb(mp(ti-ri, mp(0, -ti+ri)));
      ev.pb(mp(ti-ri, mp(1, 1)));
      ev.pb(mp(ti-le+1, mp(0, ti-le)));
      ev.pb(mp(ti-le+1, mp(1, -1)));
   }
   FOR(i,linii) {
      wez(qi)
      ev.pb(mp(qi, mp(2, i)));
   }
   sort(ALL(ev));
   ll war = 0, zasl = 0;
   FOREACH(it,ev) {
      int typ = it->se.fi;
      if (typ == 0) {
         zasl += it->se.se;
      } else if (typ == 1) {
         war += it->se.se;
      } else {
         int qi = it->fi;
         res[it->se.se] = zasl + war * qi;
      }
   }
   
   FOR(i,linii) pisz(res[i]);
}