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
#define DBG(vari) cout<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

#define N 10000007
int anydiv[N];
ll trzeba[N];
int add[N];

int main () {
   const int m = 10000000;
   for (int x = 2; x*x <= m; ++x) if (anydiv[x] == 0) for (int y = x*x; y <= m; y += x) anydiv[y] = x;
   wez(k)
   FOR(u,k) {
      wez(ai)
      add[ai+1] --;
   }
   int sila = k;
   REP(x,2,m) {
      sila += add[x];
      int ai = x;
      while (ai > 1) {
         int d = anydiv[ai];
         if (d == 0) d = ai;
         trzeba[d] += sila;
         ai /= d;
      }
   }
   
   ll res = 1;
   
   REP(p,2,m) if (anydiv[p] == 0) {
      if (trzeba[p] == 0) continue;
      ll from = 1, best = (ll)p * trzeba[p], to = best - 1;
      while (from <= to) {
         ll mid = (from + to) / 2;
         ll x = mid;
         ll times = 0;
         while (x >= p) {
            times += x / p;
            x /= p;
         }
         if (times >= trzeba[p]) {
            best = mid;
            to = best - 1;
         } else {
            from = mid + 1;
         }
      }
      res = max(res, best);
   }
   
   cout << res;
}