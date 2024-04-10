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
#define DBG(vari) // cout<<"["<<__LINE__<<"] "<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (__typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

const int N = 200200;

void add (int pos, int num, int *x) {
   int carry = 0;
   while (num > 0 || carry > 0) {
      x[pos] += (num % 2) + carry;
      carry = x[pos] / 2;
      x[pos] %= 2;
      num /= 2;
      ++pos;
   }
}

void subtract (int *x, int *y, int *z) {
   int carry = 0;
   FOR(pos,N) {
      z[pos] = x[pos] - y[pos] - carry;
      if (z[pos] < 0) {
         z[pos] += 2;
         carry = 1;
      } else {
         carry = 0;
      }
   }
}

int a[N], x[N], y[N], z[N];

int main () {
   wez2(n,k);
   REP(i,0,n) scanf("%d", a+i);
   REP(i,0,n) if (a[i] > 0) add(i, a[i], x);
   REP(i,0,n) if (a[i] < 0) add(i, -a[i], y);
   
   string sx, sy;
   REPD(i,N-1,0) {
      sx += x[i];
      sy += y[i];
   }
   bool mnus;
   if (sx >= sy) {
      subtract(x, y, z);
      mnus = 0;
   } else {
      subtract(y, x, z);
      mnus = 1;
   }
   DBG(vi(x,x+10))
   DBG(vi(y,y+10))
   DBG(vi(z,z+10))
   DBG(mnus)
   
   int zeroes = 0;
   while (z[zeroes] == 0) ++zeroes;
   int far1 = 0;
   FOR(i,N) if (z[i] == 1) far1 = i;
   int cnt = 0;
   REP(i,0,n) {
      if (i > zeroes) break;
      if (far1 - i > 50) continue;
      ll num = 0;
      REPD(pos,far1,i) {
         num *= 2;
         num += z[pos];
      }
      if (mnus) num *= -1;
      DBG(num)
      DBG(a[i])
      if (abs(num - a[i]) <= k && (i != n || num-a[i]!=0)) {
         DBG(i);
         ++cnt;      
      }
   }
   pisz(cnt);
}