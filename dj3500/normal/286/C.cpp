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

#define N 1000007
int p[N], res[N];
vector<pii> st;
void zamknij (int k) {
   while (st.back().fi != k) {
      if (st.back().fi == INF) { printf("NO");exit(0);}
      res[st.back().se] = -st.back().fi;
      int kk = st.back().fi;
      st.pop_back();
      zamknij(kk);
   }
   res[st.back().se] = k;
   st.pop_back();
}

int main () {
   wez(n)
   FORI(i,n) scanf("%d", p+i);
   TESTS {
      wez(ind)
      p[ind] *= -1;
   }
   p[n+1] = -INF;
   st.pb(mp(INF,0));
   FORI(i,n+1) {
      if (p[i] > 0) {
         st.pb(mp(p[i],i));
      } else {
         res[i] = p[i];
         zamknij(-p[i]);
      }
   }
   printf("YES\n");
   FORI(i,n) printf("%d ", res[i]);
}