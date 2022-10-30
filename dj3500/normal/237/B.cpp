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

#define N 64
pii cell[N*N];
int x[N][N], c[N];

int main () {
   wez(n)
   FORI(i,n) scanf("%d", c+i);
   int s = 0;
   FORI(i,n) {
      s += c[i];
      FORI(j,c[i]) {
         scanf("%d", &x[i][j]);
         cell[x[i][j]] = mp(i,j);
      }
   }
   vector<pair<pii,pii> > res;
   int k = s;
   REPD(i,n,1) {
      REPD(j,c[i],1) {
         if (cell[k] != mp(i,j)) {
            res.pb(mp(cell[k], mp(i,j)));
            pii p = cell[k];
            int zaw = x[i][j];
            x[p.fi][p.se] = zaw;
            x[i][j] = k;
            cell[k] = mp(i,j);
            cell[zaw] = p;
         }
         k--;
      }
   }
   pisz(SZ(res));
   FOREACH(i,res) {
      printf("%d %d %d %d\n", i->fi.fi, i->fi.se, i->se.fi, i->se.se);
   }
}