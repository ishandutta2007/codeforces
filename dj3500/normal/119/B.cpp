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

#define N 104
bool taken[N];
int a[N];

int main () {
   wez2(n,k)
   int th = n/k;
   FORI(i,n) scanf("%d",a+i);
   FORI(i,n) taken[i] = 0;
   int minsum = INF, maxsum = 0;
   set<vi> karty;
   TESTS {
      int sum = 0;
      vi akt;
      FOR(i,th) {
         wez(x)
         taken[x] = 1;
         sum += a[x];
         akt.pb(x);
      }
      REMIN(minsum,sum)
      REMAX(maxsum,sum)
      sort(ALL(akt));
      karty.insert(akt);
   }

   vi reszta;
   FORI(i,n) if (!taken[i]) reszta.pb(a[i]);
   sort(ALL(reszta));
   if (SZ(reszta) >= th && SZ(karty) < k) {
      int sum = 0;
      FOR(i,th) sum += reszta[i];
      REMIN(minsum,sum)

      sum = 0;
      FOR(i,th) sum += reszta[SZ(reszta) - 1 - i];
      REMAX(maxsum,sum)
   }

   cout << fixed << setprecision(11) << (double)minsum/th << " " << (double)maxsum/th << endl;
}