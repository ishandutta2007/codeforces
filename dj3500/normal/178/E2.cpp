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
#define IOS ios_base::sync_with_stdio(0);

struct UnionFind {
   vi tab, ile;

   UnionFind(int n) : // tworzy UF na 0, 1, ..., n-1
      tab(n), ile(n,1) {
      FOR(i,n) tab[i] = i;
   }

   int find(int a) {
      if (tab[a] == a) return a;
      return a = find(tab[a]);
   }

   bool unia(int a, int b) { // zwraca, czy odbylo sie polaczenie
      a = find(a), b = find(b);
      if (a==b) return 0;
      if (ile[a] <= ile[b]) {
         ile[b] += ile[a];
         tab[a] = b;
      } else {
         ile[a] += ile[b];
         tab[b] = a;
      }
      return 1;
   }
};

const int dx[4] = {0,0,-1,1}, dy[4] = {-1,1,0,0};

int pict[2048][2048], index[2048][2048], black[2048][2048], n;
double blurredPict[2048][2048], gaussianMask[16][16], maskSum = 0;// gradientMagnitude[2048][2048], gradientOrientation[2048][2048];
const int blurRadius = 4;
const double threshold = 0.7;//0.9683;

void gaussianBlur () {
   REP(x,-blurRadius,blurRadius) {
      REP(y,-blurRadius,blurRadius) {
         gaussianMask[blurRadius+x][blurRadius+y] = 1;//exp((double)(-(abs(x)+abs(y))*(abs(x)+abs(y)))/6);
         maskSum += gaussianMask[blurRadius+x][blurRadius+y];
      }
   }
   
   FOR(i,n) FOR(j,n) {
      double kolor = 0;
      REP(x,-blurRadius,blurRadius) {
         REP(y,-blurRadius,blurRadius) {
            kolor += pict[i+blurRadius+x][j+blurRadius+y] * gaussianMask[blurRadius+x][blurRadius+y];
         }
      }
      blurredPict[i+blurRadius][j+blurRadius] = kolor / maskSum;
   }
}

/*const int lx[3][3] = {{-1,0,1}, {-2,0,2}, {-1,0,1}}, ly[3][3] = {{1,2,1},{0,0,0},{-1,-2,-1}};

void sobel () {
   FOR(i,n) FOR(j,n) {
      double Lx = 0, Ly = 0;
      REP(x,-1,1) REP(y,-1,1) {
         Lx += lx[x+1][y+1] * blurredPict[i+blurRadius+x][j+blurRadius+y];
         Ly += ly[x+1][y+1] * blurredPict[i+blurRadius+x][j+blurRadius+y];
      }
      gradientMagnitude[i+blurRadius][j+blurRadius] = sqrt(Lx*Lx + Ly*Ly);
      gradientOrientation[i+blurRadius][j+blurRadius] = atan2(Ly, Lx);
   }
}*/

template<typename T> void wypluj (T arr[2048][2048]) {
   return;
   T maxx = 0;
   FOR(i,n) {
      printf("\n");
      FOR(j,n) {
         T &rzecz = arr[i+blurRadius][j+blurRadius];
         if (rzecz >= 0) printf(" ");
         cout << setprecision(3) << fixed << rzecz << " ";
         REMAX(maxx, rzecz);
      }
   }
   DBG(maxx)
}

#define N 2048*2048
int maxX[N], minX[N], minY[N], maxY[N];
vector<int> odleglosci[N];
int sqr (int x) { return x*x; }

void noGaussianBlur() {
   FOR(i,n) FOR(j,n) blurredPict[i+blurRadius][j+blurRadius] = pict[i+blurRadius][j+blurRadius];
}


int main () {
   scanf("%d",&n);
   FOR(i,2048) FOR(j,2048) black[i][j] = pict[i][j] = 0;
   FOR(i,n) FOR(j,n) scanf("%d",&pict[i+blurRadius][j+blurRadius]);
   
   //gaussianBlur();
   noGaussianBlur();
   
   //sobel();
   wypluj(pict);
   wypluj(blurredPict);
   //wypluj(gradientMagnitude);
   //wypluj(gradientOrientation);
   
   int nextVal = 0;
   FOR(i,n) FOR(j,n) index[i+blurRadius][j+blurRadius] = nextVal++;
   UnionFind uf(nextVal);
   FOR(i,n) FOR(j,n) {
      if (blurredPict[i+blurRadius][j+blurRadius] >= threshold) black[i+blurRadius][j+blurRadius] = 1;
   }
   wypluj(black);
   FOR(i,n) FOR(j,n) if (black[i+blurRadius][j+blurRadius]) {
      FOR(u,4) {
         int x = i+blurRadius + dx[u], y = j+blurRadius + dy[u];
         if (black[x][y]) {
            //DBG(mp(x,y))
            uf.unia(index[i+blurRadius][j+blurRadius], index[x][y]);
         }
      }
   }
   
   FOR(i,nextVal) maxX[i] = 0, minX[i] = INF, minY[i] = INF, maxY[i] = 0;
   FOR(i,n) FOR(j,n) if (black[i+blurRadius][j+blurRadius]) {
      int klasa = uf.find(index[i+blurRadius][j+blurRadius]);
      REMAX(maxX[klasa], i+blurRadius);
      REMIN(minX[klasa], i+blurRadius);
      REMAX(maxY[klasa], j+blurRadius);
      REMIN(minY[klasa], j+blurRadius);
   }
   FOR(i,n) FOR(j,n) if (black[i+blurRadius][j+blurRadius]) {
      int klasa = uf.find(index[i+blurRadius][j+blurRadius]);
      int srodekX = (maxX[klasa] + minX[klasa]) / 2;
      int srodekY = (maxY[klasa] + minY[klasa]) / 2;
      odleglosci[klasa].pb(sqr(srodekX - (i+blurRadius)) + sqr(srodekY - (j+blurRadius)));
   }
   
   int obiektow = 0, kolek = 0, kwadratow = 0;
   vector<double> dbgwsp;
   FOR(i,nextVal) if (i == uf.find(i) && uf.ile[i] >= 15) {
      ++obiektow;
      int maxodl = *max_element(ALL(odleglosci[i]));
      double p = 0.5;
      int daleko = 0, wogole = 0;
      FOREACH(odl,odleglosci[i]) {
         ++wogole;
         if (sqrt(*odl) >= p * sqrt(maxodl)) ++daleko;
      }
      double wsp = (double)daleko/wogole;
      dbgwsp.pb(wsp);
      if (wsp >= 0.69) ++kolek;
      else ++kwadratow;
   }
   //sort(ALL(dbgwsp));DBG(dbgwsp);
   //DBG(obiektow);
   printf("%d %d\n", kolek, kwadratow);
   //DBG(mp(kolek,kwadratow))
}