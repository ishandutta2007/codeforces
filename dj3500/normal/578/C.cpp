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

const int N = 200200;
int _a[N], n;
double A[N];

double ma () {
   double meh = 0, msf = 0;
   FORI(i,n) {
      meh = max(0.0, meh + A[i]);
      REMAX(msf, meh);
   }
   return msf;
}

double f (double _x) {
   FORI(i,n) A[i] = _a[i] - _x;
   double res = ma();
   FORI(i,n) A[i] = -_a[i] + _x;
   return max(res, ma());
}

int iter = 0;
double ternary (double from, double to) {
   ++iter;
	if (iter >= 150) return from;
	double mid1 = (2*from+to)/3, mid2 = (from+2*to)/3;
	if (f(mid1) > f(mid2)) return ternary(mid1,to);
	else return ternary(from,mid2);
}

int main () {
   scanf("%d", &n);
   FORI(i,n) scanf("%d", _a+i);
   cout << setprecision(18) << fixed << f(ternary(-10000.0, 10000.0));
}