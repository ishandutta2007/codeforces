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

#define M 200006
int a[M];
int val[M];
char plec[M];

set<int> dance;

void recalcval (int i) {
   set<int>::iterator it = dance.upper_bound(i);
   if (it == dance.end()) {
      val[i] = INF;
      return;
   }
   int k = *it;
   val[i] = (plec[k] == plec[i]) ? INF : abs(a[i] - a[k]);
}

int main () {
   wez(n)
   scanf("%s",plec);
   FOR(i,n) scanf("%d",a+i);
   
   FOR(i,n) dance.insert(i);
   
   vector<pii> res;
   
   FOR(i,n) recalcval(i);
   set<pii> st;
   FOR(i,n) st.insert(mp(val[i],i));
   while (!st.empty()) {
      if (st.begin()->fi == INF) break;
      int i = st.begin()->se;
      int k = *dance.upper_bound(i);
      
      int rest = -1;
      set<int>::iterator it = dance.find(i);
      if (it != dance.begin()) {
         --it;
         rest = *it;
      }
      
      st.erase(mp(val[i],i));
      st.erase(mp(val[k],k));
      dance.erase(i);
      dance.erase(k);
      if (rest != -1) {
         st.erase(mp(val[rest],rest));
         recalcval(rest);
         st.insert(mp(val[rest],rest));
      }
      res.pb(mp(i,k));
   }
   
   pisz(SZ(res));
   //FOR(i,SZ(res)) printf("%d %d\n",min(res[i].fi,res[i].se),max(res[i].fi,res[i].se));
   FOR(i,SZ(res)) printf("%d %d\n",res[i].fi + 1,res[i].se + 1);
}