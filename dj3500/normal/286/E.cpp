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


typedef long double T;
T PI = 2 * acos(0.0L);
T round (T x) { return x < 0.0 ? ceil(x - 0.5) : floor(x + 0.5); }

struct Complex {
   T re, im;
   Complex () {}
   Complex (T r) : re(r), im(0) {}
   Complex (T r, T i) : re(r), im(i) {}
   Complex operator * (const Complex &c) const {
      return Complex(re * c.re - im * c.im, im * c.re + re * c.im);
   }
   Complex operator + (const Complex &c) const {
      return Complex(re + c.re, im + c.im);
   }
   Complex operator - (const Complex &c) const {
      return Complex(re - c.re, im - c.im);
   }
};
T real (Complex x) { return x.re; }


// implementacja Stavropolu
void FFT(Complex *a, int N, int dir) {
   int lgN;
   for (lgN = 1; (1 << lgN) < N; lgN++);
   //assert((1 << lgN) == N);
   
   FOR(i,N) {
      int j = 0;
      FOR(k,lgN) {
         j |= ((i>>k)&1) << (lgN-1-k);
      }
      if (i < j) swap(a[i], a[j]);
   }
   
   FORI(s,lgN) {
      int h = 1 << (s - 1);
      Complex t, w, w_m(cos(dir*PI/h), sin(dir*PI/h));
      for (int k = 0; k < N; k += h+h) {
         w = 1;
         FOR(j,h) {
            t = w * a[k+j+h];
            a[k+j+h] = a[k+j] - t;
            a[k+j] = a[k+j] + t;
            w = w * w_m;
         }
      }
   }
}

vector<ll> sq (vector<ll> &a1) {
   int N = 8;
   while (N < SZ(a1)+SZ(a1)+2) N *= 2;
   Complex *t1 = new Complex[N];
   FOR(i,N) t1[i] = 0;
   FOR(i,SZ(a1)) t1[i] = a1[i];
   FFT(t1,N,1);
   FOR(i,N) t1[i] = t1[i] * t1[i];
   FFT(t1,N,-1);
   vector<ll> res(SZ(a1)+SZ(a1)-1);
   FOR(i,SZ(a1)+SZ(a1)-1) res[i] = (ll)round(real(t1[i])/N);
   delete [] t1;
   return res;
}

int main () {
   wez2(n,m)
   vector<ll> in(m+1,0);
   FORI(i,n) {
      wez(ai)
      in[ai] = 1;
   }
   vector<ll> out = sq(in);
   vi res;
   FORI(i,m) {
      if (in[i] && !out[i]) {
         res.pb(i);
      }
      if (!in[i] && out[i]) {
         printf("NO\n");
         return 0;
      }
   }
   printf("YES\n");
   pisz(SZ(res));
   FOREACH(x,res) printf("%d ", *x);
}