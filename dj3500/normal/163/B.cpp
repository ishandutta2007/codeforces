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

#define N 100007
int temp1[N],temp2[N], v[N], num[N];
#define real long double
int k, n;
bool select (real t, bool go = 0) {
   int ktory = k;
   vi res;
   REPD(i,n-1,0) {
      if (ktory <= t * v[i]) {
         ktory--;
         if (go) res.pb(num[i]);
         if (ktory == 0) {
            if (go) {
               REPD(j,SZ(res)-1,0) printf("%d ",res[j]);
            }
            return 1;
         }
      }
   }
   return 0;
}

int main () {
   wez3(nn,kk,syf)
   n = nn;
   k = kk;
   FOR(i,n) scanf("%d",temp1+i);
   FOR(i,n) scanf("%d",temp2+i);
   vector<pair<pii,int> > vec;
   FOR(i,n) vec.pb(mp(mp(temp1[i],temp2[i]),i+1));
   sort(ALL(vec));
   FOR(i,n) {
      num[i] = vec[i].se;
      v[i] = vec[i].fi.se;
   }
   real best = 100000, from = 0, to = best;
   FOR(u,80) {
      real teraz = (from+to)/2;
      bool mozna = select(teraz);
      if (mozna) {
         REMIN(best,teraz);
         to = teraz;
      } else {
         from = teraz;
      }
   }
   select(best,1);
}