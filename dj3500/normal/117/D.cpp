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

ll n;
int m, mod;
ll u,v;

ll arazybprzezdwa (ll a, ll b) {
   if (a & 1LL) {
      b /= 2;
   } else {
      a /= 2;
   }
   b %= mod;
   a %= mod;
   return (a*b)%mod;
}

ll go (ll l, ll r, ll le, ll re, ll seq, ll pot2) {
   if (l == le && r == re) {
      if (seq == pot2) seq = 0;
      // trzeba policzyc sume liczb z przedzialu [u,v] ktore daja reszte seq (mod pot2)
      ll u1 = u - seq + pot2;
      if (u1 % pot2 == 0) u1 /= pot2;
      else u1 = u1/pot2 + 1;
      ll v1 = v - seq + pot2;
      v1 /= pot2;

      ll d = arazybprzezdwa(u1 + v1, v1 - u1 + 1);
      d = (d * (pot2 % mod)) % mod;
      d += ((seq-pot2) % mod) * ((v1 - u1 + 1) % mod);
      return d % mod;
   }

   ll mid = (le + re) / 2;
   if (r <= mid) return go(l,r,le,mid,seq,pot2*2);
   if (l >= mid+1) return go(l,r,mid+1,re,seq+pot2,pot2*2);
   return (go(l,mid,le,mid,seq,pot2*2) + go(mid+1,r,mid+1,re,seq+pot2,pot2*2)) % mod;
}

int main () {
   scanf("%I64d %d %d",&n,&m,&mod);
   while (m--) {
      ll l,r;
      scanf("%I64d %I64d %I64d %I64d",&l,&r,&u,&v);
      if (u > n) {
         pisz(0);
         continue;
      }
      if (v > n) v = n;
      ll wyn = go(l,r,1,n,1,1);
      wyn %= mod;
      if (wyn < 0) wyn += mod;
      pisz(wyn);
   }
}