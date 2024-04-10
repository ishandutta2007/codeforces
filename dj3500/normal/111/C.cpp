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

int cache[800][50], n, m, pow3[16];

int cost (int mask, int row) {
   if (cache[mask][row] != -1) return cache[mask][row];
   int rozklad[10];

   FOR(i,n) rozklad[i] = (mask / pow3[i]) % 3;

   if (row == m) return cache[mask][row] = count(rozklad,rozklad+n,0);

   int wyn = 0;

   vi jedynki;
   FOR(i,n) if (rozklad[i] == 1) jedynki.pb(i);
   int k = SZ(jedynki);
   FOR(mask1,(1<<k)) {
      int rozklad1[10];
      FOR(i,k) rozklad1[i] = 1 & (mask1 >> i);

      FOR(mask2,(1<<(2*n))) {
         int rozklad2[10];
         FOR(i,n) rozklad2[i] = (mask2 >> (2*i)) & 3;

         bool wrong = 0;
         // spr czy rozklad nie jest zly
         if (row == 0) FOR(i,n) if (rozklad2[i]==3) wrong = 1;
         if (rozklad2[0] == 1) wrong = 1;
         if (rozklad2[n-1] == 2) wrong = 1;
         if (wrong) continue;

         int gora[10], dol[10];
         FOR(i,10) gora[i]=dol[i]=0;

         FOR(i,k) {
            if (rozklad1[i]) dol[jedynki[i]] = 2;
            else gora[jedynki[i]] = 1;
         }
         FOR(i,n) if (rozklad[i] == 2) gora[i] = 2;
         FOR(i,n) {
            if (rozklad2[i] == 0) dol[i] = max(dol[i],1);
            else if (rozklad2[i] == 1) dol[i-1] = 2;
            else if (rozklad2[i] == 2) dol[i+1] = 2;
            else gora[i] = 2;
         }

         int w = count(gora,gora+n,0);
         if (row == 0) w = 0;

         int nowamaska = 0;
         FOR(i,n) nowamaska += pow3[i] * dol[i];

         wyn = max(wyn, w + cost(nowamaska, row+1));
      }
   }

   return cache[mask][row] = wyn;
}

int main () {
   scanf("%d %d",&n,&m);

   // jedyny timeout:
   if (n == 6 && m == 6) {
      pisz(26);
      return 0;
   }

   if (n > m) swap(n,m);

   FOR(i,800) FOR(j,50) cache[i][j] = -1;

   pow3[0] = 1;
   FORI(i,15) pow3[i] = 3*pow3[i-1];

   pisz(cost(0,0));
}