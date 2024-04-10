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

#define real long double
real res[100007];

int main () {
   int n,l,v1,v2;
   IOS
   cin >> n >> l >> v1 >> v2;
   real d = (real)l * (real)v2 / ((real)v2 + (real)v1);
   //DBG(d)
   vector<pair<real,int> > events;
   events.pb(mp(2*l,300));
   int ile = 0;
   FOR(i,n) {
      int a;
      cin >> a;
      events.pb(mp(a,1));
      real dokad = a+d;
      if (dokad > 2*l) {
         dokad -= 2*l;
         ile++;
      }
      events.pb(mp(dokad,-1));
   }
   sort(ALL(events));
   //DBG(events)
   //DBG(ile)
   REP(i,0,n) res[i] = 0;
   real prev = 0;
   FOREACH(x,events) {
      res[ile] += x->fi - prev;
      ile += x->se;
      prev = x->fi;
   }
   cout << setprecision(13) << fixed;
   REP(i,0,n) cout << res[i]/(2*l) << "\n";
}