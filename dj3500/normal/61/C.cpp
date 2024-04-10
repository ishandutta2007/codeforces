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
#define IN(x,y) ((y).find((x))!=(y).end()) 
#define DBG(vari) cout<<#vari<<" = "<<vari<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(t)while(t--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
template<typename T,typename TT> inline ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> inline ostream& operator<<(ostream &s,vector<T> t){FOR(i,t.sz)s<<t[i]<<" ";return s; }
inline void pisz(int n) { printf("%d\n",n); }

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
   wez(a)
   string b1,c1;
   cin >> b1;
   int b;
   if (b1 != "R") b = atoi(b1.c_str());
   cin >> c1;
   
   ll c = fromOtherBase(c1,a);
   
   string w;
   if (b1 == "R") {
      int r1000 = c / 1000;
      FOR(i,r1000) w += "M";
      c %= 1000;
      
      if (c >= 900) {
         c -= 900;
         w += "CM";
      }
      
      if (c >= 500) {
         c -= 500;
         w += "D";
      }
      
      if (c >= 400) {
         c -= 400;
         w += "CD";
      }
      
      int r100 = c/100;
      FOR(i,r100) w += "C";
      c %= 100;
      
      if (c >= 90) {
         c -= 90;
         w += "XC";
      }
      
      if (c >= 50) {
         c -= 50;
         w += "L";
      }
      
      if (c >= 40) {
         c -= 40;
         w += "XL";
      }
      
      int r10 = c/10;
      FOR(i,r10) w += "X";
      c %= 10;
      
      if (c >= 9) {
         c -= 9;
         w += "IX";
      }
      
      if (c >= 5) {
         c -= 5;
         w += "V";
      }
      
      if (c >= 4) {
         c -= 4;
         w += "IV";
      }
      
      FOR(i,c) w += "I";
      
   } else {
      w = toOtherBase(c,b);
   }
   cout << w << endl;
}