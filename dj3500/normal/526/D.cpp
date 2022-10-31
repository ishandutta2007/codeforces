// tested by Hightail: https://github.com/dj3500/hightail
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
#include <cassert>
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
#define DBG(vari) cout<<"["<<__LINE__<<"] "<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (__typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

const int N = 1000007;
int d[22][N], n, k;
int ceildiv (int a, int b) { return (a + b - 1) / b; }
string p;
vi kn;

int period (int a, int x) {
   REPD(i,20,0) if (x >= (1 << i)) {
      a = d[i][a];
      x -= 1 << i;
   }
   return a;
}

bool can (int a) {
   int to = a - ceildiv(a, k+1), from = a - a/k;
   //DBG(a) DBG(mp(from,to))
   if (from <= to) {
      int F = 0, T = a + 1;
      while (F <= T) {
         int M = (F + T) / 2;
         int pi = period(a, M);
         if (pi < from) {
            T = M - 1;
         } else if (to < pi) {
            F = M + 1;
         } else {
            return 1;
         }
      }
   }
   return 0;
}

int main () {
   scanf("%d %d", &n, &k);
   cin >> p;
   kn.assign(SZ(p)+1,-1); // funkcja prefiksowa Knutha
   FORI(i,SZ(p)) {
      int j = kn[i-1];
      while (j != -1 && p[j] != p[i-1]) j=kn[j];
      kn[i] = j+1;
   }
   //DBG(kn)
   kn[0] = 0;
   FORI(i,n) d[0][i] = kn[i];
   REP(l,1,20) FORI(i,n) d[l][i] = d[l-1][d[l-1][i]];
   FORI(a,n) {
      printf("%d", int(can(a)));
   }
}