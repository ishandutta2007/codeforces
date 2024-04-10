// tested by Hightail: https://github.com/dj3500/hightail
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
#include <cassert>
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
#define DBG(vari) cerr<<"["<<__LINE__<<"] "<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (__typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

int a[1 << 13], sum[1 << 13], maxsum[1 << 13], n, res;

void dfs (int v, int su) {
   su += a[v];
   sum[v] = su;
   if (v < (1 << n)) {
      dfs(2*v, su);
      dfs(2*v + 1, su);
      maxsum[v] = max(maxsum[2*v], maxsum[2*v+1]);
   } else {
      maxsum[v] = sum[v];
   }
}

/*
void add (int v, int obj) {
   int adding = obj - maxsum[v];
   res += adding;
   if (v < (1 << n)) {
      add(2*v, obj);
      
}*/

int main () {
   scanf("%d", &n);
   a[1] = 0;
   REP(i,2,(1 << (n+1)) - 1) {
      scanf("%d", a + i);
   }
   dfs(1, 0);
   res = 0;
   //add(1, maxsum[1]);
   REP(i,2,(1 << (n+1)) - 1) {
      res += maxsum[i / 2] - maxsum[i];
   }
   pisz(res);
}