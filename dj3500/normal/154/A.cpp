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

char s[100007], temp[5];
int dp[100007][30];
bool ok[30][30];

int main () {
   scanf("%s",s);
   int n = strlen(s);
   
   FOR(l,26) FOR(k,26) ok[l][k] = 1;
   TESTS {
     scanf("%s",temp);
     char k = temp[0], l = temp[1];
     ok[k - 'a'][l - 'a'] = ok[l - 'a'][k - 'a'] = 0;
   }
   
   FOR(l,26) dp[0][l] = 0;
   FORI(i,n) FOR(l,26) {
      int res = dp[i-1][l]+1; // moge wywalic litere na pozycji i
      if (l+'a' == s[i-1]) FOR(k,26) if (ok[k][l]) REMIN(res, dp[i-1][k]);
      dp[i][l] = res;
   }
   int res = INF;
   FOR(l,26) REMIN(res, dp[n][l]);
   pisz(res);
}