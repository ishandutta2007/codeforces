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
#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (__typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

int a[8][3];
ll d[9];
pair<ll,int> dd[9];
ll sq (int s) {
   return 1LL * s * s;
}
ll dist (int *b, int *c) {
   return sq(b[0] - c[0]) + sq(b[1] - c[1]) + sq(b[2] - c[2]);
}
struct pt {
   ll x,y,z;
   pt (int* g) : x(g[0]), y(g[1]), z(g[2]) {}
   pt(ll X=0,ll Y=0,ll Z=0) : x(X), y(Y), z(Z) {}
};
pt operator + (pt X, pt Y) {
   return pt(X.x + Y.x, X.y + Y.y, X.z + Y.z);
}
pt operator - (pt X, pt Y) {
   return pt(X.x - Y.x, X.y - Y.y, X.z - Y.z);
}
bool operator <(pt a,pt b){
  if (a.x-b.x) return a.x<b.x;
  if (a.y-b.y) return a.y<b.y;
  return a.z<b.z;
}
bool operator == (pt a, pt b) {
   return a.x == b.x && a.y == b.y && a.z == b.z;
}

bool check (int A, int B, int C, int E, int F, int G, int D) {
   pt AA(a[A]), BB(a[B]), CC(a[C]), DD(a[D]), EE(a[E]), FF(a[F]), GG(a[G]);
   pt ZERO(a[0]);
   pt v1 = AA - ZERO, v2 = BB - ZERO, v3 = CC - ZERO;
   if (!(DD == ZERO + v1 + v2 + v3)) return 0;
   vector<pt> jeden = {EE, FF, GG}, drugi = {ZERO + v1 + v2, ZERO + v1 + v3, ZERO + v2 + v3};
   sort(ALL(jeden));
   sort(ALL(drugi));
   return jeden == drugi;
}

int main () {
   FOR(i,8) {
      scanf("%d %d %d", &a[i][0], &a[i][1], &a[i][2]);
      sort(a[i],a[i]+3);
   }
   do {
      do {
         do {
            do {
               do {
                  do {
                     do {
                        do {
                           REP(j,1,7) d[j] = dist(a[0], a[j]);
                           sort(d+1,d+8);
                           if (d[1] == 0) continue;
                           ll x = d[1];
                           if (d[2] != x) continue;
                           if (d[3] != x) continue;
                           if (d[4] != 2*x) continue;
                           if (d[5] != 2*x) continue;
                           if (d[6] != 2*x) continue;
                           if (d[7] != 3*x) continue;
                           
                           REP(j,1,7) dd[j] = mp(dist(a[0],a[j]),j);
                           sort(dd+1,dd+8);
                           int A = dd[1].se, B = dd[2].se, C = dd[3].se;
                           int D = dd[7].se;
                           int E = dd[4].se, F = dd[5].se, G = dd[6].se;
                           if (check(A,B,C,E,F,G,D)) {
                              printf("YES\n");
                              FOR(i,8) {
                                 printf("%d %d %d\n", a[i][0], a[i][1], a[i][2]);
                              }
                              return 0;
                           }
                        } while (next_permutation(a[7], a[7]+3));
                     } while (next_permutation(a[6], a[6]+3));
                  } while (next_permutation(a[5], a[5]+3));
               } while (next_permutation(a[4], a[4]+3));
            } while (next_permutation(a[3], a[3]+3));
         } while (next_permutation(a[2], a[2]+3));
      } while (next_permutation(a[1], a[1]+3));
   } while (next_permutation(a[0], a[0]+3));
   printf("NO");
}