#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <iomanip>
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

int n,k;
ll l[1002],r[1002];
double p[1002];
double dp[1002][1002];

int main () {
   ios_base::sync_with_stdio(0);
   cin >> n;
   FORI(i,n) {
      cin >> l[i] >> r[i];
   }
   cin >> k;
   
   FORI(i,n) {
      ll ile = 0;
      for (ll k = 1, ktory = 0; ktory <= 18; k *= 10, ++ktory) {
         ll s = 2*k-1;
         ll lewy = max(k,l[i]);
         ll prawy = min(s,r[i]);
         if (lewy > prawy) continue;
         ile += prawy-lewy+1;
      }
      
      p[i] = ((double)ile) / (r[i]-l[i]+1);
   }
   
   dp[0][0] = 1.0;
   FORI(j,n) dp[0][j] = 0.0;
   FORI(i,n) {
      dp[i][0] = dp[i-1][0] * (1-p[i]);
      FORI(j,n) {
         dp[i][j] = dp[i-1][j] * (1-p[i]) + dp[i-1][j-1] * p[i];
      }
   }
   
   double wyn = 0;
   for (int s = 0; s <= n; ++s) {
      if (100*s >= n*k) {
         wyn += dp[n][s];
      }
   }
   cout << setprecision(13) << wyn << endl;
}