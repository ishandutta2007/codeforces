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
int n, m, s, who[N], a[N], b[N], c[N];

struct comp {
   inline bool operator () (int i, int j) {
      if (c[i] != c[j]) return c[i] > c[j];
      return i > j;
   }
};

vector<pii> v;

bool can (int days) {
   priority_queue<int,vector<int>,comp> q;
   //q.reserve(n);
   int cost = 0, freebugs = 0, st = -1;
   FOREACH(it,v) {
      if (it->se < 0) {
         q.push(- it->se);
      } else {
         if (freebugs > 0) {
            --freebugs;
            who[it->se] = st;
         } else {
            if (q.empty()) return 0;
            st = q.top(); q.pop();
            cost += c[st];
            if (cost > s) return 0;
            freebugs = days - 1;
            who[it->se] = st;
         }
      }
   }
   return 1;
}

int main () {
   scanf("%d %d %d", &n, &m, &s);
   FORI(i,m) scanf("%d", a+i);
   FORI(i,n) scanf("%d", b+i);
   FORI(i,n) scanf("%d", c+i);
   
   FORI(i,m) v.pb(mp(-a[i], i));
   FORI(i,n) v.pb(mp(-b[i],-i));
   sort(ALL(v));
   
   int from = 1, to = 100000, best = INF;
   while (from <= to) {
      int mid = (from + to) / 2;
      if (can(mid)) {
          best = mid;
          to = mid - 1;
      } else {
         from = mid + 1;
      }
   }
   if (best == INF) {
      printf("NO");
   } else {
      printf("YES\n");
      can(best);
      FORI(i,m) {
         printf("%d ", who[i]);
      }
   }
}