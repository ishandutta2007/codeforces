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
#define DBG(vari) cout<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

const int DIGITS = 6, BASE = 1000000; // uwaga: liczba_blokow*BASE^2 musi sie miescic w longlongu
#define SIZ int(size())
struct bignum : public vi {
   bignum() {
      pb(0);
   }

   bignum(ll num) {
      if(num < BASE) pb(num);
      else while(num > 0) {
         pb(num % BASE);
         num /= BASE;
      }
   }

   bignum(const string &s) {
      for (int i = 0; i < SZ(s); i += DIGITS) {
         int kon = SZ(s)-i, pocz = max(0,kon-DIGITS);
         pb(atoi(s.substr(pocz,kon-pocz).c_str()));
      }
      cut0();
   }

   string str() const {
      stringstream ss;
      ss << back() << setfill('0');
      for(int i = SIZ-2; i>=0; --i) ss << setw(DIGITS) << at(i);
      return ss.str();
   }

   bignum& operator+= (const bignum& y) {
      int maxsz = max(SIZ,SZ(y));
      bool carry = 0;
      FOR(i,maxsz) {
         int sum = carry + (i < SIZ ? at(i) : 0) + (i < SZ(y) ? y[i] : 0);
         if (sum >= BASE) {
            carry = 1;
            sum -= BASE;
         } else {
            carry = 0;
         }
         if (i < SIZ) at(i) = sum;
         else pb(sum);
      }
      if (carry) pb(1);
      return *this;
   }

   void cut0() {
      while (size()>1 && back()==0) pop_back();
   }

   bignum operator* (const bignum& y) const {
      vector<ll> w(size()+SZ(y)+2, 0);

      FOR(i,SIZ) FOR(j,SZ(y)) w[i+j] += (ll)at(i) * y[j];

      ll carry = 0;
      FOR(i,SZ(w)) {
         w[i] += carry;
         carry = w[i] / BASE;
         w[i] %= BASE;
      }

      bignum res;
      res.resize(SZ(w));
      FOR(i,SZ(w)) res[i]=w[i];
      res.cut0();
      return res;
   }

   bignum& operator -= (const bignum &y) { // dziala tylko dla x>=y!
      FOR(i,SIZ) {
         if (i < SZ(y)) at(i) -= y[i];
         if (at(i) < 0) {
            at(i) += BASE;
            at(i+1) -= 1;
         }
      }
      cut0();
      return *this;
   }

   int compare (const bignum &y) const {
      if (SIZ < SZ(y)) return -1;
      if (SIZ > SZ(y)) return 1;
      for (int i = size()-1; i >= 0; --i) if (at(i) != y[i]) {
         if (at(i) < y[i]) return -1;
         else return 1;
      }
      return 0;
   }

   int operator % (int m) const {
      ll w = back()%m;
      for (int i = size()-2; i >= 0; --i) w = (w*BASE + at(i))%m;
      return w;
   }

   bignum& operator /= (int y) { // dziala tylko dla y < BASE!
      ll dz = 0;
      for (int i = size()-1; i >= 0; --i) {
         ll x = dz*BASE + at(i);
         at(i) = x/y;
         dz = x%y;
      }
      cut0();
      return *this;
   }

   bool operator < (const bignum &y) const { return compare(y)<0; }
   bool operator > (const bignum &y) const { return compare(y)>0; }
   bool operator <= (const bignum &y) const { return compare(y)<=0; }
   bool operator >= (const bignum &y) const { return compare(y)>=0; }
   bool operator == (const bignum &y) const { return compare(y)==0; }
   bool operator != (const bignum &y) const { return compare(y)!=0; }
   bignum operator + (const bignum& y) const { bignum res = *this; res += y; return res; }
   bignum operator - (const bignum &y) const { bignum res = *this; res -= y; return res; } // dziala tylko dla x>=y!
   bignum& operator *= (const bignum &y) { return *this = *this * y; }
   bignum operator / (int y) const { bignum res = *this; res /= y; return res; } // dziala tylko dla y < BASE!
};
ostream& operator << (ostream &s, const bignum &y) { return s << y.str(); }


int c[2048][2048];
bignum b[2048];

int main () {
   wez2(n,k)
   FORI(i,n) FORI(j,n) {
      if (i < j) scanf("%d", &c[i][j]);
      else if (i == j) c[i][j] = -1;
      else c[i][j] = c[j][i];
   }
   //DBG("weszlo");
   
   b[k-1] = 1;
   REP(j,1,k-1) b[k-1] *= j;
   REP(j,k,n-2) b[j] = (b[j-1] * j) / (j-k+1);
   
   bignum suma = 0;
   FORI(s,n) {
      int deg = 0;
      ll wg = 0;
      FORI(j,n) if (c[s][j] != -1) { ++deg; wg += c[s][j]; }
      if (deg >= k) {
         suma += b[deg-1] * wg;
      }
   }
   suma *= k;
   REP(j,0,k-1) suma /= n-j;
   cout << suma;
}