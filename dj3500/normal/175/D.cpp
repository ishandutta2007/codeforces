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

int ktostrzela[64];
int events = 0, vhp, vdt, vl, vr, vp, ehp, edt, el, er, ep, p[2], l[2], r[2];
double dp[256][256][64], sum1[256][256][64], sum2[256][256][64];

inline void compute (int vh, int eh, int u, double &constant, double &q) {
   int k = ktostrzela[u];
   q = p[k] / 100.0;
   
   int next = u+1;
   if (next == events) next = 0;
   
   double res;
   if (k == 0) {
      //DBG(eh)DBG(l[k])DBG(r[k])
      if (eh - l[k] <= 0) {
         res = 1;
      } else if (eh - r[k] <= 0) {
         res = r[k] - eh + 1;
         res += sum2[vh][eh-l[k]][next];
         res /= r[k]-l[k]+1;
      } else {
         res = sum2[vh][eh-l[k]][next] - sum2[vh][eh-r[k]-1][next];
         //DBG(sum2[vh][eh-l[k]][next])
         //DBG(sum2[vh][eh-r[k]-1][next])
         res /= r[k]-l[k]+1;
      }
   } else {
      if (vh - l[k] <= 0) {
         res = 0;
      } else if (vh - r[k] <= 0) {
         res = sum1[vh-l[k]][eh][next];
         res /= r[k]-l[k]+1;
      } else {
         res = sum1[vh-l[k]][eh][next] - sum1[vh-r[k]-1][eh][next];
         res /= r[k]-l[k]+1;
      }
   }
   
   constant = res * (1 - q);
}

int main () {
   scanf("%d %d %d %d %d %d %d %d %d %d", &vhp, &vdt, &vl, &vr, &vp, &ehp, &edt, &el, &er, &ep);
   p[0] = vp;
   p[1] = ep;
   l[0] = vl;
   l[1] = el;
   r[0] = vr;
   r[1] = er;
   if (vp == 100 && ep == 100) {
      printf("0.000000\n"); // infinite battle
   } else if (vp == 100) {
      printf("0.000000\n"); // vasya dies eventually
   } else if (ep == 100) {
      printf("1.000000\n"); // enemy dies eventually
   } else {
      
      // przygotowanie eventw
      vector<bool> vasyastrzela(1000,0), enemystrzela(1000,0);
      FOR(i,edt) vasyastrzela[i*vdt] = 1;
      FOR(j,vdt) enemystrzela[j*edt] = 1;
      FOR(h,1000) {
         if (vasyastrzela[h]) {
            ktostrzela[events] = 0;
            events++;
         }
         if (enemystrzela[h]) {
            ktostrzela[events] = 1;
            events++;
         }
      }
      
      
      FOR(a,256) FOR(b,64) sum1[0][a][b] = sum2[a][0][b] = 0;
      
      REP(vh,1,vhp) {
         REP(eh,1,ehp) {
            //DBG(mp(vh,eh))
            double constant[64], q[64];
            FOR(u,events) compute(vh,eh,u,constant[u],q[u]);
            double wholeQ = 1;
            FOR(u,events) wholeQ *= q[u];
            //DBG(wholeQ)
            double val = 0;
            REPD(u,events-1,0) val = val * q[u] + constant[u];
            //DBG(val)
            dp[vh][eh][0] = val / (1.0 - wholeQ);
            REPD(u,events-1,1) {
               int next = u+1;
               if (next == events) next = 0;
               dp[vh][eh][u] = constant[u] + q[u] * dp[vh][eh][next];
            }
            
            // uaktualnic jeszcze sum1 i sum2
            FOR(u,events) {
               sum1[vh][eh][u] = sum1[vh-1][eh][u] + dp[vh][eh][u];
               sum2[vh][eh][u] = sum2[vh][eh-1][u] + dp[vh][eh][u];
            }
            
            //DBG(vector<double>(constant,constant+events))
            //DBG(vector<double>(q,q+events))
            //DBG(vector<double>(dp[vh][eh], dp[vh][eh]+events))
         }
      }
      
      
      
      printf("%.8lf\n", dp[vhp][ehp][0]);      
   }
}