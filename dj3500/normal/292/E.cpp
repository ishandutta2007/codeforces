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

#define N 200007
int a[N], b[N], ty[N], x[N], y[N], k[N], ind[N], res[N], isset[N];

int main () {
   wez2(n,m)
   set<pii> st;
   FORI(i,n) scanf("%d", a+i);
   FORI(i,n) scanf("%d", b+i);
   FORI(i,n) isset[i] = 0;
   FORI(i,m) {
      scanf("%d", ty+i);
      if (ty[i] == 1) {
         scanf("%d %d %d", x+i, y+i, k+i);
      } else {
         scanf("%d", ind+i);
      }
   }
   REPD(i,m,1) {
      if (ty[i] == 1) {
         int l = y[i], r = y[i] + k[i] - 1;
         set<pii>::iterator it = st.lower_bound(mp(l,-1)), jt = it;
         while (jt != st.end() && jt->fi <= r) {
            res[jt->se] = a[jt->fi + x[i] - y[i]];
            isset[jt->se] = 1;
            ++jt;
         }
         st.erase(it,jt);
      } else {
         st.insert(mp(ind[i], i));
      }
   }
   FORI(i,m) if (ty[i] == 2 && !isset[i]) res[i] = b[ind[i]];
   FORI(i,m) if (ty[i] == 2) pisz(res[i]);
}