#include<bits/stdc++.h>

using namespace std;

#define X first
#define Y second

typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;

ll mod = 1e9+7;

vll F(2e5+10);
vll I(2e5+10);
vpll N;
vll R;
vll D;
ll h,w,n;

ll ex(ll a, ll p){
  if(p == 0) return 1;
  if(p%2) return (a*ex((a*a)%mod,(p-1)/2))%mod;
  else return (ex((a*a)%mod,p/2))%mod;
}

bool comp(pll a,pll b){
  if(a.X <= b.X and a.Y <= b.Y) return true;
  return false;
}

ll comb(ll a, ll b){
  return (F[a+b]*((I[a]*I[b])%mod))%mod;
}

ll f(int i){
  if(D[i] != -1) return D[i];
  
  D[i] = comb(h-N[i].X,w-N[i].Y)%mod;
  
  for(int j = 0;j < n;++j){
    if(i == j) continue;
    
    if(comp(N[i],N[j])){
      ll rest = (comb(N[j].X-N[i].X,N[j].Y-N[i].Y)*f(j))%mod;
      D[i] = (D[i]+mod-rest)%mod;
    }
  }
  
  return D[i];
}

int main(){
  F[0] = 1;
  I[0] = 1;
  for(ll i = 1;i <= 2e5;++i){ 
    F[i] = (i*F[i-1])%mod;
    I[i] = ex(F[i],mod-2)%mod;
  }
  

  cin>>h>>w>>n;
  
  N = vpll(n);
  D = vll(n,-1);
  
  for(int i = 0;i < n;++i) cin>>N[i].X>>N[i].Y;
  
  ll res = comb(h-1,w-1);

  for(int i = 0;i < n;++i){
    res = (res+mod-(comb(N[i].X-1,N[i].Y-1)*f(i))%mod)%mod;
  }
  
  cout<<res<<endl;
}