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

#define N 105
int a[N];

int main () {
   wez(n)
   FOR(i,n) scanf("%d", a+i);
   bool has100 = 0;
   int zer = 0;
   int jednocyfrowa = -1, dziesiatka = -1, inna = -1;
   FOR(i,n) {
      if (a[i] == 0) ++zer;
      else if (a[i] >= 1 && a[i] <= 9) jednocyfrowa = a[i];
      else if (a[i] == 100) has100 = 1;
      else if (a[i] % 10 == 0) dziesiatka = a[i];
      else inna = a[i];
   }
   vi res;
   while (zer--) res.pb(0);
   if (has100) res.pb(100);
   if (jednocyfrowa != -1) {
      res.pb(jednocyfrowa);
   }
   if (dziesiatka != -1) {
      res.pb(dziesiatka);
   }
   if (jednocyfrowa == -1 && dziesiatka == -1 && inna != -1) res.pb(inna);
   pisz(SZ(res));
   FOREACH(x,res) printf("%d ", *x);
}