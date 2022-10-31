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
#define fi first
#define se second
#define vi vector<int>
#define SZ(x) ((int)((x).size()))
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

typedef double X;
bool iszero (const X &a) { return abs(a) < 1e-11; }

const int N = 200200;
X a[N], p[N];
int n;
X res = -INF;

pair<pii,pii> wit = {{1,1},{1,0}};

X evalodd (int k, int x) {
   X ret = (p[n] - p[n-x] + p[k] - p[k-x-1]) / (1 + 2*x) - a[k];
   if (ret > res) {
      res = ret;
      wit = {{n-x+1,n},{k-x,k}};
   }
   return ret;
}

void getodd (int k) {
   int from = 0, to = min(k-1, n-k);
   evalodd(k, from);
   evalodd(k, to);
   while (to-from+1 >= 4) {
      int mid1 = (2*from+to)/3, mid2 = (from+2*to)/3;
      if (evalodd(k, mid1) < evalodd(k, mid2)) {
         from = mid1;
      } else {
         to = mid2;
      }
   }
   REP(x,from,to) {
      evalodd(k, x);
   }
}
X evaleven (int k, int x) {
   X ret = (p[n] - p[n-x] + p[k+1] - p[k-x-1]) / (2 + 2*x) - (a[k] + a[k+1]) / 2;
   if (ret > res) {
      res = ret;
      wit = {{n-x+1,n},{k-x,k+1}};
   }
   return ret;
}

void geteven (int k) {
   int from = 0, to = min(k-1, n-k-1);
   evaleven(k, from);
   evaleven(k, to);
   while (to-from+1 >= 4) {
      int mid1 = (2*from+to)/3, mid2 = (from+2*to)/3;
      if (evaleven(k, mid1) < evaleven(k, mid2)) {
         from = mid1;
      } else {
         to = mid2;
      }
   }
   REP(x,from,to) {
      evaleven(k, x);
   }
}



int main () {
   scanf("%d", &n);
   FORI(i,n) {
      wez(x);
      a[i] = x;
   }
   sort(a+1, a+n+1);
   FORI(i,n) p[i] = p[i-1] + a[i];
   
   FORI(k,n) getodd(k);
   FORI(k,n-1) geteven(k);
   
   pisz(wit.fi.se - wit.fi.fi + 1 + wit.se.se - wit.se.fi + 1);
   REP(x,wit.se.fi,wit.se.se) printf("%d ", int(round(a[x])));
   REP(x,wit.fi.fi,wit.fi.se) printf("%d ", int(round(a[x])));
}