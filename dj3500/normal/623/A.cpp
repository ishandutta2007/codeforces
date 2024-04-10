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

const int N = 1111;
bool c[N][N];
char res[N];

int main () {
   wez2(n,m)
   FOR(u,m) {
      wez2(a,b)
      c[a][b] = c[b][a] = 1;
   }
   int A = -1, C = -1;
   FORI(b,n) REP(a,1,b-1) if (!c[a][b]) {
      // a < b
      A = a;
      C = b;
      break;
   }
   if (A == -1) {
      // complete graph
      printf("Yes\n");
      FORI(i,n) printf("a");
   } else {
      FORI(i,n) res[i] = 'b';
      FORI(i,n) if (i != A) if (!c[A][i]) res[i] = 'c';
      FORI(i,n) if (i != C) if (!c[C][i]) res[i] = 'a';
      bool bad = 0;
      FORI(i,n) FORI(j,n) if (i != j) {
         if ((min(res[i], res[j]) == 'a' && max(res[i],res[j]) == 'c') != !c[i][j]) bad = 1;
      }
      if (bad) {
         printf("No");
      } else {
         printf("Yes\n");
         FORI(i,n) printf("%c", res[i]);
      }
   }
}