#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
vector<pii> p;
vector<pii> v;
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll N;
    cin>>N;
    for(ll i=0;i<N;i++){
      ll a,b;
      cin>>a>>b;
      p.push_back({a,b});
    }
    p.push_back(p[0]);
    if(N%2){
      cout<<"NO";
      return 0;
    }
    for(ll i=0;i<N/2;i++){
      v.push_back({abs(p[i].first-p[i+1].first),abs(p[i].second-p[i+1].second)});
    }
    for(ll i=N/2;i<N;i++){
      pii k={abs(p[i].first-p[i+1].first),abs(p[i].second-p[i+1].second)};
      if(k==v[i-N/2])continue;
      cout<<"NO";
      return 0;
    }
    cout<<"YES";
    return 0;
}