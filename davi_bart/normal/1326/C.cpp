#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll N,K;
ll mod=998244353;
vector<ll> pos;
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N>>K;
    ll ma=(N*(N+1))/2-((N-K)*(N-K+1))/2;
    for(ll i=0;i<N;i++){
      ll a;
      cin>>a;
      if(a>N-K)pos.push_back(i);
    }
    ll tot=1;
    for(ll i=1;i<pos.size();i++){
      tot*=pos[i]-pos[i-1];
      tot%=mod;
    }
    cout<<ma<<" "<<tot;
    return 0;
}