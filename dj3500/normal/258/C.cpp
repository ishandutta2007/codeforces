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

#define N 100007
vi divs[N];
int a[N], geq[N], exactly[N];
const int mod = 1000000007;

ll powe (ll x, ll p) {
	if (p == 0) return 1;
	ll w = powe((x*x)%mod, p/2);
	if (p & 1) w = (w*x)%mod;
	return w;
}

int main () {
   REP(x,1,100000) {
      for (int y = x; y <= 100000; y += x) {
         divs[y].pb(x);
      }
   }
   //DBG(divs[12])
   
   wez(n)
   FOR(i,n) scanf("%d", a+i);
   sort(a,a+n);
   ll res = 0;
   REP(x,1,100000) {
      FOR(u,SZ(divs[x])) {
         int ind = lower_bound(a,a+n,divs[x][u]) - a;
         // n-ind przedzialow zawiera >= u+1 dzielnikow
         geq[u+1] = n-ind;
      }
      geq[SZ(divs[x])+1] = 0;
      
      FORI(u,SZ(divs[x])) {
         exactly[u] = geq[u] - geq[u+1];
      }
      
      ll all = 1;
      REP(u,2,SZ(divs[x])-1) {
         all *= powe(u,exactly[u]);
         all %= mod;
      }
      all *= powe(SZ(divs[x]), exactly[SZ(divs[x])]) - powe(SZ(divs[x])-1, exactly[SZ(divs[x])]);
      all %= mod;
      res += all;
   }
   res %= mod;
   if (res < 0) res += mod;
   pisz(res);
}