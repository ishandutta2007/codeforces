#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;
#define pb push_back
#define INF (int)1e9
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define FORI(i,n) for(int (i)=1;(i)<=(n);++(i))
#define mp make_pair
#define pii pair<int,int>
#define ll long long
#define wez(n) int (n); scanf("%d",&(n));
#define IN(x,y) ((y).find((x))!=(y).end()) 
#define DBG(vari) cout<<#vari<<" = "<<vari<<endl;

inline void pisz(int n) {
   printf("%d\n",n);
}

bool p[7][7][7][7];

struct q {
   int a,b,c,d;
   q (int _a, int _b, int _c, int _d) : a(_a), b(_b), c(_c), d(_d) { }
   bool similar (q n) {
      if (a == n.a && b == n.b && c == n.c && d == n.d) return true;
      if (a == n.c && b == n.a && c == n.d && d == n.b) return true;
      if (a == n.d && b == n.c && c == n.b && d == n.a) return true;
      if (a == n.b && b == n.d && c == n.a && d == n.c) return true;
      return false;
   }
};

int main () {
   wez(n);
//   FORI(a,6)FORI(b,6)FORI(c,6)FORI(d,6) p[a][b][c][d] = 0;
   vector<q> v;
   while (n--) {
      string s,t,syf;
      cin >> s >> t;
      if (n) {
         cin >> syf;
      }
      int a,b,c,d;
      a = s[0] - '0';
      b = s[1] - '0';
      c = t[0] - '0';
      d = t[1] - '0';
      q k(a,b,c,d);
      //DBG(n)
      //DBG(k.a) DBG(k.b) DBG(k.c) DBG(k.d)
      bool jest = false;
      FOR(i,v.size()) {
         
         if (v[i].similar(k)) jest = true;
      }
      //DBG(jest)
      if (!jest) v.pb(k);
   }
   pisz(v.size());
}