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

string base[2048];
int index[2048];
pii dp[2048][2048];
vi nextinside[32][2048];
int nextcontaining[32][2048];
int n,m,lens;
string s;
const pii oo(INF,INF);

inline pii nextStronglyAfter (pii pos, int c) {
   if (pos == oo) return oo;
   int posInside = nextinside[c][index[pos.fi]][pos.se+1];
   if (posInside != INF) return mp(pos.fi, posInside);
   int nextBlock = nextcontaining[c][pos.fi+1];
   if (nextBlock == INF) return oo;
   return mp(nextBlock, nextinside[c][index[nextBlock]][0]);
}

int main () {
   IOS
   cin >> n;
   FOR(i,n) {
      cin >> base[i];
      FOR(u,SZ(base[i])) base[i][u] -= 'a' - 1;
   }
   cin >> m;
   FOR(i,m) {
      cin >> index[i];
      index[i]--;
   }
   cin >> s;
   lens = SZ(s);
   FOR(u,lens) s[u] -= 'a' - 1;
   
   // nextinside
   FOR(i,n) {
      FORI(c,26) {
         nextinside[c][i].resize(SZ(base[i])+1);
         nextinside[c][i][SZ(base[i])] = INF;
      }
      REPD(pos,SZ(base[i])-1,0) {
         FORI(c,26) nextinside[c][i][pos] = nextinside[c][i][pos+1];
         nextinside[base[i][pos]][i][pos] = pos;
      }
   }
   
   // nextcontaining
   FORI(c,26) nextcontaining[c][m] = INF;
   REPD(ind,m-1,0) {
      FORI(c,26) {
         bool contains = nextinside[c][index[ind]][0] != INF;
         nextcontaining[c][ind] = contains ? ind : nextcontaining[c][ind+1];
      }
   }
   
   // dp
   FOR(pre,lens+1) dp[pre][0] = mp(0,-1);
   FORI(len,lens) dp[0][len] = oo;
   FORI(len,lens) {
      FORI(pre,lens) dp[pre][len] = min(dp[pre-1][len], nextStronglyAfter(dp[pre-1][len-1], s[pre-1]));
   }
   
   // res
   REPD(lcs,lens,0) if (dp[lens][lcs] != oo) {
      pisz(lcs);
      return 0;
   }
}