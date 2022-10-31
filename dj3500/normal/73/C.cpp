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
inline void pisz(int n) { printf("%d\n",n); }
template<typename T,typename TT> ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &s,vector<T> t){FOR(i,t.size())s<<t[i]<<" ";return s; }
#define IN(x,y) ((y).find((x))!=(y).end()) 
#define DBG(vari) cout<<#vari<<" = "<<vari<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));

int b[400][400];
int dp[102][102][300];

int main () {
   ios_base::sync_with_stdio(0);
   int len,k;
   string s;
   cin >> s >> k;
   len = s.length();
   int ile;
   cin >> ile;
   FOR(i,300) FOR(j,300) b[i][j] = 0;
   while (ile--) {
      char x,y;
      int c;
      cin >> x >> y >> c;
      b[x][y] = c;
   }
   
   // dp[1]
   REP(ostl,'a','z') {
      if (ostl == s[0]) {
         dp[1][0][ostl] = 0;
      } else {
         dp[1][0][ostl] = -INF;
      }
   }
   REP(ostl,'a','z') {
      REP(u,1,k) {
         dp[1][u][ostl] = 0;
      }
   }

   REP(r,2,len) {
      REP(ostl,'a','z') {
         if (ostl == s[r-1]) {
//            DBG(s[r-1])
            dp[r][0][ostl] = dp[r-1][0][s[r-2]] + b[s[r-2]][ostl];
  //          DBG(b[s[r-2]][ostl])
         } else {
            dp[r][0][ostl] = -INF;
         }
         
         REP(u,1,k) {
            int maxx = -INF;
            int cf = (ostl == s[r-1]) ? 0 : 1;
            REP(przedostl,'a','z') {
               REMAX(maxx,dp[r-1][u-cf][przedostl] + b[przedostl][ostl])
            }
            dp[r][u][ostl] = maxx;
         }
      }
   }
   int wyn = -INF;
   REP(ostl,'a','z') REMAX(wyn,dp[len][k][ostl])
   cout << wyn << endl;
/*   DBG(dp[1][0]['a'])
   DBG(dp[1][1]['a'])
   DBG(dp[1][0]['c'])
   DBG(dp[1][1]['c'])
   DBG(dp[2][2]['o'])*/
}