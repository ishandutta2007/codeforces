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

#define N 400007
int a[N], b[N], cnt[N], mabyc[N];

int main () {
   wez3(n,m,p)
   FORI(i,n) scanf("%d", a+i);
   FORI(i,m) scanf("%d", b+i);
   vi sorter;
   FORI(i,n) sorter.pb(a[i]);
   FORI(i,m) sorter.pb(b[i]);
   sort(ALL(sorter));
   sorter.erase(unique(ALL(sorter)), sorter.end());
   FORI(i,n) a[i] = lower_bound(ALL(sorter), a[i]) - sorter.begin();
   FORI(i,m) b[i] = lower_bound(ALL(sorter), b[i]) - sorter.begin();
   int chce = 0;
   FORI(i,m) {
      if (0 == mabyc[b[i]]) ++chce;
      mabyc[b[i]]++;
   }
   vi res;
   FORI(of,p) {
      if (of + 1LL * (m-1) * p <= n) {
         vi used;
         int dobro = 0;
         FOR(i,m) {
            int j = of + i * p;
            if (mabyc[a[j]] == cnt[a[j]]) --dobro;
            cnt[a[j]]++;
            used.pb(a[j]);
            if (mabyc[a[j]] == cnt[a[j]]) ++dobro;
         }
         if (dobro == chce) res.pb(of);
         
         for (int q = of + p; q + 1LL * (m-1) * p <= n; q += p) {
            int j = q - p;
            if (mabyc[a[j]] == cnt[a[j]]) --dobro;
            cnt[a[j]]--;
            if (mabyc[a[j]] == cnt[a[j]]) ++dobro;
            j = q + (m-1) * p;
            if (mabyc[a[j]] == cnt[a[j]]) --dobro;
            cnt[a[j]]++;
            used.pb(a[j]);
            if (mabyc[a[j]] == cnt[a[j]]) ++dobro;
            if (chce == dobro) res.pb(q);
         }
         
         FOREACH(x,used) cnt[*x] = 0;
      }
   }
   sort(ALL(res));
   pisz(SZ(res));
   FOREACH(x,res) printf("%d ", *x);
}