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
#define TESTS wez(t)while(t--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)

int d[4004][4004];
int f[300];

int main () {
   wez2(ti,td)wez2(tr,te)
   string a,b;
   cin >> a >> b;
   
   d[0][0]=INF;
   FOR(i,a.length()+1) {
      d[i+1][1] = i*td;
      d[i+1][0] = INF;
   }
   FOR(j,b.length()+1) {
      d[1][j+1] = j*ti;
      d[0][j+1] = INF;
   }
   FOR(u,300) f[u]=0;
   FORI(i,a.length()) {
      int r=0;
      FORI(j,b.length()) {
         int i1 = f[b[j-1]];
         int j1 = r;
         int c = (a[i-1]==b[j-1]) ? 0 : 1;
         if (!c) r=j;
         d[i+1][j+1] = min(min(d[i][j] + c*tr, d[i+1][j] + ti), min(d[i][j+1]+td, d[i1][j1]+(i-i1-1)*td + te +(j-j1-1)*ti));
      }
      f[a[i-1]]=i;
   }
   pisz(d[a.length()+1][b.length()+1]);
}