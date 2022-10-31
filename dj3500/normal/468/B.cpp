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
#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (__typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

#define N 100007
int res[N];
int n,a,b;
map<int,int> m;


int main () {
   scanf("%d %d %d", &n, &a, &b);
   FORI(i,n) {
      wez(pi)
      m[pi] = i;
   }
   if (a == b) {
      FOREACH(it,m) if (!m.count(a - it->fi)) { printf("NO"); return 0; }
      printf("YES\n");
      FORI(i,n) printf("0 ");
   } else {
      while (!m.empty()) {
         int v = m.begin()->fi;
         bool nowA = 1;
         while (m.count(a-v) && m.count(b-v)) {
            if (nowA) v = a-v;
            else v = b-v;
            nowA = !nowA;
         }
         while (m.count(v)) {
            if (!m.count(a-v) && !m.count(b-v)) { printf("NO"); return 0; }
            // v ma co najwyzej jednego sasiada
            if (v == a-v) {
               res[m[v]] = 0; m.erase(v);
               break;
            }
            if (v == b-v) {
               res[m[v]] = 1; m.erase(v);
               break;
            }
            if (m.count(a-v)) {
               res[m[v]] = 0; m.erase(v);
               v = a-v;
               res[m[v]] = 0; m.erase(v);
               v = b-v;
            } else {
               // m.count(b-v)
               res[m[v]] = 1; m.erase(v);
               v = b-v;
               res[m[v]] = 1; m.erase(v);
               v = a-v;
            }
         }
      }
      printf("YES\n");
      FORI(i,n) printf("%d ", res[i]);
   }
}