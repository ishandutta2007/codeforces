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

int a[507][507];
int rowsum[507][507], colsum[507][507];

int main () {
   wez2(n,m)
   FORI(i,n) FORI(j,m) scanf("%d",&a[i][j]);
   FORI(i,n) {
      rowsum[i][0] = 0;
      FORI(j,m) rowsum[i][j] = rowsum[i][j-1] + a[i][j];
   }
   FORI(j,m) {
      colsum[0][j] = 0;
      FORI(i,n) colsum[i][j] = colsum[i-1][j] + a[i][j];
   }
   
   int best = -INF;
   
   // typ A
   REP(i,3,n) REP(j,1,m-2) {
      int sum = a[i][j] + a[i][j+1] + a[i][j+2] + a[i-1][j+2] + a[i-2][j+2] + a[i-2][j+1] + a[i-2][j];
      REMAX(best, sum);
      int minI = i-2, maxI = i, minJ = j, maxJ = j+2;
      minI -= 2, maxI += 2, minJ -= 2, maxJ += 2;
      for (;
           minI >= 1 && maxI <= n && minJ >= 1 && maxJ <= m;
           minI -= 2, maxI += 2, minJ -= 2, maxJ += 2) {
              sum += a[minI+2][minJ+1] + colsum[maxI][minJ] - colsum[minI+1][minJ] + rowsum[maxI][maxJ] - rowsum[maxI][minJ] + colsum[maxI-1][maxJ] - colsum[minI-1][maxJ] + rowsum[minI][maxJ-1] - rowsum[minI][minJ-1];
              REMAX(best,sum);
           }
   }
   
   // typ B
   REP(i,1,n) REP(j,1,m) {
      int sum = a[i][j];
      int minI = i, maxI = i, minJ = j, maxJ = j;
      minI -= 2, maxI += 2, minJ -= 2, maxJ += 2;
      for (;
           minI >= 1 && maxI <= n && minJ >= 1 && maxJ <= m;
           minI -= 2, maxI += 2, minJ -= 2, maxJ += 2) {
              sum += a[minI+2][minJ+1] + colsum[maxI][minJ] - colsum[minI+1][minJ] + rowsum[maxI][maxJ] - rowsum[maxI][minJ] + colsum[maxI-1][maxJ] - colsum[minI-1][maxJ] + rowsum[minI][maxJ-1] - rowsum[minI][minJ-1];
              REMAX(best,sum);
           }
   }
   pisz(best);
}