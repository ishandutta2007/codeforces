#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//mt19937 rng(chrono::steady_clock::now().tempo_since_epoch().count());
ll num(ll a,ll b,ll c){
  return ((a-b)*(a-b)+(a-c)*(a-c)+(b-c)*(b-c));
}
ll sol(vector<ll> &a,vector<ll> &b,vector<ll> &c){
  ll mi=4e18;
  for(ll i=0;i<a.size();i++){
    ll posb=max(lower_bound(b.begin(),b.end(),a[i])-b.begin()-3,0);
    for(ll j=0;j<6;j++){
      if(posb==b.size())break;
      ll posc=max(lower_bound(c.begin(),c.end(),(a[i]+b[posb])/2)-c.begin()-3,0);
      for(ll h=0;h<6;h++){
        if(posc==c.size())break;
        mi=min(mi,num(a[i],b[posb],c[posc]));
        posc++;
      }
      posb++;
    }
  }
  return mi;
}
void solve(){
  ll A,B,C;
  cin>>A>>B>>C;
  vector<ll> a,b,c;
  ll h;
  for(ll i=0;i<A;i++){
    cin>>h;
    a.push_back(h);
  }
  for(ll i=0;i<B;i++){
    cin>>h;
    b.push_back(h);
  }
  for(ll i=0;i<C;i++){
    cin>>h;
    c.push_back(h);
  }
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  sort(c.begin(),c.end());
  cout<<min({sol(a,b,c),sol(a,c,b),sol(b,c,a)})<<'\n';
}
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		//freopen("output.txt","w",stdout);
    ll T;
    cin>>T;
    while(T--){
      solve();
    }
    return 0;
}