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
#define DBG(vari) cout<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (__typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

const int N = 200007;
namespace F {
   void add (ll *a, int n, ll x) { // val[n] += x
      for (; n < N; n |= n+1) a[n] += x;
   }
   ll sum (ll *a, int n) { // val[0] + val[1] + ... + val[n]
      ll s = 0;
      while (n >= 0) {
         s += a[n];
         n = (n&(n+1))-1;
      }
      return s;
   }
   ll sumbetween (ll *a, int le, int ri) { return sum(a,ri) - sum(a,le-1); } // 
};

ll a[N];
int offL, offR, n;

void init () {
   FOR(i,n) F::add(a, i, 1);
   offL = offR = 0;
}
int size () {
   return n - offL - offR;
}
int get (int i) {
   return F::sumbetween(a, i + offL, i + offL);
}
void add (int i, int x) {
   F::add(a, i + offL, x);
}
void popfront () {
   ++offL;
}
void popback () {
   ++offR;
}
int sumbetween (int l, int r) {
   return F::sumbetween(a, l + offL, r + offL);
}

int main () {
   scanf("%d", &n);
   bool rev = 0;
   init();
   TESTS {
      wez(ty)
      if (ty == 1) {
         wez(pi)
         if (2 * pi > size()) {
            rev = !rev;
            pi = size() - pi;
         } 
      
         if (!rev) {
            //printf("straight\n");
            while (pi > 0) {
               //printf("add(%d, %d);\n", 2*pi - 1, get(0));
               add(2*pi - 1, get(0));
               --pi;
               popfront();
               //printf("popfront();");
            }
         } else {
            //printf("reversed\n");
            while (pi > 0) {
               //printf("add(%d, %d);\n", size() - 2*pi, get(size() - 1));
               add(size() - 2*pi, get(size() - 1));
               --pi;
               popback();
               //printf("popback();");
            }
         }
      } else {
         wez2(li,ri)
         if (rev) {
            li = size() - li;
            ri = size() - ri;
            swap(li,ri);
         }
         pisz(sumbetween(li,ri-1));
      }
      
      //DBG(size())
   }
}