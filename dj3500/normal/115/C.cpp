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

inline bool compat (int a, int b) {
   if (a == 2 && b == 1) return false;
   if (a == 1 && b == 2) return false;
   return true;
}

bool proba (const vi &v, int teraz) {
   FOR(i,SZ(v)) {
      teraz = 3-teraz;
      if (!compat(v[i],teraz)) return 0;
   }
   return 1;
}

int probuj (const vi &s) {
   return proba(s,1) + proba(s,2);
}

int main () {
   ios_base::sync_with_stdio(0);
   const int mod = 1000003;
   vector<string> s;
   int n,m;
   cin >> n >> m;
   FOR(i,n) {
      s.pb("");
      cin >> s.back();
   }
   ll w = 1;
   FOR(i,n) {
      vi v;
      FOR(j,m) {
         if (s[i][j] == '1' || s[i][j] == '2') v.pb(1);
         else if (s[i][j] == '3' || s[i][j] == '4') v.pb(2);
         else v.pb(0);
      }
      w = (w * probuj(v)) % mod;
   }
   FOR(j,m) {
      vi v;
      FOR(i,n) {
         if (s[i][j] == '1' || s[i][j] == '4') v.pb(1);
         else if (s[i][j] == '2' || s[i][j] == '3') v.pb(2);
         else v.pb(0);
      }
      w = (w * probuj(v)) % mod;
   }
   pisz(w);
}