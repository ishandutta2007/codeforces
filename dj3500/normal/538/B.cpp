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

const int N = 1000007;
int parent[N], dist[N];

int main () {
   set<int> st = {1000000};
   FOR(a0,2) FOR(a1,2) FOR(a2,2) FOR(a3,2) FOR(a4,2) FOR(a5,2) {
      st.insert(a0 + 10 * a1 + 100 * a2 + 1000 * a3 + 10000 * a4 + 100000 * a5);
   }
   st.erase(0);
   
   REP(x,0,1000000) dist[x] = -1;
   deque<int> q;
   q.pb(0);
   dist[0] = 0;
   while (!q.empty()) {
      int v = q.front();
      q.pop_front();
      FOREACH(it,st) {
         int w = v + *it;
         if (w <= 1000000) {
            if (dist[w] == -1) {
               dist[w] = dist[v] + 1;
               parent[w] = v;
               q.pb(w);
            }
         }
      }
   }
   
   wez(n)
   pisz(dist[n]);
   while (n > 0) {
      printf("%d ", n - parent[n]);
      n = parent[n];
   }
}