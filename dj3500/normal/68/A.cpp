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
using namespace std;
#define pb push_back
#define INF (int)1e9
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define FORI(i,n) for(int (i)=1;(i)<=(n);++(i))
#define mp make_pair
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define sz size()
#define fi first
#define se second
#define wez(n) int (n); scanf("%d",&(n));
#define wez2(n,m) int (n),(m); scanf("%d %d",&(n),&(m));
#define wez3(n,m,k) int (n),(m),(k); scanf("%d %d %d",&(n),&(m),&(k));
inline void pisz(int n) { printf("%d\n",n); }
template<typename T,typename TT> ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &s,vector<T> t){FOR(i,t.size())s<<t[i]<<" ";return s; }
#define IN(x,y) ((y).find((x))!=(y).end()) 
#define DBG(vari) cout<<#vari<<" = "<<vari<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(t)while(t--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)

int p[5];

inline int f(int x, int p1, int p2, int p3, int p4) {
   return ((((x%p1)%p2)%p3)%p4);
}

int main () {
   wez3(p1,p2,p3)wez3(p4,a,b)
   p[1]=p1;
   p[2]=p2;
   p[3]=p3;
   p[4]=p4;
   vi u;
   u.pb(1);
   u.pb(2);
   u.pb(3);
   u.pb(4);
   vector<vi> v;
   FOR(i,24) {
      v.pb(u);
      next_permutation(u.begin(),u.end());
   }
   int w=0;
   for (int x = a; x <= b; ++x) {
      int ile=0;
      FOR(i,24) {
         if (f(x,p[v[i][0]],p[v[i][1]],p[v[i][2]],p[v[i][3]]) == x) ++ile;
      }
      if (ile>=7) ++w;
   }
   pisz(w);  
}