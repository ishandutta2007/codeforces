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
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
template<typename T> ostream& operator<<(ostream &s,set<T> t){FOREACH(i,t)s<<*i<<" ";return s; }
#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

vector<bool> sito (int m) { // m = max_inclusive
   vector<bool> pr(m+1,1);
   pr[0] = pr[1] = 0;
   for (int x = 2; x*x <= m; ++x) if (pr[x]) for (int y = x*x; y <= m; y += x) pr[y] = 0;
   return pr;
}

vi listaPierwszych (int m) { // m = max_inclusive
   vector<bool> pr = sito(m);
   vi ans;
   FORI(i,m) if (pr[i]) ans.pb(i);
   return ans;
}

int n, limit;
vi pr;
set<int> s;

void go (int k) {
   if (k > 2*n*n) return;
   if (s.count(k)) return;
   s.insert(k);
   REP(i,0,limit) go(k * pr[i]);
}

int main () {
   scanf("%d", &n);
   pr = listaPierwszych(1000);
   for (limit = 1; limit <= 100; ++limit) {
      s.clear();
      go(1);
      if (SZ(s) >= n) {
         while (SZ(s) > n) s.erase(s.begin());
         break;
      }
   }
   
   //DBG(s)
   
   /*bool ok = 1;
   FOREACH(p,pr) {
      int cnt = 0;
      FOREACH(it,s) if (*it % *p == 0) ++cnt;
      if (cnt == 0) break;
      if (cnt > 0 && cnt*2 < n) { ok = 0; break; }
   }
   return ok;
}

int main () {
   bool allok = 1;
   for (n = 10; n <= 5000; ++n) {
      DBG(n)
      bool ok = isok();
      allok = allok && ok;
      //DBG(ok)
   }
   DBG(allok)
}
*/
   FOREACH(x,s) printf("%d ", *x);
   }