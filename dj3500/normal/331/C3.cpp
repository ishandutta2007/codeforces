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

pair<ll,int> jeszczelepszy (ll x, int zewn) {
   ll res = 0;
   const ll milionow = x / 1000000;
   
   while ((x / 1000000) == milionow) {
      ++res;
      x -= max(zewn,getbest(x));
   }
   
   while(1) {
      // zmniejszyla sie cyfra milionow
      int z = max(zewn, getbest(x / 1000000));
      pii p = cache[1000000 - (x % 1000000)][z];
      res += p.fi;
      x = (x / 1000000) * 1000000 + p.se;
      if (x <= 0) {
         return mp(res,x);
      }
      if (p.se == 0) {
         ++res;
         x -= max(zewn,getbest(x));
      }
   }
}

pair<ll,int> cache2[15][15];
#define BLN 1000000000000LL

int main () {
   pow10[0] = 1;
   REP(i,1,19) pow10[i] = pow10[i-1] * 10;
   /*REP(i,0,10) REP(j,0,9) {
      cache[i][j] = lepszy(1000000-i,j);
      printf("cache[%d][%d] = mp(%d,%d);\n", i, j, cache[i][j].fi, cache[i][j].se);
   }*/
cache[0][0] = mp(128207,0);
cache[0][1] = mp(128207,0);
cache[0][2] = mp(128207,0);
cache[0][3] = mp(128207,0);
cache[0][4] = mp(128207,0);
cache[0][5] = mp(128207,0);
cache[0][6] = mp(124320,-2);
cache[0][7] = mp(121747,0);
cache[0][8] = mp(118675,-4);
cache[0][9] = mp(111112,-8);
cache[1][0] = mp(128206,0);
cache[1][1] = mp(128206,0);
cache[1][2] = mp(128206,0);
cache[1][3] = mp(128206,0);
cache[1][4] = mp(128206,0);
cache[1][5] = mp(128206,0);
cache[1][6] = mp(124319,-2);
cache[1][7] = mp(121747,-4);
cache[1][8] = mp(118675,-4);
cache[1][9] = mp(111111,0);
cache[2][0] = mp(128206,0);
cache[2][1] = mp(128206,0);
cache[2][2] = mp(128206,0);
cache[2][3] = mp(128206,0);
cache[2][4] = mp(128206,0);
cache[2][5] = mp(128206,0);
cache[2][6] = mp(124319,-2);
cache[2][7] = mp(121747,-4);
cache[2][8] = mp(118675,-4);
cache[2][9] = mp(111111,-1);
cache[3][0] = mp(128206,0);
cache[3][1] = mp(128206,0);
cache[3][2] = mp(128206,0);
cache[3][3] = mp(128206,0);
cache[3][4] = mp(128206,0);
cache[3][5] = mp(128206,0);
cache[3][6] = mp(124319,-2);
cache[3][7] = mp(121746,0);
cache[3][8] = mp(118674,0);
cache[3][9] = mp(111111,-2);
cache[4][0] = mp(128206,0);
cache[4][1] = mp(128206,0);
cache[4][2] = mp(128206,0);
cache[4][3] = mp(128206,0);
cache[4][4] = mp(128206,0);
cache[4][5] = mp(128206,0);
cache[4][6] = mp(124319,-2);
cache[4][7] = mp(121746,0);
cache[4][8] = mp(118674,0);
cache[4][9] = mp(111111,-3);
cache[5][0] = mp(128206,0);
cache[5][1] = mp(128206,0);
cache[5][2] = mp(128206,0);
cache[5][3] = mp(128206,0);
cache[5][4] = mp(128206,0);
cache[5][5] = mp(128206,0);
cache[5][6] = mp(124319,-2);
cache[5][7] = mp(121746,0);
cache[5][8] = mp(118674,0);
cache[5][9] = mp(111111,-4);
cache[6][0] = mp(128206,0);
cache[6][1] = mp(128206,0);
cache[6][2] = mp(128206,0);
cache[6][3] = mp(128206,0);
cache[6][4] = mp(128206,0);
cache[6][5] = mp(128206,0);
cache[6][6] = mp(124319,-2);
cache[6][7] = mp(121746,0);
cache[6][8] = mp(118674,0);
cache[6][9] = mp(111111,-5);
cache[7][0] = mp(128206,0);
cache[7][1] = mp(128206,0);
cache[7][2] = mp(128206,0);
cache[7][3] = mp(128206,0);
cache[7][4] = mp(128206,0);
cache[7][5] = mp(128206,0);
cache[7][6] = mp(124319,-2);
cache[7][7] = mp(121746,0);
cache[7][8] = mp(118674,0);
cache[7][9] = mp(111111,-6);
cache[8][0] = mp(128205,0);
cache[8][1] = mp(128205,0);
cache[8][2] = mp(128205,0);
cache[8][3] = mp(128205,0);
cache[8][4] = mp(128205,0);
cache[8][5] = mp(128205,0);
cache[8][6] = mp(124318,-2);
cache[8][7] = mp(121746,-4);
cache[8][8] = mp(118674,-4);
cache[8][9] = mp(111111,-7);
cache[9][0] = mp(128205,0);
cache[9][1] = mp(128205,0);
cache[9][2] = mp(128205,0);
cache[9][3] = mp(128205,0);
cache[9][4] = mp(128205,0);
cache[9][5] = mp(128205,0);
cache[9][6] = mp(124318,-2);
cache[9][7] = mp(121746,-4);
cache[9][8] = mp(118674,-4);
cache[9][9] = mp(111111,-8);
cache[10][0] = mp(128205,0);
cache[10][1] = mp(128205,0);
cache[10][2] = mp(128205,0);
cache[10][3] = mp(128205,0);
cache[10][4] = mp(128205,0);
cache[10][5] = mp(128205,0);
cache[10][6] = mp(124318,-2);
cache[10][7] = mp(121746,-4);
cache[10][8] = mp(118674,-4);
cache[10][9] = mp(111110,0);
   //REP(i,0,10) REP(j,0,9) {
      //cache2[i][j] = jeszczelepszy(BLN-i,j);
      //printf("cache2[%d][%d] = mp(%sdfsdf,%d);\n", i, j, cache2[i][j].fi, cache2[i][j].se);LL,
   //}
cache2[0][0] = mp(116420033358LL,0);
cache2[0][1] = mp(116420033358LL,0);
cache2[0][2] = mp(116420033354LL,0);
cache2[0][3] = mp(116420033348LL,0);
cache2[0][4] = mp(116420032577LL,0);
cache2[0][5] = mp(116420032576LL,0);
cache2[0][6] = mp(116238640564LL,-2);
cache2[0][7] = mp(115936032881LL,0);
cache2[0][8] = mp(115130628209LL,0);
cache2[0][9] = mp(111111111112LL,-8);
cache2[1][0] = mp(116420033357LL,0);
cache2[1][1] = mp(116420033357LL,0);
cache2[1][2] = mp(116420033353LL,0);
cache2[1][3] = mp(116420033347LL,0);
cache2[1][4] = mp(116420032576LL,0);
cache2[1][5] = mp(116420032576LL,0);
cache2[1][6] = mp(116238640564LL,-2);
cache2[1][7] = mp(115936032881LL,0);
cache2[1][8] = mp(115130628209LL,0);
cache2[1][9] = mp(111111111111LL,0);
cache2[2][0] = mp(116420033357LL,0);
cache2[2][1] = mp(116420033357LL,0);
cache2[2][2] = mp(116420033353LL,0);
cache2[2][3] = mp(116420033347LL,0);
cache2[2][4] = mp(116420032576LL,0);
cache2[2][5] = mp(116420032576LL,0);
cache2[2][6] = mp(116238640564LL,-2);
cache2[2][7] = mp(115936032881LL,0);
cache2[2][8] = mp(115130628209LL,0);
cache2[2][9] = mp(111111111111LL,-1);
cache2[3][0] = mp(116420033357LL,0);
cache2[3][1] = mp(116420033357LL,0);
cache2[3][2] = mp(116420033353LL,0);
cache2[3][3] = mp(116420033347LL,0);
cache2[3][4] = mp(116420032576LL,0);
cache2[3][5] = mp(116420032576LL,0);
cache2[3][6] = mp(116238640564LL,-2);
cache2[3][7] = mp(115936032881LL,0);
cache2[3][8] = mp(115130628209LL,0);
cache2[3][9] = mp(111111111111LL,-2);
cache2[4][0] = mp(116420033357LL,0);
cache2[4][1] = mp(116420033357LL,0);
cache2[4][2] = mp(116420033353LL,0);
cache2[4][3] = mp(116420033347LL,0);
cache2[4][4] = mp(116420032576LL,0);
cache2[4][5] = mp(116420032576LL,0);
cache2[4][6] = mp(116238640564LL,-2);
cache2[4][7] = mp(115936032881LL,0);
cache2[4][8] = mp(115130628209LL,0);
cache2[4][9] = mp(111111111111LL,-3);
cache2[5][0] = mp(116420033356LL,0);
cache2[5][1] = mp(116420033356LL,0);
cache2[5][2] = mp(116420033352LL,0);
cache2[5][3] = mp(116420033346LL,0);
cache2[5][4] = mp(116420032575LL,0);
cache2[5][5] = mp(116420032575LL,0);
cache2[5][6] = mp(116238640563LL,-2);
cache2[5][7] = mp(115936032880LL,0);
cache2[5][8] = mp(115130628208LL,0);
cache2[5][9] = mp(111111111111LL,-4);
cache2[6][0] = mp(116420033356LL,0);
cache2[6][1] = mp(116420033356LL,0);
cache2[6][2] = mp(116420033352LL,0);
cache2[6][3] = mp(116420033346LL,0);
cache2[6][4] = mp(116420032575LL,0);
cache2[6][5] = mp(116420032575LL,0);
cache2[6][6] = mp(116238640563LL,-2);
cache2[6][7] = mp(115936032880LL,0);
cache2[6][8] = mp(115130628208LL,0);
cache2[6][9] = mp(111111111111LL,-5);
cache2[7][0] = mp(116420033356LL,0);
cache2[7][1] = mp(116420033356LL,0);
cache2[7][2] = mp(116420033352LL,0);
cache2[7][3] = mp(116420033346LL,0);
cache2[7][4] = mp(116420032575LL,0);
cache2[7][5] = mp(116420032575LL,0);
cache2[7][6] = mp(116238640563LL,-2);
cache2[7][7] = mp(115936032880LL,0);
cache2[7][8] = mp(115130628208LL,0);
cache2[7][9] = mp(111111111111LL,-6);
cache2[8][0] = mp(116420033356LL,0);
cache2[8][1] = mp(116420033356LL,0);
cache2[8][2] = mp(116420033352LL,0);
cache2[8][3] = mp(116420033346LL,0);
cache2[8][4] = mp(116420032575LL,0);
cache2[8][5] = mp(116420032575LL,0);
cache2[8][6] = mp(116238640563LL,-2);
cache2[8][7] = mp(115936032880LL,0);
cache2[8][8] = mp(115130628208LL,0);
cache2[8][9] = mp(111111111111LL,-7);
cache2[9][0] = mp(116420033356LL,0);
cache2[9][1] = mp(116420033356LL,0);
cache2[9][2] = mp(116420033352LL,0);
cache2[9][3] = mp(116420033346LL,0);
cache2[9][4] = mp(116420032575LL,0);
cache2[9][5] = mp(116420032575LL,0);
cache2[9][6] = mp(116238640563LL,-2);
cache2[9][7] = mp(115936032880LL,0);
cache2[9][8] = mp(115130628208LL,0);
cache2[9][9] = mp(111111111111LL,-8);
cache2[10][0] = mp(116420033356LL,0);
cache2[10][1] = mp(116420033356LL,0);
cache2[10][2] = mp(116420033352LL,0);
cache2[10][3] = mp(116420033346LL,0);
cache2[10][4] = mp(116420032575LL,0);
cache2[10][5] = mp(116420032575LL,0);
cache2[10][6] = mp(116238640563LL,-2);
cache2[10][7] = mp(115936032880LL,0);
cache2[10][8] = mp(115130628208LL,0);
cache2[10][9] = mp(111111111110LL,0);

   
   ll x; cin >> x;
   if (x <= 1000000) {
      pisz(zwykly(x));
   } else if (x <= BLN) {
      cout << jeszczelepszy(x,0).fi;
   } else {
      ll res = 0;
      const ll milionow = x / 1000000;
      
      while ((x / 1000000) == milionow) {
         ++res;
         x -= max(0,getbest(x));
      }
      
      const ll bilionow = x / BLN;
      int z = getbest(bilionow);
      while((x / BLN) == bilionow) {
         // zmniejszyla sie cyfra milionow
         int zz = max(z, getbest(x / 1000000));
         pii p = cache[1000000 - (x % 1000000)][zz];
         res += p.fi;
         x = (x / 1000000) * 1000000 + p.se;
         if (x <= 0) {
            //return mp(res,x);
            cout << res; return 0;
         }
         if (p.se == 0) {
            ++res;
            x -= max(zz,getbest(x));
         }
      }
      
      // zmniejszyla sie cyfra Bilionow
      while(1) {
         z = getbest(x / BLN);
         pair<ll,int> p = cache2[BLN - (x % BLN)][z];
         res += p.fi;
         x = (x / BLN) * BLN + p.se;
         if (x <= 0) {
            cout << res; return 0;
         }
         if (p.se == 0) {
            ++res;
            x -= max(z,getbest(x));
         }
      }
   }
}