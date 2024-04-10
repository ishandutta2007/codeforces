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

#define N 1024
int target;
char s[N][N];
bool seen[N][N];
int cur, n, m;
int save[N][N];
const int dx[4] = {-1,1,0,0}, dy[4] = {0,0,-1,1};

void dfs (int i, int j) {
   if (i < 0 || j < 0 || i >= n || j >= m) return;
   if (seen[i][j]++) return;
   if ('#' == s[i][j]) return;
   save[i][j] = 1;
   ++cur;
   if (cur == target) throw 1;
   FOR(d,4) {
      int x = i + dx[d], y = j + dy[d];
      dfs(x,y);
   }
}

int main () {
   wez3(nn,mm,k)
   n = nn;
   m = mm;
   FOR(i,n) scanf("%s", s[i]);
   int emp = 0;
   int sx = -1, sy = -1;
   FOR(i,n) FOR(j,m) if ('.' == s[i][j]) { ++emp; sx = i; sy = j; }
   target = emp - k;
   cur = 0;
   try {
      dfs(sx,sy);
   } catch (int hhh) {}
   FOR(i,n) FOR(j,m) if ('.' == s[i][j] && !save[i][j]) s[i][j] = 'X';
   FOR(i,n) printf("%s\n", s[i]);
}