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

int geet(int x) {
   deque<int> q;
   vi odl(x+2,-1);
   q.pb(x);
   odl[x] = 0;
   while (1) {
      //if (q.empty()) { DBG("WTF"); }
      int num = q.front(); q.pop_front();
      //DBG(num)
      if (num == 0) return odl[0];
      int k = num;
      while (k != 0) {
         int r = k % 10;
         k /= 10;
         if (odl[num - r] == -1) {
            //DBG(num-r)
            //DBG(num)
            odl[num - r] = odl[num] + 1;
            q.pb(num - r);
         }
      }
   }
}

ll pow10[20];

pii lepszy (int x, int zewn) {
   int res = 0;
   while (x > 0) {
      int k = x; int best = zewn;
      while (k != 0) {
         int r = k % 10;
         REMAX(best,r);
         k /= 10;
      }
      ++res;
      x -= best;
   }
   return mp(res,x);
}

pii cache[15][15]; // cache[i][j] = lepszy(1000000-i,j)

int getbest (ll x) {
   ll k = x;
   int best = 0;
   while (k != 0) {
      REMAX(best, int(k % 10));
      k /= 10;
   }
   return best;
}

int zwykly (int x) {
   int res = 0;
   while (x > 0) {
      ++res;
      x -= getbest(x);
   }
   return res;
}

int main () {
   pow10[0] = 1;
   REP(i,1,19) pow10[i] = pow10[i-1] * 10;
   REP(i,0,10) REP(j,0,9) cache[i][j] = lepszy(1000000-i,j);
   
   ll x; cin >> x;
   if (x <= 1000000) {
      pisz(zwykly(x));
   } else {
      ll res = 0;
      const ll milionow = x / 1000000;
      
      while ((x / 1000000) == milionow) {
         ++res;
         x -= getbest(x);
      }
      
      while(1) {
         // zmniejszyla sie cyfra milionow
         int zewn = getbest(x / 1000000);
         pii p = cache[1000000 - (x % 1000000)][zewn];
         res += p.fi;
         x = (x / 1000000) * 1000000 + p.se;
         if (p.se == 0) {
            if (x == 0) { cout << res; return 0; }
            ++res;
            x -= getbest(x);
         }
      }
   }
}