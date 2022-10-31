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
#define SZ(x) ((int)((x).size()))
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

char s[107][10007];
int leftdist[107][10007], rightdist[107][10007];

int main () {
   wez2(n,m)
   FORI(i,n) scanf("%s", s[i]+1);
   FORI(i,n) {
      leftdist[i][0] = INF;
      FORI(j,m) leftdist[i][j] = (s[i][j] == '1') ? 0 : leftdist[i][j-1]+1;
      rightdist[i][m+1] = INF;
      REPD(j,m,1) rightdist[i][j] = (s[i][j] == '1') ? 0 : rightdist[i][j+1]+1;
      if (leftdist[i][m] >= INF || rightdist[i][1] >= INF) { pisz(-1); return 0; }
   }
   int best = INF;
   FORI(j,m) {
      int score = 0;
      //cerr<<endl;
      //DBG(j)
      FORI(i,n) {
         int g;
         score += (g = min(min(leftdist[i][j], rightdist[i][j]), min(j + leftdist[i][m], m+1-j + rightdist[i][1])));
         //DBG(i)DBG(g)
      }
      //DBG(score)
      REMIN(best,score);
   }
   pisz(best);
}