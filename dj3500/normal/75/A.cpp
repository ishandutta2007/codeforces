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
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));

// uwaga: dziaaj tylko dla liczb nieujemnych

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

string toOtherBase(ll num, int b) {
   string w;
   if (num==0) w = "0";
   while (num != 0) {
      int r = num%b;
      num /= b;
      if (r < 10) w += r+'0';
      else w += r+'A'-10;
   }
   reverse(ALL(w));
   return w;
}


int main () {
   wez2(a,b)
   int c=a+b;
   string aa = toOtherBase(a,10), bb = toOtherBase(b,10), cc = toOtherBase(c,10);
   string a3,b3,c3;
   FOR(i,aa.length()) if (aa[i]!='0') a3 += aa[i];
   FOR(i,bb.length()) if (bb[i]!='0') b3 += bb[i];
   FOR(i,cc.length()) if (cc[i]!='0') c3 += cc[i];
   int a4=fromOtherBase(a3,10), b4 = fromOtherBase(b3,10), c4=fromOtherBase(c3,10);
   printf((c4==a4+b4) ? "YES\n" : "NO\n");
}