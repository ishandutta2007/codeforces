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
template<typename T> ostream& operator<<(ostream &s,vector<T> t){FOR(i,SZ(t))s<<t[i]<<"\n";return s; }
#define IN(x,y) ((y).find((x))!=(y).end())
#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));

char s[1005];
int prawo[1005][1005], dol[1005][1005];
vector<string> v;

void rot () {
   string pusty;
   FOR(i,SZ(v)) pusty += " ";
   vector<string> w(SZ(v[0]), pusty);
   FOR(i,SZ(v)) FOR(j,SZ(v[0])) w[j][i] = v[SZ(v)-1-i][j];
   v = w;
}

ll go () {
   int n = SZ(v), m = SZ(v[0]);

   FOR(i,n) prawo[i][m-1] = 0;
   REPD(j,m-2,0) FOR(i,n) prawo[i][j] = prawo[i][j+1] + (v[i][j+1] == '*');

   FOR(j,m) dol[n-1][j] = 0;
   REPD(i,n-2,0) FOR(j,m) dol[i][j] = dol[i+1][j] + (v[i+1][j] == '*');

   ll res = 0;
   FOR(i,n) FOR(j,m) if(v[i][j] == '*') res += (ll)prawo[i][j] * (ll)dol[i][j];

//DBG(res)
   return res;
}

int main () {
   wez2(n,m)
   FOR(i,n) {
      scanf("%s",s);
      v.pb(s);
   }

   //DBG(v)
   ll wyn = go();
   rot();
   //DBG(v)
   wyn += go();
   rot();
   //DBG(v)
   wyn += go();
   rot();
   //DBG(v)
   wyn += go();

   //rot();
   //DBG(v)

   printf("%I64d\n",wyn);
}