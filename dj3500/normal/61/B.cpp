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

char signs[] = "-;_";

string ext (string s) {
   string w;
   FOR(i,s.length()) {
      bool f=0;
      FOR(k,3) if(signs[k]==s[i]) f=1;
      if (f) continue;
      if (s[i] <= 'Z' && s[i] >= 'A') w += s[i]+'a'-'A';
      else w += s[i];
   }
   return w;
}

int main () {
   string s[3];
   cin >> s[0] >> s[1] >> s[2];
   int n;
   cin >> n;
   
   FOR(i,3) {
      s[i] = ext(s[i]);
   }
   
   string g[6];
   g[0] = s[0]+s[1]+s[2];
   g[1] = s[0]+s[2]+s[1];
   g[2] = s[1]+s[0]+s[2];
   g[3] = s[1]+s[2]+s[0];
   g[4] = s[2]+s[1]+s[0];
   g[5] = s[2]+s[0]+s[1];
   
   FOR(k,n) {
      string od;
      cin >> od;
      od = ext(od);
      bool f=0;
      FOR(i,6) if(g[i]==od) f=1;
      cout << (f ? "ACC" : "WA") << endl;
   }
}