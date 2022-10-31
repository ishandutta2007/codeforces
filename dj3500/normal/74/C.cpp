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
#define nlewo lewo
#define ndol dol

bool used[1000005];
int n,m;
pii ruch (int x, int y, bool &lewo, bool &dol) {
   int k;
   if (!lewo && dol) {
      k=min(n-x,m-y);
      if (n-x == m-y) {
         nlewo = 1;
         ndol = 0;
      } else if (n-x < m-y) {
         nlewo = 1;
         ndol = 1;
      } else {
         nlewo = 0;
         ndol = 0;
      }
      return mp(x+k,y+k);
   }
   else if (lewo && dol) {
      k=min(x-1,m-y);
      if (x-1 == m-y) {
         nlewo = 0;
         ndol = 0;
      } else if (x-1 < m-y) {
         nlewo = 0;
         ndol = 1;
      } else {
         ndol = 0;
         nlewo = 1;
      }
      return mp(x-k,y+k);
   }
   else if (lewo && !dol) {
      k=min(x-1,y-1);
      if (x-1 == y-1) {
         nlewo = 0;
         ndol = 1;
      } else if (x-1 < y-1) {
         nlewo = 0;
         ndol = 0;
      } else {
         nlewo = 1;
         ndol = 1;
      }
      return mp(x-k,y-k);
   }
   else { //(!lewo && !dol)
      k=min(n-x,y-1);
      if (n-x == y-1) {
         nlewo = 1;
         ndol = 1;
      } else if (n-x < y-1) {
         nlewo = 1;
         ndol = 0;
      } else {
         nlewo = 0;
         ndol = 1;
      }
      return mp(x+k,y-k);
   }
}

int main () {
   cin >> n >> m;
   if (n<m) swap(n,m);
   int w=0;
   FORI(i,n) {
      if (used[i]) continue;
      //DBG(i)
      ++w;
      
      {
      int x = i, y = 1;
      bool lewo=0,dol=1;
      do {
         pii p = ruch(x,y,lewo,dol);
         x=p.fi;
         y=p.se;
         //DBG(mp(x,y))
         if (y==1) {
            if (used[x]) break;
            used[x]=1;
         }
      } while (1);

      }
      {
      int x = i, y = 1;
      bool lewo=1,dol=1;
      do {
         pii p = ruch(x,y,lewo,dol);
         x=p.fi;
         y=p.se;
         //DBG(mp(x,y))
         if (y==1) {
            if (used[x]) break;
            used[x]=1;
         }
      } while (1);

      }
      

   }
   pisz(w);
}