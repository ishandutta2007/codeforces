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
#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

/* // Program to precompute the nimbers, runs ~5 secs:
const int K = 29;
bool in[35];
int kroj[35];
char *nim;
set<int> policzone;

void policz (int mask) {
   if (policzone.count(mask)) return;
   vi nimbers;
   REP(k,1,K) {
      int newmask = mask & (~kroj[k]);
      if (newmask != mask) {
         //printf("%d -> %d\n", mask, newmask);
         policz(newmask);
         nimbers.pb(nim[newmask]);
      }
   }
   
   FOREACH(x,nimbers) in[*x] = 1;
   
   nim[mask] = 0;
   while (in[nim[mask]]) ++nim[mask];
   
   FOREACH(x,nimbers) in[*x] = 0;   
   policzone.insert(mask);
}

int main () {
   REP(k,1,K) {
      for (int j = k; j <= K; j += k) kroj[k] |= 1 << (j-1);
   }
   
   nim = new char [1 << K];
   nim[0] = 0;
   
   REP(k,1,K) {
       policz((1 << k) - 1);
       printf("%d, ", nim[(1 << k) - 1]);
   }
}
*/

int nimber[] = {0, 1, 2, 1, 4, 3, 2, 1, 5, 6, 2, 1, 8, 7, 5, 9, 8, 7, 3, 4, 7, 4, 2, 1, 10, 9, 3, 6, 11, 12};

bool ispower[1000000];

int main () {
   wez(n)
   int xo = 0; // za 1
   int nonpowers = n;
   for (int i = 2; i*i <= n; ++i) {
      if (!ispower[i]) {
         int cnt = 0;
         for (ll x = i; x <= n; x *= i) {
            ++cnt;
            --nonpowers;
            if (x * x <= n) ispower[x] = 1;
         }
         //DBG(i)
         //DBG(cnt)
         xo ^= nimber[cnt];
      }
   }
   //DBG(nonpowers)
   if (nonpowers & 1) xo ^= nimber[1];
   
   printf((xo == 0) ? "Petya" : "Vasya");
}