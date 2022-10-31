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

const int N = 5005;
int c[N], d[N], parent[N];
vi ch[N];
int sz[N];

// custom inv!

int temp[N][N];
int tanio[N][N], drogo[N][N];

int main () {
   wez2(n,b);
   FORI(i,n) {
      scanf("%d %d", c+i, d+i);
      if (i > 1) {
         scanf("%d", parent+i);
         ch[parent[i]].pb(i);
      }
   }
   
   REPD(i,n,1) {
      sz[i] = 1;
      for (int x : ch[i]) sz[i] += sz[x];
   }
   
   REPD(i,n,1) {
      REP(j,0,sz[i]) tanio[i][j] = drogo[i][j] = INF;
      tanio[i][0] = 0;
      drogo[i][0] = 0;
      
      const vi &dz = ch[i];
      
      if (dz.empty()) {
         tanio[i][1] = c[i] - d[i];
         drogo[i][1] = c[i];
      } else {
         REP(j,0,sz[dz[0]]) temp[0][j] = tanio[dz[0]][j];
         int cursz = sz[dz[0]];
         REP(u,1,SZ(dz)-1) {
            // merge temp[u-1] of size cursz
            // with  tanio[dz[u]] of size sz[dz[u]]
            // into  temp[u]
            REP(j,0,cursz+sz[dz[u]]) temp[u][j] = INF;
            REP(j1,0,cursz) {
               REP(j2,0,sz[dz[u]]) {
                  REMIN(temp[u][j1+j2], temp[u-1][j1] + tanio[dz[u]][j2]);
               }
            }
            
            cursz += sz[dz[u]];
         }
         assert(cursz == sz[i] - 1);
         // now create tanio[i][*]
         REP(j,1,sz[i]) {
            tanio[i][j] = temp[SZ(dz)-1][j-1] + c[i] - d[i];
            REMIN(tanio[i][j], INF);
         }
         
         // same for drogo
         REP(j,0,sz[dz[0]]) temp[0][j] = drogo[dz[0]][j];
         cursz = sz[dz[0]];
         REP(u,1,SZ(dz)-1) {
            // merge temp[u-1] of size cursz
            // with  drogo[dz[u]] of size sz[dz[u]]
            // into  temp[u]
            REP(j,0,cursz+sz[dz[u]]) temp[u][j] = INF;
            REP(j1,0,cursz) {
               REP(j2,0,sz[dz[u]]) {
                  REMIN(temp[u][j1+j2], temp[u-1][j1] + drogo[dz[u]][j2]);
               }
            }
            
            cursz += sz[dz[u]];
         }
         assert(cursz == sz[i] - 1);
         // now create drogo[i][*]
         REP(j,1,sz[i]) {
            drogo[i][j] = temp[SZ(dz)-1][j-1] + c[i];
            if (j < sz[i]) REMIN(drogo[i][j], temp[SZ(dz)-1][j]);
            REMIN(drogo[i][j], INF);
         }
      }
      
      REP(j,0,sz[i]) REMIN(tanio[i][j], drogo[i][j]);
   }
   
   int res = 0;
   while (res+1 <= n && tanio[1][res+1] <= b) ++res;
   pisz(res);
   
   //DBG(vi(tanio[1], tanio[1] + n+1))
}