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
#include <bitset>
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

#define N 70006
bool taken[N];
bitset<N> can;
int whatToPack[N], contains[N], a[N];

int main () {
   wez2(n,s)
   FORI(i,n) scanf("%d", a+i);
   int maxi = *max_element(a+1,a+n+1);
   int maxind; FORI(i,n) if (a[i] == maxi) maxind = i;
   int req = s - maxi;
   if (req < 0) {
      pisz(-1); return 0;
   }
   can[0] = 1;
   FORI(i,n) if (i != maxind) {
      bitset<N> newCan = can | (can << a[i]);
      bitset<N> firstActivated = newCan ^ can;
      can = newCan;
      
      // bitset<N> wouldn't cooperate in iterating over its words
      // so we do it forcefully
      unsigned long *w = reinterpret_cast<unsigned long*>(&firstActivated);
      for (int k = 0; k*32 <= req; k += 1) {
         if (w[k] != 0) {
            for (int j = 0; j < 32 && k*32+j <= req; ++j) {
               if ((1U << j) & w[k]) {
                  whatToPack[k*32 + j] = i;
               }
            }
         }
      }
   }
   if (!can[req]) {
      pisz(-1); return 0;
   }
   taken[maxind] = 1;
   int r = req;
   while (r != 0) {
      int i = whatToPack[r];
      taken[i] = 1;
      r -= a[i];
   }
   vector<pii> notTaken;
   FORI(i,n) if (!taken[i]) notTaken.pb(mp(a[i],i));
   sort(ALL(notTaken)); reverse(ALL(notTaken));
   if (!notTaken.empty()) contains[maxind] = notTaken[0].se;
   FOR(i,SZ(notTaken)-1) {
      contains[notTaken[i].se] = notTaken[i+1].se;
   }
   
   FORI(i,n) {
      if (!contains[i]) {
         printf("%d 0\n", a[i]);
      } else {
         printf("%d 1 %d\n", a[i] - a[contains[i]], contains[i]);
      }
   }
}