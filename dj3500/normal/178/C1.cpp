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
set<int> wolne[N];
int posInCycle[N], whichCycle[N];

int main () {
   wez2(h,m)

   int ktorycykl = 0, rozmiarCykli;
   vector<bool> vis(h+5,0);
   FOR(i,h) {
      if (vis[i]) continue;
      int v=i;
      vi cykl;
      do {
         cykl.pb(v);
         v = (m+v) % h;
         vis[v]=1;
      } while (v!=i);
      // zrobic teraz cos z cyklem
      FOR(u,SZ(cykl)) {
         whichCycle[cykl[u]] = ktorycykl;
         posInCycle[cykl[u]] = u;
         wolne[ktorycykl].insert(u);
      }
      ++ktorycykl;
      rozmiarCykli = SZ(cykl);
   }
   
   /*DBG(vi(whichCycle,whichCycle+h))
   DBG(vi(posInCycle,posInCycle+h))
   return 0;*/
   
   map<int,pii> position;
   ll res = 0;
   
   TESTS {
      char c;
      scanf(" %c", &c);
      if (c == '+') {
         wez2(id,hash)
         
         int desiredPosInCycle = posInCycle[hash], ktorycykl = whichCycle[hash];
         set<int> &wol = wolne[ktorycykl];
         set<int>::iterator it = wol.lower_bound(desiredPosInCycle);
         bool obrot = 0;
         if (it == wol.end()) {
            it = wol.begin();
            obrot = 1;
         }
         int posWCyklu = *it;
         wol.erase(it);
         position[id] = mp(ktorycykl,posWCyklu);
         res += (obrot ? rozmiarCykli - desiredPosInCycle + posWCyklu : posWCyklu - desiredPosInCycle);
      } else {
         wez(id)
         pii pos = position[id];
         wolne[pos.fi].insert(pos.se);
      }
   }
   cout << res << endl;
}