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
using namespace std;
#define pb push_back
#define INF 2147483647
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define FORI(i,n) for(int (i)=1;(i)<=(n);++(i))
#define mp make_pair
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define sz size()
#define fi first
#define se second
#define wez(n) int (n); scanf("%d",&(n));
#define wez2(n,m) int (n),(m); scanf("%d %d",&(n),&(m));
#define wez3(n,m,k) int (n),(m),(k); scanf("%d %d %d",&(n),&(m),&(k));
inline void pisz(int n) { printf("%d\n",n); }
template<typename T,typename TT> ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &s,vector<T> t){FOR(i,t.size())s<<t[i]<<" ";return s; }
#define IN(x,y) ((y).find((x))!=(y).end()) 
#define DBG(vari) cout<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));

double px[105],py[105],pz[105],dx,dy,dz;
const double eps = 1e-7;
int n;

inline double sqr (double x) { return x*x; }
double dist() {
   double ans = 0;
   FOR(i,n) REMAX(ans, sqr(px[i]-dx) + sqr(py[i]-dy) + sqr(pz[i]-dz))
   return -ans; // zeby funkcja miala maksimum
}

void tz(double from, double to) {
   if (abs(from-to) < eps) {
      dz = from;
      return;
   }
   double mid1 = (2*from + to)/3, mid2 = (from + 2*to)/3;
   
   dz = mid1;
   double wyn1 = dist();
   
   dz = mid2;
   double wyn2 = dist();
   
   if (wyn1 < wyn2) tz(mid1,to);
   else tz(from,mid2);
}
void ty(double from, double to) {
   if (abs(from-to) < eps) {
      dy = from;
      return;
   }
   double mid1 = (2*from + to)/3, mid2 = (from + 2*to)/3;
   
   dy = mid1;
   tz(-10000,10000);
   double wyn1 = dist();
   
   dy = mid2;
   tz(-10000,10000);
   double wyn2 = dist();
   
   if (wyn1 < wyn2) ty(mid1,to);
   else ty(from,mid2);
}
void tx(double from, double to) {
   if (abs(from-to) < eps) {
      dx = from;
      return;
   }
   double mid1 = (2*from + to)/3, mid2 = (from + 2*to)/3;
   
   dx = mid1;
   ty(-10000,10000);
   double wyn1 = dist();
   
   dx = mid2;
   ty(-10000,10000);
   double wyn2 = dist();
   
   if (wyn1 < wyn2) tx(mid1,to);
   else tx(from,mid2);
}


int main () {
   scanf("%d",&n);
   FOR(i,n) {
      wez3(a,b,c)
      px[i]=a;
      py[i]=b;
      pz[i]=c;
   }
   tx(-10000,10000);
   printf("%.9lf %.9lf %.9lf\n", dx,dy,dz);   
}