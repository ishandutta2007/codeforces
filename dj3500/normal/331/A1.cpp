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
#define FOREACH(i,t) for (__typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

#define N 300007
int a[N];
ll pref[N];

int main () {
   wez(n)
   map<int,vi> mapa;
   pref[0] = 0;
   FORI(i,n) {
      scanf("%d", a+i);
      pref[i] = pref[i-1] + max(0,a[i]);
      mapa[a[i]].pb(i);
   }
   ll best = -2*INF;
   FOREACH(it,mapa) if (SZ(it->se) >= 2) {
      int pos1 = it->se[0], pos2 = it->se.back();
      ll cand = 2 * it->fi + pref[pos2-1] - pref[pos1];
      REMAX(best, cand);
   }
   FOREACH(it,mapa) if (SZ(it->se) >= 2) {
      int pos1 = it->se[0], pos2 = it->se.back();
      ll cand = 2 * it->fi + pref[pos2-1] - pref[pos1];
      if (best == cand) {
         vi cut;
         REP(k,1,pos1-1) cut.pb(k);
         REP(k,pos1 + 1, pos2 - 1) if (a[k] < 0) cut.pb(k);
         REP(k,pos2+1,n) cut.pb(k);
         printf("%I64d %d\n", best, SZ(cut));
         FOREACH(x,cut) printf("%d ", *x);
         return 0;
      }
   }
}