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
using namespace std;
#define pb push_back
#define INF ((int)1e9)+9
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
//#define DBG(vari) cout<<#vari<<" = "<<vari<<endl;
#define DBG(v)
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));

int dp[1023][3003];
int a[1023];
int lastx[1023][3003],lasty[1023][3003];

int main () {
   wez(n)
   FORI(i,n) {
      wez(x)
      a[i]=x;
   }
   REP(i,n+1,n+10) a[i] = 0;
   
   int kmax = n/2 + 1;
   if (n % 2 == 0) kmax--;
   
   REP(k,0,505) REP(u,1,1020) dp[k][u] = INF;
   
   dp[0][1] = 0;
   lastx[0][1] = lasty[0][1] = 0;
   
   REP(k,0,kmax+2) REP(u,1,2*k+1) {
      int val;
      val = dp[k][u] + max(a[2*k+2],a[2*k+3]);
      if (val < dp[k+1][u]) {
         dp[k+1][u] = val;
         lastx[k+1][u] = 2*k+2;
         lasty[k+1][u] = 2*k+3;
      }
      val = dp[k][u] + max(a[u],a[2*k+3]);
      if (val < dp[k+1][2*k+2]) {
         dp[k+1][2*k+2] = val;
         lastx[k+1][2*k+2] = u;
         lasty[k+1][2*k+2] = 2*k+3;
      }
      val = dp[k][u] + max(a[u],a[2*k+2]);
      if (val < dp[k+1][2*k+3]) {
         dp[k+1][2*k+3] = val;
         lastx[k+1][2*k+3] = u;
         lasty[k+1][2*k+3] = 2*k+2;
      }
   }
   
   int last = n+1;
   if (n & 1) ++last;
   
   pisz(dp[kmax][last]);
   
   int ucurr = last;
   vector<string> vv;
   for (int k = kmax; k > 0; --k) {
      stringstream ss;
      DBG(k)
      DBG(ucurr)
      if (lastx[k][ucurr] >= 1 && lastx[k][ucurr] <= n) {
         ss << lastx[k][ucurr] << " ";
      }
      if (lasty[k][ucurr] >= 1 && lasty[k][ucurr] <= n) {
         ss << lasty[k][ucurr] << " ";
      }
      vv.pb(ss.str());
      int nucurr = -666;
      DBG(lastx[k][ucurr])
      DBG(lasty[k][ucurr])
      if (lastx[k][ucurr]<=2*k-1) nucurr = lastx[k][ucurr];
      if (lasty[k][ucurr]<=2*k-1) nucurr = lasty[k][ucurr];
      if (ucurr<=2*k-1) nucurr = ucurr;
      DBG(nucurr)
      ucurr = nucurr;
   }
   reverse(ALL(vv));
   FOR(i,vv.sz) cout << vv[i] << "\n";
}