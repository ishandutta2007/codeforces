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

int girl[1001001];

int main () {
   wez(n);
   int offOdd = 0, offEven = 0;
   bool oddToOdd = 1;
   TESTS {
      wez(ty);
      if (ty == 1) {
         wez(x);
         if (x % n == 0) continue;
         if (x < 0) x += n;
         // 0 < x < n
         if (x % 2 == 1) {
            // move by 1
            if (oddToOdd) {
               ++offOdd;
            } else {
               ++offEven;
            }
            oddToOdd = !oddToOdd;
         }
         offOdd += x/2;
         offEven += x/2;
      } else {
         oddToOdd = !oddToOdd;
      }
      offOdd %= n/2;
      offEven %= n/2;
   }
   //DBG(offOdd)DBG(offEven)DBG(oddToOdd);
   FOR(i,n/2) {
      girl[(2*i + 2*offEven) % n] = 2*i;
      girl[(2*i+1 + 2*offOdd) % n] = 2*i+1;
   }
   if (!oddToOdd) {
      FOR(i,n/2) swap(girl[2*i], girl[2*i+1]);
   }
   FOR(i,n) printf("%d ", girl[i] + 1);
}