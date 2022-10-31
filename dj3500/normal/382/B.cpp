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
#define DBG(vari) cout<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

int a,b,w,x,c,cma;
ll res = 0;
void sim () {
   if (cma == 0) {
      cout << res;
      exit(0);
   }
   ++res;
   if (b >= x) {
      b -= x;
      --cma;
      if (cma == 0) {
         cout << res;
         exit(0);
      }
   } else {
      b = w - (x - b);
   }
}

int main () {
   cin >> a >> b >> w >> x >> c;
   cma = c-a;
   if (cma <= 0) {
      pisz(0);
      return 0;
   }
   
   int najpierw = b / x;
   if (najpierw >= cma) {
      pisz(cma);
      return 0;
   }
   cma -= najpierw;
   res += najpierw;
   b %= x;
   
   // b < x
   
   set<int> bb;
   int theB = -INF;
   while(1) {
      sim();
      if (bb.count(b)) {
         theB = b;
         break;
      } else bb.insert(b);
   }
   
   int cma1 = cma;
   ll res1 = res;
   do {
      sim();
   } while (b != theB);
   int cmadelta = cma1 - cma; // o ile spadla
   ll resdelta = res - res1;
   int tur = max(cma / cmadelta - 2, 0);
   //DBG(tur)
   res += resdelta * tur;
   cma -= cmadelta * tur;
   while(1) sim();
}