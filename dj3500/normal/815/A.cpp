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

const int N = 667;
int s[N][N];

int main () {
   wez2(n,m);
   FORI(i,n) FORI(j,m) scanf("%d", &s[i][j]);
   vector<pair<string,int>> res;
   if (n > m) {
      FORI(j,m) {
         int mi = s[1][j];
         FORI(i,n) REMIN(mi, s[i][j]);
         FOR(u,mi) res.pb(mp("col", j));
         FORI(i,n) s[i][j] -= mi;
      }
      
      FORI(i,n) {
         FORI(j,m) if (s[i][1] != s[i][j]) {
            pisz(-1);
            return 0;
         }
         FOR(u,s[i][1]) res.pb(mp("row", i));
      }
   } else {
      FORI(i,n) {
         int mi = s[i][1];
         FORI(j,m) REMIN(mi, s[i][j]);
         FOR(u,mi) res.pb(mp("row", i));
         FORI(j,m) s[i][j] -= mi;
      }
      
      FORI(j,m) {
         FORI(i,n) if (s[1][j] != s[i][j]) {
            pisz(-1);
            return 0;
         }
         FOR(u,s[1][j]) res.pb(mp("col", j));
      }      
   }
   
   pisz(SZ(res));
   for (auto it : res) cout << it.fi << ' ' << it.se << '\n';
}