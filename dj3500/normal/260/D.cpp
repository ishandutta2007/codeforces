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

#define N 100007
int s[N];
bool conn[N];

int main () {
   wez(n)
   vi v[2];
   int any[2];
   FORI(i,n) {
      int ci;
      scanf("%d %d", &ci, s+i);
      v[ci].pb(i);
      any[ci] = i;
      conn[i] = 0;
   }
   //conn[v[0].back()] = 1;
   
   int k = 0;
   while(1) {
      if (v[k].empty() || v[1-k].empty()) break;
      int a = v[k].back();
      while (1) {
         int b = v[1-k].back();
         if (s[a] > s[b]) {
            s[a] -= s[b];
            printf("%d %d %d\n", a, b, s[b]);
            conn[a] = conn[b] = 1;
            v[1-k].pop_back();
         } else if (s[a] < s[b]) {
            s[b] -= s[a];
            printf("%d %d %d\n", a, b, s[a]);
            v[k].pop_back();
            conn[a] = conn[b] = 1;
            k = 1-k;
            break;
         } else { // ==
            printf("%d %d %d\n", a, b, s[a]);
            v[k].pop_back();
            v[1-k].pop_back();
            conn[a] = conn[b] = 1;
            if (!v[k].empty()) {
               printf("%d %d 0\n", b, v[k].back());
               conn[v[k].back()] = 1;
            }
            break;
         }
      }
   }
   FOR(k,2) FOREACH(x,v[k]) if (!conn[*x]) {
      printf("%d %d 0\n", *x, any[1-k]);
   }
}