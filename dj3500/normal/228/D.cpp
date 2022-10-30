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
#define IOS ios_base::sync_with_stdio(0);


#define MAXN 100007
// value[n] += x
void add(ll *t, int n, ll x) { for (; n < MAXN; n |= n + 1) t[n] += x; }
// Returns value[0] + value[1] + ... + value[n]
ll sum(ll *t, int n) { ll s=0; while (n>=0) { s+=t[n]; n=(n&(n+1))-1; } return s; }

int a[MAXN];
ll tab[6][14][MAXN];

void dodaj (int ppi, ll diff) {
   REP(z,2,6) REP(k,0,2*z-3) {
      int pos = (ppi+1-k) % (2*z-2);
      if (pos < 0) pos += 2*z-2;
      int res;
      if (pos == 0) res = 2;
      else if (pos <= z) res = pos;
      else res = 2*z - pos;
      add(tab[z-2][k], ppi, diff * res);
   }
}

int main () {
   REP(z,2,6) REP(k,0,2*z-3) FOR(i,MAXN) tab[z-2][k][i] = 0;
   wez(n)
   FORI(i,n) {
      scanf("%d", a+i);
      dodaj(i, a[i]);
   }
   TESTS {
      wez(tp)
      if (tp == 1) {
         wez2(ppi,vvi);
         ll diff = vvi - a[ppi];
         a[ppi] = vvi;
         dodaj(ppi, diff);
      } else {
         wez3(l,r,z)
         ll sum1 = sum(tab[z-2][l % (2*z-2)], l-1);
         ll sum2 = sum(tab[z-2][l % (2*z-2)], r);
         printf("%I64d\n", sum2 - sum1);
      }
   }
}