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

const int mod = 1000000007, inv2 = 500000004;

typedef vector<int> row;   // na longlongach dziala 10 razy wolniej
const int R = 2;                // ustawic to przed uzyciem
struct macierz {
   int a00, a01, a10, a11;
   macierz () : a00(0), a01(0), a10(0), a11(0) {}
   
};

macierz id() {
   macierz w;
   w.a00 = w.a11 = 1;
   return w;
}

macierz mult(const macierz &m1, const macierz &m2) {
   macierz w;
   w.a00 = (1LL * m1.a00 * m2.a00 + 1LL * m1.a01 * m2.a10) % mod;
   w.a01 = (1LL * m1.a00 * m2.a01 + 1LL * m1.a01 * m2.a11) % mod;
   w.a10 = (1LL * m1.a10 * m2.a00 + 1LL * m1.a11 * m2.a10) % mod;
   w.a11 = (1LL * m1.a10 * m2.a01 + 1LL * m1.a11 * m2.a11) % mod;
   return w;
}

macierz potega(const macierz &m, ll k) { // uwaga: czy wczytae k jako longlonga?
   if (!k) return id();
   macierz x = potega(m,k/2);
   x = mult(x,x);
   if (k&1) return mult(m,x);
   return x;
}

int main () {
   macierz st;
   st.a00 = inv2;
   st.a10 = inv2;
   macierz m;
   m.a00 = mod-1;
   m.a01 = 1;
   m.a11 = 2;
   TESTS {
      ll ai;
      scanf("%I64d", &ai);
      m = potega(m, ai);
   }
   macierz res = mult(m, st);
   printf("%d/%d", res.a00, res.a10);
}