#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
#define int ll
using ll = long long;
using pii = pair<int,int>;
const int MOD = 998244353, N = 1e5 + 10; 
 
vector<int> factor;
int fact[N];
 
long long power(long long x,long long y){
   long long ans=1;
   x %= MOD;
   if(y < 0) return 0;
   while(y){
      if(y & 1) ans = (ans*x) %MOD;
      x = x*x % MOD;
      y /= 2;
   }
   return ans;
}
 
long long inv(long long x){
   return power(x,MOD-2);
}
 
int path(int u,int v){
   u /= v;
   int tot = 0,ans = 1;
   for(auto &e : factor){
      int c = 0;
      while(u%e == 0){
         ++c;
         ++tot;
         u /= e;
      }
      if(c){
         ans *= inv(fact[c]);
         ans %= MOD;
      }
   }
   ans *= fact[tot];
   ans %= MOD;
   return ans;
}  
 
int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   fact[0] = 1;
   f(i,1,N){
      fact[i] = fact[i-1]*i%MOD;
   }
   int D;
   cin >> D;
   for(int i=2;i*i<=D;i++){
      if(D%i == 0){
         factor.pb(i);
         while(D%i == 0){
            D /= i;
         }
      }
   }
   if(D>1){
      factor.pb(D);
   }
   int q;
   cin >> q;
   while(q--){
      int u,v;
      cin >> u >> v;
      int g = __gcd(u,v);
      int ans = path(u,g)*path(v,g);
      ans %= MOD;
      cout << ans << '\n';
   }
   return 0;
}