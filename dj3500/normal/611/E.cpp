// tested by Hightail: https://github.com/dj3500/hightail
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
#include <cassert>
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
#define DBG(vari) cout<<"["<<__LINE__<<"] "<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (__typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

int go1 (int k, int A, int B, int C, int AB) {
   B += max(0, A-k);
   C += max(0, B-k);
   C = max(0, C-k);
   C = max(0, C-AB);
   return k + AB + (C + 1)/2;
}
int go2 (int k, int A, int B, int C, int AB) {
   B += max(0, A-k);
   AB += max(0, B-k);
   if (C > k) {
      C -= k;
      AB = max(0, AB - C);
      return k + C + (AB+1)/2;
   } else {
      AB = max(0, AB - (k-C));
      // C = 0;
      return k + (AB+1)/2;
   }
}


int main () {
   wez(nnn)
   int musk[3];
   scanf("%d %d %d", musk, musk+1, musk+2);
   sort(musk,musk+3);
   int a = musk[0], b = musk[1], c = musk[2];
   multiset<int,greater<int> > cr;
   FOR(i,nnn) {
      wez(x)
      cr.insert(x);
   }
   int res = 0;
   if (!cr.empty() && *cr.begin() > a+b+c) {
      pisz(-1);
      return 0;
   }
   while (!cr.empty() && *cr.begin() > b+c) {
      // abc
      cr.erase(cr.begin());
      ++res;
   }
   while (!cr.empty() && *cr.begin() > a+c) {
      // a, bc
      cr.erase(cr.begin());
      ++res;
      auto it = cr.lower_bound(a);
      if (it != cr.end()) cr.erase(it);
   }
   //DBG(SZ(cr))
   while (!cr.empty() && *cr.begin() > max(a+b,c)) {
      // b, ac
      cr.erase(cr.begin());
      ++res;
      auto it = cr.lower_bound(b);
      if (it != cr.end()) cr.erase(it);
   }

   int best = INF;
   if (a+b > c) {
      int A=0, B=0, C=0, AB=0;
      for (int x : cr) {
         if (x > c) ++AB;
         else if (x > b) ++C;
         else if (x > a) ++B;
         else ++A;
      }
      REP(k,0,nnn) REMIN(best, go1(k,A,B,C,AB));
   } else {
      int A=0, B=0, AB=0, C=0;
      for (int x : cr) {
         if (x > a+b) ++C;
         else if (x > b) ++AB;
         else if (x > a) ++B;
         else ++A;
      }
      REP(k,0,nnn) REMIN(best, go2(k,A,B,C,AB));
   }
   pisz(best + res);
}