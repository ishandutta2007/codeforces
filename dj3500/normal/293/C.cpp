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

#define ull unsigned ll
const int _k = 16; const ull _mask = (1<<_k)-1;
ull mul (ull a, ull b, ull mod) { // za: b, mod < 2^(64-_k)
    ull result = 0;
    while (a) {
        ull temp = (b * (a & _mask)) % mod;
        result = (result + temp) % mod;
        a >>= _k;
        b = (b << _k) % mod;
    }
    return result;
}

/* inline ull mul(ull a, ull b, ull mod) { return (a*b) % mod; } */

ull pow (ull a, ull w, ull mod) {
    ull res = 1;
    while (w){
        if (w&1) res = mul(res, a, mod);
        a = mul(a, a, mod);
        w /= 2;
    }
    return res;
}

bool primeTest (ull n, int a) {
    if (a > n-1) return 1;
    ull d = n-1;
    int s = 0;
    while (!(d&1)) {
        d /= 2;
        s++;
    }
    ull x = pow(a, d, n);
    if (x == 1 || x == n-1) return 1;
    FOR(i,s-1){
        x = mul(x, x, n);
        if (x == 1) return 0;
        if (x == n-1) return 1;    
    }
    return 0;
}

/*  Dla n<2^32 testujemy 2, 7, 61
 *  Dla n<2^48 testujemy pierwsze z [2,17] 
 *  Dla n<2^64 testujemy 2, 325, 9375, 28178, 
        450775, 9780504, 1795265022             */
        
bool isPrime(ull n) {
    if (n < 4) return n > 1;
    return (n%2) && primeTest(n, 2) && primeTest(n, 7) && primeTest(n, 61);
}

/*  Test mozna przyspieszyc, sprawdzajac najpierw podzielnosc przez
 *  pierwsze kilkanascie liczb pierwszych. */


// dziala w czasie O(n^0.25)
// zostawia wynik w mapie roz
// przed uzyciem zrobic roz.clear()

map<ull,int> roz; // rozklad: {<liczba pierwsza, krotnosc>}
ull find_factor(ull z) {
    if (!(z&1)) return 2;
    ull c = rand() % z, x = 2, y = 2, d = 1;
    while (d == 1) {
        ull tp = (mul(y,y,z) + c) % z;
        y = (mul(tp,tp,z) + c) % z;
        x = (mul(x,x,z) + c) % z;
        d = __gcd(x>y ? x-y : y-x, z);
    }
    return d;
}
void rhofact(ull z) {
    if (z==1) return;
    if (isPrime(z)) { roz[z]++; return; }
    while(1) {
        ull f = find_factor(z);
        if (f != z) {
            rhofact(f);
            rhofact(z/f);
            break;
        }
    }
}

typedef vector<pair<ll,int> > Roz;
Roz rozklad (ll x) { // rozklad: {<liczba pierwsza, krotnosc>}
   roz.clear();
   rhofact(x);
   Roz res;
   FOREACH(it,roz) res.pb(*it);
   return res;
}

int main () {
   ll n;
   cin >> n;
   if (n % 3) { pisz(0); return 0; }
   n /= 3;
   Roz roz = rozklad(n);
   
   int res = 0;
   int m = SZ(roz);
   vi v(m,0);
   while(1) {
      vi w(m,0);
      while(1) {
         // rob cos z v i w
         ll a=1,b=1;
         FOR(j,m) {
            FOR(u,v[j]) a *= roz[j].fi;
            FOR(u,w[j]) b *= roz[j].fi;
         }
         ll c =  n/a/b;
         if ((a+b+c) % 2 == 0) if (a+b>c && a+c>b && b+c>a) ++res;
         
         int j = 0;
         while (j < m) {
            w[j]++;
            if (w[j] > roz[j].se-v[j]) {
               w[j] = 0;
               j++;
            } else break;
         }
         if (j == m) break;
      }
      
      
      int j = 0;
      while(j < m) {
         v[j]++;
         if (v[j] > roz[j].se) {
            v[j] = 0;
            j++;
         } else break;
      }
      if (j == m) break;
   }
   pisz(res);
}