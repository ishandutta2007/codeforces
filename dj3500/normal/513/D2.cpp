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

void fail () {
   printf("IMPOSSIBLE");
   exit(0);
}

char s[233];
const int N = 1001001;
int maxLeft[N], minRight[N], maxRight[N];

vi res;
int v;
void go (int atl) { //, bool rightmost) {
   ++v;
   int ai = v;
   //DBG(ai)
   if (maxLeft[ai] != 0) {
      //DBG("left")
      go(maxLeft[ai]);
      //DBG("up")
   }
   
   res.pb(ai);
   
   if (minRight[ai] < v+1) fail();
   REMAX(atl, maxRight[ai]);
   if (atl <= v) return;
   //DBG("right")
   go(atl);
   //DBG("up");
}

int main () {
   wez2(n,c)
   FORI(i,n) {
      maxLeft[i] = maxRight[i] = 0;
      minRight[i] = INF;
   }
   FORI(q,c) {
      wez2(ai,bi)
      if (ai >= bi) fail();
      scanf("%s", s);
      bool le = (0 == strcmp(s, "LEFT"));
      if (le) {
         REMAX(maxLeft[ai], bi); // maxLeft[ai] = 0 or is > ai
      } else {
         REMAX(maxRight[ai], bi);
         REMIN(minRight[ai], bi);
      }
   }
   
   v = 0;
   go(n);
   FOREACH(it,res) printf("%d ", *it);
}