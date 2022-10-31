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

char s[50000];

inline bool pyt (char c) {
   return c=='.' || c=='?' || c=='!';
}

int main () {
   int n;
   cin >> n;
   cin.getline(s,5000);
   cin.getline(s,20000);
   vi v;
   int dl=0;
   int len = strlen(s);
   FOR(i,len) {
      dl++;
      if (pyt(s[i])) {
         v.pb(dl);
         dl=0;
      }
      if (i != 0 && pyt(s[i-1])) --dl;
   }
     
   int maxx=-1;
   FOR(i,v.sz) REMAX(maxx,v[i]);
   if (maxx > n) {
      printf("Impossible\n");
      return 0;
   }
   
   int w=1, z=n;
   FOR(i,v.sz) {
      if (z >= v[i]) {
      } else {
         ++w;
         z=n;
      }
      z -= v[i]+1;
   }
   pisz(w);
}