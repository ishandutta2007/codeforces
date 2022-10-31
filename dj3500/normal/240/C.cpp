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

void freop() {
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
}

vector<vi> matches[1024];

int main () {
   freop();
   // matches[1] empty
   matches[2].pb(vi(1,1));
   REP(n,3,1000) {
      int a = n - n/2, b = n/2;
      vi firstgame;
      FORI(i,a) firstgame.pb(i);
      matches[n].pb(firstgame);
      FOR(k,SZ(matches[a])) {
         vi thismatch = matches[a][k];
         if (k < SZ(matches[b])) FOREACH(player, matches[b][k]) {
            thismatch.pb(*player + a);
         }
         matches[n].pb(thismatch);
      }
   }
   wez(n)
   pisz(SZ(matches[n]));
   FOREACH(ma,matches[n]) {
      printf("%d ", SZ(*ma));
      FOREACH(pl,(*ma)) {
         printf("%d ", *pl);
      }
      printf("\n");
   }
}