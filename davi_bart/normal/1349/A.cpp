#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
vector<pair<ll,ll> > k[200010];
ll poss[20][200010];
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		//freopen("input.txt","r",stdin);
		//freopen("output.txt","w",stdout);
		for(ll i=2;i<200005;i++){
      if(k[i].size())continue;
      k[i].push_back({i,1});
      for(ll j=i+i;j<200007;j+=i){
          ll f=i;
          k[j].push_back({i,0});
          while((j%f)==0){
            k[j].back().second++;
            f*=i;
          }
      }
		}
    ll N;
    cin>>N;
    vector<ll> v;
    for(ll i=0;i<N;i++){
      ll a;
      cin>>a;
      for(ll j=0;j<k[a].size();j++){
        for(ll h=0;h<k[a][j].second;h++){
          poss[h][k[a][j].first]++;
        }
      }
    }
    ll tot=1;
    for(ll i=2;i<200009;i++){
      ll val=1;
      for(ll j=0;j<19;j++){
        if(poss[j][i]>=(N-1))val*=i;
        else break;
      }
      tot*=val;
    }
    cout<<tot;
    return 0;
}