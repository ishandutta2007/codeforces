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

string res[4];
void dopisz (const string &x) {
   FOR(i,4) res[i] += x[i];
}

int main () {
   wez3(s12,s13,s14)
   wez2(s23,s24)
   wez(s34)
   int best = INF, bestk1, bestk2, bestk3, bestk4, bestk12, bestk13, bestk14;
   REP(k4,0,s14) {
      int a = -k4 + s14 - s23;
      int b = +k4 + s12 - s34;
      int c = +k4 + s13 - s24;
      if ((b+c) % 2 != 0) continue;
      if ((b-a) % 2 != 0) continue;
      if ((c-a) % 2 != 0) continue;
      int k1 = (b+c) / 2, k2 = (b-a)/2, k3 = (c-a)/2;
      int d = s14 - k1 - k4;
      int e = s13 - k1 - k3;
      int f = s12 - k1 - k2;
      if ((d+e+f) % 2 != 0) continue;
      int def2 = (d+e+f)/2;
      int k12 = def2 - f, k13 = def2 - e, k14 = def2 - d;
      if (k1 < 0) continue;
      if (k2 < 0) continue;
      if (k3 < 0) continue;
      if (k4 < 0) continue;
      if (k12 < 0) continue;
      if (k13 < 0) continue;
      if (k14 < 0) continue;
      if (s12 != k1+k2+k13+k14) continue;
      if (s13 != k1+k3+k12+k14) continue;
      if (s14 != k1+k4+k12+k13) continue;
      if (s23 != k2+k3+k12+k13) continue;
      if (s24 != k2+k4+k12+k14) continue;
      if (s34 != k3+k4+k13+k14) continue;
      int now = k1+k2+k3+k4+k12+k13+k14;
      if (best > now) {
         best = now;
         bestk1 = k1;
         bestk2 = k2;
         bestk3 = k3;
         bestk4 = k4;
         bestk12 = k12;
         bestk13 = k13;
         bestk14 = k14;
      }
   }
   
   if (best == INF) {
      pisz(-1);
   } else {
      pisz(best);
      while(bestk1--) dopisz("abbb");
      while(bestk2--) dopisz("babb");
      while(bestk3--) dopisz("bbab");
      while(bestk4--) dopisz("bbba");
      while(bestk12--) dopisz("aabb");
      while(bestk13--) dopisz("abab");
      while(bestk14--) dopisz("abba");
      FOR(i,4) printf("%s\n", res[i].c_str());
   }
}