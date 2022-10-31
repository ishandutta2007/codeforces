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

#define N 760
char s[N];
int matching[N];
const int mod = 1000000007;
int dp[N][N][3][3];

int get (int a, int b, int k1, int k2) {
   // s[a..b] is correct
   if (dp[a][b][k1][k2] != -1) return dp[a][b][k1][k2];
   
   // leaf
   if (b == a+1) {
      if ((k1 == 0 && k2 != 0) || (k2 == 0 && k1 != 0)) return dp[a][b][k1][k2] = 1;
      return dp[a][b][k1][k2] = 0;
   }
   
   // subtree
   if (matching[a] == b) {
      if (k1 == 0 && k2 != 0) {
         ll res = 0;
         FOR(l1,3) FOR(l2,3) if (l2 != k2) res += get(a+1,b-1,l1,l2);
         return dp[a][b][k1][k2] = res%mod;
      } else if (k2 == 0 && k1 != 0) {
         ll res = 0;
         FOR(l1,3) FOR(l2,3) if (l1 != k1) res += get(a+1,b-1,l1,l2);
         return dp[a][b][k1][k2] = res%mod;         
      } else {
         return dp[a][b][k1][k2] = 0;
      }
   }
   
   // two or more subtrees
   int mid = matching[a];
   ll res = 0;
   FOR(l1,3) FOR(l2,3) if (l1 == 0 || l2 == 0 || l1 != l2) {
      res += ((ll)get(a,mid,k1,l1) * get(mid+1,b,l2,k2)) % mod;
   }
   return dp[a][b][k1][k2] = res % mod;
}

int main () {
   scanf("%s",s);
   int n = strlen(s);
   FOR(i,n) if (s[i] == '(') {
      int c = 1;
      matching[i] = i;
      while (c) {
         ++matching[i];
         if (s[matching[i]] == '(') ++c;
         else --c;
      }
   }
   
   FOR(i,n) FOR(j,n) FOR(k1,3) FOR(k2,3) dp[i][j][k1][k2] = -1;
   
   ll res = 0;
   FOR(k1,3) FOR(k2,3) res += get(0,n-1,k1,k2);
   pisz(res % mod);
}