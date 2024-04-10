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

inline void dopelnij (int &l) {
   while ((l & 3) != 1) l++;
}
inline void dopelnij2 (int &l) {
   while ((l & 3) != 3) l++;
}

vector<bool> sito(int m) { // m = max_inclusive
   vector<bool> pr(m+1,1);
   pr[0]=pr[1]=0;
   const int lim = (sqrt(m)+5);
   for (int x = 3; x <= lim; x += 2) {
      if (pr[x]) {
         if ((x & 3) == 1) {
            int y;
            for (y = x; x*y <= lim; y++) pr[x*y]=0;
            dopelnij(y);
            for (; x*y <= m; y += 4) pr[x*y]=0;
         } else {
            int y;
            for (y = x; x*y <= lim; y++) pr[x*y]=0;
            dopelnij2(y);
            for (; x*y <= m; y += 4) pr[x*y]=0;
         }
      }
   }
   return pr;
}

int main () {
   wez2(l,r)
   int lorg = l;
   //int l = 1, r = 30000000;

   vector<bool> pr = sito(r);
   int num = 0;
   if (l < 5) l = 5;
   dopelnij(l);
   for (int k = l; k <= r; k += 4) {
      if (pr[k]) num++;
   }
   int u = lorg <= 2 && 2 <= r;
   pisz(num + u);
}