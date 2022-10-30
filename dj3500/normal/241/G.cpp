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

double artha (int n, vector<int> &p, vector<ll> &x, int prog) { // p,x 1-based
   vector<double> radius;
   vector<int> s;
   double sum = 0;
   FORI(i,n) {
      radius.pb(p[i]);
      FORI(j,min(SZ(s),prog)) {
         int jj = SZ(s) - j + 1;
         int t = s[jj-1];
         REMIN(radius[i-1], (x[i] - x[t]) * (x[i] - x[t]) / (4 * radius[t-1]));
      }
      while (!s.empty() && radius[s.back() - 1] <= radius[i-1]) {
         s.pop_back();
      }
      s.pb(i);
      sum += radius[i-1];
      cerr << setprecision(6) << fixed;
      DBG(SZ(s))
      DBG(radius[i-1])
   }
   return sum;
}

int main () {
   srand(time(0));
   int n = 500;
   vector<int> p;
   vector<ll> x;
   p.pb(-1);
   x.pb(0);
   
   
   p.pb(1000000);
   x.pb(0);
   
   REP(i,2,n-1) {
      p.pb(n-i);
      x.pb(x.back() + 3*n + (i == 2 ? 10000 : 0));
   }
   x.pb(x.back() + 20000);
   p.pb(1000000);
   //DBG(x[SZ(x)])
   //DBG(artha(n,p,x,1));
   //DBG(artha(n,p,x,6));
   //double res1500 = artha(n,p,x,1500);
   //double res300 = artha(n,p,x,30);
   //DBG(x)DBG(p)
   //DBG(res1500)DBG(res300)
   pisz(n);
   FORI(i,n) { printf("%d %d\n", int(x[i]), int(p[i])); }
}