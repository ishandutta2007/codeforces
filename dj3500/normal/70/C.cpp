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

string toOtherBase(int num, int b) {
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

int fromOtherBase(string s, int b) {
   int res = 0, po = 1;
   REPD(i,s.length()-1,0) {
      int num;
      if (s[i] >= '0' && s[i] <= '9') num = s[i]-'0';
      else num = s[i]-'A'+10;
      res += po*num;
      po *= b;
   }
   return res;
}

int rev (int x) {
   string s = toOtherBase(x,10);
   reverse(ALL(s));
   return fromOtherBase(s,10);
}

int gcd (int a, int b) {
   if (b==0) return a;
   return gcd(b,a%b);
}

pii skroc (pii p) {
   int g = gcd(p.fi,p.se);
   return mp(p.fi/g, p.se/g);
}

inline pii odwroc (pii p) {
   return mp(p.se,p.fi);
}

inline bool lepszy (pii p, pii q) {
   return ((ll)p.fi*p.se < (ll)q.fi*q.se);
}

const int N = 100000;
pii areva[100002], revaa[100002];

int main () {
   wez3(maxx,maxy,w)
   int n = max(maxx,maxy);
   FORI(i,n) {
      areva[i] = skroc(mp(i,rev(i)));
      revaa[i] = odwroc(areva[i]);
   }
   
   map<pii,int> m1,m2;
   
   int x = maxx, y = 1;
   m2[areva[1]]=1;
   REP(i,1,x) m1[revaa[i]]++;
   pii wyn=mp(INF,INF); // uwaga na mnozenie!
   int ile = m1[mp(1,1)];
   while (x > 0) {
      bool koniec = 0;
      while (ile < w) {
         y++;
         // recalc
         m2[areva[y]]++;
         ile += m1[areva[y]];
         if (y > maxy) { koniec = 1; break; }
      }
      if (koniec) break;
      if (lepszy(mp(x,y), wyn)) wyn = mp(x,y);
      --x;
      // recalc
      m1[revaa[x+1]]--;
      ile -= m2[revaa[x+1]];
   }
   if (wyn.fi == INF) pisz(-1);
   else printf("%d %d\n",wyn.fi,wyn.se);
   
   

}