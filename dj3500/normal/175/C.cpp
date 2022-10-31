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

ll prog[150];

int main () {
   IOS
   int n;
   cin >> n;
   ll all = 0;
   vector<pair<ll,ll> > v;
   FOR(i,n) {
      ll k,c;
      cin >> k >> c;
      v.pb(mp(c,k)); // koszt, ile
      all += k;
   }
   sort(ALL(v));
   reverse(ALL(v)); // najmniej kosztowne z tylu
   
   int f = 1, t;
   cin >> t;
   REP(i,2,t+1) cin >> prog[i];
   prog[t+2] = 10000000000000000LL;
   
   ll res = 0, crushed = 0;
   while (crushed < all) {
      ll a = v.back().se, b = prog[f+1] - crushed, teraz = min(a,b);
      //DBG(teraz)
      res += v.back().fi * teraz * f;
      crushed += teraz;
      v[SZ(v)-1].se -= teraz;
      if (v[SZ(v)-1].se == 0) v.pop_back();
      if (prog[f+1] == crushed) ++f;
   }
   cout << res << endl;
}