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

const int N = 200007, S = 450;
int a[N], delta[N];

int main () {
   wez(n)
   FORI(i,n) scanf("%d", a+i);
   REP(k,1,min(S,n-1)) {
      int res = 0;
      FORI(v,n) {
         int from = k*(v-1) + 2, to = min(k*v + 1, n);
         REP(x,from,to) {
            if (a[v] > a[x]) ++res;
         }
      }
      printf("%d ", res);
   }
   //return 0;
   REP(v,1,S) REP(x,2,n) {
      if (a[v] > a[x]) {
         int from = (x-1+v-1) / v, to = (v==1) ? INF : ((x-2) / (v-1));
         REMAX(from, S+1);
         REMIN(to, n-1);
         if (from <= to) {
            delta[from]++;
            delta[to+1]--;
         }
      }
   }
   int res = 0;
   REP(k,S+1,n-1) {
      res += delta[k];
      printf("%d ", res);
   }
}