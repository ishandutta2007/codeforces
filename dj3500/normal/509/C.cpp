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
#define DBG(vari) cerr<<"["<<__LINE__<<"] "<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (__typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

vi v = {0};

void print () {
   FOREACH(it,v) printf("%d", *it);
   printf("\n");
}

void go () {
   wez(b)
   while (1) {
      REPD(i,SZ(v)-1,0) { // 300?
         // can I change v[i] to a higher number,
         // v[i+1 .. SZ(prev)-1] to anything,
         // and get sum of digits = b?
         REP(d,v[i]+1,9) {
            int sumBefore = d;
            REP(a,0,i-1) sumBefore += v[a];
            int maxRest = 9 * (SZ(v) - 1 - i);
            if (sumBefore <= b && b <= sumBefore + maxRest) {
               // ok
               v[i] = d;
               b -= sumBefore;
               REPD(j,SZ(v)-1,i+1) {
                  v[j] = min(9, b);
                  b -= v[j];
               }
               print();
               return;
            }
         }
      }
      // can't
      v.insert(v.begin(), 0);
   }
}

int main () {
   TESTS { go(); }
}