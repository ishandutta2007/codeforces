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
using namespace std;
#define pb push_back
#define INF 2147483647
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

inline bool uppercase (char c) {
   return ((c >= 'A') && (c <= 'Z'));
}

string tolow (string a) {
   FOR(i,a.length()) if (uppercase(a[i])) a[i] += 'a'-'A';
   return a;
}

string w[200], u[200];

int main () {
   wez(n)
   FOR(i,n) {
      cin >> u[i];
      w[i] = tolow(u[i]);
   }
   string f;
   cin >> f;
   
   string s = tolow(f);
   
   char letter;
   cin >> letter;
   char upletter = letter + 'A' - 'a';
   char other = 'a';
   if (letter == 'a') other = 'b';
   char upother = other + 'A' - 'a';
   
   vector<bool> good(s.length(),0);
   
   FOR(i,n) {
      for (int pos = 0; pos + w[i].length() <= s.length(); ++pos) {
         bool ok = 1;
         FOR(p,w[i].length()) if (w[i][p] != s[pos+p]) ok = 0;
         if (ok) FOR(p,w[i].length()) good[pos+p] = 1;
      }
   }
   
   //DBG(good)
   FOR(i,f.length()) {
      if (!good[i]) continue;
      if (f[i] == letter) f[i] = other;
      else if (f[i] == upletter) f[i] = upother;
      else if (uppercase(f[i])) f[i] = upletter;
      else f[i] = letter;
   }
   cout << f << endl;
   
}