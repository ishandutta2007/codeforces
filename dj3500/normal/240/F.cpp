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

struct Counter {
   int ile[26];
   int single;
   Counter() : single(-1) {
      memset(ile,0,sizeof(ile));
   }
   inline Counter operator + (const Counter &s) const {
      Counter nu;
      FOR(i,26) nu.ile[i] = ile[i] + s.ile[i];
      return nu;
   }
};



#define MAXX 524298
Counter sum[MAXX];
bool monochar[MAXX]; // mono-char
int n;

void init () {
   FOR(i,MAXX) monochar[i] = 0;
   // jesli bedzie sie initowalo wielokrotnie, to clearowac tez sum[i]
}

void ustaw (int v, int a, int b, int aw, int bw, int x) {
   if (a == aw && b == bw) {
      monochar[v] = 1;
      Counter c;
      c.ile[x] = b-a+1;
      c.single = x;
      sum[v] = c;
   } else {
      int mid = (a+b)/2;
      if (monochar[v]) {
         ustaw(2*v, a, mid, a, mid, sum[v].single);
         ustaw(2*v+1, mid+1, b, mid+1, b, sum[v].single);
      }
      if (mid < aw) {
         ustaw(2*v+1, mid+1, b, aw, bw, x);
      } else if (mid+1 > bw) {
         ustaw(2*v, a, mid, aw, bw, x);
      } else {
         ustaw(2*v, a, mid, aw, mid, x);
         ustaw(2*v+1, mid+1, b, mid+1, bw, x);
      }

      monochar[v] = 0;
      sum[v] = sum[2*v] + sum[2*v+1];
   }
}

void ustaw (int aw, int bw, int x) {
   if (aw > bw) return;
   ustaw(1,0,n-1,aw,bw,x);
}

Counter sumuj (int v, int a, int b, int aw, int bw) {
   if (a == aw && b == bw) {
      return sum[v];
   } else if (monochar[v]) {
      Counter res;
      res.ile[sum[v].single] = bw-aw+1;
      res.single = sum[v].single;
      return res;
   } else {
      int mid = (a+b)/2;
      if (mid < aw) {
         return sumuj(2*v+1, mid+1, b, aw, bw); 
      } else if (mid+1 > bw) {
         return sumuj(2*v, a, mid, aw, bw);
      } else {
         return sumuj(2*v, a, mid, aw, mid) + sumuj(2*v+1, mid+1, b, mid+1, bw);
      }
   }
}

Counter sumuj (int aw, int bw) {
   if (aw > bw) return Counter();
   return sumuj(1,0,n-1,aw,bw);
}

#define N 100007
char s[N];
void freop() {
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
}
int main () {
   freop();
   scanf("%d", &n);
   init();
   wez(m)
   scanf("%s", s);
   FOR(i,n) {
      ustaw(i,i,s[i] - 'a');
   }
   while (m--) {
      wez2(l,r)
      l--;r--;
      Counter c = sumuj(l,r);
      int odds = 0;
      FOR(i,26) if (1 & c.ile[i]) ++odds;
      if (odds <= 1) {
         int a = l, b = r;
         FOR(i,26) {
            ustaw(a,a+c.ile[i]/2-1,i);
            a += c.ile[i]/2;
            ustaw(b-c.ile[i]/2+1,b,i);
            b -= c.ile[i]/2;
         }
         FOR(i,26) if (1 & c.ile[i]) {
            ustaw(a,a,i);
         }
      }
   }
   FOR(i,n) {
      Counter c = sumuj(i,i);
      char ch = 'a' + c.single;
      printf("%c", ch);
   }
}