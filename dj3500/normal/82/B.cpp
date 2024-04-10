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
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));

bool used[204];
set<int> s[20006];

int main () {
   wez(n)
   int k = n*(n-1)/2;
   FOR(i,k) {
      TESTS {
         wez(x)
         used[x]=1;
         s[i].insert(x);
      }
   }
   
   if (n == 2) {
      vi v0(ALL(s[0]));
      printf("1 %d\n",v0[0]);
      printf("%d ",v0.sz-1);
      FORI(i,v0.sz-1) {
         printf("%d ",v0[i]);
      }
      printf("\n");
      return 0;
   }
   
   set<vi> w;
   
   FORI(j,200) {
      if (!used[j]) continue;
      vi v;
      FOR(i,k) if (IN(j,s[i])) {
         v.pb(i);
         if (v.sz==2) break;
      }
      vi nowy(200);
      vi::iterator e = set_intersection(ALL(s[v[0]]), ALL(s[v[1]]), nowy.begin());
      for (vi::iterator it = nowy.begin(); it != e; ++it) {
         used[*it]=0;
      }
      w.insert(vi(nowy.begin(),e));
   }
   
   FOREACH(it,w) {
      printf("%d ",it->size());
      FOR(i,it->sz) {
         printf("%d ", (*it)[i]);
      }
      printf("\n");
   }
   
}