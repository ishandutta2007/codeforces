// tested by Hightail: https://github.com/dj3500/hightail
#include <bits/stdc++.h>
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

const int MOD = 1000000007, N = 200200;

ll inv[N], st[N], pow2i[N], fact[N], factinv[N];

int main () {
   inv[1] = 1;
   REP(i,2,200000) inv[i] = MOD - MOD / i * inv[MOD % i] % MOD;
   pow2i[0] = 1;
   REP(i,1,200000) pow2i[i] = pow2i[i-1] * inv[2] % MOD;
   fact[0] = 1;
   REP(i,1,200000) fact[i] = fact[i-1] * i % MOD;
   factinv[0] = 1;
   REP(i,1,200000) factinv[i] = factinv[i-1] * inv[i] % MOD;
   wez(n);
   ll T;
   cin >> T;
   FORI(i,n) {
      wez(x);
      st[i] = st[i-1] + x;
   }
   ll res = 0;
   ll k = -1;
   ll p = 1;
   FORI(i,n) {
      ll l = T - st[i];
      if (l < 0) break;
      if (l >= i) {
         res += 1;
         k = i;
      } else {
         ll sum = 0;
         REP(j,l+1,k) sum += fact[i-1] * factinv[j] % MOD * factinv[i-1-j] % MOD;
         sum %= MOD;
         p -= sum * pow2i[i-1] % MOD;
         //DBG(sum * pow2i[i-1] % MOD);
         p -= fact[i-1] * factinv[l] % MOD * factinv[i-1-l] % MOD * pow2i[i] % MOD;
         //DBG(fact[i-1] * factinv[l] % MOD * factinv[i-1-l] % MOD * pow2i[i] % MOD);
         
         k = l;
         res += p;
      }
      //DBG(i);
      //DBG(res);
   }
   res %= MOD;
   if (res < 0) res += MOD;
   cout << res;
}