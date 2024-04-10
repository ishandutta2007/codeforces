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

int m, cost0, gain0;
int cost[12], gain[12], allowed[12];
int memo[1002][12];

int go (const int dough, const int used) {
   if (used == m) return dough / cost0 * gain0;
   if (memo[dough][used] != -1) return memo[dough][used];
   int now = used+1;
   int moge = min(dough / cost[now], allowed[now]);
   int ans = 0;
   REP(ile,0,moge) REMAX(ans, ile*gain[now] + go(dough - ile*cost[now], now))
   return memo[dough][used] = ans;
}

int main () {
   int n;
   scanf("%d %d %d %d",&n,&m,&cost0,&gain0);
   FORI(i,m) {
      int stuffing,needstuffing;
      scanf("%d %d %d %d",&stuffing,&needstuffing,cost+i,gain+i);
      allowed[i] = stuffing / needstuffing;
   }
   FOR(a,1002)FOR(b,12)memo[a][b]=-1;
   pisz(go(n,0));
}