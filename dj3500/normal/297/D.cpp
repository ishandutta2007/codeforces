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
#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

#define N 2005
int t[N][N], temp[N][N];

int main () {
   wez3(h,w,k)
   int all = 0, satisfied = 0;
   FOR(i,2*h-1) {
      char s[N];
      scanf("%s", s);
      if (1&i) {
         // dlugi
         FOR(j,w) t[i][2*j] = s[j];
         all += w;
         FOR(j,w) if ('E' == s[j]) ++satisfied;
      } else {
         // krotki
         FOR(j,w-1) t[i][2*j+1] = s[j];
         all += w-1;
         FOR(j,w-1) if ('E' == s[j]) ++satisfied;
      }
   }
   
   if (k == 1) {
      if (4*satisfied >= 3*all) {
         printf("YES\n");
         FOR(i,h) {
            FOR(j,w) printf("%d ", 1);
            printf("\n");
         }
      } else {
         printf("NO\n");
      }
      return 0;
   }
     
   bool flipped = 0;
   if (w < h) {
      flipped = 1;
      FOR(i,2*h-1) FOR(j,2*w-1) temp[i][j] = t[i][j];
      FOR(i,2*h-1) FOR(j,2*w-1) t[j][i] = temp[i][j];
      swap(w,h);
   }
   
   
   FOR(i,h) {
      t[2*i][0] = 1;
      REP(j,1,w-1) {
         if (t[2*i][2*j-1] == 'E') t[2*i][2*j] = t[2*i][2*(j-1)];
         else t[2*i][2*j] = 3 - t[2*i][2*(j-1)];
      }
      
      if (i > 0) {
         int ok = 0; // all == w
         FOR(j,w) {
            if (t[2*i-1][2*j] == 'E') {
               if (t[2*i][2*j] == t[2*(i-1)][2*j]) ++ok;
            } else {
               if (t[2*i][2*j] != t[2*(i-1)][2*j]) ++ok;
            }
         }
         
         if (2*ok < w) {
            FOR(j,w) t[2*i][2*j] = 3 - t[2*i][2*j];
         }
      }
   }
   
   if (flipped) {
      FOR(i,2*h-1) FOR(j,2*w-1) temp[i][j] = t[i][j];
      FOR(i,2*h-1) FOR(j,2*w-1) t[j][i] = temp[i][j];
      swap(w,h);
   }
   
   printf("YES\n");
   FOR(i,h) {
      FOR(j,w) printf("%d ", t[2*i][2*j]);
      printf("\n");
   }
}