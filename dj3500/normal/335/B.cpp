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

#define N 50007
char s[N];
int dp[N][60], pr[26][N];
bool opt[N][60];
pair<int,bool> wynik[N];

int main () {
   scanf("%s", s);
   const int n = strlen(s);
   FOR(i,n) s[i] -= 'a';
   
   // indeksowanie 1-based, tylko s[] jest 0-based
   FOR(i,26) pr[i][0] = 0;
   REP(i,1,n) {
      FOR(j,26) pr[j][i] = pr[j][i-1];
      pr[s[i-1]][i] = i;
   }
   
   pair<int,bool> best(0,0);
   dp[0][0] = n + 1;
   REP(k,1,50) dp[0][k] = -1;
   REP(i,1,n) {
      dp[i][0] = n + 1;
      REP(k,1,50) {
         dp[i][k] = dp[i-1][k];
         if (dp[i-1][k-1] != -1) {
            int cand = pr[s[i-1]][dp[i-1][k-1]-1];
            if (cand > i) {
               if (cand > dp[i][k] || (cand == dp[i][k] && cand > i+1)) {
                  dp[i][k] = cand;
                  opt[i][k] = 1;
                  bool fajny = cand > i+1;
                  REMAX(best, mp(k, fajny));
                  REMAX(wynik[i], mp(k,fajny));
               }
            }
         }
      }
   }
   //cout << best;
   
   if (best.fi == 0) {
      printf("%c", 'a' + s[0]);
      return 0;
   }
      
   REP(i,1,n) if (wynik[i] == best) {
      string srodek = "";
      if (best.se == 1 && best.fi != 50) srodek = s[i]+'a';
      string ss;
      int k = best.fi;
      while (k != 0) {
         if (opt[i][k] == 1) {
            ss += s[i-1]+'a';
            i--;
            k--;
         } else {
            i--;
         }
      }
      string tt = ss;
      reverse(ALL(tt));
      ss = tt + srodek + ss;
      printf("%s", ss.c_str());
      return 0;
   }
}