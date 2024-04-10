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
#define DBG(vari) cerr<<"["<<__LINE__<<"] "<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (__typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

vi toposort(int n, vi *adj) {
   vi ins(n+1,0), wyn;
   FORI(i,n) FOREACH(it,adj[i]) ++ins[*it];
   deque<int> q;
   FORI(i,n) if (ins[i] == 0) q.pb(i);
   while (!q.empty()) {
      int v = q.front();
      q.pop_front();
      FOREACH(it,adj[v]) if ((--ins[*it]) == 0) q.pb(*it);
      wyn.pb(v);
   }
   return SZ(wyn)==n ? wyn : vi();
}

vi adj[256];
string s[256];

int main () {
   int n;
   cin >> n;
   FOR(i,n) cin >> s[i];
   bool fail = 0;
   FOR(i,n-1) {
      bool diff = 0;
      FOR(j,min(SZ(s[i]),SZ(s[i+1]))) {
         if (s[i][j] != s[i+1][j]) {
            adj[s[i][j] - 'a' + 1].pb(s[i+1][j] - 'a' + 1);
            diff = 1;
            break;
         }
      }
      if (!diff && SZ(s[i]) > SZ(s[i+1])) fail = 1;
   }
   vi srt = toposort(26,adj);
   if (srt.empty() || fail) {
      cout << "Impossible";
   } else {
      FOREACH(it,srt) cout << char('a' + (*it) - 1);
   }
}