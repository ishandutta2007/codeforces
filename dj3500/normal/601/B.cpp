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

const int N = 100100;
int _a[N], a[N], b[N], d[N];

int main () {
   wez2(n,q)
   FORI(i,n) scanf("%d", _a + i);
   FORI(i,n-1) d[i] = abs(_a[i] - _a[i+1]);
   set<int> s = {0, n};
   vector<pii> sorter;
   FORI(i,n-1) sorter.pb(mp(d[i], i));
   sort(sorter.rbegin(), sorter.rend());
   for (const pii & p : sorter) {
      set<int>::iterator it = s.insert(p.se).fi;
      ++it;
      b[p.se] = *it;
      --it;
      --it;
      a[p.se] = *it;
   }
   while (q--) {
      wez2(l,r);
      --r;
      ll res = 0;
      REP(i,l,r) {
         int A = max(l, a[i] + 1), B = min(r, b[i] - 1);
         res += 1LL * d[i] * (i-A+1) * (B-i+1);
      }
      cout << res << '\n';
   }
}