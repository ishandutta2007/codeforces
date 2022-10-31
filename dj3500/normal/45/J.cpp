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

#define M 104
int res[M][M];

int main () {
   bool swapped = 0;
   wez2(n,m)
   if (n < m) {
      swap(n,m);
      swapped = 1;
   }
   // n >= m
   if (n <= 3) {
      if (n == 3) {
         if (m == 1) {
            pisz(-1);
            return 0;
         } else if (m == 2) {
            res[0][0] = 3;
            res[0][1] = 6;
            res[0][2] = 2;
            res[1][0] = 5;
            res[1][1] = 1;
            res[1][2] = 4;
         } else {
            res[0][0] = 1;
            res[0][1] = 6;
            res[0][2] = 3;
            res[1][0] = 7;
            res[1][1] = 2;
            res[1][2] = 8;
            res[2][0] = 4;
            res[2][1] = 9;
            res[2][2] = 5;
         }
      } else {
         // m <= n <= 2
         if (m == n && m == 1) {
            pisz(1);
         } else {
            pisz(-1);
         }
         return 0;
      }
   } else {
      // zbuduj
      res[0][(n-1)/2] = 1;
      res[0][n-1] = 2;
      int k = 2, a = 0, b = (n-1)/2 + 1;
      while (k < n) {
         res[0][a++] = ++k;
         if (k == n) break;
         res[0][b++] = ++k;
      }
      
      FORI(i,m-1) FOR(j,n) res[i][j] = res[i-1][j] + n;
   }
   
   if (!swapped) {
      FOR(i,n) {
         FOR(j,m) printf("%d ",res[j][i]);
         printf("\n");
      }
   } else {
      FOR(i,m) {
         FOR(j,n) printf("%d ",res[i][j]);
         printf("\n");
      }
   }
}