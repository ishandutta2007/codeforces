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
#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

#define N 5005
bool mex[N];
int nimber[N];

int get (string s) {
   int cur = 0, xo = 0;
   s += '#';
   for (int i = 1; i < SZ(s); ++i) {
      if (s[i-1] == s[i+1]) ++cur;
      else {
         xo ^= nimber[cur];
         //DBG(cur);
         cur = 0;
      }
   }
   return xo;
}

int main () {
   nimber[0] = 0;
   nimber[1] = 1;
   nimber[2] = 1;
   REP(i,3,5000) {
      vi v;
      v.pb(nimber[i-2]);
      for (int j = 0; j < (i-1)/2; ++j) {
         v.pb(nimber[j] ^ nimber[i-3-j]);
      }
      FOREACH(x,v) mex[*x] = 1;
      while (mex[nimber[i]]) nimber[i]++;
      FOREACH(x,v) mex[*x] = 0;
   }
   
   IOS
   string s;
   cin >> s;
   int xo = get(s);
   if (xo == 0) {
      cout << "Second";
   } else {
      s += '#';
      for (int i = 1; i < SZ(s); ++i) {
         if (s[i-1] == s[i+1]) {
            if (0 == (get(s.substr(0,i)) ^ get(s.substr(i+1)))) {
               cout << "First\n" << i+1;
               return 0;
            }
         }
      }
   }
}