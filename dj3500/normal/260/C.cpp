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

#define N 100007
int a[N], minEndingAtX[N];
ll b[N];

int main () {
   wez2(n,x)
   x--;
   FOR(i,n) scanf("%d", a+i);
   int mini = *min_element(a,a+n);
   // minEndingAtX[j] = min of a(j..x]
   minEndingAtX[x] = INF;
   int prev = x;
   for (int i = (x+n-1) % n; i != x; i = (i+n-1) % n) {
      minEndingAtX[i] = min(minEndingAtX[prev], a[prev]);
      prev = i;
   }
   //DBG(vi(minEndingAtX,minEndingAtX+n));
   FOR(i,n) {
      if (mini >= a[i]) {
         ll p = a[i];
         int s = (x-i+n) % n;
         ll k = p*n + s;
         if (minEndingAtX[i] >= p+1) {
            // ok
            //DBG(i)
            FOR(j,n) b[j] = -1;
            for (int pos = (i+1) % n; pos != (x+1) % n; pos = (pos+1) % n) {
               b[pos] = a[pos] - (p+1);
            }
            FOR(j,n) if (b[j] == -1) b[j] = a[j] - p;
            b[i] = k;
            FOR(j,n) printf("%I64d ", b[j]);
            return 0;
         }
      }
   }
}