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

#define ull unsigned long long
map<ull,int> roz; // rozklad: {<liczba pierwsza, krotnosc>}

ull gcd (ull a,ull b) {
    if (!a) return b;
    return gcd(b%a,a);
}

ull mult (ull a, ull b, ull m) { //mnozy (a*b)%m dla a,b<2^63
    if (!a || !b) return 0;
    if (b < (1LL<<31) && a < (1LL<<31)) return (a*b)%m;
    ull x = 0;
    while (b) {
        if (b&1) x = (x+a) % m;
        a = (a<<1) % m;
        b >>= 1;
    }
    return x;
}

ull pow (ull n, ull k, ull m) { //(n^k)%m
    ull w = 1;
    while (k) {
        if (k&1) w = mult(w,n,m);
        n = mult(n,n,m);
        k >>= 1;
    }
    return w;
}

bool TRM (ull x, int ile) {
    if (x==2 || x==3) return 1;
    if (!(x%2) || !(x%3) || x==1) return 0;
    ull z0 = x-1; int t = 0;
    while (!(z0&1)) { z0 >>= 1; t++; }
    while (ile--) {
        ull b = pow(2+rand()%(x-3),z0,x);
        if (b==1) continue;
        for(int j=0; j<t && b!=x-1 && b!=1; j++) b = mult(b,b,x);
        if (b != x-1) return 0;
    }
    return 1;
}

ull find_factor(ull z) {
    if (!(z&1)) return 2;
    ull c = rand()%z, x=2, y=2, d=1;
    while (d==1) {
        ull tp = (mult(y,y,z) + c) % z;
        y = (mult(tp,tp,z) + c) % z;
        x = (mult(x,x,z) + c) % z;
        d = gcd(x>y?x-y:y-x, z);
    }
    return d;
}

void rhofact(ull z) {
    if (z==1) return;
    if (TRM(z,10)) {
        roz[z]++;
        return;
    }
    while(1) {
        ull f = find_factor(z);
        if (f != z) {
            rhofact(f);
            rhofact(z/f);
            break;
        }
    }
}

int main () {
   wez(p)
   rhofact(p-1);
   int res = 1;
   FOREACH(it,roz) {
      FOR(u,it->se-1) res *= it->fi;
      res *= it->fi - 1;
   }
   pisz(res);
}