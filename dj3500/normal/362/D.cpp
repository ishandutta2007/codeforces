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

#define N 100007
int tab[N];
int find (int a) { return tab[a] == a ? a : tab[a] = find(tab[a]); }
void unia (int a, int b) { a = find(a), b = find(b); tab[a] = b; }

ll len[N];
vi sz[N];

int main () {
   wez2(n,m)
   wez2(p,q)
   vector<pair<pii,int> > v;
   FORI(i,n) tab[i] = i;
   FOR(i,m) {
      wez3(x,y,l)
      v.pb(mp(mp(x,y),l));
      unia(x,y);
   }
   FOREACH(it,v) {
      len[find(it->fi.fi)] += it->se;
   }
   int k = 0;
   FORI(i,n) if (i == find(i)) ++k;
   if (k < q || k-p > q || (k == n && q == n && p > 0)) { printf("NO"); return 0; }
   printf("YES\n");
   
   pii podwojny;
   FORI(i,n) sz[find(i)].pb(i);
   FORI(i,n) if (SZ(sz[i]) >= 2) podwojny = mp(sz[i][0], sz[i][1]);
   
   set<pair<ll,int> > st;
   FORI(i,n) if (i == find(i)) st.insert(mp(len[i], i));
   FOR(u,k-q) {
      set<pair<ll,int> >::iterator it, jt;
      it = st.begin();
      jt = it;
      ++jt;
      printf("%d %d\n", it->se, jt->se);
      int repr = it->se;
      ll nowy = it->fi + jt->fi + min(1000000000LL, 1 + it->fi + jt->fi);
      podwojny = mp(it->se, jt->se);
      st.erase(it);
      st.erase(jt);
      st.insert(mp(nowy,repr));
   }
   FOR(u,p-(k-q)) {
      printf("%d %d\n", podwojny.fi, podwojny.se);
   }
}