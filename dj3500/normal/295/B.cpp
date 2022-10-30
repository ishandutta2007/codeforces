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

#define N 605
int a[N][N], a1[N][N], dist[N][N], p[N];

int main () {
   wez(n)
   FORI(i,n) FORI(j,n) scanf("%d", &a1[i][j]);
   FORI(i,n) scanf("%d", p+i);
   FORI(i,n) FORI(j,n) a[i][j] = a1[p[n+1-i]][p[n+1-j]];
   vector<ll> res;
   
   FORI(v,n) {
      dist[v][v] = 0;
      FORI(w,v-1) {
         dist[v][w] = a[v][w];
         FORI(x,v-1) REMIN(dist[v][w], a[v][x] + dist[x][w]);
         dist[w][v] = a[w][v];
         FORI(x,v-1) REMIN(dist[w][v], dist[w][x] + a[x][v]);
      }
      
      FORI(i,v-1) FORI(j,v-1) if (i != j) {
         REMIN(dist[i][j], dist[i][v] + dist[v][j]);
      }
      
      ll r = 0;
      FORI(i,v) FORI(j,v) r += dist[i][j];
      res.pb(r);
   }
   
   reverse(ALL(res));
   FOREACH(x,res) printf("%I64d ", *x);
}