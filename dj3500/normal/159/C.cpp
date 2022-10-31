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
#define INF 1000000000
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define FORI(i,n) for(int (i)=1;(i)<=(n);++(i))
#define mp make_pair
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define SZ(x) ((int)(x.size()))
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

#define MAXN 200007
int a[MAXN];
// value[n] += x
void add(int n, int x) { for (; n < MAXN; n |= n + 1) a[n] += x; }
// Returns value[0] + value[1] + ... + value[n]
int sum(int n) { int s=0; while (n>=0) { s+=a[n]; n=(n&(n+1))-1; } return s; }

vi transform (vi v) {
   memset(a,0,sizeof(a));
   vi res;
   FOREACH(xx,v) {
      int best = 200000, to = best-1, from = 1, x = *xx;
      while (to >= from) {
         int m = (to+from)/2;
         int ile = m - sum(m);
         if (ile >= x) {
            best = m;
            to = m-1;
         } else {
            from = m+1;
         }
      }
      
      res.pb(best);
      add(best, 1);
   }
   return res;
}

char s[2048];

int main () {
   wez(k)
   scanf("%s",s);
   vi removals[300];
   TESTS {
      int a; char c;
      scanf("%d %c",&a,&c);
      removals[c].pb(a);
   }
   REP(i,'a','z') removals[i] = transform(removals[i]);
   FOR(i,300) {
      sort(ALL(removals[i]));
      removals[i].pb(INF);
      reverse(ALL(removals[i]));
   }
   vi occ(300,0);
   int len = strlen(s);
   FOR(j,k) {
      FOR(i,len) {
         char c = s[i];
         occ[c]++;
         if (removals[c].back() == occ[c]) {
            removals[c].pop_back();
         } else {
            putchar(c);
         }
      }
   }
}