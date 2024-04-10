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
#define DBG(vari) cout<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (__typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

#define N 128
int b[N][N], a[N][N], row[N], col[N];

int main () {
   wez2(n,m)
   FOR(i,n) FOR(j,m) scanf("%d", &b[i][j]);
   
   FOR(i,n) {
      bool all = 1;
      FOR(j,m) if (b[i][j] == 0) all = 0;
      row[i] = all;
   }
   FOR(j,m) {
      bool all = 1;
      FOR(i,n) if (b[i][j] == 0) all = 0;
      col[j] = all;
   }
   //DBG(vi(row,row+n))
   //DBG(vi(col,col+m))
   
   FOR(i,n) FOR(j,m) {
      a[i][j] = row[i] && col[j];
   }
   FOR(i,n) FOR(j,m) {
      bool any = 0;
      FOR(k,m) if (a[i][k]) any = 1;
      FOR(k,n) if (a[k][j]) any = 1;
      if (b[i][j] != any) {
         printf("NO");
         return 0;
      }
   }
   printf("YES\n");
   FOR(i,n) {
      FOR(j,m) printf("%d ", a[i][j]);
      printf("\n");
   }
}