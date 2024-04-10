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

#define N 300006
char str[N], p[N];
vi children[N];
string up[N];
int kn[N];
int res = 0;
int szp;
int trans[N][30];

void go (int v, int ind, int ppos) {
   if (ind == SZ(up[v])) {
      FOREACH(x,children[v]) {
         go(*x,0,ppos);
      }
   } else {
      ppos = trans[ppos][up[v][ind] - 'a'];
      if (ppos==szp) ++res;
      go(v,ind+1,ppos);
   }
}

int main () {
   wez(n)
   REP(i,2,n) {
      wez(pi)
      scanf("%s", str);
      children[pi].pb(i);
      up[i] = str;
   }
   scanf("%s", p);
   szp = strlen(p);
   REP(i,0,szp) kn[i] = -1;
   FORI(i,szp) {
      int j = kn[i-1];
      while (j != -1 && p[j] != p[i-1]) j = kn[j];
      kn[i] = j+1;
   }
   REP(c,'a','z') trans[0][c-'a'] = (c == p[0]);
   REP(ppos,1,szp) REP(c,'a','z') {
      if (ppos == szp || p[ppos] != c) trans[ppos][c-'a'] = trans[kn[ppos]][c-'a'];
      else trans[ppos][c-'a'] = ppos + 1;
   }
   
   go(1,0,0);
   pisz(res);
}