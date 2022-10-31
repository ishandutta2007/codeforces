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

#define N 43
char in[N][N];
int ile[N][N];
int ok[N][N][N][N];
ll s[N][N][N][N];

int main () {
   wez3(n,m,q)
   FORI(i,n) scanf("%s", in[i] + 1);
   FORI(i,n) FORI(j,m) {
      ile[i][j] = ile[i-1][j] + ile[i][j-1] - ile[i-1][j-1] + ('1' == in[i][j]);
   }
   REP(a,1,n) REP(c,a,n) REP(b,1,m) REP(d,b,m) {
      ok[a][b][c][d] = (ile[c][d] - ile[a-1][d] - ile[c][b-1] + ile[a-1][b-1] == 0);
   }
   REP(a,1,n) REP(c,1,n) REP(b,1,m) REP(d,1,m) {
      s[a][b][c][d] = s[a-1][b][c][d] + s[a][b-1][c][d] + s[a][b][c-1][d] + s[a][b][c][d-1] - s[a-1][b-1][c][d] - s[a-1][b][c-1][d] - s[a-1][b][c][d-1] - s[a][b-1][c-1][d] - s[a][b-1][c][d-1] - s[a][b][c-1][d-1] + s[a][b-1][c-1][d-1] + s[a-1][b][c-1][d-1] + s[a-1][b-1][c][d-1] + s[a-1][b-1][c-1][d] - s[a-1][b-1][c-1][d-1] + ok[a][b][c][d];
   }
   
   
   while (q--) {
      wez2(a,b)
      wez2(c,d)
      pisz(s[n][m][c][d] - s[a-1][m][c][d] - s[n][b-1][c][d] + s[a-1][b-1][c][d]);
   }
}