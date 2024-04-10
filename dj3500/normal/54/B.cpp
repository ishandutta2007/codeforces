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
#define IN(x,y) ((y).find((x))!=(y).end()) 
#define DBG(vari) cout<<#vari<<" = "<<vari<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(t)while(t--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
template<typename T,typename TT> inline ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> inline ostream& operator<<(ostream &s,vector<T> t){FOR(i,t.sz)s<<t[i]<<" ";return s; }
inline void pisz(int n) { printf("%d\n",n); }
typedef vector<string> bitmapa;

// odwrcenie stringa
string reverse(string src) {
   return string(src.rbegin(), src.rend());
}

// obrot o 180 stopni
bitmapa inv (bitmapa v) {
   bitmapa wyn;
   FOR(i,v.size()) {
      wyn.pb(reverse(v[v.size()-1-i]));
   }
   return wyn;
}

// obrot o 90 stopni w prawo
bitmapa obr (bitmapa v) {
   bitmapa wyn;
   FOR(i,v.size()) {
      wyn.pb(string());
      FOR(j,v.size()) {
         wyn[i] += v[j][v.size()-1-i];
      }
   }
   return wyn;
}

// czy jedn bitmap mona otrzyma przez obrt drugiej?
bool sim (bitmapa v, bitmapa w) {
   vector<bitmapa> comps;
   comps.pb(inv(v));
   if (v.size() == v[0].length()) {
      comps.pb(obr(v));
      comps.pb(inv(comps[1]));
   }
   comps.pb(v);
   
   bool si = false;
   FOR(i,comps.size()) {
      bool same = true;
      FOR(j,v.size()) {
         if (comps[i][j] !=  w[j]) {
            same = false;
            break;
         }
      }
      if (same) {
         si = true;
         break;
      }
   }
   return si;
}
int a,b;
string s[25];
int minarea = INF, minx, miny;
bool spr (int x, int y) {
   vector<bitmapa> kawalki;
   bool ok = true;
   FOR(i,a/x) {
      FOR(j,b/y) {
         bitmapa kawalek;

         FOR(k,x) {
            kawalek.pb(s[i*x+k].substr(j*y,y));
         }

         FOR(l,kawalki.size()) {
            if (sim(kawalek,kawalki[l])) {
               ok = false;
            }
         }

         if (ok) kawalki.pb(kawalek);
      }
   }
   return ok;
}

int main () {
   scanf("%d",&a);
   scanf("%d",&b);
   FOR(i,a) cin >> s[i];
   
//   FOR(i,a) cout << s[i] << endl;
   
   int wyn = 0;
   FORI(x,a) {
      if (a % x == 0) {
         FORI(y,b) {
            if (b % y == 0) {
               bool ok = spr(x,y);
               //DBG(x) DBG(y) DBG(ok)
               if (ok) {
                  ++wyn;
                  if (x*y < minarea) {
                     minarea = x*y;
                     minx = x;
                     miny = y;
                  }
               }
            }
         }
      }
   }
   pisz(wyn);
   printf("%d %d\n",minx,miny);   
}