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
#define DBG(vari) cout<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

#define MAXX ((1 << 20) + 5)
int a[MAXX], b[MAXX];
ll possibleOnLev[22], nowOnLev[22];
//bool switched[22];

void go (int from, int to, int lev) { // [from,to)
   // to - from = 2^lev
   if (lev == 0) {
      // nic
   } else {
      int mid = (from + to) / 2;
      go(from,mid,lev-1);
      go(mid,to,lev-1);
      
      int i = from, j = mid, s = from, ile_druga = 0;
      while (i < mid && j < to) {
         if (a[i] <= a[j]) {
            b[s++] = a[i++];
            nowOnLev[lev] += ile_druga;
         } else {
            b[s++] = a[j++];
            ile_druga++;
         }
      }
      while (i < mid) {
         b[s++] = a[i++];
         nowOnLev[lev] += ile_druga;
      }
      while (j < to) {
         b[s++] = a[j++];
      }
      
      REP(it,from,to-1) a[it] = b[it];
      
      possibleOnLev[lev] += 1LL * (to - from) * (to - from - 1) / 2;
      //1LL << (2*lev - 2);
      int cnt = 1;
      REP(it,from+1,to-1) {
         if (a[it] == a[it-1]) {
            possibleOnLev[lev] -= cnt;
            ++cnt;
         } else {
            cnt = 1;
         }
      }
   }
}

int main () {
   wez(N)
   int n = 1 << N;
   FOR(i,n) scanf("%d", a+i);
   go(0,n,N);
   ll invs = 0;
   REP(lev,0,N) invs += nowOnLev[lev];
   REPD(lev,N,1) possibleOnLev[lev] -= possibleOnLev[lev-1];
   /*if (N >= 3) DBG(possibleOnLev[3])
   DBG(possibleOnLev[2])
   DBG(possibleOnLev[1])*/
   TESTS {
      wez(qi)
      //DBG(lev)
      REP(lev,0,qi) {
         invs -= nowOnLev[lev];
         nowOnLev[lev] = possibleOnLev[lev] - nowOnLev[lev];
         invs += nowOnLev[lev];
      }
      //DBG(nowOnLev[lev])
      printf("%lld\n", invs);
   }
}