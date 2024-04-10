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

#define N 128
bool isfavorite[N];
char name[N];
int fav[N], unknown[N], nonfav[N], minfav[N], maxfav[N], realfav[N];

int main () {
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   wez2(m,k)
   FORI(i,m) isfavorite[i] = 0;
   FOR(i,k) {
      wez(x)
      isfavorite[x] = 1;
   }
   wez(n)
   FOR(i,n) {
      scanf("%s", name);
      wez(di)
      fav[i] = unknown[i] = nonfav[i] = 0;
      FOR(u,di) {
         wez(x)
         if (x == 0) ++unknown[i];
         else if (isfavorite[x]) ++fav[i];
         else ++nonfav[i];
      }
      
      int maxaddfavs = min(unknown[i], k - fav[i]), maxaddnonfavs = min(m-k - nonfav[i], unknown[i]);
      maxfav[i] = fav[i] + maxaddfavs;
      minfav[i] = di - (nonfav[i] + maxaddnonfavs);
      //DBG(minfav[i])
      //DBG(maxfav[i])
   }
   
   FOR(i,n) {
      bool canwin = 1, canlose = 0;
      
      FOR(j,n) {
         if (i == j) realfav[i] = maxfav[i];
         else realfav[j] = minfav[j];
      }
      FOR(j,n) if (realfav[j] > realfav[i]) canwin = 0;
      
      FOR(j,n) {
         if (i == j) realfav[i] = minfav[i];
         else realfav[j] = maxfav[j];
      }
      FOR(j,n) if (realfav[j] > realfav[i]) canlose = 1;
      
      if (canwin && !canlose) pisz(0);
      else if (!canwin && canlose) pisz(1);
      else if (canwin && canlose) pisz(2);
      else DBG("FAIL");
   }
}