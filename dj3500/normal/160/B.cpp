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

bool go (vi &v, vi &w) {
   vi lessthan(10,0);
   REP(i,1,9) {
      REP(j,0,i-1) lessthan[i] += w[j];
   }
   // lessthan[0] >= v[0]
   // lessthan[1] >= v[1] + v[0]
   // lessthan[2] >= v[2] + v[1] + v[0]
   REP(i,0,9) {
      int vv = 0;
      REP(j,0,i) vv += v[j];
      if (lessthan[i] < vv) return 0;
   }
   return 1;
}

int main () {
   wez(n)
   char s[300];
   scanf("%s",s);
   vi cnt(10,0), cnt2(10,0);
   FOR(i,n) cnt[s[i]-'0']++;
   FOR(i,n) cnt2[s[i+n]-'0']++;
   printf(go(cnt,cnt2) || go(cnt2,cnt) ? "YES\n" : "NO\n");
}