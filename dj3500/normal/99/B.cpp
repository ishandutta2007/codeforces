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
template<typename T> ostream& operator<<(ostream &s,vector<T> t){FOR(i,t.size())s<<t[i]<<" ";return s; }
#define IN(x,y) ((y).find((x))!=(y).end())
#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));

int a[1004];

int main () {
   wez(n)
   FOR(i,n) scanf("%d",a+i);
   int suma=0;
   FOR(i,n) suma += a[i];
   if (suma % n != 0) {
      printf("Unrecoverable configuration.\n");
      return 0;
   }
   suma /= n;
   int rozn = 0;
   FOR(i,n) if (a[i] != suma) ++rozn;
   if (rozn == 0) {
      printf("Exemplary pages.\n");
      return 0;
   }
   if (rozn == 2) {
      int mn,w,ile;
      FOR(i,n) {
         if (a[i] > suma) {
            w = i;
            ile = a[i] - suma;
         } else if (a[i] < suma) mn = i;
      }
      printf("%d ml. from cup #%d to cup #%d.\n",ile,mn+1,w+1);
      return 0;
   }


      printf("Unrecoverable configuration.\n");
      return 0;

}