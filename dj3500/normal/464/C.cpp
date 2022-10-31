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
#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (__typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

#define N 200007
const int M = 1000000007;
ll powe (ll x, ll p) {
	if (p == 0) return 1;
	ll w = powe((x*x)%M, p/2);
	if (p & 1) w = (w*x)%M;
	return w;
}

ll val[14], len[14];
char temp[N];
string query[N];

int main () {
   scanf("%s", temp);
   query[0] = string("x->") + temp;
   REP(c,0,9) {
      val[c] = c;
      len[c] = 1;
   }
   wez(q)
   FORI(i,q) {
      scanf("%s", temp);
      query[i] = temp;
   }
   REPD(i,q,0) {
      int c = query[i][0];
      if (c == 'x') {
         c = 10;
      } else {
         c = c - '0';
      }
      
      ll dl = 0, wart = 0;
      REP(k,3,SZ(query[i])-1) {
         int d = query[i][k] - '0';
         wart = wart * powe(10, len[d]) + val[d];
         wart %= M;
         dl += len[d];
      }
      dl %= M-1;
      len[c] = dl;
      val[c] = wart;
   }
   int res = val[10];
   res %= M;
   if (res < 0) res += M;
   pisz(res);
}