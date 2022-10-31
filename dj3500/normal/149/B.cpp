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

string lead0 (string x) {
   int p = 0;
   while (p < SZ(x) && x[p] == '0') ++p;
   if (p == SZ(x)) return "0";
   else return x.substr(p);
}

ll fromOtherBase(string s, int b) {
   ll res = 0, po = 1;
   REPD(i,s.length()-1,0) {
      int num;
      if (s[i] >= '0' && s[i] <= '9') num = s[i]-'0';
      else num = s[i]-'A'+10;
      res += po*num;
      po *= b;
   }
   return res;
}


string a[2];
int maxval[] = {23,59};
bool possible (int u, int r) {
   FOR(i,SZ(a[u])) {
      int dig;
      if (a[u][i] >= '0' && a[u][i] <= '9') dig = a[u][i] - '0';
      else dig = a[u][i] - 'A' + 10;
      //DBG(a[u][i])
      //DBG(dig)
      if (dig >= r) return 0;
   }
   ll val = fromOtherBase(a[u], r);
   return val <= maxval[u];
}

char ss[20];

int main () {
   scanf("%s",ss);
   string s(ss);
   int pos = 0;
   while (s[pos] != ':') ++pos;
   a[0] = s.substr(0,pos);
   a[1] = s.substr(pos+1);
   FOR(u,2) a[u] = lead0(a[u]);
   if (possible(0,60) && possible(1,60)) {
      pisz(-1);
   } else {
      int k = 0;
      REP(r,2,59) if (possible(0,r) && possible(1,r)) { printf("%d ",r); k++; }
      if (k == 0) pisz(0);
   }
}